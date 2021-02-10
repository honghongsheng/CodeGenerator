# -*- coding: utf-8 -*-
_author_ = 'Administrator'
#######################################################
#                       头文件
#######################################################
TEMPLATE_DEF = u'''\
{{FILE_COMMENTS}}
#ifndef {{FileName}}_{{tag}}_H_
#define {{FileName}}_{{tag}}_H_
#include <string>
#include <map>
#include <vector>
#include <list>
#include <json/json.h>
#include <boost/function>
{{IncludeCodes}}
using std::string;
using std::map;
using std::vector;
using std::list;
namespace {{Namespace}}
{
{{Contents}}
}//{{Namespace}}

#endif //{{FileName}}_{{tag}}_H_
'''

#struct/class
TEMPLATE_ONE_SERVICE_DEF = u'''\
class {{ServiceName}}_client 
{
public:
    {{ServiceName}}_client();
    void init();
    
    /****************************
     *      自动构建的SQL
     ****************************/
    {{SqlFunctions}}
    
    /****************************
     *      自定义调用函数
     ****************************/
    {{Functions}}

    //请求函数的实现，可以自定义实现
    boost::function<int (const Json::Value &, Json::Value &)> m_funImpl;
};
'''
#请求函数的同步调用
TEMPLATE_ONE_SERVICE_SYNC_FUNC_DEF =u'''\
int {{FuncName}}({{InParam}}{{OutParam}});
'''

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
    strTag = "";
}

/****************************
 *      自动构建的SQL
 ****************************/
{{SqlFunctions}}

/****************************
 *      自定义调用函数
 ****************************/
{{Functions}}
'''

#if(0 != jReq_db_agent(jReq, jResp))

TEMPLATE_ONE_SERVICE_SYNC_FUNC_IMPL =u'''\
int {{ServiceName}}_client::{{FuncName}}({{InParam}}{{OutParam}})
{
    int nRet = -1;
    do
    {
        json::value jReq;
        json::value jResp;
        utils::addJsonValue(jReq, "operation", "{{FuncName}}");
        utils::addJsonValue(jReq, "tag", strTag);
        {{GenJson}}
        if(0 != m_funImpl(jReq, jResp))
        {
            nRet = -1;
            break;
        }
        {{ParseJson}}
    }while(0);
    return nRet;
}
'''

TEMPLATE_ONE_SERVICE_SQL_INSERT_IMPL =u'''\
int {{ServiceName}}_client::{{StructName}}Insert(const {{StructName}}& data)
{
    int nRet = -1;
    do
    {
        json::value jReq;
        json::value jResp;
        utils::addJsonValue(jReq, "operation", "{{StructName}}Insert");
        utils::addJsonValue(jReq, "tag", strTag);
        data.toJson(jReq);
        if(0 != m_funImpl(jReq, jResp))
        {
            nRet = -1;
            break;
        }
        {{ParseJson}}
    }while(0);
    return nRet;
}
'''

TEMPLATE_ONE_SERVICE_SQL_GET_IMPL =u'''\
int {{ServiceName}}_client::{{StructName}}Get_By_{{ByStr}}(const {{StructName}}& data, {{ParStr}})
{
    int nRet = -1;
    do
    {
        json::value jReq;
        json::value jResp;
        utils::addJsonValue(jReq, "operation", "{{StructName}}Get_By_{{ByStr}}");
        utils::addJsonValue(jReq, "tag", strTag);
        {{GenJson}}
        if(0 != m_funImpl(jReq, jResp))
        {
            nRet = -1;
            break;
        }
        data.fromjson(jReq);
    }while(0);
    return nRet;
}
'''

TEMPLATE_ONE_SERVICE_SQL_UPDATE_IMPL =u'''\
int {{ServiceName}}_client::{{StructName}}Update_By_{{ByStr}}(const {{StructName}}& data, {{ParStr}})
{
    int nRet = -1;
    do
    {
        json::value jReq;
        json::value jResp;
        utils::addJsonValue(jReq, "operation", "{{StructName}}Update_By_{{ByStr}}");
        utils::addJsonValue(jReq, "tag", strTag);
        data.toJson(jReq);
        if(0 != m_funImpl(jReq, jResp))
        {
            nRet = -1;
            break;
        }
        {{ParseJson}}
    }while(0);
    return nRet;
}
'''
