﻿# -*- coding: utf-8 -*-

# 代码生成脚本入口
__author__ = 'Administrator'
import sys
import codecs
import os
from base.RPCParser import *
from base.tools import *
from cpp.StructCodeGenerator import *
from cpp.ClientCodeGenerator import *

def parseFile(inputFile, typeManager):
    inputHandler = codecs.open(inputFile,'r', 'utf-8')
    parser = RPCParser()
    data = inputHandler.read()
    desc = parser.parse(data)
    desc.genTypeInfos(typeManager)
    return desc

def cpp_gen(inputFile, outputFile):
    baseName = os.path.basename(inputFile)[0:-4]
    print("baseName",baseName)
    hStructOutput = outputFile + "/" + "%s_struct.h" % baseName;
    cppStructOutput = outputFile + "/" + "%s_struct.cpp" % baseName;
    
    hClientOutput = outputFile + "/" + "%s_client.h" % baseName;
    cppClientOutput = outputFile + "/" + "%s_client.cpp" % baseName;
    
    typeManager = CppTypeManger()
    desc = parseFile(inputFile, typeManager)
    generator = None
    generator = StructCodeGenerator(desc, typeManager, baseName, hStructOutput, cppStructOutput)
    generator.genCodes()
    
    generator = ClientCodeGenerator(desc, typeManager, baseName, hClientOutput, cppClientOutput)
    generator.genCodes()

def genCodes(language, typeName, inputFile, outputFile):
    print(language, typeName, inputFile, outputFile)
    if language == "cpp":
        cpp_gen(inputFile, outputFile)
    else:
        print("no sopport:",language)

def Usages():
    print("usages:")
    print("./CodeGenerator.exe [gen|help] [c|cpp|go] [struct|code|sql] [src_file] [out_dir]")
    print("./CodeGenerator.exe gen cpp struct test.rpc ./ ")

if __name__ == "__main__":
    if sys.version_info[0] < 3:
        reload(sys)
        sys.setdefaultencoding( "utf-8" )

    if len(sys.argv) < 5:
        Usages();
        sys.exit()
        
    opera = sys.argv[1].lower()
    if opera == "h" or opera == "-h" or opera == "-help" or opera == "--help":
        Usages();
        sys.exit()
    elif opera == "gen":
        _lan = sys.argv[2].lower()
        _type = sys.argv[3].lower()
        _input = sys.argv[4]
        _output = sys.argv[5]
        print(sys.argv)
        genCodes(_lan, _type, _input, _output)
    else:
        Usages();
        sys.exit()