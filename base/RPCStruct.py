# -*- coding: utf-8 -*-
__author__ = 'Administrator'

class TypeInfo:
    def __init__(self, typeName, needInit, constRef):
        self.typeName = typeName
        self.needInit = needInit
        self.constRef = constRef
        if not self.needInit :
            if self.isEnum():
                self.needInit = True


    def paramString(self):
        return u"const %s&" % self.typeName
        
        if self.constRef:
            return u"const %s&" % self.typeName
        else:
            return self.typeName

    def getTypeName(self):
        return self.typeName

    def isNeedInit(self):
        return self.needInit

    def declearVariantString(self, name):
        ret = u"%s %s" % (self.getTypeName(), name)
        if self.isNeedInit():
            if self.getTypeName() == u"bool":
                ret += u" = false"
            else :
                ret += u" = utils::getDefaultValue< %s >()" % self.getTypeName()
        ret += u";"
        return ret

    def inParamString(self, name):
        ret = u"%s %s" % (self.paramString(), name)
        return ret

    def outParamString(self, name):
        ret = u"%s& %s" % (self.getTypeName(), name)
        return ret

    def isEnum(self):
        typeName = self.typeName
        typeName = typeName.replace("{{Namespace}}", "")
        if typeName.find("[") == -1 and typeName.find("{") == -1:
            lines = typeName.split(":")
            if len(lines) > 0:
                line = lines[-1]
                if  line.startswith("E") and not line.endswith(">"):
                    return True
                else :
                    return False
            else:
                return False
        else:
            return False

class TypeManager:
    def __init__(self):
        self.types = {}
        self.types[u"b"] = TypeInfo(u"bool", True, False)
        self.types[u"i"] = TypeInfo(u"int", True, False)
        self.types[u"d"] = TypeInfo(u"double", True, False)
        self.types[u"l"] = TypeInfo(u"long long", True, False)
        self.types[u"s"] = TypeInfo(u"std::string", False, False)
        self.types[u"v"] = TypeInfo(u"std::vector", True, False)
        self.types[u"m"] = TypeInfo(u"std::map", True, False)

    def getTypeInfo(self, tag):
        tag = tag.strip(u"#")
        if len(tag) == 1:
            tag = tag.lower()
        typeInfo = self.types.get(tag, None)
        if typeInfo is None:
            typeName = self.getTypeName(tag)
            typeInfo = TypeInfo(typeName, False, True)
        return typeInfo

    def registerType(self, typeName):
        self.types[typeName] = TypeInfo(typeName, False, True)

    def getTypeName(self, tag):
        rawTag = tag
        tag = tag.strip(u"#").strip()
        if len(tag) == 1:
            tag = tag.lower()
        typeName = u""
        typeInfo = self.types.get(tag, None)
        if typeInfo is None:
            # 判断是否是list
            if tag.startswith(u"[") and tag.endswith("]"):
                content = tag[1:-1]
                lName =  self.types.get(u"v", None)
                if  lName is None :
                    raise Exception("list name not find")
                typeName = u"%s< %s >" % (lName, self.getTypeName(content))

            # 判断是否是Map
            elif tag.startswith(u"{") and tag.endswith("}"):
                content = tag[1:-1]
                fields = content.split(u":", 1)
                mName =  self.types.get(u"m", None)
                if  mName is None :
                    raise Exception("map name not find")
                typeName = u"%s< %s, %s >" % (mName, self.getTypeName(fields[0].strip()), self.getTypeName(fields[1].strip()))
            else:
                if tag.find(u"PB::") >= 0:
                    typeName = tag[4:]
                elif tag.find(u"::") >= 0:
                    typeName =tag
                else:
                    typeName = u"{{Namespace}}::%s" % tag
        else :
            typeName = typeInfo.getTypeName()
        return typeName

class Function:
    def __init__(self, name, inParam, outParam, property, comment):
        self.name = name
        self.strInparam = inParam
        self.strOutParam = outParam
        self.property = property
        self.comment = comment
        # 外部使用的参数
        self.inParam = []   # [ [#s, TypeInfo] ] , #s代表参数名, TypeInfo代表参数类型
        self.outParam = []  # [ [#s, TypeInfo] ] , #s代表参数名, TypeInfo代表参数类型

    def genTypeInfos(self, typeManger):
        self.inParam = [ [param[0], typeManger.getTypeInfo(param[1]) ] for param in self.strInparam ]
        self.outParam = [ [param[0], typeManger.getTypeInfo(param[1]) ] for param in self.strOutParam ]
        
        """
        # 避免参数重复
        inParams = []
        for inParam in self.inParam:
            find = False
            for outParam in self.outParam:
                if inParam[0] == outParam[0]:
                    find = True
                    break
            if not find:
                inParams.append(inParam)
        self.inParam = inParams
        """

    def isIncrement(self):
        bIncrement = False
        if len(self.outParam) == 1:
            if self.outParam[0][1].getTypeName().startswith("std::vector"):
                bIncrement = True
        return bIncrement

    def __str__(self):
        return u"name:" + self.name + u"\n" + u"inparam:" + str(self.inParam) + u"\n" + u"outParam:" + str(self.outParam) + u"\n"

class Service:
    def __init__(self, name, property, functions):
        # 服务名称
        self.name = name
        # 请求函数 [ Function ]
        self.functions = functions
        #属性 {}
        self.property = property

class EnumItem :
    def __init__(self):
        self.name = u""
        self.value = u""
        self.comment = u""
        self.chsname = u""#中文显示


class Enum :
    def __init__(self):
        self.name = u""
        self.items = []
        self.property = {}


    def getDefault(self):
        ret = u""
        if len(self.items) > 0:
            ret = self.items[0].name
        return ret

class Struct:
    def __init__(self):
        self.name = u""
        self.property = {}
        self.items = []
        self.baseType = ""
        #结构的序号
        self.num = "0"

    def getDefault(self):
        return u""

class StructItem :
    def __init__(self):
        #字段名
        self.name = u""
        #序号
        self.num = -1
        #对应的数据库字段
        self.json = ""
        #是否是key
        self.isKey = False
        #中文名
        self.chsname = u""
        #类型
        self.type = u""
        #精度
        self.precision = 1
        #标识
        self.flag = 0
        #注释
        self.comment = u""
        #默认值
        self.default = u""
        #是否显示,给c++那边传递一个字符串，1001这样的，1为真，0为假
        self.visible = u""
        #这个item的属性
        self.propertys = []
        #这个item的显示的时候应该调用的函数
        self.funcs = []
        #是否显示在log中
        self.isLog = 0
        #新创建时忽略
        self.ignore = False
        #是否更新时忽略
        self.updateIgnore = False
        #是否强制打包
        self.isForcePack = False

class ConstItem :
    def __init__(self):
        self.name = u""
        self.type = None
        self.value = u""
        self.comment = u""

class RPCDescript:
    def __init__(self):
        # namespace
        self.nameSpace = u""
        # 服务名称
        self.serviceName = u""
        # DLL导出宏
        self.exportMacro = u""
        # 头文件, [#s]
        self.HppIncludes = []
        self.CppIncludes = []
        # 常量定义 [#s]
        self.consts = []
        # 枚举类型([ Enum])
        self.enums = []
        #  结构( [Struct] )
        self.structs = []
        # 服务代码
        self.services = []
        # 请求函数 [ Function ]
        #self.functions = []
        # 错误类型
        self.isNewError = False
        # 类型管理器
        self.typeManager = CppTypeManger()

    def genTypeInfos(self, typeManager):
        for struct in self.structs:
            for item in struct.items:
                item.type = typeManager.getTypeInfo(item.type)
        for service in self.services :
            for item in service.functions :
                item.genTypeInfos(typeManager)
        for aconst in self.consts:
            aconst.type = typeManager.getTypeInfo(aconst.type)

    def getStruct(self, name):
        if len(name):
            for i in self.structs:
                if i.name == name:
                    return i
        return None

class CppTypeManger(TypeManager):
    def __init__(self):
        TypeManager.__init__(self)

if __name__ == "__main__":
    tm = CppTypeManger()
    tag = u"{#s : {#s: #s} }"