﻿/**
  File:
  Note : This file is generated by codegenerator.
  Author: JanyHong(janyhong@yeahka.com)
  Version: v1.0.0
*/
#include "DBInterface_dbagent_struct.h"
#include "DBInterface_dbagent_client.h"
namespace db_agent_api
{
DBInterface_client::DBInterface_client()
    
{}

void DBInterface_client::init()
{
    strTag = "";
}

/****************************
 *      自动构建的SQL
 ****************************/
int DBInterface_client::MerchantCommissionInsert(const db_agent_api::MerchantCommission& MerchantCommission)
{
    int nRet = -1;
    do
    {
        json::value jReq;
        json::value jResp;
        utils::addJsonValue(jReq, "operation", "MerchantCommissionInsert");
        utils::addJsonValue(jReq, "tag", strTag);
        utils::addJsonValue(jReq, "MerchantCommission", MerchantCommission);
        if(0 != m_funImpl(jReq, jResp))
        {
            nRet = -1;
            break;
        }
        
    }while(0);
    return nRet;
}

int DBInterface_client::MerchantCommissionGet_By_MerchantId(const string& strMerchantId, db_agent_api::MerchantCommission& MerchantCommission)
{
    int nRet = -1;
    do
    {
        json::value jReq;
        json::value jResp;
        utils::addJsonValue(jReq, "operation", "MerchantCommissionGet_By_MerchantId");
        utils::addJsonValue(jReq, "tag", strTag);
        utils::addJsonValue(jReq, "strMerchantId", strMerchantId);
        if(0 != m_funImpl(jReq, jResp))
        {
            nRet = -1;
            break;
        }
        utils::getJsonValue(jResp, "MerchantCommission", MerchantCommission);
    }while(0);
    return nRet;
}

int DBInterface_client::MerchantCommissionUpdate_By_MerchantId(const string& strMerchantId)
{
    int nRet = -1;
    do
    {
        json::value jReq;
        json::value jResp;
        utils::addJsonValue(jReq, "operation", "MerchantCommissionUpdate_By_MerchantId");
        utils::addJsonValue(jReq, "tag", strTag);
        utils::addJsonValue(jReq, "strMerchantId", strMerchantId);
        if(0 != m_funImpl(jReq, jResp))
        {
            nRet = -1;
            break;
        }
        
    }while(0);
    return nRet;
}

int DBInterface_client::AgentInsert(const db_agent_api::Agent& Agent)
{
    int nRet = -1;
    do
    {
        json::value jReq;
        json::value jResp;
        utils::addJsonValue(jReq, "operation", "AgentInsert");
        utils::addJsonValue(jReq, "tag", strTag);
        utils::addJsonValue(jReq, "Agent", Agent);
        if(0 != m_funImpl(jReq, jResp))
        {
            nRet = -1;
            break;
        }
        
    }while(0);
    return nRet;
}

int DBInterface_client::AgentGet_By_AgentId(const string& strAgentId, db_agent_api::Agent& Agent)
{
    int nRet = -1;
    do
    {
        json::value jReq;
        json::value jResp;
        utils::addJsonValue(jReq, "operation", "AgentGet_By_AgentId");
        utils::addJsonValue(jReq, "tag", strTag);
        utils::addJsonValue(jReq, "strAgentId", strAgentId);
        if(0 != m_funImpl(jReq, jResp))
        {
            nRet = -1;
            break;
        }
        utils::getJsonValue(jResp, "Agent", Agent);
    }while(0);
    return nRet;
}

int DBInterface_client::AgentUpdate_By_AgentId(const string& strAgentId)
{
    int nRet = -1;
    do
    {
        json::value jReq;
        json::value jResp;
        utils::addJsonValue(jReq, "operation", "AgentUpdate_By_AgentId");
        utils::addJsonValue(jReq, "tag", strTag);
        utils::addJsonValue(jReq, "strAgentId", strAgentId);
        if(0 != m_funImpl(jReq, jResp))
        {
            nRet = -1;
            break;
        }
        
    }while(0);
    return nRet;
}

/****************************
 *      自定义调用函数
 ****************************/
int DBInterface_client::say_hello(const string& req, string& resq)
{
    int nRet = -1;
    do
    {
        json::value jReq;
        json::value jResp;
        utils::addJsonValue(jReq, "operation", "say_hello");
        utils::addJsonValue(jReq, "tag", strTag);
        utils::addJsonValue(jReq, "req", req);
        if(0 != m_funImpl(jReq, jResp))
        {
            nRet = -1;
            break;
        }
        utils::getJsonValue(jResp, "resq", resq);
    }while(0);
    return nRet;
}

int DBInterface_client::update_metchant_commission_perfertialType(const int& nPreferentialType, const string& strAgentId, int& ret)
{
    int nRet = -1;
    do
    {
        json::value jReq;
        json::value jResp;
        utils::addJsonValue(jReq, "operation", "update_metchant_commission_perfertialType");
        utils::addJsonValue(jReq, "tag", strTag);
        utils::addJsonValue(jReq, "nPreferentialType", nPreferentialType);
        utils::addJsonValue(jReq, "strAgentId", strAgentId);
        if(0 != m_funImpl(jReq, jResp))
        {
            nRet = -1;
            break;
        }
        utils::getJsonValue(jResp, "ret", ret);
    }while(0);
    return nRet;
}


}//db_agent_api
