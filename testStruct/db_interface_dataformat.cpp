#include "db_interface_dataformat.h"

namespace  db_agent_api
{
Merchant::Merchant()
    : bValid(false)
    , nSpId(0)
    , nBankAccountType(-1)
    , nMiaodaoActivity(0)
    , nChannelId(-1)
    , nMerchantFlag(0)
    , nPosLevel(1)
    , nPreauthLevel(0)
    , nPreAuthorizationFlag(0)
    , nQuickLevel(0)
    , nUnionScanLevel(0)
    , nWxLevel(0)
    , nState(0)
    , nBitFlag(0)
    , nMerchantType(0)
    , nPinfreeState(0)
    , nRegisterStatus(0)
    , nPosRefundFlag(0)
    , nCategory_id(0)
    , nIsdel(0)
    , nStatus(0)
    , nPinfreeLimit(0)
    , nAlipaySingleMaxAmount(0)
    , nAlipayOrdermaxAmount(0)
    , nCreditMouthMaxAmount(0)
    , nCreditOrderMaxAmount(0)
    , nCreditSingleMaxAmount(0)
    , nDebitMouthMaxAmount(0)
    , nDebitOrderMaxAmount(0)
    , nDebitSingleMaxAmount(0)
    , nMaxCommissionOneTransaction(0)
    , nCommission(0)
    , nCommissionDudect(0)
    , nCommissionByWeixin(0)
    , nIsBackUpCommission(0)
    , nBackUpCommission(0)
    , nBackUpMaxCommissionOneTransaction(0)
    , nSaasMultiAmountWarnVolume(0)
    , nSettlementTimeFlag(0)
    , nActiveDays(0)
    {
    }

void Merchant::print() const
{
    LOGDEBUG(
        "merchant: \n{\n"
        << "\tmerchant_id: " << strMerchantId << ",\n" 
		<< "\tunionpay_merchant_id: " << strUnionPayMerchantId << ",\n"
        << "\tmerchant_name: " << strMerchantName << ",\n" 
        << "\tagent_id: " << strAgentId << ",\n" 
        << "\ttop_agent_id: " << strTopAgentId << ",\n" 
        << "\tmcc_code: " << strMccCode << ",\n" 
        << "\treal_mcc_code: " << strRealMccCode << ",\n" 
        << "\tapplicant: " << strApplicant << ",\n" 
        << "\tbank_area: " << strBankArea << ",\n" 
        << "\tbank_account: " << strBankAccount << ",\n" 
        << "\tbank_city: " << strBankCity << ",\n" 
        << "\tbank_holder: " << strbankHolder << ",\n" 
        << "\tprovince: " << strProvince << ",\n" 
        << "\tcity: " << strCity << ",\n" 
        << "\tcreate_time: " << strCreateTime << ",\n" 
        << "\tstart_time_limit: " << strStartTimeLimit << ",\n" 
        << "\tend_time_limit: " << strEndTimeLimit << ",\n" 
        << "\tid_card: " << strIdCard << ",\n" 
        << "\tlatitude: " << strLatitude << ",\n" 
        << "\tlongitude: " << strLongitude << ",\n" 
        << "\tunionpay_code: " << strUnionpayCode << ",\n" 
        << "\tchannel_merchant_id: " << strChannelMerchantId << ",\n" 
        << "\tmobile: " << strMobile << ",\n" 
        << "\tuserName: " << strUserName << ",\n"
        << "\tstrMerchantKey: " << strMerchantKey << ",\n"
        << "\tbank_name: " << strBankName << ",\n"
        << "\tsp_id: " << nSpId << ",\n" 
        << "\tbank_account_type: " << nBankAccountType << ",\n" 
        << "\tmaiodao_activity: " << nMiaodaoActivity << ",\n" 
        << "\tchannel_id: " << nChannelId << ",\n" 
        << "\tmerchant_flag: " << nMerchantFlag << ",\n" 
        << "\tpos_level: " << nPosLevel << ",\n" 
        << "\tpreauth_level: " << nPreauthLevel << ",\n" 
        << "\tpreauth_flag: " << nPreAuthorizationFlag << ",\n" 
        << "\tquick_level: " << nQuickLevel << ",\n" 
        << "\tunionscan_level: " << nUnionScanLevel << ",\n" 
        << "\twx_level: " << nWxLevel << ",\n" 
        << "\tstate: " << nState << ",\n" 
        << "\tbit_flag: " << nBitFlag << ",\n" 
        << "\tmerchant_type: " << nMerchantType << ",\n" 
        << "\tpinfree_state: " << nPinfreeState << ",\n" 
        << "\tnRegisterStatus: " << nRegisterStatus << ",\n"
        << "\tnPosRefundFlag: " << nPosRefundFlag << ",\n"
        << "\tnCategory_id: " << nCategory_id << ",\n" 
        << "\tnIsdel: " << nIsdel << ",\n" 
        << "\tnStatus: " << nStatus << ",\n" 
        << "\tpinfree_limit: " << nPinfreeLimit << ",\n" 
        << "\tnAlipaySingleMaxAmount: " << nAlipaySingleMaxAmount << ",\n" 
        << "\tnAlipayOrdermaxAmount: " << nAlipayOrdermaxAmount << ",\n" 
        << "\tnCreditMouthMaxAmount: " << nCreditMouthMaxAmount << ",\n" 
        << "\tnCreditOrderMaxAmount: " << nCreditOrderMaxAmount << ",\n" 
        << "\tnCreditSingleMaxAmount: " << nCreditSingleMaxAmount << ",\n" 
        << "\tnDebitMouthMaxAmount: " << nDebitMouthMaxAmount << ",\n" 
        << "\tnDebitOrderMaxAmount: " << nDebitOrderMaxAmount << ",\n" 
        << "\tnDebitSingleMaxAmount: " << nDebitSingleMaxAmount << ",\n" 
        << "\tnMaxCommissionOneTransaction: " << nMaxCommissionOneTransaction << ",\n" 
        << "\tnCommission: " << nCommission << ",\n" 
		<< "\tnCommissionDudect: " << nCommissionDudect << ",\n" 
		<< "\tnCommissionByWeixin: " << nCommissionByWeixin << ",\n" 
        << "\tnIsBackUpCommission: " << nIsBackUpCommission << ",\n"
        << "\tnBackUpCommission: " << nBackUpCommission << ",\n"
        << "\tnBackUpMaxCommissionOneTransaction: " << nBackUpMaxCommissionOneTransaction << ",\n"
        << "\tnSaasMultiAmountWarnVolume: " << nSaasMultiAmountWarnVolume << ",\n" 
        << "\tnSettlementTimeFlag: " << nSettlementTimeFlag << ",\n" 
        << "\tnActiveDays: " << nActiveDays << ",\n" 
        << "}"
    );
}

void Merchant::Format(Json::Value &mer)
{
    bValid = true;
    strMerchantId = mer["merchant_id"].asString();
	strUnionPayMerchantId = mer["unionpay_merchant_id"].asString();
    strMerchantName = mer["merchant_name"].asString();
    strAgentId = mer["agent_id"].asString();
    strTopAgentId = mer["agent_id_1g"].asString();
    strMccCode = mer["mcc_code"].asString();
    strRealMccCode = mer["real_mcc_code"].asString();
    strApplicant = mer["applicant"].asString();
    strBankArea = mer["bank_area"].asString();
    strBankAccount = mer["bank_account"].asString();
    strBankCity = mer["bank_city"].asString();
    strbankHolder = mer["bank_holder"].asString();
    strProvince = mer["province"].asString();
    strCity = mer["city"].asString();
    strCreateTime = mer["create_time"].asString();
    strStartTimeLimit = mer["start_time_limit"].asString();
    strEndTimeLimit = mer["end_time_limit"].asString();
    strIdCard = mer["idcard"].asString();
    strLatitude = mer["latitude"].asString();
    strLongitude = mer["longitude"].asString();
    strUnionpayCode = mer["unionpay_code"].asString();
    strChannelMerchantId = mer["payment_merchant_id"].asString();
    strMobile = mer["mobile"].asString();
    strUserName = mer["user_name"].asString();
    strMerchantKey = mer["bind_merchant_key"].asString();
    strBankName = mer["bank_name"].asString();
    nSpId = mer["sp_id"].asInt();
    nBankAccountType = mer["bank_account_type"].asInt();
    nMiaodaoActivity = mer["business_miaodao_activity"].asInt();
    nChannelId = mer["payment_channel_id"].asInt();
    nMerchantFlag = mer["merchant_flag"].asInt();
    nPreAuthorizationFlag = mer["pre_authorization_flag"].asInt();
    nPosLevel = mer["privilege_level"].asInt();
    nPreauthLevel = mer["pre_authorization_level"].asInt();
    nQuickLevel = mer["quick_payment_pos_level"].asInt();
    nUnionScanLevel = mer["union_scan_level"].asInt();
    nWxLevel = mer["wx_class"].asInt();
    nState = mer["state"].asInt();
    nBitFlag = mer["bit_flag"].asInt();
    nMerchantType = mer["merchant_type"].asInt();
    nPinfreeState = mer["pinfree_state"].asInt();
    nRegisterStatus = mer["register_status"].asInt();
    nPosRefundFlag = mer["pos_refund_flag"].asInt();
	nCategory_id = mer["category_id"].asInt();
    nIsdel = mer["isdel"].asInt();
    nStatus = mer["status"].asInt();
    nPinfreeLimit = int64_t(mer["pinfree_limit"].asDouble());
    nAlipaySingleMaxAmount = int64_t(mer["alipay_single_max_amount"].asDouble());
    nAlipayOrdermaxAmount = int64_t(mer["alipay_order_max_amount"].asDouble());
    nCreditMouthMaxAmount = int64_t(mer["credit_month_max_amount"].asDouble());
    nCreditOrderMaxAmount = int64_t(mer["credit_order_max_amount"].asDouble());
    nCreditSingleMaxAmount = int64_t(mer["credit_single_max_amount"].asDouble());
    nDebitMouthMaxAmount = int64_t(mer["debit_month_max_amount"].asDouble());
    nDebitOrderMaxAmount = int64_t(mer["debit_order_max_amount"].asDouble());
    nDebitSingleMaxAmount = int64_t(mer["debit_single_max_amount"].asDouble());
    nMaxCommissionOneTransaction = int64_t(mer["max_commission_one_transaction"].asDouble());
    nCommission = int64_t(mer["commission"].asDouble());
	nCommissionDudect = int64_t(mer["commission_deduct"].asDouble());
	nCommissionByWeixin = int64_t(mer["commission_by_weixin"].asDouble());
    nIsBackUpCommission = int64_t(mer["is_back_up_commission"].asDouble());
    nBackUpCommission = int64_t(mer["back_up_commission"].asDouble());
    nBackUpMaxCommissionOneTransaction = int64_t(mer["back_up_max_commission_one_transaction"].asDouble());
    nSaasMultiAmountWarnVolume = int64_t(mer["saas_multi_amount_warn_volume"].asDouble());
    nSettlementTimeFlag = int64_t(mer["settlement_time_flag"].asDouble());
    nActiveDays = int64_t(mer["active_days"].asDouble());
    print();
}
    
MerchantCommission::MerchantCommission()
    : bValid(false)
    , nPreferentialType(0)
    , nT1DebitCardCommission(0)
    , nT1DebitCardMaxFee(0)
    , nT1CreditCardCommission(0)
    , nT1OverseasCardCommission(0)
    , nT0DebitCardCommission(0)
    , nT0CreditCardCommission(0)
    , nT0OverseasCardCommission(0)
    , nT0CommissionFixed(0)
    {
    }

void MerchantCommission::print() const
{
    LOGDEBUG(
        "merchant commision: \n{\n"
        << "\tmerchant_id: " << strMerchantId << ",\n" 
        << "\tpreferential_type: " << nPreferentialType << ",\n" 
        << "\tcreate_time: " << strCreateTime << ",\n" 
        << "\tt1_debit_card_commission: " << nT1DebitCardCommission << ",\n" 
        << "\tt1_debit_card_max_fee: " << nT1DebitCardMaxFee << ",\n" 
        << "\tt1_credit_card_commission: " << nT1CreditCardCommission << ",\n" 
        << "\tt1_overseas_card_commission: " << nT1OverseasCardCommission << ",\n" 
        << "\tt0_debit_card_commission: " << nT0DebitCardCommission << ",\n" 
        << "\tt0_credit_card_commission: " << nT0CreditCardCommission << ",\n" 
        << "\tt0_overseas_card_commission: " << nT0OverseasCardCommission << ",\n" 
        << "\tt0_commission_fixed: " << nT0CommissionFixed << ",\n" 
        << "}"
    );
}

void MerchantCommission::Format(Json::Value &merCommison)
{
    bValid = true;
    strMerchantId = merCommison["merchant_id"].asString();
    strCreateTime = merCommison["create_time"].asString();
    nPreferentialType = merCommison["preferential_type"].asInt();
    nT1DebitCardCommission = merCommison["t1_debit_card_commission"].asDouble();
    nT1DebitCardMaxFee = merCommison["t1_debit_card_max_fee"].asDouble();
    nT1CreditCardCommission = merCommison["t1_credit_card_commission"].asDouble();
    nT1OverseasCardCommission = merCommison["t1_overseas_card_commission"].asDouble();
    nT0DebitCardCommission = merCommison["t0_debit_card_commission"].asDouble();
    nT0CreditCardCommission = merCommison["t0_credit_card_commission"].asDouble();
    nT0OverseasCardCommission = merCommison["t0_overseas_card_commission"].asDouble();
    nT0CommissionFixed = merCommison["t0_commission_fixed"].asDouble();
    print();
}

MerchantCommissionByPlanId::MerchantCommissionByPlanId()
    : bValid(false)
    , nPlanId(0)
    , nRateByMillion(0)
    , nMaxFeeByMillion(0)
    {
    }

void MerchantCommissionByPlanId::print() const
{
    LOGDEBUG(
        "merchant commision by plan id: \n{\n"
        << "\tnPlanId: " << nPlanId << ",\n" 
        << "\tnRateByMillion: " << nRateByMillion << ",\n" 
        << "\tnMaxFeeByMillion: " << nMaxFeeByMillion << ",\n"  
        << "}"
    );
}

void MerchantCommissionByPlanId::Format(Json::Value &merCommisonByPlanId)
{
    bValid = true;
    nPlanId = merCommisonByPlanId["plan_id"].asInt();
    nRateByMillion = merCommisonByPlanId["rate_by_million"].asDouble();
    nMaxFeeByMillion = merCommisonByPlanId["max_fee_by_million"].asDouble();
    print();
}

Agent::Agent()
    : bValid(false)
	, nproperty(0)
    , nAgentType(0)
    , nAgentClass(0)
    , nStatus(0)
    , nProfitRuleType(0)
    {
    }

void Agent::print() const
{
    LOGDEBUG(
        "agent: \n{\n"
        << "\tagent_id: " << strAgentId << ",\n" 
        << "\tagent_name: " << strAgentName << ",\n" 
        << "\tparent_id: " << strParentId << ",\n" 
        << "\tagent_type: " << nAgentType << ",\n" 
        << "\tstrThirdPartyPublicKey: " << strThirdPartyPublicKey << ",\n" 
		<< "\tproperty: " << nproperty << ",\n" 
		<< "\tagent_class: " << nAgentClass << ",\n" 
        << "\tstatus: " << nStatus << ",\n" 
        << "\tprofit_rule_type: " << nProfitRuleType << ",\n" 
        << "\tcreate_time: " << strCreateTime << ",\n" 
        << "}"
    );
}

Agent& Agent::operator=(const Agent & other)
{
    bValid = other.bValid;
    strAgentId = other.strAgentId;
    strAgentName = other.strAgentName;
    strParentId = other.strParentId;
    nAgentType = other.nAgentType;
    nAgentClass = other.nAgentClass;
    nStatus = other.nStatus;
    nProfitRuleType = other.nProfitRuleType;
    strCreateTime = other.strCreateTime;
	strThirdPartyPublicKey = other.strThirdPartyPublicKey;	
	nproperty = other.nproperty;	
    return *this;
}

void Agent::Format(Json::Value &agent)
{
    bValid = true;
    strAgentId = agent["agent_id"].asString();
    strAgentName = agent["agent_name"].asString();
    strParentId = agent["agent_parent_id"].asString();
    nAgentType = agent["agent_type"].asInt();
    nAgentClass = agent["agent_class"].asInt();
    nStatus = agent["status"].asInt();
    nProfitRuleType = agent["profit_rule_type"].asInt();
    strCreateTime = agent["create_time"].asString();
	nproperty = agent["property"].asInt();
    strThirdPartyPublicKey = agent["third_party_public_key"].asString();
    print();
}

AgentCommission::AgentCommission()
    : bValid(false)
    , nPreferentialType(0)
    , nT1DebitCommissionBymillion(0)
    , nT1DebitMaxFeeBymillion(0)
    , nT1CreditCommissionBymillion(0)
    , nT1OverseasCommissionBymillion(0)
    , nT0DebitCommissionBymillion(0)
    , nT0CreditCommissionBymillion(0)
    , nT0OverseasCommissionBymillion(0)
    , nT0DebitBlendCommissionBymillion(0)
    , nT0CreditBlendCommissionBymillion(0)
    , nT0OverseasBlendCommissionBymillion(0)
    {
    }

void AgentCommission::print() const
{
    LOGDEBUG(
        "agent commission: \n{\n"
        << "\tagent_id: " << strAgentId << ",\n" 
        << "\tpreferential_type: " << nPreferentialType << ",\n" 
        << "\tstart_date: " << strStartDate << ",\n" 
        << "\tupdate_time: " << strUpdateTime << ",\n" 
        << "\tt1_debit_commission_bymillion: " << nT1DebitCommissionBymillion << ",\n" 
        << "\tt1_debit_max_fee_bymillion: " << nT1DebitMaxFeeBymillion << ",\n" 
        << "\tt1_credit_commission_bymillion: " << nT1CreditCommissionBymillion << ",\n" 
        << "\tt1_overseas_commission_bymillion: " << nT1OverseasCommissionBymillion << ",\n" 
        << "\tt0_debit_commission_bymillion: " << nT0DebitCommissionBymillion << ",\n" 
        << "\tt0_credit_commission_bymillion: " << nT0CreditCommissionBymillion << ",\n" 
        << "\tt0_overseas_commission_bymillion: " << nT0OverseasCommissionBymillion << ",\n" 
        << "\tt0_debit_blend_commission_bymillion: " << nT0DebitBlendCommissionBymillion << ",\n" 
        << "\tt0_credit_blend_commission_bymillion: " << nT0CreditBlendCommissionBymillion << ",\n" 
        << "\tt0_overseas_blend_commission_bymillion: " << nT0OverseasBlendCommissionBymillion << ",\n" 
        << "}"
    );
}

void AgentCommission::Format(Json::Value &agentComminsion)
{
    bValid = true;
    strAgentId = agentComminsion["agent_id"].asString();
    strStartDate = agentComminsion["start_date"].asString();
    strUpdateTime = agentComminsion["update_time"].asString();
    nPreferentialType = agentComminsion["preferential_type"].asInt();
    nT1DebitCommissionBymillion = agentComminsion["t1_debit_commission_bymillion"].asDouble();
    nT1DebitMaxFeeBymillion = agentComminsion["t1_debit_max_fee_bymillion"].asDouble();
    nT1CreditCommissionBymillion = agentComminsion["t1_credit_commission_bymillion"].asDouble();
    nT1OverseasCommissionBymillion = agentComminsion["t1_overseas_commission_bymillion"].asDouble();
    nT0DebitCommissionBymillion = agentComminsion["t0_debit_commission_bymillion"].asDouble();
    nT0CreditCommissionBymillion = agentComminsion["t0_credit_commission_bymillion"].asDouble();
    nT0OverseasCommissionBymillion = agentComminsion["t0_overseas_commission_bymillion"].asDouble();
    nT0DebitBlendCommissionBymillion = agentComminsion["t0_debit_blend_commission_bymillion"].asDouble();
    nT0CreditBlendCommissionBymillion = agentComminsion["t0_credit_blend_commission_bymillion"].asDouble();
    nT0OverseasBlendCommissionBymillion = agentComminsion["t0_overseas_blend_commission_bymillion"].asDouble();
    print();
}

void PinpadCheckin::print() const
{
    LOGDEBUG(
        "pinpad_checkin_info: \n{\n"
        << "\tstrPinpadId: " << strPinpadId << ",\n" 
        << "\tstrTakByLmk: " << strTakByLmk << ",\n" 
        << "\tstrTakByTmk: " << strTakByTmk << ",\n" 
        << "\tstrCheckInTime: " << strCheckInTime << ",\n" 
        << "}"
    );
}		   
    
void PinpadCheckin::Format(Json::Value &jsonPinpad)
{
    strPinpadId = jsonPinpad["pinpad_id"].asString();
    strTakByLmk = jsonPinpad["tak_by_lmk"].asString();
    strTakByTmk = jsonPinpad["tak_by_tmk"].asString();
    strCheckInTime = jsonPinpad["checkin_time"].asString();
    print();
}

Pinpad::pinpad_info::pinpad_info()
    : bValid(false)
    , nHasEncryptor(0)
    , nState(0)
    {
    }

void Pinpad::pinpad_info::print() const
{
    LOGDEBUG(
        "pinpad_info: \n{\n"
        << "\tntHasEncryptor: " << nHasEncryptor << ",\n" 
        << "\tnState: " << nState << ",\n" 
        << "\tstrPinpadId: " << strPinpadId << ",\n" 
        << "\tstrMerchantId: " << strMerchantId << ",\n" 
        << "\tstrSerialNum: " << strSerialNum << ",\n" 
        << "\tstrTTK: " << strTTK << ",\n" 
        << "\tstrTmkByLmk: " << strTmkByLmk << ",\n" 
        << "\tstrTpkByTmk: " << strTpkByTmk << ",\n" 
        << "\tstrTpkByLmk: " << strTpkByLmk << ",\n" 
        << "\tstrPinpadUuid: " << strPinpadUuid << ",\n" 
        << "}"
    );
}
    
void Pinpad::pinpad_info::Format(Json::Value &jsonPinpad)
{
    bValid = true;
    nHasEncryptor = jsonPinpad["has_encryptor"].asInt();
    nState = jsonPinpad["state"].asInt();
    strPinpadId = jsonPinpad["pinpad_id"].asString();
    strMerchantId = jsonPinpad["merchant_id"].asString();
    strSerialNum = jsonPinpad["serial_number"].asString();
    strTTK = jsonPinpad["ttk"].asString();
    strTmkByLmk = jsonPinpad["tmk_by_lmk"].asString();
    strTpkByTmk = jsonPinpad["tpk_by_tmk"].asString();
    strTpkByLmk = jsonPinpad["tpk_by_lmk"].asString();
    strPinpadUuid = jsonPinpad["pinpad_uuid"].asString();
    print();
}

Pinpad::pinpad_uuid_info::pinpad_uuid_info()
    : bValid(false)
    , nStatus(0)
    , nMaxUnbindTimes(0)
    , nEnable(0)
    , nRepairCounts(0)
    , nLoadTmkAllowNum(0)
    {
    }

void Pinpad::pinpad_uuid_info::print() const
{
    LOGDEBUG(
        "pinpad_uuid_info: \n{\n"
        << "\tstrPinpadUuid: " << strPinpadUuid << ",\n" 
        << "\tstrPinpadId: " << strPinpadId << ",\n" 
        << "\tnStatus: " << nStatus << ",\n" 
        << "\tnMaxUnbindTimes: " << nMaxUnbindTimes << ",\n" 
        << "\tnEnable: " << nEnable << ",\n" 
        << "\tnRepairCounts: " << nRepairCounts << ",\n" 
        << "\tnLoadTmkAllowNum: " << nLoadTmkAllowNum << ",\n" 
        << "\tstrDeviceId: " << strDeviceId << ",\n" 
        << "\tstrCreateTime: " << strCreateTime << ",\n" 
        << "\tstrStartUsingTime: " << strStartUsingTime << ",\n" 
        << "\tstrStartUsingDay: " << strStartUsingDay << ",\n" 
        << "\tstrLastRepairTime: " << strLastRepairTime << ",\n" 
        << "\tstrSn: " << strSn << ",\n" 
        << "\tstrIndustryName: " << strIndustryName << ",\n" 
        << "\tstrIndustryModel: " << strIndustryModel << ",\n" 
        << "\tstrPinpadCreateTime: " << strPinpadCreateTime << ",\n" 
        << "\tstrPinpadCommuication: " << strPinpadCommuication << ",\n" 
        << "\tstrPinpadOrganNo: " << strPinpadOrganNo << ",\n" 
        << "\tstrPosType: " << strPosType << ",\n" 
        << "\tstrIndustryCode: " << strIndustryCode << ",\n" 
        << "\tstrStoreTime: " << strStoreTime << ",\n" 
        << "\tstrDeliverTime: " << strDeliverTime << ",\n" 
        << "\tstrLeshuaModel: " << strLeshuaModel << ",\n" 
        << "\tstrAuthCode: " << strAuthCode << ",\n" 
        << "}"
    );
}
        
void Pinpad::pinpad_uuid_info::Format(Json::Value &jsonPinpadUuid)
{
    bValid = true;
    nStatus = jsonPinpadUuid["status"].asInt();
    nMaxUnbindTimes = jsonPinpadUuid["max_unbind_times"].asInt();
    nEnable = jsonPinpadUuid["enable"].asInt();
    nRepairCounts = jsonPinpadUuid["repair_counts"].asInt();
    nLoadTmkAllowNum = jsonPinpadUuid["load_TMK_allow_num"].asInt();
    strPinpadUuid = jsonPinpadUuid["pinpad_uuid"].asString();
    strPinpadId = jsonPinpadUuid["pinpad_id"].asString();
    strDeviceId = jsonPinpadUuid["device_id"].asString();
    strCreateTime = jsonPinpadUuid["create_time"].asString();
    strStartUsingTime = jsonPinpadUuid["start_using_time"].asString();
    strStartUsingDay = jsonPinpadUuid["start_using_day"].asString();
    strLastRepairTime = jsonPinpadUuid["last_repair_time"].asString();
    strSn = jsonPinpadUuid["pinpad_sn"].asString();
    strIndustryName = jsonPinpadUuid["industry_name"].asString();
    strIndustryModel = jsonPinpadUuid["industry_model"].asString();
    strPinpadCreateTime = jsonPinpadUuid["pinpad_create_time"].asString();
    strPinpadCommuication = jsonPinpadUuid["pinpad_communication"].asString();
    strPinpadOrganNo = jsonPinpadUuid["pinpad_organization_no"].asString();
    strPosType = jsonPinpadUuid["pos_type"].asString();
    strIndustryCode = jsonPinpadUuid["industry_code"].asString();
    strStoreTime = jsonPinpadUuid["store_time"].asString();
    strDeliverTime = jsonPinpadUuid["deliver_time"].asString();
    strLeshuaModel = jsonPinpadUuid["leshua_model"].asString();
    strAuthCode = jsonPinpadUuid["authorization_code"].asString();
    print();
}

void Pinpad::Format(Json::Value &jsonPinpad)
{
    Json::Value &pinpad_details = jsonPinpad["pinpad_details"];
    pinpad.Format(pinpad_details);

    Json::Value &pinpad_uuid_details = jsonPinpad["pinpad_uuid_details"];
    pinpad_uuid.Format(pinpad_uuid_details);
}

MerchantBindCups::MerchantBindCups()
    : bValid(false)
    , nBindType(-1)
    , nBindKey(-1)
    {
    }		

void MerchantBindCups::print() const
{
    LOGDEBUG(
        "merchant_bind_cups: \n{\n"
        << "\tstrMerchantId: " << strMerchantId << ",\n" 
        << "\tChannelMerchantId: " << strChannelMerchantId << ",\n" 
        << "\tstrShowChannelMerchantId: " << strShowChannelMerchantId << ",\n" 
        << "\tstrBindTime: " << strBindTime << ",\n" 
        << "\tnBindType: " << nBindType << ",\n" 
        << "\tnBindKey: " << nBindKey << ",\n" 
        << "}"
    );
}
        
void MerchantBindCups::Format(Json::Value &jsonMerBindCups)
{
    bValid = true;
    strMerchantId = jsonMerBindCups["merchant_id"].asString();
    strChannelMerchantId = jsonMerBindCups["paychannel_merchant_id"].asString();
    strShowChannelMerchantId = jsonMerBindCups["show_paychannel_merchant_id"].asString();
    strBindTime = jsonMerBindCups["bind_time"].asString();
    nBindType = jsonMerBindCups["bind_type"].asInt();
    nBindKey = jsonMerBindCups["bind_key"].asInt();
    print();
}

CupsMerchant::CupsMerchant()
    : bValid(false)
    , nHasEncryptor(0)
    , nCommision(0)
    , nCommissionExt(0)
    , nMinCommissionOneTransaction(0)
    , nMaxCommissionOneTransaction(0)
    , nCommissionByDebitBymillion(0)
    , nMinCommissionDebit(0)
    , nMaxCommissionDebit(0)
    , nCommissionByCreditBymillion(0)
    , nMinCommissionCredit(0)
    , nMaxCommissionCredit(0)
    , nCommissionByOverseasBymillion(0)
    , nMinCommissionOverseas(0)
    , nMaxCommissionOverseas(0)
    , nPinfreeLimit(0)
    , nDailyLimit(0)
    , nPreferentialType(0)
    , nPinfreeState(0)
    , nEnable(0)
    , nContactless(0)
    , nEnableLimit(0)
    , nChargingType(0)		
    {
    }

CupsMerchant& CupsMerchant::operator=(const CupsMerchant & other)
{
    bValid = other.bValid;
    strCupsId = other.strCupsId;
    strTerminalId = other.strTerminalId;
    strMerchantName = other.strMerchantName;
    strTerminalSn = other.strTerminalSn;
    strZmk = other.strZmk;
    strZmkByLmk = other.strZmkByLmk;
    strMccCode = other.strMccCode;
    strOrganNo = other.strOrganNo;
    strSource = other.strSource;
    strCreateTime = other.strCreateTime;
    strUpdateTime = other.strUpdateTime;
    nHasEncryptor = other.nHasEncryptor;
    nCommision = other.nCommision;
    nCommissionExt = other.nCommissionExt;
    nMinCommissionOneTransaction = other.nMinCommissionOneTransaction;
    nMaxCommissionOneTransaction = other.nMaxCommissionOneTransaction;
    nCommissionByDebitBymillion = other.nCommissionByDebitBymillion;
    nMinCommissionDebit = other.nMinCommissionDebit;
    nMaxCommissionDebit = other.nMaxCommissionDebit;
    nCommissionByCreditBymillion = other.nCommissionByCreditBymillion;
    nMinCommissionCredit = other.nMinCommissionCredit;
    nMaxCommissionCredit = other.nMaxCommissionCredit;
    nCommissionByOverseasBymillion = other.nCommissionByOverseasBymillion;
    nMinCommissionOverseas = other.nMinCommissionOverseas;
    nMaxCommissionOverseas = other.nMaxCommissionOverseas;

    nPinfreeLimit = other.nPinfreeLimit;

    nDailyLimit = other.nDailyLimit;

    nPreferentialType = other.nPreferentialType;
    nPinfreeState = other.nPinfreeState;

    nEnable = other.nEnable;
    nContactless = other.nContactless;

    nEnableLimit = other.nEnableLimit;

    nChargingType = other.nEnableLimit;

    return *this;
}

void CupsMerchant::print() const
{
    LOGDEBUG(
        "cups merchant: \n{\n"
        << "\tstrCupsId: " << strCupsId << ",\n" 
        << "\tstrTerminalId: " << strTerminalId << ",\n" 
        << "\tstrMerchantName: " << strMerchantName << ",\n" 
        << "\tstrTerminalSn: " << strTerminalSn << ",\n" 
        << "\tstrZmk: " << strZmk << ",\n" 
        << "\tstrZmkByLmk: " << strZmkByLmk << ",\n" 
        << "\tstrMccCode: " << strMccCode << ",\n" 
        << "\tstrOrganNo: " << strOrganNo << ",\n" 
        << "\tstrSource: " << strSource << ",\n" 
        << "\tstrCreateTime: " << strCreateTime << ",\n" 
        << "\tstrUpdateTime: " << strUpdateTime << ",\n" 
        << "\tnHasEncryptor: " << nHasEncryptor << ",\n" 
        << "\tnCommision: " << nCommision << ",\n" 
        << "\tnCommissionExt: " << nCommissionExt << ",\n" 
        << "\tnnMinCommissionOneTransaction: " << nMinCommissionOneTransaction << ",\n" 
        << "\tnnMaxCommissionOneTransaction: " << nMaxCommissionOneTransaction << ",\n" 
        << "\tnCommissionByDebitBymillion: " << nCommissionByDebitBymillion << ",\n" 
        << "\tnMinCommissionDebit: " << nMinCommissionDebit << ",\n" 
        << "\tnMaxCommissionDebit: " << nMaxCommissionDebit << ",\n" 
        << "\tnCommissionByCreditBymillion: " << nCommissionByCreditBymillion << ",\n" 
        << "\tnnMinCommissionCredit: " << nMinCommissionCredit << ",\n" 
        << "\tnMaxCommissionCredit: " << nMaxCommissionCredit << ",\n" 
        << "\tnCommissionByOverseasBymillion: " << nCommissionByOverseasBymillion << ",\n" 
        << "\tnMinCommissionOverseas: " << nMinCommissionOverseas << ",\n" 
        << "\tnMaxCommissionOverseas: " << nMaxCommissionOverseas << ",\n" 
        << "\tnPinfreeLimit: " << nPinfreeLimit << ",\n" 
        << "\tnDailyLimit: " << nDailyLimit << ",\n" 
        << "\tnPreferentialType: " << nPreferentialType << ",\n" 
        << "\tnPinfreeState: " << nPinfreeState << ",\n" 
        << "\tnEnable: " << nEnable << ",\n" 
        << "\tnContactless: " << nContactless << ",\n" 
        << "\tnEnableLimit: " << nEnableLimit << ",\n" 
        << "\tnChargingType: " << nChargingType << ",\n" 
        << "}"
    );
}
        
void CupsMerchant::Format(Json::Value &jsonCups)
{
    bValid = true;
    strCupsId = jsonCups["merchant_id"].asString();
    strTerminalId = jsonCups["terminal_id"].asString();
    strMerchantName = jsonCups["merchant_name"].asString();
    strTerminalSn = jsonCups["terminal_sn"].asString();
    strZmk = jsonCups["zmk"].asString();
    strZmkByLmk = jsonCups["zmk_by_lmk"].asString();
    strMccCode = jsonCups["mcc_code"].asString();
    strOrganNo = jsonCups["organization_no"].asString();
    strSource = jsonCups["source"].asString();
    strCreateTime = jsonCups["create_time"].asString();
    strUpdateTime = jsonCups["update_time"].asString();
    nHasEncryptor = jsonCups["has_encryptor"].asInt();
    nCommision = jsonCups["commission"].asDouble();
    nCommissionExt = jsonCups["commission_ext"].asDouble();
    nMinCommissionOneTransaction = jsonCups["min_commission_one_transaction"].asDouble();
    nMaxCommissionOneTransaction = jsonCups["max_commission_one_transaction"].asDouble();
    nCommissionByDebitBymillion = jsonCups["commission_by_debit_bymillion"].asDouble();
    nMinCommissionDebit = jsonCups["min_commission_debit"].asDouble();
    nMaxCommissionDebit = jsonCups["max_commission_debit"].asDouble();
    nCommissionByCreditBymillion = jsonCups["commission_by_credit_bymillion"].asDouble();
    nMinCommissionCredit = jsonCups["min_commission_credit"].asDouble();
    nMaxCommissionCredit = jsonCups["max_commission_credit"].asDouble();
    nCommissionByOverseasBymillion = jsonCups["commission_by_overseas_bymillion"].asDouble();
    nMinCommissionOverseas = jsonCups["min_commission_overseas"].asDouble();
    nMaxCommissionOverseas = jsonCups["max_commission_overseas"].asDouble();

    nPinfreeLimit = jsonCups["pinfree_limit"].asDouble();

    nDailyLimit = jsonCups["daily_limit"].asDouble();

    nPreferentialType = jsonCups["preferential_type"].asInt();
    nPinfreeState = jsonCups["pinfree_state"].asInt();

    nEnable = jsonCups["enable"].asInt();
    nContactless = jsonCups["contactless"].asInt();

    nEnableLimit = jsonCups["enable_limit"].asInt();

    nChargingType = jsonCups["charging_type"].asInt();

    print();
}

RouteDetails::RouteDetails()
    : nBankCardType(0)
    , nPaychannelId(0)
    , nTerminalType(0)
    , nAmount(0)
    , nMerchantPreferentialType(0)
    , nPaychannelMerchantPreferentialType(0)	
    {
    }

void RouteDetails::print() const
{
    LOGDEBUG(
        "RouteDetails: \n{\n"
        << "\tstrRegularNo: " << strRegularNo << ",\n" 
        << "\tsstrMerchantId: " << strMerchantId << ",\n" 
        << "\tstrOrderId: " << strOrderId << ",\n" 
        << "\tstrTransactionId: " << strTransactionId << ",\n" 
        << "\tstrSettlementAccount: " << strSettlementAccount << ",\n" 
        << "\tstrPaychannelMerchantId: " << strPaychannelMerchantId << ",\n" 
        << "\tstrPaychannelTerminalId: " << strPaychannelTerminalId << ",\n" 
        << "\tstrPaychannelMerchantName: " << strPaychannelMerchantName << ",\n" 
        << "\tstrTopAgentId: " << strTopAgentId << ",\n" 
        << "\tstrPinpadUuid: " << strPinpadUuid << ",\n" 
        << "\tstrMerchantOrganId: " << strMerchantOrganId << ",\n" 
        << "\tstrMerchantMccCode: " << strMerchantMccCode << ",\n" 
        << "\tstrPaychannelMerchantOrganId: " << strPaychannelMerchantOrganId << ",\n" 
        << "\tstrPaychannelMerchantMccCode: " << strPaychannelMerchantMccCode << ",\n" 
        << "\tstrEncryptCardId: " << strEncryptCardId << ",\n" 
        << "\tnBankCardType: " << nBankCardType << ",\n" 
        << "\tnPaychannelId: " << nPaychannelId << ",\n" 
        << "\tnTerminalType: " << nTerminalType << ",\n" 
        << "\tnAmount: " << nAmount << ",\n" 
        << "\tnMerchantPreferentialType: " << nMerchantPreferentialType << ",\n" 
        << "\tnPaychannelMerchantPreferentialType: " << nPaychannelMerchantPreferentialType << ",\n" 
        << "}"
    );
}

void RouteDetails::Format(Json::Value &data) const
{
    data["regular_no"] = strRegularNo;
    data["merchant_id"] = strMerchantId;
    data["transaction_id"] = strTransactionId;
    data["order_id"] = strOrderId;
    data["settlement_account"] = strSettlementAccount;
    data["paychannel_merchant_id"] = strPaychannelMerchantId;
    data["paychannel_terminal_id"] = strPaychannelTerminalId;
    data["paychannel_merchant_name"] = strPaychannelMerchantName;
    data["top_agent_id"] = strTopAgentId;
    data["merchant_organ_id"] = strMerchantOrganId;
    data["merchant_mcc_code"] = strMerchantMccCode;
    data["paychannel_merchant_organ_id"] = strPaychannelMerchantOrganId;
    data["paychannel_merchant_mcc_code"] = strPaychannelMerchantMccCode;
    data["encrypt_card_id"] = strEncryptCardId;
    data["bank_card_type"] = nBankCardType;
    data["paychannel_id"] = nPaychannelId;
    data["terminal_type"] = nTerminalType;
    data["amount"] = double(nAmount);
    data["merchant_preferential_type"] = nMerchantPreferentialType;
    data["paychannel_merchant_preferential_type"] = nPaychannelMerchantPreferentialType;
    data["pinpad_uuid"] = strPinpadUuid;
    print();
}

ChannelPosInfo::ChannelPosInfo()
    : nChannelCatiStatus(0),nChannelBusiFlag(0),nChannelTjBusiFlag(0)
    {
    }

void ChannelPosInfo::print() const
{
    LOGDEBUG(
        "ChannelPosInfo: \n{\n"
        << "\tstrPosSn: " << strPosSn << ",\n" 
        << "\tstrChannelMerchantId: " << strChannelMerchantId << ",\n" 
        << "\tstrChannelAgentId: " << strChannelAgentId << ",\n" 
        << "\tstrTerminalId: " << strTerminalId << ",\n" 
        << "\tstrTerminalTypte: " << strTerminalType << ",\n" 
        << "\tnChannelCatiStatus: " << nChannelCatiStatus << ",\n" 
        << "\tnChannelBusiFlag: " << nChannelBusiFlag << ",\n" 
        << "\tnChannelTjBusiFlag: " << nChannelTjBusiFlag << ",\n"
        << "}"
    );
}

void ChannelPosInfo::Format(Json::Value& posInfo)
{
    strPosSn = posInfo["pos_sn"].asString();
    strChannelMerchantId = posInfo["channel_merchant_id"].asString();
    strChannelAgentId = posInfo["channel_agent_id"].asString();
    strTerminalId = posInfo["terminal_id"].asString();
    strTerminalType = posInfo["terminal_type"].asString();
    nChannelCatiStatus = posInfo["channel_cati_status"].asInt();
    nChannelBusiFlag = posInfo["channel_busi_flag"].asInt();
    nChannelTjBusiFlag = posInfo["channel_tj_business_flag"].asInt();
    print();
}

ChannelMerchantInfo::ChannelMerchantInfo()
    : nChannelMerchantStatus(0)
    , nChannelMerchantInsuranceFlag(0)
    , nChannelMerchantDebitT0Flag(0)
    , nChannelMerchantCreditT0Flag(0)
    , nChannelMerchantNocturnalT0Flag(0)
    , nChannelMerchantDebitCardAmountLimit(0)
    , nChannelMerchantCreditCardAmountLimit(0)
    , nChannelMerchantToWalletT0Flag(0)
    {
    }

void ChannelMerchantInfo::print() const
{
    LOGDEBUG(
        "ChannelMerchantInfo: \n{\n"
        << "\tstrChannelAgentId: " << strChannelAgentId << ",\n" 
        << "\tstrChannelShopId: " << strChannelShopId << ",\n" 
        << "\tstrMerchantId: " << strMerchantId << ",\n" 
        << "\tnChannelMerchantStatus: " << nChannelMerchantStatus << ",\n" 
        << "\tnChannelMerchantInsuranceFlag: " << nChannelMerchantInsuranceFlag << ",\n" 
        << "\tnChannelMerchantDebitT0Flag: " << nChannelMerchantDebitT0Flag << ",\n"
        << "\tnChannelMerchantCreditT0Flag: " << nChannelMerchantCreditT0Flag << ",\n"
        << "\tnChannelMerchantNocturnalT0Flag: " << nChannelMerchantNocturnalT0Flag << ",\n"
        << "\tnChannelMerchantDebitCardAmountLimit: " << nChannelMerchantDebitCardAmountLimit << ",\n"
        << "\tnChannelMerchantCreditCardAmountLimit: " << nChannelMerchantCreditCardAmountLimit << ",\n"
        << "\tnChannelMerchantToWalletT0Flag: " << nChannelMerchantToWalletT0Flag << ",\n"
        << "}"
    );
}

void ChannelMerchantInfo::Format(Json::Value& merInfo)
{
    strChannelAgentId = merInfo["channel_agent_id"].asString();
    strChannelShopId = merInfo["channel_shop_id"].asString();
    strMerchantId = merInfo["merchant_id"].asString();
    nChannelMerchantStatus = merInfo["channel_merchant_status"].asInt();
    nChannelMerchantInsuranceFlag = merInfo["channel_merchant_insurance_flag"].asInt();
    nChannelMerchantDebitT0Flag = merInfo["channel_merchant_debit_t0_flag"].asInt();
    nChannelMerchantCreditT0Flag = merInfo["channel_merchant_credit_t0_flag"].asInt();
    nChannelMerchantNocturnalT0Flag = merInfo["channel_merchant_nocturnal_t0_flag"].asInt();
    nChannelMerchantDebitCardAmountLimit = merInfo["channel_merchant_debit_card_amount_limit"].asInt();
    nChannelMerchantCreditCardAmountLimit = merInfo["channel_merchant_credit_card_amount_limit"].asInt();
    nChannelMerchantToWalletT0Flag = merInfo["channel_merchant_to_wallet_t0_flag"].asInt();
    
    print();
}

TransactionInfo::TransactionInfo()
    : nPaymentChannelId(0)
    , nPanType(0)
    , nPanOverseas(0)
    {
    }

void TransactionInfo::print() const
{
    LOGDEBUG(
        "TransactionInfo: \n{\n"
        << "\tstrPaymentChannelMerchantDd: " << strPaymentChannelMerchantDd << ",\n"
        << "\tstrTransactionId: " << strTransactionId << ",\n"
        << "\tstrTime: " << strTime << ",\n"
        << "\tnPaymentChannelId: " << nPaymentChannelId << ",\n"
        << "\tnPanType: " << nPanType << ",\n"
        << "\tnPanOverseas: " << nPanOverseas << ",\n"
        << "}"
    );
}

void TransactionInfo::Format(Json::Value& transInfo)
{
    strPaymentChannelMerchantDd = transInfo["payment_channel_merchant_id"].asString();
    strTransactionId = transInfo["transaction_id"].asString();
    strTime = transInfo["time"].asString();
    nPaymentChannelId = transInfo["payment_channel_id"].asInt();
    nPanType = transInfo["pan_type"].asInt();
    nPanOverseas  =transInfo["pan_overseas"].asInt();
    print();
}

LeshuaPosOrder::LeshuaPosOrder()
: bValid(false)
{}

void LeshuaPosOrder::print() const
{
    LOGDEBUG(
        "order: \n{\n"
        << "\tstrPinpadId: "	  << strPinpadId << ", \n"
        << "\tstrBatchNo: "	   << strBatchNo << ", \n"
        << "\tstrFlowId: "		<< strFlowId << ", \n"
        << "\tstrMerchantId: "	<< strMerchantId << ", \n"
        << "\tstrOrderId: "	   << strOrderId << ", \n"
        << "\tstrEncryptCardId: " << strEncryptCardId << ", \n"
        << "}"
    );
}
        
void LeshuaPosOrder::Format(Json::Value& OrderInfo)
{
    if(!OrderInfo.empty()) {
        bValid = true;
        strPinpadId = OrderInfo["pinpad_id"].asString();
        strBatchNo = OrderInfo["batch_no"].asString();
        strFlowId = OrderInfo["flow_id"].asString();
        strMerchantId = OrderInfo["merchant_id"].asString();
        strOrderId = OrderInfo["order_id"].asString();
        strEncryptCardId = OrderInfo["encrypt_card_id"].asString();
        strCardId = OrderInfo["card_id"].asString();
        print();
    }
}

void LeshuaPosOrder::Format2Json(Json::Value &data) const
{
    data["pinpad_id"] = strPinpadId;
    data["batch_no"] = strBatchNo;
    data["flow_id"] = strFlowId;
    data["merchant_id"] = strMerchantId;
    data["order_id"] = strOrderId;
    data["encrypt_card_id"] = strEncryptCardId;
    data["card_id"] = strCardId;

    print();
}

LeshuaPreAuthOrder::LeshuaPreAuthOrder()
: bValid(false)
{}

void LeshuaPreAuthOrder::print() const
{
    LOGDEBUG(
        "order: \n{\n"
        << "\tstrPinpadId: "	  << strPinpadId << ", \n"
        << "\tstrBatchNo: "	   << strBatchNo << ", \n"
        << "\tstrFlowId: "		<< strFlowId << ", \n"
        << "\tstrPreAuthCode: " << strPreAuthCode << ", \n"
        << "\tstrMerchantId: "	<< strMerchantId << ", \n"
        << "\tstrOrderId: "	   << strOrderId << ", \n"
        << "\tstrEncryptCardId: " << strEncryptCardId << ", \n"
        << "\tstrDate: " << strDate << ", \n"
        << "\tstrTrackData: " << strTrackData << ", \n"
        << "}"
    );
}
        
void LeshuaPreAuthOrder::Format(Json::Value& OrderInfo)
{
    if(!OrderInfo.empty()) {
        bValid = true;
        strPinpadId = OrderInfo["pinpad_id"].asString();
        strBatchNo = OrderInfo["batch_no"].asString();
        strFlowId = OrderInfo["flow_id"].asString();
        strPreAuthCode = OrderInfo["pre_auth_code"].asString();
        strMerchantId = OrderInfo["merchant_id"].asString();
        strOrderId = OrderInfo["order_id"].asString();
        strEncryptCardId = OrderInfo["encrypt_card_id"].asString();
        strDate = OrderInfo["date"].asString();
        strTrackData = OrderInfo["track_data"].asString();
        print();
    }
}

void LeshuaPreAuthOrder::Format2Json(Json::Value &data) const
{
    data["pinpad_id"] = strPinpadId;
    data["batch_no"] = strBatchNo;
    data["flow_id"] = strFlowId;
    data["pre_auth_code"] = strPreAuthCode;
    data["merchant_id"] = strMerchantId;
    data["order_id"] = strOrderId;
    data["encrypt_card_id"] = strEncryptCardId;
    data["track_data"] = strTrackData;
    data["date"] = strDate;

    print();
}

void ChannelPosOrder::print() const
{
    LOGDEBUG(
        "order: \n{\n"
        << "\tstrChannelPosCati: "	   << strChannelPosCati << ", \n"
        << "\tstrChannelBatchNo: "	   << strChannelBatchNo << ", \n"
        << "\tstrChannelFlowId: "		<< strChannelFlowId << ", \n"
        << "\tstrChannelMerchantId: "	<< strChannelMerchantId << ", \n"
        << "\tstrMerchantId: "		   << strMerchantId << ", \n"
        << "\tstrOrderId: "	  << strOrderId << ", \n"
        << "\tstrTerminalId: "		   << strTerminalId << ", \n"
        << "\tstrEncryptCardId: "		<< strEncryptCardId << ", \n"
        << "}"
    );
}
        
void ChannelPosOrder::Format(Json::Value& OrderInfo)
{
    strChannelPosCati = OrderInfo["channel_pos_cati"].asString();
    strChannelBatchNo = OrderInfo["channel_pos_batch_no"].asString();
    strChannelFlowId = OrderInfo["channel_pos_flow_id"].asString();
    strChannelMerchantId = OrderInfo["channel_merchant_id"].asString();
    strMerchantId = OrderInfo["merchant_id"].asString();
    strOrderId = OrderInfo["order_id"].asString();
    strTerminalId = OrderInfo["terminal_id"].asString();
    strEncryptCardId = OrderInfo["encrypt_card_id"].asString();
    print();
}

void ChannelPosOrder::Format2Json(Json::Value &data) const
{
    data["channel_pos_cati"] = strChannelPosCati;
    data["channel_pos_batch_no"] = strChannelBatchNo;
    data["channel_pos_flow_id"] = strChannelFlowId;
    data["channel_merchant_id"] = strChannelMerchantId;
    data["merchant_id"] = strMerchantId;
    data["order_id"] = strOrderId;
    data["terminal_id"] = strTerminalId;
    data["encrypt_card_id"] = strEncryptCardId;

    print();
}

Order::Order()
    : bValid(false)
    , nState(0)
    , nAmount(0)
    , nRefundAmount(0)
    , nPayMode(0)
    , nDepositComm(0)
    , nThirdPlatComm(0)
    , nPaychannelId(0)
    , nPanType(0)
    , nPanClass(0)
    , nPanProducts(0)
    , nPanOverseas(0)
    , nT0Flag(0)
    , nScanMethod(0)
    , nDeductPayType(0)
    , nPaySourceType(0)
    , nErrorType(-1)
    {
    }

void Order::print() const
{
    LOGDEBUG(
        "order: \n{\n"
        << "\tstrOrderId: "		<< strOrderId << ", \n"
        << "\tstrMerchantId: "	 << strMerchantId << ", \n"
        << "\tstrUserName: "	   << strUserName << ", \n"
        << "\tnState: "	<< nState << ", \n"
        << "\tnAmount: "		   << nAmount << ", \n"
        << "\tnRefundAmount: "	 << nRefundAmount << ", \n"
        << "\tstrGoodsType: "	  << strGoodsType << ", \n"
        << "\tstrGoodsName: "	  << strGoodsName << ", \n"
        << "\tstrGoodsDetails: "   << strGoodsDetails << ", \n"
        << "\tstrThirdOrderId: "   << strThirdOrderId << ", \n"
        << "\tnPayMode: "		  << nPayMode << ", \n"
        << "\tnDepositComm: "	  << nDepositComm << ", \n"
        << "\tnThirdPlatComm: "	<< nThirdPlatComm << ", \n"
        << "\tstrReserverParam: "  << strReserverParam << ", \n"
        << "\tstrTime: "		   << strTime << ", \n"
        << "\tnPaychannelId: "	 << nPaychannelId << ", \n"
        << "\tnPanType: "		  << nPanType << ", \n"
        << "\tnPanClass: "		 << nPanClass << ", \n"
        << "\tnPanProducts: "	  << nPanProducts << ", \n"
        << "\tnPanOverseas: "	  << nPanOverseas << ", \n"
        << "\tnT0Flag: "		   << nT0Flag << ", \n"
        << "\tstrRoyalty: "		<< strRoyalty << ", \n"
        << "\tnPaySourceType: "	<< nPaySourceType << ", \n"
        << "\tstrVocherId: "	   << strVocherId << ", \n"
        << "\tstrClientIp: "	   << strClientIp << ", \n"
        << "\tstrCallbackUrl: "	<< strCallbackUrl << ", \n"
        << "\tnScanMethod: "	   << nScanMethod << ", \n"
        << "\tnDeductPayType: "	<< nDeductPayType << ", \n"
        << "\tstrMerchantShopNo: " << strMerchantShopNo << ", \n"
        << "\tstrMerchantPosNo: "  << strMerchantPosNo << ", \n"
        << "\tstrCustomerId: "	 << strCustomerId << ", \n"
        << "\tstrVoucherInfo: "	<< strVoucherInfo << ", \n"
        << "\tstrQrCode: "		 << strQrCode << ", \n"
        << "\tnErrorType: "		<< nErrorType << ", \n"
        << "\tstrErrorMsg: "	   << strErrorMsg << ", \n"
        << "\tstrAttach: "		 << strAttach << ", \n"
        << "}"
    );
}

void Order::Format(Json::Value& OrderInfo)
{
    bValid = true;
    strOrderId = OrderInfo["order_id"].asString();
    strMerchantId = OrderInfo["merchant_id"].asString();
    strUserName = OrderInfo["user_name"].asString();
    nState = OrderInfo["state"].asInt();
    nAmount = OrderInfo["amount"].asDouble();
    nRefundAmount = OrderInfo["refund_amount"].asDouble();
    strGoodsType = OrderInfo["goods_type"].asString();
    strGoodsName = OrderInfo["goods_name"].asString();
    strGoodsDetails = OrderInfo["goods_detail"].asString();
    strThirdOrderId = OrderInfo["third_order_id"].asString();
    nPayMode = OrderInfo["payment_mode"].asInt();
    nDepositComm = OrderInfo["deposit_commission"].asDouble();
    nThirdPlatComm = OrderInfo["third_platform_commission"].asDouble();
    strReserverParam = OrderInfo["reserver_param"].asString();
    strTime = OrderInfo["order_time"].asString();
    nPaychannelId = OrderInfo["payment_channel_id"].asInt();
    nPanType = OrderInfo["pan_type"].asInt();
    nPanClass = OrderInfo["pan_class"].asInt();
    nPanProducts = OrderInfo["pan_products"].asInt();
    nPanOverseas = OrderInfo["pan_overseas"].asInt();
    nT0Flag = OrderInfo["t0_flag"].asInt();
    strRoyalty = OrderInfo["royalty"].asString();
    nPaySourceType = OrderInfo["payment_source_type"].asInt();
    strVocherId = OrderInfo["voucher_id"].asString();
    strClientIp = OrderInfo["client_ip"].asString();
    strCallbackUrl = OrderInfo["callback_url"].asString();
    nScanMethod = OrderInfo["scan_method"].asInt();
    nDeductPayType = OrderInfo["deductpay_type"].asInt();
    strMerchantShopNo = OrderInfo["merchant_shop_no"].asString();
    strMerchantPosNo = OrderInfo["merchant_pos_no"].asString();
    strCustomerId = OrderInfo["customer_id"].asString();
    strVoucherInfo = OrderInfo["voucher_info"].asString();
    strQrCode = OrderInfo["qrcode"].asString();
    nErrorType = OrderInfo["error_type"].asInt();
    strErrorMsg = OrderInfo["error_msg"].asString();
    strAttach = OrderInfo["attach"].asString();
    
    print();
}

void Order::Format2Json(Json::Value &data) const
{
    if (!bValid)
    {
        return;
    }
    data["order_id"] = strOrderId;
    data["merchant_id"] = strMerchantId;
    data["user_name"] = strUserName;
    data["state"] = nState;
    data["amount"] = double(nAmount);
    data["refund_amount"] = double(nRefundAmount);
    data["goods_type"] = strGoodsType;
    data["goods_name"] = strGoodsName;
    data["goods_detail"] = strGoodsDetails;
    data["third_order_id"] = strThirdOrderId;
    data["payment_mode"] = nPayMode;
    data["deposit_commission"] = double(nDepositComm);
    data["third_platform_commission"] = double(nThirdPlatComm);
    data["reserver_param"] = strReserverParam;
    data["order_time"] = strTime;
    data["payment_channel_id"] = nPaychannelId;
    data["pan_type"] = nPanType;
    data["pan_class"] = nPanClass;
    data["pan_products"] = nPanProducts;
    data["pan_overseas"] = nPanOverseas;
    data["t0_flag"] = nT0Flag;
    data["royalty"] = strRoyalty;
    data["payment_source_type"] = nPaySourceType;
    data["voucher_id"] = strVocherId;
    data["client_ip"] = strClientIp;
    data["callback_url"] = strCallbackUrl;
    data["scan_method"] = nScanMethod;
    data["deductpay_type"] = nDeductPayType;
    data["merchant_shop_no"] = strMerchantShopNo;
    data["merchant_pos_no"] = strMerchantPosNo;
    data["customer_id"] = strCustomerId;
    data["voucher_info"] = strVoucherInfo;
    data["qrcode"] = strQrCode;
    data["error_type"] = nErrorType;
    data["error_msg"] = strErrorMsg;
    data["attach"] = strAttach;
    print();
}

Transaction::Transaction()
    : bValid(false)
    , nAmount(0)
    , nOperationType(0)
    , nCardType(0)
    , nPanType(0)
    , nPanClass(0)
    , nPanProducts(0)
    , nPanOverseas(0)
    , nNoPwdFlag(0)
    , nPaychannelId(0)
    , nApptype(0)
    , nFlag(0)
    , nOrderAmount(0)
    , nCouponAmount(0)
    {
    }

void Transaction::print() const
{
    LOGDEBUG(
        "transaction: \n{\n"
        << "\tstrTransactionId: "	<<	strTransactionId		  << ", \n"
        << "\tstrOrderId: "		  <<	strOrderId		  << ", \n"
        << "\tstrMerchantId: "	   <<	strMerchantId		  << ", \n"
        << "\tstrPinpadId: "		 <<	strPinpadId		  << ", \n"
        << "\tstrLongitude: "		<<	strLongitude		  << ", \n"
        << "\tstrLatitude: "		 <<	strLatitude		  << ", \n"
        << "\tstrUserName: "		 <<	strUserName		  << ", \n"
        << "\tnAmount: "	 <<	nAmount		  << ", \n"
        << "\tnOperationType: "	  <<	nOperationType		  << ", \n"
        << "\tstrTime: "	 <<	strTime		  << ", \n"
        << "\tstrCardId: "		   <<	strCardId		  << ", \n"
        << "\tstrCardBank: "		 <<	strCardBank		  << ", \n"
        << "\tstrCardValid: "		<<	strCardValid		  << ", \n"
        << "\tstrCardSeqNum: "	   <<	strCardSeqNum		  << ", \n"
        << "\tstrIcField55: "		<<	strIcField55		  << ", \n"
        << "\tstrIcAid: "	<<	strIcAid		  << ", \n"
        << "\tstrIcAtc: "	<<	strIcAtc		  << ", \n"
        << "\tstrIcTc: "	 <<	strIcTc		  << ", \n"
        << "\tnCardType: "		   <<	nCardType		  << ", \n"
        << "\tnPanType: "	<<	nPanType		  << ", \n"
        << "\tnPanClass: "		   <<	nPanClass		  << ", \n"
        << "\tnPanProducts: "		<<	nPanProducts		  << ", \n"
        << "\tnPanOverseas: "		<<	nPanOverseas		  << ", \n"
        << "\tnNoPwdFlag: "		  <<	nNoPwdFlag		  << ", \n"
        << "\tnPaychannelId: "	   <<	nPaychannelId		  << ", \n"
        << "\tstrChlMerchantId: "	<<	strChlMerchantId		  << ", \n"
        << "\tstrChlTerminalId: "	<<	strChlTerminalId		  << ", \n"
        << "\tnApptype: "	<<	nApptype		  << ", \n"
        << "\tstrMobileId: "		 <<	strMobileId		  << ", \n"
        << "\tstrChlOrderId: "	   <<	strChlOrderId		  << ", \n"
        << "\tstrChlRefNum: "		<<	strChlRefNum		  << ", \n"
        << "\tstrChlSettleDate: "	<<	strChlSettleDate		  << ", \n"
        << "\tstrChlAuthCode: "	  <<	strChlAuthCode		  << ", \n"
        << "\tstrChlBatchNum: "	  <<	strChlBatchNum		  << ", \n"
        << "\tstrChlErrCode: "	   <<	strChlErrCode		  << ", \n"
        << "\tstrThirdTime: "		<<	strThirdTime		  << ", \n"
        << "\tstrPinpadUuid: "	   <<	strPinpadUuid		  << ", \n"
        << "\tnFlag: "	   <<	nFlag		  << ", \n"
        << "\tstrEncryptCardId: "	<<	strEncryptCardId		  << ", \n"
        << "\tstrRecvBankCode: "	 <<	strRecvBankCode		  << ", \n"
        << "\tstrTopAgentId: "	   <<	strTopAgentId		  << ", \n"
        << "\tstrRefundId: "		 <<	strRefundId		  << ", \n"
        << "\tnOrderAmount: "		<<	nOrderAmount		  << ", \n"
        << "\tnCouponAmount: "	   <<	nCouponAmount		  << ", \n"
        << "\tstrChlMcc: "		   <<	strChlMcc		  << ", \n"
        << "\tstrCardHoldSign: "		   <<	strChlMcc		  << ", \n"
        << "}"
    );
}

void Transaction::Format(Json::Value& TransInfo)
{
    bValid = true;
    strTransactionId = TransInfo["transaction_id"].asString();
    strOrderId = TransInfo["order_id"].asString();
    strMerchantId = TransInfo["merchant_id"].asString();
    strPinpadId = TransInfo["pinpad_id"].asString();
    strLongitude = TransInfo["longitude"].asString();
    strLatitude = TransInfo["latitude"].asString();
    strUserName = TransInfo["user_name"].asString();
    nAmount = TransInfo["amount"].asDouble();
    nOperationType = TransInfo["operation_type"].asInt();
    strTime = TransInfo["time"].asString();
    strCardId = TransInfo["card_id"].asString();
    strCardBank = TransInfo["card_bank"].asString();
    strCardValid = TransInfo["card_valid"].asString();
    strCardSeqNum = TransInfo["card_sequence_number"].asString();
    strIcField55 = TransInfo["ic_field_55"].asString();
    strIcAid = TransInfo["ic_aid"].asString();
    strIcAtc = TransInfo["ic_atc"].asString();
    strIcTc = TransInfo["ic_tc"].asString();
    nCardType = TransInfo["card_type"].asInt();
    nPanType = TransInfo["pan_type"].asInt();
    nPanClass = TransInfo["pan_class"].asInt();
    nPanProducts = TransInfo["pan_products"].asInt();
    nPanOverseas = TransInfo["pan_overseas"].asInt();
    nNoPwdFlag = TransInfo["no_passwd_flag"].asInt();
    nPaychannelId = TransInfo["payment_channel_id"].asInt();
    strChlMerchantId = TransInfo["payment_channel_merchant_id"].asString();
    strChlTerminalId = TransInfo["payment_channel_terminal_id"].asString();
    nApptype = TransInfo["app_type"].asInt();
    strMobileId = TransInfo["mobile_id"].asString();
    strChlOrderId = TransInfo["channel_order_id"].asString();
    strChlRefNum = TransInfo["channel_reference_number"].asString();
    strChlSettleDate = TransInfo["channel_settle_date"].asString();
    strChlAuthCode = TransInfo["channel_authorize_code"].asString();
    strChlBatchNum = TransInfo["channel_batch_number"].asString();
    strChlErrCode = TransInfo["channel_error_code"].asString();
    strThirdTime = TransInfo["third_time"].asString();
    strPinpadUuid = TransInfo["pinpad_uuid"].asString();
    nFlag = TransInfo["flag"].asInt();
    strEncryptCardId = TransInfo["encrypt_card_id"].asString();
    strRecvBankCode = TransInfo["receive_bank_code"].asString();
    strTopAgentId = TransInfo["top_agent_id"].asString();
    strRefundId = TransInfo["merchant_refund_id"].asString();
    nOrderAmount = TransInfo["order_amount"].asDouble();
    nCouponAmount = TransInfo["coupon_amount"].asDouble();
    strChlMcc = TransInfo["payment_channel_mcc"].asString();
    strCardHoldSign = TransInfo["card_holder_sign"].asString();
    print();
}

void Transaction::Format2Json(Json::Value &data) const
{
    data["transaction_id"] = strTransactionId;
    data["order_id"] = strOrderId;
    data["merchant_id"] = strMerchantId;
    data["pinpad_id"] = strPinpadId;
    data["longitude"] = strLongitude;
    data["latitude"] = strLatitude;
    data["user_name"] = strUserName;
    data["amount"] = double(nAmount);
    data["operation_type"] = nOperationType;
    data["time"] = strTime;
    data["card_id"] = strCardId;
    data["card_bank"] = strCardBank;
    data["card_valid"] = strCardValid;
    data["card_sequence_number"] = strCardSeqNum;
    data["ic_field_55"] = strIcField55;
    data["ic_aid"] = strIcAid;
    data["ic_atc"] = strIcAtc;
    data["ic_tc"] = strIcTc;
    data["card_type"] = nCardType;
    data["pan_type"] = nPanType;
    data["pan_class"] = nPanClass;
    data["pan_products"] = nPanProducts;
    data["pan_overseas"] = nPanOverseas;
    data["no_passwd_flag"] = nNoPwdFlag;
    data["payment_channel_id"] = nPaychannelId;
    data["payment_channel_merchant_id"] = strChlMerchantId;
    data["payment_channel_terminal_id"] = strChlTerminalId;
    data["app_type"] = nApptype;
    data["mobile_id"] = strMobileId;
    data["channel_order_id"] = strChlOrderId;
    data["channel_reference_number"] = strChlRefNum;
    data["channel_settle_date"] = strChlSettleDate;
    data["channel_authorize_code"] = strChlAuthCode;
    data["channel_batch_number"] = strChlBatchNum;
    data["channel_error_code"] = strChlErrCode;
    data["third_time"] = strThirdTime;
    data["pinpad_uuid"] = strPinpadUuid;
    data["flag"] = nFlag;
    data["encrypt_card_id"] = strEncryptCardId;
    data["receive_bank_code"] = strRecvBankCode;
    data["top_agent_id"] = strTopAgentId;
    data["merchant_refund_id"] = strRefundId;
    data["order_amount"] = double(nOrderAmount);
    data["coupon_amount"] = double(nCouponAmount);
    data["payment_channel_mcc"] = strChlMcc;
    data["card_holder_sign"] = strCardHoldSign;
    print();
}

Transaction& Transaction::operator=(const Transaction &t)
{
    bValid = true;
    strTransactionId    =  t.strTransactionId;
    strOrderId          =  t.strOrderId;      
    strMerchantId       =  t.strMerchantId;   
    strPinpadId         =  t.strPinpadId;    
    strLongitude        =  t.strLongitude;    
    strLatitude         =  t.strLatitude;    
    strUserName         =  t.strUserName;    
    nAmount             =  t.nAmount;    
    nOperationType      =  t.nOperationType;  
    strTime             =  t.strTime;  
    strCardId           =  t.strCardId;  
    strCardBank         =  t.strCardBank; 
    strCardValid        =  t.strCardValid; 
    strCardSeqNum       =  t.strCardSeqNum;   
    strIcField55        =  t.strIcField55;    
    strIcAid            =  t.strIcAid;        
    strIcAtc            =  t.strIcAtc;        
    strIcTc             =  t.strIcTc;         
    nCardType           =  t.nCardType;       
    nPanType            =  t.nPanType;        
    nPanClass           =  t.nPanClass;       
    nPanProducts        =  t.nPanProducts;    
    nPanOverseas        =  t.nPanOverseas;    
    nNoPwdFlag          =  t.nNoPwdFlag;      
    nPaychannelId       =  t.nPaychannelId;   
    strChlMerchantId    =  t.strChlMerchantId;
    strChlTerminalId    =  t.strChlTerminalId;
    nApptype            =  t.nApptype;        
    strMobileId         =  t.strMobileId;     
    strChlOrderId       =  t.strChlOrderId;   
    strChlRefNum        =  t.strChlRefNum;    
    strChlSettleDate    =  t.strChlSettleDate;
    strChlAuthCode      =  t.strChlAuthCode;  
    strChlBatchNum      =  t.strChlBatchNum;  
    strChlErrCode       =  t.strChlErrCode ;  
    strThirdTime        =  t.strThirdTime;    
    strPinpadUuid       =  t.strPinpadUuid;   
    nFlag               =  t.nFlag;           
    strEncryptCardId    =  t.strEncryptCardId;
    strRecvBankCode     =  t.strRecvBankCode; 
    strTopAgentId       =  t.strTopAgentId;   
    strRefundId         =  t.strRefundId;     
    nOrderAmount        =  t.nOrderAmount;    
    nCouponAmount       =  t.nCouponAmount;   
    strChlMcc           =  t.strChlMcc;
    strCardHoldSign     =  t.strCardHoldSign;
    return *this;
}    

void simpleRisk::Format2Json(Json::Value &data) const
{	
    data["order_id"] = strOrderId;
    data["merchant_id"] = strMerchantId;
    data["amount"] = double(nAmount);
    data["t0_flag"] = nT0Flag;
    data["paychannel_id"] = nChlId;
    data["data"] = strRequest;
    data["operation_type"] = strOperationType;
}
        
leposParam::leposParam()
    : bValid (false)
    {
    }

void leposParam::Format(Json::Value&   param)
{
    bValid = true;
    strKey = param["key"].asString();
    strValue = param["value"].asString();
}

mccInfo::mccInfo()
    : bValid(false)
    , nMccType(0)
    , nDailyLimit(0)
    , nPinFreeFlag(0)
    {
    }

void mccInfo::Format(Json::Value& item)
{
    bValid = true;
    strMccCode = item["mcc_code"].asString();
    strFatherMccCode = item["father_mcc_code"].asString();
    strGrandpaMccCode = item["grandpa_mcc_code"].asString();
    nMccType = item["mcc_type"].asInt();
    nDailyLimit = item["daily_limit"].asDouble();
    nPinFreeFlag = item["no_pin_flag"].asInt();
}

void offlineOrder::Format2Json(Json::Value &data) const
{	
    data["field_55"] = strField55;
    data["merchant_id"] = strMerchantId;
    data["amount"] = double(nAmount);
    data["order_id"] = strOrderId;
    data["pinpad_uuid"] = strPinpadUuid;
}

offlineParam::offlineParam()
    : bValid(false)
    , nOfflineMerchantWhitelstFlag(0)
    {
    }

void offlineParam::print() const
{
    LOGDEBUG(	
        "offline param: \n{\n"
        << "\tnOfflineMerchantWhitelstFlag: "	<<	nOfflineMerchantWhitelstFlag << ", \n"
        << "\tstrOffLowBound: "	 <<	strOffLowBound	<< ", \n"
        << "}"
    );
}

void offlineParam::Format(Json::Value& item)
{
    bValid = true;
    nOfflineMerchantWhitelstFlag = item["is_offline_white_list"].asDouble();
    strOffLowBound = item["off_low_bound"].asString();
    print();
}

merchantFirstPayInfo::merchantFirstPayInfo()
    : bValid(false)
    , nAgentClass(0)
    , nAmount(0)
    {
    }

void merchantFirstPayInfo::print() const
{
    LOGDEBUG(	
        "merchantFirstPayInfo: \n{\n"
        << "\tstrMerchantId: "	 << strMerchantId << ", \n"
        << "\tstrOrderId: " << strOrderId << ", \n"
        << "\tstrTopAgentId: " << strTopAgentId << ", \n"
        << "\tstrEncryptCardId: " << strEncryptCardId << ", \n"
        << "\tnAgentClass: " << nAgentClass << ", \n"
        << "\tnAmount: " << nAmount << ", \n"
        << "}"
    );
}

void merchantFirstPayInfo::Format(Json::Value& item)
{
    bValid = true;
    strMerchantId = item["merchant_id"].asString();
    strOrderId = item["order_id"].asString();
    strTopAgentId = item["top_agent_id"].asString();
    strEncryptCardId = item["encrypt_card_id"].asString();
    nAgentClass = item["agent_class"].asInt();
    nAmount = item["amount"].asDouble();
    print();
}

void merchantFirstPayInfo::Format2Json(Json::Value &data) const
{	
    data["merchant_id"] = strMerchantId;
    data["order_id"] = strOrderId;
    data["encrypt_card_id"] = strEncryptCardId;
    data["top_agent_id"] = strTopAgentId;
    data["agent_class"] = nAgentClass;
    data["amount"] = double(nAmount);
}

pinFreeCard::pinFreeCard() 
{}

void pinFreeCard::print() const
{
    LOGDEBUG(	
        "pinFreeCard: \n{\n"
        << "\tstrEncryptCardId: " << strEncryptCardId << ", \n"
        << "\tstrCreateTime: " << strCreateTime << ", \n"
        << "}"
    );
}

void pinFreeCard::Format(Json::Value& item)
{
    strEncryptCardId = item["encrypt_card_id"].asString();
    strCreateTime = item["create_time"].asString();
    print();
}

void pinFreeCard::Format2Json(Json::Value &data) const
{	
    data["encrypt_card_id"] = strEncryptCardId;
    data["create_time"] = strCreateTime;
}

delayInsurace::delayInsurace() 
    : nState(-1)
    , nCompany(-1)
    {}

void delayInsurace::print() const
{
    LOGDEBUG(	
        "delayInsurace: \n{\n"
        << "\tstrMerchantId: " << strMerchantId << ", \n"
        << "\tstrTopAgentId: " << strTopAgentId << ", \n"
        << "\tstrOrderId: " << strOrderId << ", \n"
        << "\tnState: " << nState << ", \n"
        << "\tnCompany: " << nCompany << ", \n"
    );
}

void delayInsurace::Format(Json::Value& item)
{
    strMerchantId = item["merchant_id"].asString();
    strTopAgentId = item["top_agent_id"].asString();
    strOrderId = item["order_id"].asString();
    nState = item["state"].asInt();
    nCompany = item["company"].asInt();
    print();
}

void delayInsurace::Format2Json(Json::Value &data) const
{	
    data["merchant_id"] = strMerchantId;
    data["top_agent_id"] = strTopAgentId;
    data["order_id"] = strOrderId;
    data["state"] = nState;
    data["company"] = nCompany;
}

channelTransaction::channelTransaction() 
    : nChannelId(-1)
    , nAmount(0)
    , nOperationType(-1)
    {}

void channelTransaction::print() const
{
    LOGDEBUG(	
        "channelTransaction: \n{\n"
        << "\tstrTransactionId: " << strTransactionId << ", \n"
        << "\tnChannelId: " << nChannelId << ", \n"
        << "\tstrChannelMerchantId: " << strChannelMerchantId << ", \n"
        << "\tstrChannelTerminalId: " << strChannelTerminalId << ", \n"
        << "\tnAmount: " << nAmount << ", \n"
        << "\tnOperationType: " << nOperationType << ", \n"
        << "\tstrTime: " << strTime << ", \n"
        << "\tstrThirdTime: " << strThirdTime << ", \n"
        << "}"
    );
}

void channelTransaction::Format2Json(Json::Value &data) const
{	
    data["transaction_id"] = strTransactionId;
    data["payment_channel_id"] = nChannelId;
    data["payment_channel_merchant_id"] = strChannelMerchantId;
    data["payment_channel_terminal_id"] = strChannelTerminalId;
    data["amount"] = double(nAmount);
    data["operation_type"] = nOperationType;
    data["time"] = strTime;
    data["third_time"] = strThirdTime;
    print();
}

merchantTransaction::merchantTransaction() 
    : nChannelId(-1)
    , nAmount(0)
    , nOperationType(-1)
    , nTradeStatus(-1)
    , nCardType(0)
    , nPanType(0)
    , nPanClass(0)
    , nPanProducts(0)
    , nPanOverseas(0)
    , nFlag(0)
    , nPaySource(0)
    , nDeductType(0)
    {}

void merchantTransaction::print() const
{
    LOGDEBUG(	
        "merchantTransaction: \n{\n"
        << "\tstrTransactionId: " << strTransactionId << ", \n"
        << "\tnChannelId: " << nChannelId << ", \n"
        << "\tstrChannelMerchantId: " << strChannelMerchantId << ", \n"
        << "\tstrChannelTerminalId: " << strChannelTerminalId << ", \n"
        << "\tstrOrderId: " << strOrderId << ", \n"
        << "\tstrMerchantId: " << strMerchantId << ", \n"
        << "\tnAmount: " << nAmount << ", \n"
        << "\tnOperationType: " << nOperationType << ", \n"
        << "\tnTradeStatus: " << nTradeStatus << ", \n"
        << "\tstrTime: " << strTime << ", \n"
        << "\tstrThirdTime: " << strThirdTime << ", \n"
        << "\tstrThirdChannelSettleDate: " << strThirdChannelSettleDate << ", \n"
        << "\tnCardType: " << nCardType << ", \n"
        << "\tnPanType: " << nPanType << ", \n"
        << "\tnPanClass: " << nPanClass << ", \n"
        << "\tnPanProducts: " << nPanProducts << ", \n"
        << "\tnPanOverseas: " << nPanOverseas << ", \n"
        << "\tnFlag: " << nFlag << ", \n"
        << "\tnPaySource: " << nPaySource << ", \n"
        << "\tnDeductType: " << nDeductType << ", \n"
        << "\tstrVoucherInfo: " << strVoucherInfo << ", \n"
        << "}"
    );
}

void merchantTransaction::Format2Json(Json::Value &data) const
{	
    data["transaction_id"] = strTransactionId;
    data["payment_channel_id"] = nChannelId;
    data["payment_channel_merchant_id"] = strChannelMerchantId;
    data["payment_channel_terminal_id"] = strChannelTerminalId;
    data["order_id"] = strOrderId;
    data["merchant_id"] = strMerchantId;
    data["amount"] = double(nAmount);
    data["operation_type"] = nOperationType;
    data["trade_status"] = nTradeStatus;
    data["time"] = strTime;
    data["third_time"] = strThirdTime;
    data["third_channel_settle_date"] = strThirdChannelSettleDate;
    data["card_type"] = nCardType;
    data["pan_type"] = nPanType;
    data["pan_class"] = nPanClass;
    data["pan_products"] = nPanProducts;
    data["pan_overseas"] = nPanOverseas;
    data["flag"] = nFlag;
    data["payment_source_type"] = nPaySource;
    data["deductpay_type"] = nDeductType;
    data["voucher_info"] = strVoucherInfo;
    print();
}

void merchantTransaction::Format(Json::Value& item)
{	
    strTransactionId = item["transaction_id"].asString();
    nChannelId = item["payment_channel_id"].asInt();
    strChannelMerchantId = item["payment_channel_merchant_id"].asString();
    strChannelTerminalId = item["payment_channel_terminal_id"].asString();
    strOrderId = item["order_id"].asString();
    strMerchantId = item["merchant_id"].asString();
    nAmount = item["amount"].asInt();
    nOperationType = item["operation_type"].asInt();
    nTradeStatus = item["trade_status"].asInt();
    strTime = item["time"].asString();
    strThirdTime = item["third_time"].asString();
    strThirdChannelSettleDate = item["third_channel_settle_date"].asString();
    nCardType = item["card_type"].asInt();
    nPanType = item["pan_type"].asInt();
    nPanClass = item["pan_class"].asInt();
    nPanProducts = item["pan_products"].asInt();
    nPanOverseas = item["pan_overseas"].asInt();
    nFlag = item["flag"].asInt();
    nPaySource = item["payment_source_type"].asInt();
    nDeductType = item["deductpay_type"].asInt();
    strVoucherInfo = item["voucher_info"].asString();
    print();
}

holdTransaction::holdTransaction() 
    : nChannelId(-1)
    , nAmount(0)
    , nOperationType(-1)
    {}

void holdTransaction::print() const
{
    LOGDEBUG(	
        "holdTransaction: \n{\n"
        << "\tstrTransactionId: " << strTransactionId << ", \n"
        << "\tnChannelId: " << nChannelId << ", \n"
        << "\tstrMerchantId: " << strMerchantId << ", \n"
        << "\tstrChannelMerchantId: " << strChannelMerchantId << ", \n"
        << "\tstrChannelTerminalId: " << strChannelTerminalId << ", \n"
        << "\tnAmount: " << nAmount << ", \n"
        << "\tnOperationType: " << nOperationType << ", \n"
        << "\tstrTime: " << strTime << ", \n"
        << "}"
    );
}

void holdTransaction::Format2Json(Json::Value &data) const
{	
    data["transaction_id"] = strTransactionId;
    data["payment_channel_id"] = nChannelId;
    data["merchant_id"] = strMerchantId;
    data["payment_channel_merchant_id"] = strChannelMerchantId;
    data["payment_channel_terminal_id"] = strChannelTerminalId;
    data["amount"] = double(nAmount);
    data["operation_type"] = nOperationType;
    data["time"] = strTime;
    print();
}

orderExternInfo::orderExternInfo()
    : nPinAndSignFreeFlag(0)
    , nYunShanFuFlag(0)
    {
    }

void orderExternInfo::print() const
{
    LOGDEBUG(	
        "orderExternInfo: \n{\n"
        << "\tstrOrderID: " << strOrderID << ", \n"
        << "\tnPinAndSignFreeFlag: " << nPinAndSignFreeFlag << ", \n"
        << "\tnYunShanFuFlag: " << nYunShanFuFlag << ", \n"
        << "\tstrOrderExtInfo: " << strOrderExtInfo << ", \n"
        << "}"
    );
}

void orderExternInfo::Format(Json::Value& item)
{
    strOrderID = item["order_id"].asString();
    nPinAndSignFreeFlag = item["pin_and_sign_free_flag"].asInt();
    nYunShanFuFlag = item["yunshanfu_flag"].asInt();
    strOrderExtInfo = item["order_extern_info"].asString();
    print();
}

void orderExternInfo::Format2Json(Json::Value &data) const
{	
    data["order_id"] = strOrderID;
    data["pin_and_sign_free_flag"] = nPinAndSignFreeFlag;
    data["yunshanfu_flag"] = nYunShanFuFlag;
    data["order_extern_info"] = strOrderExtInfo;
}

leposOrganization::leposOrganization()
    : bValid(false)
    , nCupsBlackRegionFlag(0)
    {
    }

void leposOrganization::Format(Json::Value& item)
{
    bValid = true;
    strOrganizationNo = item["organization_no"].asString();
    strUseOrganizationNo = item["use_organization_no"].asString();
    strProvince = item["province"].asString();
    strCity = item["city"].asString();
    strCounty = item["county"].asString();
    strAlias = item["alias"].asString();
    nCupsBlackRegionFlag = item["cups_black_region_flag"].asInt();
}

BankCardBin::BankCardBin()
    : nCardLength(0)
    , nContactless(0)
    , nOversea(0)
    , nDoubleFree(0)
    {}

void BankCardBin::Format(Json::Value& item)
{
    strBankId = item["bank_id"].asString();
    strBankName = item["bank_name"].asString();
    strCardType = item["card_type"].asString();
    strCardBin = item["card_bin"].asString();
    strFinInstitutionCode = item["fin_institution_code"].asString();
    nCardLength = item["card_length"].asInt();
    nContactless = item["contactless_flag"].asInt();
    nOversea = item["oversea_flag"].asInt();
    nDoubleFree = item["double_free_flag"].asInt();
}

void BankInstitutionCode::Format(Json::Value& item)
{
    strFinInstitutionCode = item["fin_institution_code"].asString();
    strEnSimpleName = item["en_simple_name"].asString();
}

ChannelAgent::ChannelAgent()
    : nAgentLevel(0), nAgentClass(0), nAgentType(0)
    {}

void ChannelAgent::Format(Json::Value& item)
{
    strAgentId = item["agent_id"].asString();
    strTopAgentId = item["top_agent_id"].asString();
    strAgentParentId = item["agent_parent_id"].asString();
    strAllSuperAgentAgentId = item["all_super_agent_id"].asString();
    strCoopNo = item["coop_no"].asString();
    strAgentName = item["agent_name"].asString();
    nAgentLevel = item["agent_level"].asInt();
    nAgentClass = item["agent_class"].asInt();
    nAgentType = item["agent_type"].asInt();
}

void ChannelAgent::print() const
{
    LOGDEBUG(	
        "ChannelAgent: \n{\n"
        << "\t strAgentId: " << strAgentId << ", \n"
        << "\t strTopAgentId: " << strTopAgentId << ", \n"
        << "\t strAgentParentId: " << strAgentParentId << ", \n"
        << "\t strAllSuperAgentAgentId: " << strAllSuperAgentAgentId << ", \n"
        << "\t strCoopNo: " << strCoopNo << ", \n"
        << "\t strAgentName: " << strAgentName << ", \n"
        << "\t nAgentLevel: " << nAgentLevel << ", \n"
        << "\t nAgentClass: " << nAgentClass << ", \n"
        << "\t nAgentType: " << nAgentType << ", \n"
        << "}"
    );
}

HappyposAgentWithdrawInfo::HappyposAgentWithdrawInfo()
    : nUsageType(0)
    {}

void HappyposAgentWithdrawInfo::Format(Json::Value& item)
{
    strAgentID = item["agent_id"].asString();
    nUsageType = item["usage_type"].asInt();
}

void HappyposAgentWithdrawInfo::print() const
{
    LOGDEBUG(
        "ChannelAgent: \n{\n"
        << "\t strAgentId: " << strAgentID << ", \n"
        << "\t nUsageType: " << nUsageType << ", \n"
        << "}"
    );
}
CardNoMerchantId::CardNoMerchantId()
    : nChannelId(0),nStatus(0)
{}

void CardNoMerchantId::Format(Json::Value& item)
{
    strCradNo = item["card_no"].asString();
    strCustomerId = item["customer_id"].asString();
    strCreateTime = item["create_time"].asString();
    strCpsBindId = item["cps_bind_id"].asString();
    nChannelId = item["channel_id"].asInt();
    nStatus = item["status"].asInt();
    strUpdateTime = item["update_time"].asString();
}

void CardNoMerchantId::print() const 
{
    LOGDEBUG(
        "CardNoMerchantId: \n{\n"
        << "\t strCradNo: " << strCradNo << ", \n"
        << "\t strCustomerId: " << strCustomerId << ", \n"
        << "\t strCreateTime: " << strCreateTime << ", \n"
        << "\t strCpsBindId: " << strCpsBindId << ", \n"
        << "\t nChannelId: " << nChannelId << ", \n"
        << "\t nStatus: " << nStatus << ", \n"
        << "\t strUpdateTime: " << strUpdateTime << ", \n"
        << "}"
    );
}

static void print(const char* tag,Json::Value& item)
{
    LOGDEBUG(tag << ":" << item.toStyledString());
}

CPolicyParam::CPolicyParam() 
    : bValid(false), nId(-1), nStatus(-1)
{}

void CPolicyParam::Format(Json::Value& item)
{
    bValid = item["valid"].asBool();
    nId = item["id"].asInt();
    strPolicyId = item["policy_id"].asString();
    strName = item["name"].asString();
    strValue = item["value"].asString();
    strComment = item["comment"].asString();
    nStatus = item["status"].asInt();
    strUser = item["user"].asString();
    strCreateTime = item["create_time"].asString();
    strUpdateTime = item["update_time"].asString();
    print("CPolicyParam", item);
}

CChannelPosBatchInfo::CChannelPosBatchInfo() 
{}

void CChannelPosBatchInfo::Format(Json::Value& item)
{
    strChannelPosCati = item["channel_pos_cati"].asString();
    strBatchNo = item["batch_no"].asString();
    strCheckinTime = item["checkin_time"].asString();
    strTime = item["time"].asString();
    print("CChannelPosBatchInfo", item);
}

CSwipeCardCallbackInfo::CSwipeCardCallbackInfo()
    : nStatus(-1), nCurrentNum(-1)
{}

void CSwipeCardCallbackInfo::Format2Json(Json::Value& item)
{
    item["order_id"] = strOrderId;
    item["callback_url"] = strCallbackUrl;
    item["message_head"] = strMessageHead;
    item["message_body"] = strMessageBody;
    item["status"] = nStatus;
    item["currnt_num"] = nCurrentNum;
    item["step"] = strStep;
    item["max_num"] = strMaxNum;
    item["last_time"] = strLastTime;
    item["time"] = strTime;
    item["type"] = strTime;
}

CPosOperation::CPosOperation()
    : nOperationType(-1)
{}

void CPosOperation::Format(Json::Value& item)
{
    strChannelPosCati = item["channel_pos_cati"].asString();
    strChannelPosBatchNo = item["channel_pos_batch_no"].asString();
    strChannelPosFlowId = item["channel_pos_flow_id"].asString();
    strChannelMerchantId = item["channel_merchant_id"].asString();
    strChannelPosShopId = item["channel_shop_id"].asInt();
    strChannelAgentId = item["channel_agent_id"].asInt();
    nOperationType = item["operation_type"].asInt();
    strOrderId = item["order_id"].asString();
    strTransactionId = item["transaction_id"].asString();
    strShowCupsId = item["show_cups_id"].asString();
    strShowCupsName = item["show_cups_name"].asInt();
    strResponseCode = item["response_code"].asInt();
    print("CPosOperation", item);
}

void CPosOperation::Format2Json(Json::Value& item)
{
    item["channel_pos_cati"] = strChannelPosCati;
    item["channel_pos_batch_no"] = strChannelPosBatchNo;
    item["channel_pos_flow_id"] = strChannelPosFlowId;
    item["channel_merchant_id"] = strChannelMerchantId;
    item["channel_shop_id"] = strChannelPosShopId;
    item["channel_agent_id"] = strChannelAgentId;
    item["operation_type"] = nOperationType;
    item["order_id"] = strOrderId;
    item["transaction_id"] = strTransactionId;
    item["show_cups_id"] = strShowCupsId;
    item["show_cups_name"] = strShowCupsName;
    item["response_code"] = strResponseCode;
    print("CPosOperation", item);
}

PosMerchantTradeControlInfo::PosMerchantTradeControlInfo()
: nAgentClass(0)
, nTradeMode(0)
, bValid(false)
{}

void PosMerchantTradeControlInfo::print() const
{
    LOGDEBUG(
        "PosMerchantTradeControlInfo: \n{\n"
        << "\t strAgentID: " << strAgentID << ", \n"
        << "\t strTopAgentID: " << strTopAgentID << ", \n"
        << "\t strMerchantID: " << strMerchantID << ", \n"
        << "\t strCreateTime: " << strCreateTime << ", \n"
        << "\t nAgentClass: " << nAgentClass << ", \n"
        << "\t nTradeMode: " << nTradeMode << ", \n"
        << "}"
    );
}

void PosMerchantTradeControlInfo::Format(Json::Value& item)
{
    if(!item.empty()) {
        bValid = true;
        strAgentID = item["agent_id"].asString();
        strTopAgentID = item["top_agent_id"].asString();
        strMerchantID = item["merchant_id"].asString();
        strCreateTime = item["create_time"].asString();
        nAgentClass = item["agent_class"].asInt();
        nTradeMode = item["trade_mode"].asInt();
        print();
    }
}

void PosMerchantTradeControlInfo::Format2Json(Json::Value& item)
{
    item["agent_id"] = strAgentID;
    item["top_agent_id"] = strTopAgentID;
    item["merchant_id"] = strMerchantID;
    item["create_time"] = strCreateTime;
    item["agent_class"] = nAgentClass;
    item["trade_mode"] = nTradeMode;
}

PosMerchantSwitchMccControlInfo::PosMerchantSwitchMccControlInfo()
: nAgentClass(0)
, nStatus(0)
{}

void PosMerchantSwitchMccControlInfo::print() const
{
    LOGDEBUG(
        "PosMerchantSwitchMccControlInfo: \n{\n"
        << "\t strMerchantID: " << strMerchantID << ", \n"
        << "\t strMccCode: " << strMccCode << ", \n"
        << "\t nAgentClass: " << nAgentClass << ", \n"
        << "\t nStatus: " << nStatus << ", \n"
        << "}"
    );
}

void PosMerchantSwitchMccControlInfo::Format(Json::Value& item)
{
    if(!item.empty()) {
        strMerchantID = item["merchant_id"].asString();
        strMccCode = item["mcc_code"].asString();
        nAgentClass = item["agent_class"].asInt();
        nStatus = item["status"].asInt();
        print();
    }
}

void PosMerchantSwitchMccControlInfo::Format2Json(Json::Value& item)
{
    item["merchant_id"] = strMerchantID;
    item["mcc_code"] = strMccCode;
    item["agent_class"] = nAgentClass;
    item["status"] = nStatus;
}

CpsBusinessConfigInfo::CpsBusinessConfigInfo()
:nBusinessYype(0),
isCps(0),
isYkpay(0),          
isPos2cps(0)
{}
void CpsBusinessConfigInfo::print() const
{
    LOGDEBUG(
        "CpsBusinessConfigInfo: \n{"
        << "nBusinessYype: " << nBusinessYype << ", " 
        << "strModel: " << strModel << ", " 
        << "strParentId: " << strParentId << ", " 
        << "strPayType: " << strPayType << ", " 
        << "strPaymentSource: " << strPaymentSource << ", " 
        << "isCps: " << isCps << ", " 
        << "isYkpay: " << isYkpay << ", " 
        << "isPos2cps: " << isPos2cps << ", "
        << "strAppTypes: " << strAppTypes << ", "
        << "}"
    );
}

void CpsBusinessConfigInfo::Format(Json::Value &agent)
{

    nBusinessYype = agent["business_type"].asInt();
    isCps = agent["is_cps"].asInt();
    isYkpay = agent["is_ykpay"].asInt();
    isPos2cps = agent["is_pos2cps"].asInt();
    strModel = agent["model"].asString();
    strParentId = agent["partner_id"].asString();
    strPayType = agent["pay_type"].asString();
    strPaymentSource = agent["payment_source_type"].asString();
    strAppTypes = agent["app_types"].asString();
    print();
}

IsoPosInfo::IsoPosInfo()
: nBatchNo(0)
, nFlowID(0)
, nRefNo(0)
, bValid(false)
{}

void IsoPosInfo::print() const
{
    LOGDEBUG(
        "IsoPosInfo: \n{\n"
        << "\t strPinpadID: " << strPinpadID << ", \n"
        << "\t strPinpadUUID: " << strPinpadUUID << ", \n"
        << "\t nBatchNo: " << nBatchNo << ", \n"
        << "\t nFlowID: " << nFlowID << ", \n"
        << "\t nRefNo: " << nRefNo << ", \n"
        << "\t strTime: " << strTime << ", \n"
        << "\t strPosType: " << strPosType << ", \n"
        << "\t strVersion: " << strVersion << ", \n"
        << "}"
    );
}

void IsoPosInfo::Format(Json::Value& item)
{
    if(!item.empty()) {
        bValid = true;
        strPinpadID = item["pinpad_id"].asString();
        strPinpadUUID = item["pinpad_uuid"].asString();
        nBatchNo = item["batch_no"].asInt();
        nFlowID = item["flow_id"].asInt();
        nRefNo = item["ref_no"].asInt();
        strTime = item["time"].asString();
        strPosType = item["pos_type"].asString();
        strVersion = item["version"].asString();
        print();
    }
}

void IsoPosInfo::Format2Json(Json::Value& item) const
{
    item["pinpad_id"] = strPinpadID;
    item["pinpad_uuid"] = strPinpadUUID;
    item["batch_no"] = nBatchNo;
    item["flow_id"] = nFlowID;
    item["ref_no"] = nRefNo;
    item["time"] = strTime;
    item["pos_type"] = strPosType;
    item["version"] = strVersion;
}

LeposParamInfo::LeposParamInfo()
: bValid(false)
{}

void LeposParamInfo::print() const
{
    LOGDEBUG(
        "LeposParamInfo: \n{\n"
        << "\t Key: " << strKey << ","
        << "\t Value: " << strValue << "\n"
        << "}"
    );
}

void LeposParamInfo::Format(Json::Value& item)
{
    if(!item.empty()) {
        bValid = true;
        strKey = item["key"].asString();
        strValue = item["value"].asString();
        print();
    }
}

BaseStationInfo::BaseStationInfo()
: bValid(false)
{}

void BaseStationInfo::print() const
{
    LOGDEBUG(
        "BaseStationInfo: \n{\n"
        << "\t strMcc: " << strMcc << ", \n"
        << "\t strMnc: " << strMnc << ", \n"
        << "\t strLac: " << strLac << ", \n"
        << "\t strCi: " << strCi << ", \n"
        << "\t strLongtitude: " << strLongitude << ", \n"
        << "\t strLatitude: " << strLatitude << ", \n"
        << "}"
    );
}

void BaseStationInfo::Format(Json::Value& item)
{
    if(!item.empty()) {
        bValid = true;
        strMcc = item["mcc"].asString();
        strMnc = item["mnc"].asString();
        strLac = item["lac"].asString();
        strCi = item["ci"].asString();
        strLongitude = item["lon"].asString();
        strLatitude = item["lat"].asString();
        print();
    }
}

void BaseStationInfo::Format2Json(Json::Value& item) const
{
    item["mcc"] = strMcc;
    item["mnc"] = strMnc;
    item["lac"] = strLac;
    item["ci"] = strCi;
    item["lon"] = strLongitude;
    item["lat"] = strLatitude;
}

Pos2DeductRegular::Pos2DeductRegular()
    : nStatus(0)
{}

void Pos2DeductRegular::Format(Json::Value& item)
{
    if(!item.empty()) {
        strRegularNo = item["regular_no"].asString();
        strRegularName = item["regular_name"].asString();
        strRegular = item["regular"].asString();
        nStatus = item["status"].asInt();
        strTime = item["time"].asString();
    }
}

}//namespace db_agent_api


