# -*- coding: utf-8 -*-
__author__ = 'Administrator'
import sys
import codecs
import os
from tools import *

def saveFile(outputFile, str):
    print(outputFile)
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

def parseFileName(filePath):
    print(filePath)
    posA = filePath.rfind('\\')
    posB = filePath.rfind('/')
    if posA < posB:
        posA = posB
    return filePath[posA+1:]

def offsetLines(str, offset):
    lines = str.splitlines()
    ret = u"\n".join([ u" " * offset + line for line in lines])
    return ret

def replace(raw, old, new):
    oldLines = [line for line in raw.splitlines() if line.strip() == old ]
    if len(new.splitlines()) <= 1 :
        raw = raw.replace(old, new)
    else:
        for line in oldLines:
            offset = line.find(old)
            now = offsetLines(new, offset)
            raw = raw.replace(line, now)
    return raw

def getTypes(astruct):
    # 看类中有多少种数据结构, 然后填充之
    listTypeNames = {"bool":["Bool", "false"], "int":["Int", "0"], "std::string":["String", "\"\""]}
    listTypeNames["r_int64"] = ["Long", "0"]
    listTypeNames["double"] = ["Double", "0.0"]
    listTypeNames["IDataPtr"] = ["IData", "IDataPtr()"]
    listTypeNames["std::vector<bool>"] = ["VBool", "vector<bool>()"]
    listTypeNames["std::vector<int>"] = ["VInt", "vector<int>()"]
    listTypeNames["std::vector<r_int64>"] = ["VLong", "vector<r_int64>()"]
    listTypeNames["std::vector<double>"] = ["VDouble", "vector<double>()"]
    listTypeNames["std::vector<string>"] = ["VString", "vector<string>()"]
    listTypeNames["std::vector<IDataPtr>"] = ["VIData", "vector<IDataPtr>()"]

    ownedTypes = {}

    for tn in listTypeNames.keys():
        cont = u""
        for i in astruct.items:
            if tn in ["IDataPtr"]:
                if i.type.typeName.find("{{Namespace}}::C") == 0:
                    ownedTypes[tn] = listTypeNames[tn]
            elif tn in ["std::vector<IDataPtr>"]:
                if i.type.typeName.find("std::vector< {{Namespace}}::C") == 0:
                    ownedTypes[tn] = listTypeNames[tn]
            else:
                if i.type.typeName == tn:
                    ownedTypes[tn] = listTypeNames[tn]
    return ownedTypes
