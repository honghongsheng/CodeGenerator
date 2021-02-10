# -*- coding: utf-8 -*-
__author__ = 'Administrator'

import re
from datetime import date
import base.tools as tools
import base.BaseCodeGeneratorTemplate as temp
import hashlib
TAB_SIZE = 4

class BaseCodeGenerator():
    def __init__(self, desc, typeManager, baseName, tag = u"unknown"):
        self.baseName = baseName
        self.desc = desc
        self.typeManager = typeManager
        self.tag = tag
        self.OutDir = "" #生成的文件目录
        self.DefFile = "" #生成的文件名称
        self.ImplFile = "" #生成的文件名称
        self.fileDefTemplate = "" #头文件模板
        self.fileImplTemplate = "" #实现文件模板

    #生产代码，不同语言和不同的生成类型，需要继承重写
    def genCodes(self, baseName = ""):
        self.genCodeDef()
        self.genCodeImpl()
    
    #c生成.h
    #C++生成.hpp
    #go生成.go
    def genCodeDef(self):
        ret = self.fileDefTemplate
        ret = tools.replace(ret, u"{{IncludeCodes}}", self.genCodeDefInclude())
        ret = tools.replace(ret, u"{{Contents}}", self.genCodeDefContent())
        ret = tools.replace(ret, u"{{JsonUtils}}", self.genCodeDefJsonUtils())
        ret = tools.replace(ret, u"{{FILE_COMMENTS}}", temp.TEMPLATE_COMMENT)
        ret = tools.replace(ret, u"{{FileName}}", self.baseName.upper())
        ret = tools.replace(ret, u"{{tag}}", self.tag.upper())
        ret = tools.replace(ret, u"{{ExportMacro}}", self.desc.exportMacro)
        ret = tools.replace(ret, u"{{Namespace}}", self.desc.nameSpace)
        tools.saveFile(self.OutDir + "/" + self.DefFile, ret)
    
    #c生成.c
    #C++生成.cpp
    #go没有生成
    def genCodeImpl(self):
        ret = self.fileImplTemplate
        ret = tools.replace(ret, u"{{IncludeCodes}}", self.genCodeImplInclude())
        ret = tools.replace(ret, u"{{Contents}}", self.genCodeImplContent())
        ret = tools.replace(ret, u"{{JsonUtils}}", self.genCodeImplJsonUtils())
        ret = tools.replace(ret, u"{{FILE_COMMENTS}}", temp.TEMPLATE_COMMENT)
        ret = tools.replace(ret, u"{{FileName}}", self.baseName)
        ret = tools.replace(ret, u"{{tag}}", self.tag)
        ret = tools.replace(ret, u"{{ExportMacro}}", self.desc.exportMacro)
        ret = tools.replace(ret, u"{{Namespace}}", self.desc.nameSpace)
        tools.saveFile(self.OutDir + "/" + self.ImplFile, ret)

    #生成头文件的包含目录，或者import代码
    def genCodeDefInclude(self):
        str = u"\n".join([u"#include \"%s\"" % item.strip() for item in self.desc.HppIncludes ])
        return str
    
    #生成实现代码的包含目录，或者import代码
    def genCodeImplInclude(self):
        str = u"\n".join([u"#include \"%s\"" % item.strip() for item in self.desc.CppIncludes ])
        return str

    #生成代码主题内容
    def genCodeDefContent(self):
        return ""
    
    #生成代码主题内容
    def genCodeImplContent(self):
        return ""

    def genCodeDefJsonUtils(self):
        return ""
    
    def genCodeImplJsonUtils(self):
        return ""