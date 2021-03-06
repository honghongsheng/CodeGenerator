# -*- coding: utf-8 -*-
__author__ = 'Administrator'
from base.BaseCodeGenerator import BaseCodeGenerator
import base.tools as tools
from cpp.DbAgentStructCodeGenerator import *
import cpp.DbAgentStructCodeGeneratorTemplate as temp

#生成参数
def genItemString(structitem):
    line = u"%s %s;" % (structitem.type.getTypeName(), structitem.name)
    if len(structitem.comment) > 0 : line += u"  //" + structitem.comment
    return line

def genInitCode(astruct):
    ret = u"\n".join([ u", %s(%s)" % (item.name, u"utils::defaultValue<%s>()" % item.type.getTypeName() if len(item.default) == 0 else item.default)\
                                 for item in astruct.items if item.type.isNeedInit() or len(item.default) > 0 ])
    if len(ret) > 0 : ret = u':' + ret[1:len(ret)]
    return ret

def genAssignCode(astruct):
    ret = u"\n".join([ u", %s(right.%s)" % (item.name, item.name) for item in astruct.items])
    if len(ret) > 0 : ret = u':' + ret[1:len(ret)]
    return ret
     
def genCopyCode(astruct):
    ret = u"\n".join([ u"%s = right.%s;" % (item.name, item.name) for item in astruct.items])
    return ret
    
#数据结构
class DbAgentStructCodeGenerator(BaseCodeGenerator):
    def __init__(self, desc, typeManager, baseName, inputFile, outputFile):
        BaseCodeGenerator.__init__(self, desc, typeManager, baseName, u"CPP_DBAGENT_STRUCT")
        self.OutDir = outputFile
        self.DefFile = "%s_dbagent_struct.h" % baseName #生成的文件名称
        self.ImplFile = "%s_dbagent_struct.cpp" % baseName #生成的文件名称
        self.fileDefTemplate = temp.TEMPLATE_DEF #头文件模板
        self.fileImplTemplate = temp.TEMPLATE_IMPL #实现文件模板
        
    #overide
    def genCodeDefInclude(self):
        '''
        每一种类型的代码生成，应该有自己额外的需要包含的头文件
        '''
        #self.desc.HppIncludes.append("")
        str = BaseCodeGenerator.genCodeDefInclude(self)
        return str
    
   #overide
    def genCodeImplInclude(self):
        '''
        每一种类型的代码生成，应该有自己额外的需要包含的头文件
        '''
        self.desc.CppIncludes.append(self.DefFile)
        str = BaseCodeGenerator.genCodeImplInclude(self)
        return str

    #overide
    def genCodeDefContent(self):
        '''
        主体部分, enum,struct
        '''
        ret = u'\n'.join('%s' % self.genCodeDefOneStruct(astruct) for astruct in self.desc.structs)
        return ret
    
    #overide
    def genCodeImplContent(self):
        '''
        主体部分, enum,struct
        '''
        ret = u'\n'.join('%s' % self.genCodeImplOneStruct(astruct) for astruct in self.desc.structs)
        return ret
    
    def genCodeDefJsonUtils(self):
        ret = ''
        for astruct in self.desc.structs:
            ret += 'template<> utils::addJsonValue(jReq, "_%s_", const %s& _%s_);\n' % (astruct.name, astruct.name.lower(), astruct.name.lower())
        return ret
    
    def genCodeImplJsonUtils(self):
        ret = ''
        for astruct in self.desc.structs:
            ret += 'template<> utils::addJsonValue(jReq, "_%s_", const %s& _%s_){_%s_.toJson(jReq);}\n' % (astruct.name, astruct.name, astruct.name.lower(), astruct.name.lower())
        return ret
    
    #生成一个struct定义
    def genCodeDefOneStruct(self, astruct):
        '''Variables'''
        Variables = u"\n".join(['%s' % genItemString(item) for  item in astruct.items])

        '''Serialise'''
        Serialise = u''
        if "json" in astruct.property:
            Serialise += temp.TEMPLATE_STRUCT_FUNC_JSON_DEF

        ret = temp.TEMPLATE_STRUCT_DEF
        ret = tools.replace(ret, u"{{Serialise}}",Serialise)
        ret = tools.replace(ret, u"{{TypeName}}", astruct.name)
        ret = tools.replace(ret, u"{{TypeNameWithInherit}}", astruct.name)
        ret = tools.replace(ret, u"{{Variables}}", Variables)
        
        return ret
    
    #生成一个struct实现
    def genCodeImplOneStruct(self, astruct):
        '''initCode'''
        initCode = genInitCode(astruct)

        '''assignCode'''
        assignCode = genAssignCode(astruct)
   
        '''copycode'''
        copyCode = genCopyCode(astruct)
   
        '''Serialise'''
        Serialise = ""
        if "json" in astruct.property:
            Serialise += temp.TEMPLATE_STRUCT_FUNC_JSON_IMPL
            FromJsonObj = u"\n".join([u"utils::getJsonValue(jsonObj, \"%s\", %s);" % (item.json, item.name) for item in astruct.items])
            Format2JsonObj = u"\n".join([u"utils::addJsonValue(jsonObj, \"%s\", %s);" % (item.json, item.name) for item in astruct.items])
            Serialise = tools.replace(Serialise, u"{{FromJsonObj}}", FromJsonObj)
            Serialise = tools.replace(Serialise, u"{{Format2JsonObj}}", Format2JsonObj)
        
        ret = temp.TEMPLATE_STRUCT_IMPL
        ret = tools.replace(ret, u"{{Serialise}}",Serialise)
        ret = tools.replace(ret, u"{{TypeName}}", astruct.name)
        ret = tools.replace(ret, u"{{TypeNameWithInherit}}", astruct.name)
        ret = tools.replace(ret, u"{{InitCode}}", initCode)
        ret = tools.replace(ret, u"{{AssignCode}}", assignCode)
        ret = tools.replace(ret, u"{{CopyCode}}", copyCode)
        return ret