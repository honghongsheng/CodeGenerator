﻿/**
  File:
  Note : This file is generated by codegenerator.
  Author: JanyHong(janyhong@yeahka.com)
  Version: v1.0.0
*/
#ifndef DBINTERFACE_CPP_DBAGENT_CLIENT_H_
#define DBINTERFACE_CPP_DBAGENT_CLIENT_H_
#include <string>
#include <map>
#include <vector>
#include <list>
#include <json/json.h>
#include <boost/function>
#include "DBInterface_dbagent_struct.h"

namespace db_agent_api
{

class DBInterface_client 
{
public:
    DBInterface_client();
    void init();
    
    /****************************
     *      自动构建的SQL
     ****************************/
    //MerchantCommission
    int MerchantCommissionInsert(MerchantCommission& MerchantCommission);
    int MerchantCommissionGet_By_MerchantId(MerchantCommission& merchantcommission, const std::string& strMerchantId);
    int MerchantCommissionUpdate_By_MerchantId(MerchantCommission& merchantcommission, const std::string& strMerchantId);
    //Agent
    int AgentInsert(Agent& Agent);
    int AgentGet_By_AgentId(Agent& agent, const std::string& strAgentId);
    int AgentUpdate_By_AgentId(Agent& agent, const std::string& strAgentId);
    
    /****************************
     *      自定义调用函数
     ****************************/
    int say_hello(const std::string& req, std::string& resq);
    int say_hi(const std::string& name, const int& num, std::string& resp);
    int update_metchant_commission_perfertialType(const int& nPreferentialType, const std::string& strAgentId, int& ret);

    //请求函数的实现，可以自定义实现
    boost::function<int (const Json::Value &, Json::Value &)> m_funImpl;
};

}//db_agent_api

#endif //DBINTERFACE_CPP_DBAGENT_CLIENT_H_
