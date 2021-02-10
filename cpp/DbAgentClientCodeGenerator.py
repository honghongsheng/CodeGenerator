# -*- coding: utf-8 -*-
__author__ = 'Administrator'
import base.tools as tools 
from base.BaseCodeGenerator import BaseCodeGenerator
from cpp.DbAgentClientCodeGenerator import *
import cpp.DbAgentClientCodeGeneratorTemplate as temp
import itertools #排列组合
try:
    from base.RPCStruct import *
except:
    from rpc.script.codeGenerator.base.RPCStruct import *

def genInParamString(func):
    inParamStr = u", ".join([u"%s %s" % (x[1].paramString(), x[0]) for x in func.inParam])
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
        if len(outParamStr) > 0 : inParamStr += u", "
        
        """func params comment"""
        inParamComment = genInParamCommentString(func)
        outParamComment = genOutParamCommentString(func)
        if len(outParamComment) > 0 : inParamComment += u"\n"

        ret = temp.TEMPLATE_ONE_SERVICE_SYNC_FUNC_DEF
        ret = tools.replace(ret, u"{{FuncName}}", func.name)
        ret = tools.replace(ret, u"{{InParam}}", inParamStr)
        ret = tools.replace(ret, u"{{OutParam}}", outParamStr)
        return ret
    
    #genCodeImplOneServiceFunc
    def genCodeImplOneServiceFunc(self, aservice, func):
        """params"""
        inParamStr = genInParamString(func)
        outParamStr = genOutParamString(func)
        if len(outParamStr) > 0 : inParamStr += u", "

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
    
    def genCodeOneStructSqlFunctions(self, aservice, astruct):
        KeyItems = [item for item in astruct.items if item.isKey == True]
        KeyItems = strip(KeyItems)

        Functions = []
        """Insert"""
        Functions.append(self.genCodeOneSqlInsertFunction(aservice, astruct, KeyItems))
        """Get"""
        for keyitem in KeyItems:
            Functions.append(self.genCodeOneSqlGetByKeysFunction(aservice, astruct, keyitem))
        """Update"""
        for keyitem in KeyItems:
            Functions.append(self.genCodeOneSqlUpdateByKeysFunction(aservice, astruct, keyitem))
            
        Functions_1 = []
        for afunc in Functions:
            afunc.with_trace_id = self.desc.with_trace_id
            afunc.genTypeInfos(self.typeManager)
            Functions_1.append(afunc)
        return Functions_1
    
    def genCodeDefOneStructSqlfunctions(self, aservice, astruct):
        '''
        '''
        Functions =  self.genCodeOneStructSqlFunctions(aservice, astruct)
        return '\n'.join([self.genCodeDefOneServiceFunc(aservice, afunc) for afunc in Functions])
    
    def genCodeImplSqlfunctions(self, aservice):
        '''
        '''
        ret = u'\n'.join('%s' % self.genCodeImplOneStructSqlfunctions(aservice, astruct) for astruct in self.desc.structs if "sql" in astruct.property)
        return ret
    
    def genCodeImplOneStructSqlfunctions(self, aservice, astruct):
        Functions =  self.genCodeOneStructSqlFunctions(aservice, astruct)
        return '\n'.join([self.genCodeImplOneServiceFunc(aservice, afunc) for afunc in Functions])
    
    def genCodeOneSqlInsertFunction(self, aservice, astruct, structitems):
        func_name = "%sInsert" % astruct.name
        func_inParams = [[astruct.name, '#%s' % astruct.name]]
        func = Function(func_name, func_inParams, [], {}, "")
        return func
    
    def genCodeOneSqlGetByKeysFunction(self, aservice, astruct, structitems):
        func_name = "%sGet_By_%s" % (astruct.name, '_'.join(['%s' % stripStart(item.name) for item in structitems]))
        func_inParams = [ [item.name, '#%s' % item.type.getRawTypeName()] for item in structitems]
        func_outParams = [[astruct.name, '#%s' % astruct.name]]
        func = Function(func_name, func_inParams, func_outParams,  {}, "")
        return func
    
    def genCodeOneSqlUpdateByKeysFunction(self, aservice, astruct, structitems):
        func_name = "%sUpdate_By_%s" % (astruct.name, '_'.join(['%s' % stripStart(item.name) for item in structitems]))
        func_inParams = [ [item.name, '#%s' % item.type.getRawTypeName()] for item in structitems]
        func = Function(func_name, func_inParams, [], {}, "")
        return func