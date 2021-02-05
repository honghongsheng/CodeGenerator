# -*- coding: utf-8 -*-
_author_ = 'Administrator'
#######################################################
#                       头文件
#######################################################
TEMPLATE_DEF = u'''\
{{FILE_COMMENTS}}
#ifndef {{FileName}}_{{tag}}_H_
#define {{FileName}}_{{tag}}_H_
{{IncludeCodes}}

namespace {{Namespace}}
{
{{Contents}}
}//{{Namespace}}

#endif //{{FileName}}_{{tag}}_H_
'''

#struct/class
TEMPLATE_ONE_SERVICE_DEF = u'''\
class {{ExportMacro}} {{ServiceName}}_client {
public:
    {{ServiceName}}_client();
    void init();

    {{Functions}}
private:
    boost::shared_ptr<boom::protocol> m_ptrProtocal;
    boost::shared_ptr<boom::netengine> m_ptrNetEngine;
};
'''
#请求函数的同步调用
TEMPLATE_ONE_SERVICE_SYNC_FUNC_DEF =u'''\
/*
 {{FuncComment}}
 */
void {{FuncName}}({{InParam}}{{OutParam}});
'''

#应用协议实现

#######################################################
#                       源文件
#######################################################
TEMPLATE_IMPL = u'''\
{{FILE_COMMENTS}}
{{IncludeCodes}}
namespace {{Namespace}}
{
{{Contents}}
}//{{Namespace}}
'''

TEMPLATE_ONE_SERVICE_IMPL = u'''\
{{ServiceName}}_client::{{ServiceName}}_client()
    {{InitCode}}
{}

void {{ServiceName}}_client::init()
{
}
{{Functions}}
'''

TEMPLATE_ONE_SERVICE_SYNC_FUNC_IMPL =u'''\
void {{ServiceName}}_client::{{FuncName}}({{InParam}}{{OutParam}})
{
{{Protocal_Impl}}
}
'''

#提供给yk_json的协议实现
TEMPLATE_ONE_SERVICE_SYNC_FUNC_PTOTOCAL_YAKA_IMPL = u'''\
    //yk_db
    int nRet = -1;
    do
    {
        json::value request;
        request["operation"] = "{{FuncName}}";
        request["tag"] = strTag;
        {{GenJson}}
        Boom::Buffer respbuf;
        if(0 != request_db_agent(request, response))
        {
            nRet = -1;
            break;
        }
        {{ParseJson}}
    }while(0);
'''