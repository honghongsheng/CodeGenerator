# -*- coding: utf-8 -*-
__author__ = 'Administrator'
import re
try:
    from base.RPCStruct import *
except:
    from rpc.script.codeGenerator.base.RPCStruct import *

class RPCParser:
    def parse(self, rawString):
        lines = rawString.splitlines()
        rawString = u"\n".join([line for line in lines if not line.strip().startswith(u"#") and not line.strip().startswith(u"//") ])

        desc = RPCDescript()
        desc.nameSpace = self.parseNameSpace(rawString)
        desc.serviceName = self.parseServiceName(rawString)
        desc.exportMacro = self.parseExportMacro(rawString)
        desc.HppIncludes = self.parseIncludes('Includes', rawString)
        desc.CppIncludes = self.parseIncludes('CppIncludes', rawString)
        desc.serverIncludes = self.parseIncludes('ServerIncludes', rawString)
        desc.clientIncludes = self.parseIncludes('ClientIncludes', rawString)
        desc.enums = self.parseEnums(rawString)
        desc.structs = self.parseStructs(rawString)
        desc.services = self.parseServices(rawString)
        #desc.functions = self.parseFunctions(rawString)
        desc.consts = self.parseConsts(rawString)
        desc.isNewError = self.parseIsNewError(rawString)
        return desc

    def parseNameSpace(self, rawString):
        mret = re.search(u"Namespace\s*=\s*(\w+)\s*", rawString, re.IGNORECASE)
        if mret != None:
            return mret.group(1)
        else:
            return u""

    def parseServiceName(self, rawString):
        mret = re.search(u"ServiceName\s*=\s*(\w+)\s*", rawString, re.IGNORECASE)
        if mret != None:
            return mret.group(1)
        else:
            return u""

    def parseExportMacro(self, rawString):
        mret = re.search(u"ExportMacro\s*=\s*(\w+)\s*", rawString, re.IGNORECASE)
        if mret != None:
            return mret.group(1)
        else:
            return u""

    def parseIsNewError(self, rawString):
        mret = re.search(u"IsNewError\s*=\s*(\w+)\s*", rawString, re.IGNORECASE)
        if mret != None:
            return True
        else:
            return False

    def parseConsts(self, rawString):
        ret = []
        constList = re.findall(u"\w+\([^\)]+\)\s*:\s*[^;]+;", rawString, re.IGNORECASE)
        for line in constList:
            line = line.strip()
            mret = re.search(u"\s*(?P<name>\w+)\s*\((?P<type>[^\)]+)\s*\)\s*:\s*(?P<value>[^;]+);", line, re.IGNORECASE)
            if mret and mret.group(u"name") and mret.group(u"type") and mret.group(u"value"):
                aconst = ConstItem()
                aconst.name = mret.group(u"name").strip()
                aconst.type = mret.group(u"type").strip()
                aconst.value = mret.group(u"value").strip()
                m = re.search(u"//(.*)", line)
                if m : aconst.comment = m.group(1).strip()
                ret.append(aconst)
        return ret

    def parseIncludes(self, tag, rawString):
        ret = []
        reString = tag + u"\s*=\s*\(([^)]*)\)\s*"
        mret = re.search(reString, rawString, re.IGNORECASE)
        if mret != None:
            content = mret.group(1)
            ret = re.findall(u"\s*([^\s]+)", content)
            ret = [item.strip(",").strip() for item in ret if len(item.strip()) > 0]
        return ret

    def parseEnums(self, rawString):
        strEnums = re.findall(u"enum_\w+\s*:\s*\([^\)]+\)(?:\s*\{[^\}]+\}){0,1}", rawString, re.MULTILINE)
        enums = []
        for anEnum in strEnums:
            enum =  Enum()
            m = re.match(u"enum_(?P<name>\w+)\s*:\s*\((?P<content>[^\)]+)\)\s*(\{(?P<property>[^\}]+)\}){0,1}", anEnum)
            enum.name = m.group(u"name")
            propertys = m.group(u"property")
            if propertys:
                propertys = propertys.strip().split(",")
                tmp = propertys
                propertys = []
                for i in tmp:
                    propertys.append(i.strip())
                #print "parseEnums propertys: ",propertys
            else:
                propertys = []
            for property in propertys:
                enum.property[property] = 1
            strContents = re.findall(u"\w+\s*[^;]+.*", m.group(u"content"), re.MULTILINE)
            contents = []
            for x in strContents:
                item = EnumItem()
                m = re.search(u"//(.*)", x)
                if m : item.comment = m.group(1).strip()
                tmp = ""
                if x.find(u":") > 0:
                    tmp = re.match(u"(\w+(\s*\|[^;]*){0,1})\s*:\s*[^;]", x).group(1).strip()
                else :
                    tmp = re.match(u"(\w+(\s*\|[^;]*){0,1})", x).group(1).strip()
                #item.name = tmp
                if (tmp.find("|") >= 0):
                    item.name, item.chsname = tmp.split("|")
                else:
                    item.name = tmp.split("|")[0]
                    item.chsname = item.comment
                m = re.search(u"[\w\s]*:\s*([^;]+);", x)
                if m:
                    item.value = m.group(1).strip()
                enum.items.append(item)
            enums.append(enum)
        return enums

    def cleanStr(self, raw, key):
        searchStr = u"%s\s*=\s*(?P<ret>[^;:]+)" %(key)
        m = re.search(searchStr, raw)
        try:
            return m.group(u"ret").strip()
        except:
            return u""

    def parseItem(self, strItem):
        item = StructItem()
        hasTagKey = False

        strItem = strItem.strip()
        m = re.search(u"//(.*)", strItem)
        if m :
            item.comment = m.group(1).strip()
        content = strItem[0:strItem.index(";")]
        itemList = content.split(":", 1)
        if len(itemList) < 2:
            print("error")
            return None,  hasTagKey

        ##bValid:#i=1, json="vaild";  //是否有效
        ##第一个参数是字段名称，剩下的,按','分隔作为字段的属性
        item.name = itemList[0].strip()
        m = {}
        sitems = itemList[1].split(",")
        if len(sitems) > 1:
            for d in sitems[1:]:
                ditems = d.split("=")
                if len(ditems) == 2:
                    k = ditems[0].strip()
                    v = ditems[1].strip()
                    if len(k) > 0 and len(v) > 0:
                        m[k] = v

        item.num = int(m.get("index", "-1"))
        item.json = m.get("json", item.json)
        if len(item.json) > 0:
            item.json = item.json[1:len(item.json)-1]
        if len(item.json) == 0:
            item.json = item.name
        if len(item.chsname) == 0:
            item.chsname = item.comment
        item.isKey = len(m.get("iskey", "")) > 0 and int(m.get("iskey", "0")) == 1
    
        str = sitems[0]
        defaultPos = str.find(u"=")
        if defaultPos > 0:
            default = str[defaultPos + 1:]
            item.default = default.strip()
            str = str[0:defaultPos].strip()
        item.type = str.strip()
        return item, hasTagKey

    def parseStructs(self, rawString):
        strStructs = re.findall(u"struct\s*\w+(?:\s*\|\s*[^:]+){0,1}\s*:\s*\{[^\)]+\}(?:\s*\([^\}]+\)){0,1}", rawString)
        structs = []
        for aStruct in strStructs:
            #print "parse struct %s" % repr(aStruct)
            m = re.search(u"(?P<name>\w+)(\s*\|\s*(?P<base>[^:]+)){0,1}\s*:\s*\{(?P<content>[^\)]+)\}\s*(\((?P<property>[^\}]+)\)){0,1}", aStruct)
            baseType = m.group(u"base")
            name = m.group(u"name").strip()
            strContents = m.group(u"content").strip()
            if name.startswith(u"enum"):
                continue
            struct = Struct()
            struct.name = name
            if baseType is not None:
                struct.baseType = baseType.strip()
            propertys = m.group(u"property")
            if propertys:
                propertys = propertys.strip().split(",")
                tmp = propertys
                propertys = []
                for i in tmp:
                    if i.find("=") >= 0:
                        d = i.strip()
                        kvItem = d.split("=")
                        if len(kvItem) == 2:
                            struct.property[kvItem[0].strip()] = kvItem[1].strip()
                    else:
                        struct.property[i.strip()] = 1

            strItems = re.findall(u"\w+[^;^\n]+:[^;:]*;.*", aStruct, re.MULTILINE)
            maxNum = 0
            hasTagKey = False
            maxIndex = 1
            for strItem in strItems:
                item, tHasTagKey = self.parseItem(strItem)
                if tHasTagKey:
                    struct.has = True
                if item is None:
                    continue
                if item is not None:
                    if item.num == -1:
                        item.num = maxIndex
                        maxIndex = maxIndex + 1
                    else:
                        maxIndex = item.num
                        maxIndex = maxIndex + 1
                    struct.items.append(item)
            structs.append(struct)
        return structs

    def parseServices(self, rawString):
        """
        strServices = re.findall(u"service\s*\w+\s+\{\s*(\s*\w+\([^\)]*\)\s*=>\s*\([^\)]*\)\s*(?:\s*\{[^\}]+\}){0,1}\s*)+\s*\}\s*", rawString)
        print("strServices",strServices)
        services = []
        for strService in strServices:
            print("strService",strService)
            m = re.search(u"service\s*(?P<ServiceName>\w+)\s+\{(\s*\w+\([^\)]*\)\s*=>\s*\([^\)]*\)\s*(?:\s*\{[^\}]+\}){0,1}\s*)+\}", strService)
            if m :
                ServiceName = self.parseParams(m.group(u"ServiceName"))
                print("ServiceName",ServiceName)
                service = Service(ServiceName,functions)
                services.append(service)
        """ 
        services = []
        service = Service("dbInterface", self.parseFunctions(rawString))
        services.append(service)
        return services

    def parseFunctions(self, rawString):
        strFuncs = re.findall(u"\s*\w+\([^\)]*\)\s*=>\s*\([^\)]*\)\s*(?:\s*\{[^\}]+\}){0,1}\s*", rawString)
        funcs = []
        for aFunc in strFuncs:
            m = re.search(u"(?P<name>\w+)\s*\((?P<inParam>[^\)]*)\)\s*=>\s*\((?P<outParam>[^\)]*)\)\s*(\{(?P<property>[^\}]+)\}){0,1}\s*", aFunc)
            if m :
                inParams = self.parseParams(m.group(u"inParam"))
                outParams = self.parseParams(m.group(u"outParam"))
                propertys = m.group(u"property")
                if propertys:
                    propertys = propertys.strip().split(",")
                    tmp = propertys
                    propertys = {}
                    for i in tmp:
                        if i.find("=") >= 0:
                            d = i.strip()
                            kvItem = d.split("=")
                            if len(kvItem) == 2:
                                propertys[kvItem[0].strip()] = kvItem[1].strip()
                        else:
                            propertys[i.strip()] = 1
                func_comment = self.getFuncComment(m.group(u"name").strip(), rawString)
                func = Function(m.group(u"name").strip(), inParams , outParams, propertys, func_comment)
                funcs.append(func)
        return funcs

    def getFuncComment(self, function_name, rawString):
        reg_str = u"@\s*" + function_name + "\s*\w+"
        aComments = re.findall(reg_str, rawString)
        funcs = []
        for aComment in aComments:
            reg_str = u"@\s*" + function_name + "\s*(?P<comment>\w+)\s*"
            m = re.search(reg_str, aComment)
            if m :
                comment = m.group(u"comment")
                return comment
        return ""

    def parseParams(self, rawString):
        rawStringCopy = rawString.replace(';', ',')
        words = rawStringCopy.split(u",")
        params = []
        preWord = []
        for word in words:
            word = word.strip()
            if len(word) == 0:
                continue
            elif word.endswith(u"}"):
                preWord.append(word)
                param = u""
                for x in preWord:
                    if len(param) == 0:
                        param += x
                    else :
                        param += (u",",x)
                param = param.rstrip(u",")
                params.append(param)
                preWord = []
            else :
                params.append(word)

        paramList = []
        for param in params:
            pos = param.find(u":")
            name = param[0:pos].strip()
            typeStr = param[pos+1:].strip()
            paramList.append([ name, typeStr])
        return paramList




