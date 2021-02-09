import sys
import codecs# as codecsR
import os
import re
import requests

def saveFile(outputFile, str):
    print("save file to:", outputFile)
    #print("file data:\n", str)
    rawData = u""
    try:
        handler = codecs.open(outputFile,'r', 'utf-8')
        rawData = handler.read().decode()
        rawData = rawData.lstrip(  codecs.BOM_UTF8, "utf8"  )
    except :
        pass

    if (rawData != str) :
        outputHandler = codecs.open(outputFile, 'w', 'utf-8-sig')
        outputHandler.write(str)
        outputHandler.close()

type_map = {
    "int":"i",
    "int64_t":"i",
    "string":"s",
    "std::string":"s",
    "bool":"b",
}

def get_json():
    inputHandler = codecs.open("db_interface_dataformat.cpp",'r', 'utf-8')
    data = inputHandler.read()
    inputHandler.close()
    
    lines = data.splitlines()
    outs = []
    StructDetaild = {}
    StructName = ''
    for line in lines:
        line = line.strip()
        mret = re.search(u"\s*(?P<StructName>\w+)::Format\s*\(.*\).*", line, re.IGNORECASE)
        if mret:
            StructName = mret.group(u"StructName").strip()
            StructDetaild[StructName] = {}
            print("StructName",StructName)
        mret = re.search(u"\s*(?P<Item>\w+)\s*=\s*\w+\[\"(?P<Json>\w+)\"\].*;\s*", line, re.IGNORECASE)
        if mret:
            Item = mret.group(u"Item").strip()
            Json = mret.group(u"Json").strip()
            print("StructName:%s,Item:%s,Json:%s" % (StructName,Item,Json))
            StructDetaild[StructName][Item] = Json
            
        mret = re.search(u"\s*(?P<StructName>\w+)::Format2Json\s*\(.*\).*", line, re.IGNORECASE)
        if mret:
            StructName = mret.group(u"StructName").strip()
            StructDetaild[StructName] = {}
            print("StructName",StructName)
        #item["order_id"] = strOrderId;
        mret = re.search(u"\s*\w+\[\"(?P<Json>\w+)\"\]\s*=\s*(?P<Item>\w+)\s*;\s*", line, re.IGNORECASE)
        if mret:
            Item = mret.group(u"Item").strip()
            Json = mret.group(u"Json").strip()
            print("StructName:%s,Item:%s,Json:%s" % (StructName,Item,Json))
            StructDetaild[StructName][Item] = Json
            
    return StructDetaild

if __name__ == "__main__":
    if sys.version_info[0] < 3:
        reload(sys)
        sys.setdefaultencoding( "utf-8" )
  
    map_json = get_json()
    inputHandler = codecs.open("db_interface_dataformat.h",'r', 'utf-8')
    data = inputHandler.read()
    inputHandler.close()
    
    lines = data.splitlines()
    
    outs = []
    StructName = ''
    for line in lines:
        line = line.strip()
        mret = re.search(u"\s*struct\s*(?P<StructName>\w+)\s*\{\s*", line, re.IGNORECASE)
        if mret:
            StructName = mret.group(u"StructName").strip()
            print("StructName:",StructName)
        mret = re.search(u"\s*(?P<Type>\w+)\s*(?P<Value>\w+);\s*", line, re.IGNORECASE)
        if mret:
            Type = mret.group(u"Type").strip()
            Value = mret.group(u"Value").strip()
            #bValid:#i,                      json="vaild";  //是否有效
            space_len = 0
            if(len(Value)+2) > 0:
                space_len = 30-(len(Value)+2)
            if(len(Value)+2) > 30:
                space_len = 35-(len(Value)+2)
            if(len(Value)+2) > 35:
                space_len = 40-(len(Value)+2)
            space = ''
            for i in range(space_len):
                space += ' '
            json = ''
            if StructName in map_json:
                if Value in map_json[StructName]:
                    json = map_json[StructName][Value]
            outs.append("    %s:#%s,%sjson=\"%s\";//" % (Value, type_map[Type], space, json))
        else:
            outs.append(line)
    out = '\n'.join(outs)
    out = out.replace("{"," : {")
    out = out.replace("};","}(json)")
    saveFile("db_interface_dataformat.hpp", out);