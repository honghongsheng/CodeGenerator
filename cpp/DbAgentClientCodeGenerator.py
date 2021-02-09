# -*- coding: utf-8 -*-
__author__ = 'Administrator'
import base.tools as tools 
from base.BaseCodeGenerator import BaseCodeGenerator
from cpp.DbAgentClientCodeGenerator import *
import cpp.DbAgentClientCodeGeneratorTemplate as temp
import itertools #排列组合

def genInParamString(func):
    inParamStr = u", ".join([u"%s %s" % (x[1].paramString(), x[0]) for x in func.inParam])
    if len(inParamStr) > 0 : inParamStr += u", "
    return inParamStr

def genOutParamString(func):
    outParamStr = u", ".join([u"%s& %s" % (x[1].getTypeName(), x[0]) for x in func.outParam])
    return outParamStr

def genInParamCommentString(func):
    inParamComment = ''
    if len(func.inParam) > 0: inParamComment = u"\n".join([u"*param[in]  %s" % (x[0]) for x in func.inParam])
    else: inParamComment = 'param[in]'
    return inParamComment
    
def genOutParamCommentString(func):
    outParamComment = ''
    if len(func.inParam) > 0: outParamComment = u"\n".join([u"*param[out] %s" % (x[0]) for x in func.outParam])
    else: outParamComment = 'param[out]'
    return outParamComment

#排重参数
def strip(KeyItems):
    a = KeyItems
    b = KeyItems
    
    #过滤
    KeyItems = itertools.product(a,b)
    
    newKeyItems_map = {}
    for itempair in KeyItems:
        keys = [item.name for item in set(itempair)]
        keys_str = '__'.join([key for key in sorted(keys)])
        print(keys_str)
        newKeyItems_map[keys_str] = set(itempair)
    
    newKeyItems = []
    for itempair in newKeyItems_map:
        newKeyItems.append(newKeyItems_map[itempair])
    KeyItems = newKeyItems
    return KeyItems

#将strData->Data
def stripStart(name):
    if name.startswith("str"):
        return name[3:len(name)]
    if name.startswith("n"):
        return name[1:len(name)]
    if name.startswith("b"):
        return name[1:len(name)]
    
#数据结构
class DbAgentClientCodeGenerator(BaseCodeGenerator):
    def __init__(self, desc, typeManager, baseName, inputFile, outputFile):
        BaseCodeGenerator.__init__(self, desc, typeManager, baseName, u"CPP_DBAGENT_CLIENT")
        self.OutDir = outputFile
        self.DefFile = "%s_dbagent_client.h" % baseName #生成的文件名称
        self.ImplFile = "%s_dbagent_client.cpp" % baseName #生成的文件名称
        self.fileDefTemplate = temp.TEMPLATE_DEF #头文件模板
        self.fileImplTemplate = temp.TEMPLATE_IMPL #实现文件模板
    
    #overide
    def genCodeDefInclude(self):
        '''
        每一种类型的代码生成，应该有自己额外的需要包含的头文件
        '''
        self.desc.HppIncludes.append("%s_dbagent_struct.h" % self.baseName)
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
        生成一个服务客户端类
        '''
        ret = "\n"
        for aservice in self.desc.services:
            print("gen one", aservice.name)
            ret = ret + self.genCodeDefOneService(aservice) + "\n"
        return ret
    
    #overide
    def genCodeImplContent(self):
        ret = ""
        for aservice in self.desc.services:
            ret = ret + self.genCodeImplOneService(aservice) + "\n"
        return ret
    
    #生成一个客户端服务的代码定义
    def genCodeDefOneService(self, aservice):
        ret = temp.TEMPLATE_ONE_SERVICE_DEF
        functions = ""
        for afunc in aservice.functions:
            functions = functions + self.genCodeDefOneServiceFunc(aservice, afunc)
        ret = tools.replace(ret, u"{{SqlFunctions}}", self.genCodeDefSqlfunctions(aservice))
        ret = tools.replace(ret, u"{{Functions}}", functions)
        ret = tools.replace(ret, u"{{ServiceName}}", self.baseName)
        return ret
    
    #生成一个客户端服务的代码实现
    def genCodeImplOneService(self, aservice):
        ret = temp.TEMPLATE_ONE_SERVICE_IMPL
        functions = ""
        for afunc in aservice.functions:
            functions = functions + self.genCodeImplOneServiceFunc(aservice, afunc) + "\n"
        ret = tools.replace(ret, u"{{SqlFunctions}}", self.genCodeImplSqlfunctions(aservice))
        ret = tools.replace(ret, u"{{Functions}}", functions)
        ret = tools.replace(ret, u"{{ServiceName}}", self.baseName)
        ret = tools.replace(ret, u"{{InitCode}}", "")
        return ret
    
    #genCodeDefOneServiceFunc
    def genCodeDefOneServiceFunc(self, aservice, func):
        """params"""
        inParamStr = genInParamString(func)
        outParamStr = genOutParamString(func)
        
        """func params comment"""
        inParamComment = genInParamCommentString(func)
        outParamComment = genOutParamCommentString(func)
        if len(outParamComment) > 0 : inParamComment += u"\n"
        strParamComment = ""#inParamComment + outParamComment

        ret = temp.TEMPLATE_ONE_SERVICE_SYNC_FUNC_DEF
        ret = tools.replace(ret, u"{{FuncName}}", func.name)
        ret = tools.replace(ret, u"{{InParam}}", inParamStr)
        ret = tools.replace(ret, u"{{OutParam}}", outParamStr)
        return ret
    
    #genCodeDefOneServiceFunc
    def genCodeImplOneServiceFunc(self, aservice, func):
        """params"""
        inParamStr = genInParamString(func)
        outParamStr = genOutParamString(func)

        """实现协议"""
        genYkJson = u"\n".join([ u"utils::addJsonValue(jReq, \"%s\", %s);" % (param[0], param[0]) for param in func.inParam ] )
        parseYkJson = u"\n".join([ u"utils::getJsonValue(jResp, \"%s\", %s);" % (param[0], param[0]) for param in func.outParam ] )

        ret = temp.TEMPLATE_ONE_SERVICE_SYNC_FUNC_IMPL
        ret = tools.replace(ret, u"{{FuncName}}", func.name)
        ret = tools.replace(ret, u"{{InParam}}", inParamStr)
        ret = tools.replace(ret, u"{{OutParam}}", outParamStr)
        ret = tools.replace(ret, u"{{FuncName}}", func.name)
        ret = tools.replace(ret, u"{{GenJson}}", genYkJson)
        ret = tools.replace(ret, u"{{ParseJson}}", parseYkJson)
        return ret
    
    def genCodeDefSqlfunctions(self, aservice):
        '''
        SQL请求, enum,struct
        '''
        ret = u'\n'.join('%s' % self.genCodeDefOneStructSqlfunctions(aservice, astruct) for astruct in self.desc.structs if "sql" in astruct.property)
        return ret
    
    def genCodeDefOneStructSqlfunctions(self, aservice, astruct):
        '''
        SQL请求, enum,struct
        '''
        KeyItems = [item for item in astruct.items if item.isKey == True]
        KeyItems = strip(KeyItems)
        print('----%s---' % astruct.name)

        #去重,排列组合
        
        
        ret = "//%s\n" % astruct.name
        """Insert"""
        ret += self.genCodeDefOneSqlInsertfunctions(aservice, astruct, KeyItems)
        """Get"""
        ret += u'\n'.join('%s' % self.genCodeDefOneSqlGetByKeysfunctions(aservice, astruct, keyitem) for keyitem in KeyItems)
        """Update"""
        ret += '\n'
        ret += u'\n'.join('%s' % self.genCodeDefOneSqlUpdateByKeysfunctions(aservice, astruct, keyitem) for keyitem in KeyItems)
        return ret
    
    def genCodeDefOneSqlInsertfunctions(self, aservice, astruct, structitems):
        ret = 'int %sInsert(%s& %s);\n' % (astruct.name, astruct.name, astruct.name)
        return ret
    
    def genCodeDefOneSqlGetByKeysfunctions(self, aservice, astruct, structitems):
        byStr = '_'.join(['%s' % stripStart(item.name) for item in structitems])
        parStr = ', '.join(['const %s& %s' % (item.type.getTypeName(), item.name) for item in structitems])
        ret = 'int %sGet_By_%s(%s& %s, %s);' % (astruct.name, byStr, astruct.name, astruct.name.lower(), parStr)
        return ret
    
    def genCodeDefOneSqlUpdateByKeysfunctions(self, aservice, astruct, structitems):
        byStr = '_'.join(['%s' % stripStart(item.name) for item in structitems])
        parStr = ', '.join(['const %s& %s' % (item.type.getTypeName(), item.name) for item in structitems])
        ret = 'int %sUpdate_By_%s(%s& %s, %s);' % (astruct.name, byStr, astruct.name, astruct.name.lower(), parStr)
        return ret
    
    def genCodeImplSqlfunctions(self, aservice):
        '''
        '''
        ret = u'\n'.join('%s' % self.genCodeImplOneStructSqlfunctions(aservice, astruct) for astruct in self.desc.structs if "sql" in astruct.property)
        return ret
    
    def genCodeImplOneStructSqlfunctions(self, aservice, astruct):
        '''
        SQL请求, enum,struct
        '''
        KeyItems = [item for item in astruct.items if item.isKey == True]
        #去重,排列组合
        KeyItems = strip(KeyItems)

        ret = ""
        """ Insert """
        ret += self.genCodeImplOneSqlInsertfunctions(aservice, astruct)
        """ Get """
        ret += u'\n'.join('%s' % self.genCodeImplOneSqlGetByKeysfunctions(aservice, astruct, keyitem) for keyitem in KeyItems)
        """ Update """
        ret += '\n'
        ret += u'\n'.join('%s' % self.genCodeImplOneSqlUpdateByKeysfunctions(aservice, astruct, keyitem) for keyitem in KeyItems)
        return ret
    
    def genCodeImplOneSqlInsertfunctions(self, aservice, astruct):
        ret = temp.TEMPLATE_ONE_SERVICE_SQL_INSERT_IMPL
        ret = tools.replace(ret, u"{{FuncName}}", self.baseName)
        ret = tools.replace(ret, u"{{StructName}}", astruct.name)
        return ret
    
    def genCodeImplOneSqlGetByKeysfunctions(self, aservice, astruct, structitems):
        
        
        byStr = '_'.join(['%s' % stripStart(item.name) for item in structitems])
        parStr = ', '.join(['const %s& %s' % (item.type.getTypeName(), item.name) for item in structitems])
        
        ret = temp.TEMPLATE_ONE_SERVICE_SQL_GET_IMPL
        ret = tools.replace(ret, u"{{FuncName}}", self.baseName)
        ret = tools.replace(ret, u"{{StructName}}", astruct.name)
        ret = tools.replace(ret, u"{{ByStr}}", byStr)
        ret = tools.replace(ret, u"{{ParStr}}", parStr)
        return ret
    
    def genCodeImplOneSqlUpdateByKeysfunctions(self, aservice, astruct, structitems):
        byStr = '_'.join(['%s' % stripStart(item.name) for item in structitems])
        parStr = ', '.join(['const %s& %s' % (item.type.getTypeName(), item.name) for item in structitems])
        
        ret = temp.TEMPLATE_ONE_SERVICE_SQL_UPDATE_IMPL
        ret = tools.replace(ret, u"{{FuncName}}", self.baseName)
        ret = tools.replace(ret, u"{{StructName}}", astruct.name)
        ret = tools.replace(ret, u"{{ByStr}}", byStr)
        ret = tools.replace(ret, u"{{ParStr}}", parStr)
        return ret