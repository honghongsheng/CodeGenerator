# -*- coding: utf-8 -*-
__author__ = 'Administrator'
import base.tools as tools 
from base.BaseCodeGenerator import BaseCodeGenerator
from cpp.ClientCodeGenerator import *
import cpp.ClientCodeGeneratorTemplate as temp

def genInParamString(func):
    inParamStr = u", ".join([u"%s %s" % (x[1].paramString(), x[0]) for x in func.inParam])
    if len(inParamStr) > 0 : inParamStr += u", "
    return inParamStr

def genOutParamString(func):
    outParamStr = u", ".join([u"%s& %s" % (x[1].getTypeName(), x[0]) for x in func.outParam])
    return outParamStr

def genInParamCommentString(func):
    inParamComment = u"\n".join([u"*param[in]  %s" % (x[0]) for x in func.inParam])
    return inParamComment
    
def genOutParamCommentString(func):
    outParamComment = u"\n".join([u"*param[out] %s" % (x[0]) for x in func.outParam])
    return outParamComment

#数据结构
class ClientCodeGenerator(BaseCodeGenerator):
    def __init__(self, desc, typeManager, baseName, DefFile, ImplFile):
        BaseCodeGenerator.__init__(self, desc, typeManager, baseName, u"client")
        self.DefFile = DefFile #生成的文件名称
        self.ImplFile = ImplFile #生成的文件名称
        self.fileDefTemplate = temp.TEMPLATE_DEF #头文件模板
        self.fileImplTemplate = temp.TEMPLATE_IMPL #实现文件模板
    
    #overide
    def genCodeDefInclude(self):
        '''
        每一种类型的代码生成，应该有自己额外的需要包含的头文件
        '''
        self.desc.HppIncludes.append("server_comment_h.h")
        str = BaseCodeGenerator.genCodeDefInclude(self)
        return str
    
   #overide
    def genCodeImplInclude(self):
        '''
        每一种类型的代码生成，应该有自己额外的需要包含的头文件
        '''
        #self.desc.CppIncludes.append("struct_comment_cpp.h")
        str = BaseCodeGenerator.genCodeImplInclude(self)
        return str

    #overide
    def genCodeDefContent(self):
        '''
        生成一个服务客户端类
        '''
        ret = "\n"
        for aservice in self.desc.services:
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
            functions = functions + self.genCodeDefOneServiceFunc(afunc) + "\n"
        ret = tools.replace(ret, u"{{Functions}}", functions)
        ret = tools.replace(ret, u"{{ServiceName}}", aservice.name)
        return ret
    
    #生成一个客户端服务的代码实现
    def genCodeImplOneService(self, aservice):
        ret = temp.TEMPLATE_ONE_SERVICE_IMPL
        functions = ""
        for afunc in aservice.functions:
            functions = functions + self.genCodeImplOneServiceFunc(afunc) + "\n"
        ret = tools.replace(ret, u"{{Functions}}", functions)
        ret = tools.replace(ret, u"{{ServiceName}}", aservice.name)
        return ret
    
    #genCodeDefOneServiceFunc
    def genCodeDefOneServiceFunc(self, func):
        """params"""
        inParamStr = genInParamString(func)
        outParamStr = genOutParamString(func)
        if len(outParamStr) > 0 : outParamStr += u", "

        """func params comment"""
        inParamComment = genInParamCommentString(func)
        outParamComment = genOutParamCommentString(func)
        if len(outParamComment) > 0 : inParamComment += u"\n"

        ret = temp.TEMPLATE_ONE_SERVICE_SYNC_FUNC_DEF
        ret = tools.replace(ret, u"{{FuncComment}}", inParamComment + outParamComment)
        ret = tools.replace(ret, u"{{FuncName}}", func.name)
        ret = tools.replace(ret, u"{{InParam}}", inParamStr)
        ret = tools.replace(ret, u"{{OutParam}}", outParamStr)
        return ret
    
    #genCodeDefOneServiceFunc
    def genCodeImplOneServiceFunc(self, func):
        """params"""
        inParamStr = genInParamString(func)
        outParamStr = genOutParamString(func)
        if len(outParamStr) > 0 : outParamStr += u", "

        ret = temp.TEMPLATE_ONE_SERVICE_SYNC_FUNC_IMPL
        ret = tools.replace(ret, u"{{FuncName}}", func.name)
        ret = tools.replace(ret, u"{{InParam}}", inParamStr)
        ret = tools.replace(ret, u"{{OutParam}}", outParamStr)
        
        """实现协议 yk_json"""
        if True:
            protocal_impl_yk_json = temp.TEMPLATE_ONE_SERVICE_SYNC_FUNC_PTOTOCAL_YAKA_IMPL
            genYkJson = u"\n".join([ u"utils::append(request, \"%s\", %s);" % (param[0], param[0]) for param in func.inParam ] )
            parseYkJson = u"\n".join([ u"utils::safe(response, \"%s\", %s);" % (param[0], param[0]) for param in func.outParam ] )
            protocal_impl_yk_json = tools.replace(protocal_impl_yk_json, u"{{FuncName}}", func.name)
            protocal_impl_yk_json = tools.replace(protocal_impl_yk_json, u"{{GenJson}}", genYkJson)
            protocal_impl_yk_json = tools.replace(protocal_impl_yk_json, u"{{ParseJson}}", parseYkJson)
            ret = tools.replace(ret, u"{{Protocal_Impl}}", protocal_impl_yk_json)
        
        return ret