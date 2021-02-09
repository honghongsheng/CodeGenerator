﻿
struct Merchant : {
    bValid:#b,                      json="";//
    strMerchantId:#s,               json="merchant_id";//
    strUnionPayMerchantId:#s,       json="unionpay_merchant_id";//
    strMerchantName:#s,             json="merchant_name";//
    strAgentId:#s,                  json="agent_id";//
    strTopAgentId:#s,               json="agent_id_1g";//
    strMccCode:#s,                  json="mcc_code";//
    strRealMccCode:#s,              json="real_mcc_code";//
    strApplicant:#s,                json="applicant";//
    strBankArea:#s,                 json="bank_area";//
    strBankAccount:#s,              json="bank_account";//
    strBankCity:#s,                 json="bank_city";//
    strbankHolder:#s,               json="bank_holder";//
    strProvince:#s,                 json="province";//
    strCity:#s,                     json="city";//
    strCreateTime:#s,               json="create_time";//
    strStartTimeLimit:#s,           json="start_time_limit";//
    strEndTimeLimit:#s,             json="end_time_limit";//
    strIdCard:#s,                   json="idcard";//
    strLatitude:#s,                 json="latitude";//
    strLongitude:#s,                json="longitude";//
    strUnionpayCode:#s,             json="unionpay_code";//
    strChannelMerchantId:#s,        json="payment_merchant_id";//
    strMobile:#s,                   json="mobile";//
    strUserName:#s,                 json="user_name";//
    strMerchantKey:#s,              json="bind_merchant_key";//
    strBankName:#s,                 json="bank_name";//
    nSpId:#i,                       json="sp_id";//
    nBankAccountType:#i,            json="bank_account_type";//
    nMiaodaoActivity:#i,            json="business_miaodao_activity";//
    nChannelId:#i,                  json="payment_channel_id";//
    nMerchantFlag:#i,               json="merchant_flag";//
    nPosLevel:#i,                   json="privilege_level";//
    nPreauthLevel:#i,               json="pre_authorization_level";//
    nPreAuthorizationFlag:#i,       json="pre_authorization_flag";//
    nQuickLevel:#i,                 json="quick_payment_pos_level";//
    nUnionScanLevel:#i,             json="union_scan_level";//
    nWxLevel:#i,                    json="wx_class";//
    nState:#i,                      json="state";//
    nBitFlag:#i,                    json="bit_flag";//
    nMerchantType:#i,               json="merchant_type";//
    nPinfreeState:#i,               json="pinfree_state";//
    nRegisterStatus:#i,             json="register_status";//
    nPosRefundFlag:#i,              json="pos_refund_flag";//
    nCategory_id:#i,                json="category_id";//
    nIsdel:#i,                      json="isdel";//
    nStatus:#i,                     json="status";//
    nPinfreeLimit:#i,               json="";//
    nAlipaySingleMaxAmount:#i,      json="";//
    nAlipayOrdermaxAmount:#i,       json="";//
    nCreditMouthMaxAmount:#i,       json="";//
    nCreditOrderMaxAmount:#i,       json="";//
    nCreditSingleMaxAmount:#i,      json="";//
    nDebitMouthMaxAmount:#i,        json="";//
    nDebitOrderMaxAmount:#i,        json="";//
    nDebitSingleMaxAmount:#i,       json="";//
    nMaxCommissionOneTransaction:#i,json="";//
    nCommission:#i,                 json="";//
    nCommissionDudect:#i,           json="";//
    nCommissionByWeixin:#i,         json="";//
    nIsBackUpCommission:#i,         json="";//
    nBackUpCommission:#i,           json="";//
    nBackUpMaxCommissionOneTransaction:#i,    json="";//
    nSaasMultiAmountWarnVolume:#i,  json="";//
    nSettlementTimeFlag:#i,         json="";//
    nActiveDays:#i,                 json="";//
}(json)

struct MerchantCommission : {
    bValid:#b,                      json="";//
    strMerchantId:#s,               json="merchant_id";//
    strCreateTime:#s,               json="create_time";//
    nPreferentialType:#i,           json="preferential_type";//
    nT1DebitCardCommission:#i,      json="t1_debit_card_commission";//
    nT1DebitCardMaxFee:#i,          json="t1_debit_card_max_fee";//
    nT1CreditCardCommission:#i,     json="t1_credit_card_commission";//
    nT1OverseasCardCommission:#i,   json="t1_overseas_card_commission";//
    nT0DebitCardCommission:#i,      json="t0_debit_card_commission";//
    nT0CreditCardCommission:#i,     json="t0_credit_card_commission";//
    nT0OverseasCardCommission:#i,   json="t0_overseas_card_commission";//
    nT0CommissionFixed:#i,          json="t0_commission_fixed";//
}(json)

struct MerchantCommissionByPlanId : {
    bValid:#b,                      json="";//
    nPlanId:#i,                     json="plan_id";//
    nRateByMillion:#i,              json="rate_by_million";//
    nMaxFeeByMillion:#i,            json="max_fee_by_million";//
}(json)


struct Agent : {
    bValid:#b,                      json="";//
    strAgentId:#s,                  json="agent_id";//
    strAgentName:#s,                json="agent_name";//
    strParentId:#s,                 json="agent_parent_id";//
    strThirdPartyPublicKey:#s,      json="third_party_public_key";//
    nproperty:#i,                   json="property";//
    nAgentType:#i,                  json="agent_type";//
    nAgentClass:#i,                 json="agent_class";//
    nStatus:#i,                     json="status";//
    nProfitRuleType:#i,             json="profit_rule_type";//
    strCreateTime:#s,               json="create_time";//
}(json)


struct AgentCommission : {
    bValid:#b,                      json="";//
    strAgentId:#s,                  json="agent_id";//
    strStartDate:#s,                json="start_date";//
    strUpdateTime:#s,               json="update_time";//
    nPreferentialType:#i,           json="preferential_type";//
    nT1DebitCommissionBymillion:#i, json="t1_debit_commission_bymillion";//
    nT1DebitMaxFeeBymillion:#i,     json="t1_debit_max_fee_bymillion";//
    nT1CreditCommissionBymillion:#i,json="t1_credit_commission_bymillion";//
    nT1OverseasCommissionBymillion:#i,   json="t1_overseas_commission_bymillion";//
    nT0DebitCommissionBymillion:#i, json="t0_debit_commission_bymillion";//
    nT0CreditCommissionBymillion:#i,json="t0_credit_commission_bymillion";//
    nT0OverseasCommissionBymillion:#i,   json="t0_overseas_commission_bymillion";//
    nT0DebitBlendCommissionBymillion:#i, json="t0_debit_blend_commission_bymillion";//
    nT0CreditBlendCommissionBymillion:#i,json="t0_credit_blend_commission_bymillion";//
    nT0OverseasBlendCommissionBymillion:#i,   json="t0_overseas_blend_commission_bymillion";//
}(json)

struct PinpadCheckin : {
    strPinpadId:#s,                 json="pinpad_id";//
    strTakByLmk:#s,                 json="tak_by_lmk";//
    strTakByTmk:#s,                 json="tak_by_tmk";//
    strCheckInTime:#s,              json="checkin_time";//
}(json)

struct Pinpad : {

struct pinpad_info : {
    bValid:#b,                      json="";//
    nHasEncryptor:#i,               json="has_encryptor";//
    nState:#i,                      json="state";//
    strPinpadId:#s,                 json="pinpad_id";//
    strMerchantId:#s,               json="merchant_id";//
    strSerialNum:#s,                json="serial_number";//
    strTTK:#s,                      json="ttk";//
    strTmkByLmk:#s,                 json="tmk_by_lmk";//
    strTpkByTmk:#s,                 json="tpk_by_tmk";//
    strTpkByLmk:#s,                 json="tpk_by_lmk";//
    strPinpadUuid:#s,               json="pinpad_uuid";//
}(json)

struct pinpad_uuid_info : {
    bValid:#b,                      json="";//
    nStatus:#i,                     json="status";//
    nMaxUnbindTimes:#i,             json="max_unbind_times";//
    nEnable:#i,                     json="enable";//
    nRepairCounts:#i,               json="repair_counts";//
    nLoadTmkAllowNum:#i,            json="load_TMK_allow_num";//
    strPinpadUuid:#s,               json="pinpad_uuid";//
    strPinpadId:#s,                 json="pinpad_id";//
    strDeviceId:#s,                 json="device_id";//
    strCreateTime:#s,               json="create_time";//
    strStartUsingTime:#s,           json="start_using_time";//
    strStartUsingDay:#s,            json="start_using_day";//
    strLastRepairTime:#s,           json="last_repair_time";//
    strSn:#s,                       json="pinpad_sn";//
    strIndustryName:#s,             json="industry_name";//
    strIndustryModel:#s,            json="industry_model";//
    strPinpadCreateTime:#s,         json="pinpad_create_time";//
    strPinpadCommuication:#s,       json="pinpad_communication";//
    strPinpadOrganNo:#s,            json="pinpad_organization_no";//
    strPosType:#s,                  json="pos_type";//
    strIndustryCode:#s,             json="industry_code";//
    strStoreTime:#s,                json="store_time";//
    strDeliverTime:#s,              json="deliver_time";//
    strLeshuaModel:#s,              json="leshua_model";//
    strAuthCode:#s,                 json="authorization_code";//
}(json)
}(json)

struct MerchantBindCups : {
    bValid:#b,                      json="";//
    strMerchantId:#s,               json="merchant_id";//
    strChannelMerchantId:#s,        json="paychannel_merchant_id";//
    strShowChannelMerchantId:#s,    json="show_paychannel_merchant_id";//
    strBindTime:#s,                 json="bind_time";//
    nBindType:#i,                   json="bind_type";//
    nBindKey:#i,                    json="bind_key";//
}(json)

struct CupsMerchant : {
    bValid:#b,                      json="";//
    strCupsId:#s,                   json="merchant_id";//
    strTerminalId:#s,               json="terminal_id";//
    strMerchantName:#s,             json="merchant_name";//
    strTerminalSn:#s,               json="terminal_sn";//
    strZmk:#s,                      json="zmk";//
    strZmkByLmk:#s,                 json="zmk_by_lmk";//
    strMccCode:#s,                  json="mcc_code";//
    strOrganNo:#s,                  json="organization_no";//
    strSource:#s,                   json="source";//
    strCreateTime:#s,               json="create_time";//
    strUpdateTime:#s,               json="update_time";//
    nHasEncryptor:#i,               json="has_encryptor";//
    nCommision:#i,                  json="commission";//
    nCommissionExt:#i,              json="commission_ext";//
    nMinCommissionOneTransaction:#i,json="min_commission_one_transaction";//
    nMaxCommissionOneTransaction:#i,json="max_commission_one_transaction";//
    nCommissionByDebitBymillion:#i, json="commission_by_debit_bymillion";//
    nMinCommissionDebit:#i,         json="min_commission_debit";//
    nMaxCommissionDebit:#i,         json="max_commission_debit";//
    nCommissionByCreditBymillion:#i,json="commission_by_credit_bymillion";//
    nMinCommissionCredit:#i,        json="min_commission_credit";//
    nMaxCommissionCredit:#i,        json="max_commission_credit";//
    nCommissionByOverseasBymillion:#i,   json="commission_by_overseas_bymillion";//
    nMinCommissionOverseas:#i,      json="min_commission_overseas";//
    nMaxCommissionOverseas:#i,      json="max_commission_overseas";//
    nPinfreeLimit:#i,               json="pinfree_limit";//
    nDailyLimit:#i,                 json="daily_limit";//
    nPreferentialType:#i,           json="preferential_type";//
    nPinfreeState:#i,               json="pinfree_state";//
    nEnable:#i,                     json="enable";//
    nContactless:#i,                json="contactless";//
    nEnableLimit:#i,                json="enable_limit";//
    nChargingType:#i,               json="charging_type";//
}(json)

struct RouteDetails : {
    strRegularNo:#s,                json="regular_no";//
    strMerchantId:#s,               json="merchant_id";//
    strOrderId:#s,                  json="order_id";//
    strTransactionId:#s,            json="transaction_id";//
    strSettlementAccount:#s,        json="settlement_account";//
    strPaychannelMerchantId:#s,     json="paychannel_merchant_id";//
    strPaychannelTerminalId:#s,     json="paychannel_terminal_id";//
    strPaychannelMerchantName:#s,   json="paychannel_merchant_name";//
    strTopAgentId:#s,               json="top_agent_id";//
    strPinpadUuid:#s,               json="pinpad_uuid";//
    strMerchantOrganId:#s,          json="merchant_organ_id";//
    strMerchantMccCode:#s,          json="merchant_mcc_code";//
    strPaychannelMerchantOrganId:#s,json="paychannel_merchant_organ_id";//
    strPaychannelMerchantMccCode:#s,json="paychannel_merchant_mcc_code";//
    strEncryptCardId:#s,            json="encrypt_card_id";//
    nBankCardType:#i,               json="bank_card_type";//
    nPaychannelId:#i,               json="paychannel_id";//
    nTerminalType:#i,               json="terminal_type";//
    nAmount:#i,                     json="";//
    nMerchantPreferentialType:#i,   json="merchant_preferential_type";//
    nPaychannelMerchantPreferentialType:#i,   json="paychannel_merchant_preferential_type";//
}(json)

struct ChannelPosInfo : {
    strPosSn:#s,                    json="pos_sn";//
    strChannelMerchantId:#s,        json="channel_merchant_id";//
    strChannelAgentId:#s,           json="channel_agent_id";//
    strTerminalId:#s,               json="terminal_id";//
    strTerminalType:#s,             json="terminal_type";//
    nChannelCatiStatus:#i,          json="channel_cati_status";//
    nChannelBusiFlag:#i,            json="channel_busi_flag";//
    nChannelTjBusiFlag:#i,          json="channel_tj_business_flag";//
}(json)

struct ChannelMerchantInfo : {
    strChannelAgentId:#s,           json="channel_agent_id";//
    strChannelShopId:#s,            json="channel_shop_id";//
    strMerchantId:#s,               json="merchant_id";//
    nChannelMerchantStatus:#i,      json="channel_merchant_status";//
    nChannelMerchantInsuranceFlag:#i,    json="channel_merchant_insurance_flag";//
    nChannelMerchantDebitT0Flag:#i, json="channel_merchant_debit_t0_flag";//
    nChannelMerchantCreditT0Flag:#i,json="channel_merchant_credit_t0_flag";//
    nChannelMerchantNocturnalT0Flag:#i,  json="channel_merchant_nocturnal_t0_flag";//
    nChannelMerchantDebitCardAmountLimit:#i,  json="channel_merchant_debit_card_amount_limit";//
    nChannelMerchantCreditCardAmountLimit:#i, json="channel_merchant_credit_card_amount_limit";//
    nChannelMerchantToWalletT0Flag:#i,   json="channel_merchant_to_wallet_t0_flag";//
}(json)

struct TransactionInfo : {
    strPaymentChannelMerchantDd:#s, json="payment_channel_merchant_id";//
    strTransactionId:#s,            json="transaction_id";//
    strTime:#s,                     json="time";//
    nPaymentChannelId:#i,           json="payment_channel_id";//
    nPanType:#i,                    json="pan_type";//
    nPanOverseas:#i,                json="pan_overseas";//
}(json)

struct LeshuaPosOrder : {
    strPinpadId:#s,                 json="pinpad_id";//
    strBatchNo:#s,                  json="batch_no";//
    strFlowId:#s,                   json="flow_id";//
    strMerchantId:#s,               json="merchant_id";//
    strOrderId:#s,                  json="order_id";//
    strEncryptCardId:#s,            json="encrypt_card_id";//
    strCardId:#s,                   json="card_id";//

    bValid:#b,                      json="";//
}(json)

struct LeshuaPreAuthOrder : {
    strPinpadId:#s,                 json="pinpad_id";//
    strBatchNo:#s,                  json="batch_no";//
    strFlowId:#s,                   json="flow_id";//
    strPreAuthCode:#s,              json="pre_auth_code";//
    strMerchantId:#s,               json="merchant_id";//
    strOrderId:#s,                  json="order_id";//
    strEncryptCardId:#s,            json="encrypt_card_id";//
    strTrackData:#s,                json="track_data";//
    strDate:#s,                     json="date";//

    bValid:#b,                      json="";//
}(json)

struct ChannelPosOrder : {
    strChannelPosCati:#s,           json="channel_pos_cati";//
    strChannelBatchNo:#s,           json="channel_pos_batch_no";//
    strChannelFlowId:#s,            json="channel_pos_flow_id";//
    strChannelMerchantId:#s,        json="channel_merchant_id";//
    strMerchantId:#s,               json="merchant_id";//
    strOrderId:#s,                  json="order_id";//
    strTerminalId:#s,               json="terminal_id";//
    strEncryptCardId:#s,            json="encrypt_card_id";//
}(json)

struct Order : {
    bValid:#b,                      json="";//
    strOrderId:#s,                  json="order_id";//
    strMerchantId:#s,               json="merchant_id";//
    strUserName:#s,                 json="user_name";//
    strGoodsType:#s,                json="goods_type";//
    strGoodsName:#s,                json="goods_name";//
    strGoodsDetails:#s,             json="goods_detail";//
    strThirdOrderId:#s,             json="third_order_id";//
    strReserverParam:#s,            json="reserver_param";//
    strTime:#s,                     json="order_time";//
    strRoyalty:#s,                  json="royalty";//
    strVocherId:#s,                 json="voucher_id";//
    strClientIp:#s,                 json="client_ip";//
    strCallbackUrl:#s,              json="callback_url";//
    strMerchantShopNo:#s,           json="merchant_shop_no";//
    strMerchantPosNo:#s,            json="merchant_pos_no";//
    strCustomerId:#s,               json="customer_id";//
    strVoucherInfo:#s,              json="voucher_info";//
    strQrCode:#s,                   json="qrcode";//
    strErrorMsg:#s,                 json="error_msg";//
    strAttach:#s,                   json="attach";//
    nState:#i,                      json="state";//
    nAmount:#i,                     json="";//
    nRefundAmount:#i,               json="";//
    nPayMode:#i,                    json="payment_mode";//
    nDepositComm:#i,                json="";//
    nThirdPlatComm:#i,              json="";//
    nPaychannelId:#i,               json="payment_channel_id";//
    nPanType:#i,                    json="pan_type";//
    nPanClass:#i,                   json="pan_class";//
    nPanProducts:#i,                json="pan_products";//
    nPanOverseas:#i,                json="pan_overseas";//
    nT0Flag:#i,                     json="t0_flag";//
    nScanMethod:#i,                 json="scan_method";//
    nDeductPayType:#i,              json="deductpay_type";//
    nPaySourceType:#i,              json="payment_source_type";//
    nErrorType:#i,                  json="error_type";//
}(json)

struct Transaction : {
    bValid:#b,                      json="";//
    strTransactionId:#s,            json="transaction_id";//
    strOrderId:#s,                  json="order_id";//
    strMerchantId:#s,               json="merchant_id";//
    strPinpadId:#s,                 json="pinpad_id";//
    strLongitude:#s,                json="longitude";//
    strLatitude:#s,                 json="latitude";//
    strUserName:#s,                 json="user_name";//
    nAmount:#i,                     json="";//
    nOperationType:#i,              json="operation_type";//
    strTime:#s,                     json="time";//
    strCardId:#s,                   json="card_id";//
    strCardBank:#s,                 json="card_bank";//
    strCardValid:#s,                json="card_valid";//
    strCardSeqNum:#s,               json="card_sequence_number";//
    strIcField55:#s,                json="ic_field_55";//
    strIcAid:#s,                    json="ic_aid";//
    strIcAtc:#s,                    json="ic_atc";//
    strIcTc:#s,                     json="ic_tc";//
    nCardType:#i,                   json="card_type";//
    nPanType:#i,                    json="pan_type";//
    nPanClass:#i,                   json="pan_class";//
    nPanProducts:#i,                json="pan_products";//
    nPanOverseas:#i,                json="pan_overseas";//
    nNoPwdFlag:#i,                  json="no_passwd_flag";//
    nPaychannelId:#i,               json="payment_channel_id";//
    strChlMerchantId:#s,            json="payment_channel_merchant_id";//
    strChlTerminalId:#s,            json="payment_channel_terminal_id";//
    nApptype:#i,                    json="app_type";//
    strMobileId:#s,                 json="mobile_id";//
    strChlOrderId:#s,               json="channel_order_id";//
    strChlRefNum:#s,                json="channel_reference_number";//
    strChlSettleDate:#s,            json="channel_settle_date";//
    strChlAuthCode:#s,              json="channel_authorize_code";//
    strChlBatchNum:#s,              json="channel_batch_number";//
    strChlErrCode:#s,               json="channel_error_code";//
    strThirdTime:#s,                json="third_time";//
    strPinpadUuid:#s,               json="pinpad_uuid";//
    nFlag:#i,                       json="flag";//
    strEncryptCardId:#s,            json="encrypt_card_id";//
    strRecvBankCode:#s,             json="receive_bank_code";//
    strTopAgentId:#s,               json="top_agent_id";//
    strRefundId:#s,                 json="merchant_refund_id";//
    nOrderAmount:#i,                json="";//
    nCouponAmount:#i,               json="";//
    strChlMcc:#s,                   json="payment_channel_mcc";//
    strCardHoldSign:#s,             json="card_holder_sign";//
}(json)

struct simpleRisk : {
    strOrderId:#s,                  json="order_id";//
    strMerchantId:#s,               json="merchant_id";//
    nAmount:#i,                     json="";//
    nT0Flag:#i,                     json="t0_flag";//
    nChlId:#i,                      json="paychannel_id";//
    strRequest:#s,                  json="data";//
    strOperationType:#s,            json="operation_type";//
}(json)

struct leposParam : {
    bValid:#b,                      json="";//
    strKey:#s,                      json="key";//
    strValue:#s,                    json="value";//
}(json)

struct mccInfo : {
    bValid:#b,                      json="";//
    strMccCode:#s,                  json="mcc_code";//
    strFatherMccCode:#s,            json="father_mcc_code";//
    strGrandpaMccCode:#s,           json="grandpa_mcc_code";//
    nMccType:#i,                    json="mcc_type";//
    nDailyLimit:#i,                 json="daily_limit";//
    nPinFreeFlag:#i,                json="no_pin_flag";//
}(json)

struct offlineOrder : {
    bValid:#b,                      json="";//
    strField55:#s,                  json="field_55";//
    strOrderId:#s,                  json="order_id";//
    strMerchantId:#s,               json="merchant_id";//
    strPinpadUuid:#s,               json="pinpad_uuid";//
    nAmount:#i,                     json="";//
}(json)

struct offlineParam : {
    bValid:#b,                      json="";//
    nOfflineMerchantWhitelstFlag:#i,json="is_offline_white_list";//
    strOffLowBound:#s,              json="off_low_bound";//
}(json)

struct merchantFirstPayInfo : {
    bValid:#b,                      json="";//
    strMerchantId:#s,               json="merchant_id";//
    strOrderId:#s,                  json="order_id";//
    strTopAgentId:#s,               json="top_agent_id";//
    strEncryptCardId:#s,            json="encrypt_card_id";//
    nAgentClass:#i,                 json="agent_class";//
    nAmount:#i,                     json="";//
}(json)//商户首笔交易信息

struct pinFreeCard : {
    strEncryptCardId:#s,            json="encrypt_card_id";//
    strCreateTime:#s,               json="create_time";//
}(json)

struct delayInsurace : {
    strMerchantId:#s,               json="merchant_id";//
    strTopAgentId:#s,               json="top_agent_id";//
    strOrderId:#s,                  json="order_id";//
    nState:#i,                      json="state";//
    nCompany:#i,                    json="company";//
}(json)

struct channelTransaction : {
    strTransactionId:#s,            json="transaction_id";//
    nChannelId:#i,                  json="payment_channel_id";//
    strChannelMerchantId:#s,        json="payment_channel_merchant_id";//
    strChannelTerminalId:#s,        json="payment_channel_terminal_id";//
    nAmount:#i,                     json="";//
    nOperationType:#i,              json="operation_type";//
    strTime:#s,                     json="time";//
    strThirdTime:#s,                json="third_time";//
}(json)

struct merchantTransaction : {
    strTransactionId:#s,            json="transaction_id";//
    nChannelId:#i,                  json="payment_channel_id";//
    strChannelMerchantId:#s,        json="payment_channel_merchant_id";//
    strChannelTerminalId:#s,        json="payment_channel_terminal_id";//
    strOrderId:#s,                  json="order_id";//
    strMerchantId:#s,               json="merchant_id";//
    nAmount:#i,                     json="amount";//
    nOperationType:#i,              json="operation_type";//
    nTradeStatus:#i,                json="trade_status";//
    strTime:#s,                     json="time";//
    strThirdTime:#s,                json="third_time";//
    strThirdChannelSettleDate:#s,   json="third_channel_settle_date";//
    nCardType:#i,                   json="card_type";//
    nPanType:#i,                    json="pan_type";//
    nPanClass:#i,                   json="pan_class";//
    nPanProducts:#i,                json="pan_products";//
    nPanOverseas:#i,                json="pan_overseas";//
    nFlag:#i,                       json="flag";//
    nPaySource:#i,                  json="payment_source_type";//
    nDeductType:#i,                 json="deductpay_type";//
    strVoucherInfo:#s,              json="voucher_info";//
}(json)

struct holdTransaction : {
    strTransactionId:#s,            json="transaction_id";//
    strMerchantId:#s,               json="merchant_id";//
    nChannelId:#i,                  json="payment_channel_id";//
    strChannelMerchantId:#s,        json="payment_channel_merchant_id";//
    strChannelTerminalId:#s,        json="payment_channel_terminal_id";//
    nAmount:#i,                     json="";//
    nOperationType:#i,              json="operation_type";//
    strTime:#s,                     json="time";//
}(json)

struct orderExternInfo  : {
    strOrderID:#s,                  json="order_id";//
    nPinAndSignFreeFlag:#i,         json="pin_and_sign_free_flag";//
    nYunShanFuFlag:#i,              json="yunshanfu_flag";//
std::string strOrderExtInfo
}(json)

struct leposOrganization : {
    bValid:#b,                      json="";//
    strOrganizationNo:#s,           json="organization_no";//
    strUseOrganizationNo:#s,        json="use_organization_no";//
    strProvince:#s,                 json="province";//
    strCity:#s,                     json="city";//
    strCounty:#s,                   json="county";//
    strAlias:#s,                    json="alias";//
    nCupsBlackRegionFlag:#i,        json="cups_black_region_flag";//
}(json)

struct BankCardBin : {
    strBankId:#s,                   json="bank_id";//
    strBankName:#s,                 json="bank_name";//
    strCardType:#s,                 json="card_type";//
    strCardBin:#s,                  json="card_bin";//
    strFinInstitutionCode:#s,       json="fin_institution_code";//
    nCardLength:#i,                 json="card_length";//
    nContactless:#i,                json="contactless_flag";//
    nOversea:#i,                    json="oversea_flag";//
    nDoubleFree:#i,                 json="double_free_flag";//
}(json)

struct BankInstitutionCode : {
    strFinInstitutionCode:#s,       json="fin_institution_code";//
    strEnSimpleName:#s,             json="en_simple_name";//
}(json)

/* Note: ChannelAgent,对应letrade.t_channel_agent_info表信息
* Author: janyhong
*/
struct ChannelAgent  : {
    strAgentId:#s,                  json="agent_id";//
    strTopAgentId:#s,               json="top_agent_id";//
    strAgentParentId:#s,            json="agent_parent_id";//
    strAllSuperAgentAgentId:#s,     json="all_super_agent_id";//
    strCoopNo:#s,                   json="coop_no";//
    strAgentName:#s,                json="agent_name";//
    nAgentLevel:#i,                 json="agent_level";//
    nAgentClass:#i,                 json="agent_class";//
    nAgentType:#i,                  json="agent_type";//
}(json)

struct HappyposAgentWithdrawInfo  : {
    strAgentID:#s,                  json="agent_id";//
    nUsageType:#i,                  json="usage_type";//
}(json)
/* breif : CardNoMerchantId,银行卡商户关联表collectpay.t_card_no_merchant_id
* author: janyhong
*/
struct CardNoMerchantId  : {
    strCradNo:#s,                   json="card_no";//
    strCustomerId:#s,               json="customer_id";//
    strCreateTime:#s,               json="create_time";//
    strCpsBindId:#s,                json="cps_bind_id";//
    nChannelId:#i,                  json="channel_id";//
    nStatus:#i,                     json="status";//
    strUpdateTime:#s,               json="update_time";//
}(json)

struct CPolicyParam : {
    bValid:#b,                      json="valid";//
    nId:#i,                         json="id";//
    strPolicyId:#s,                 json="policy_id";//
    strName:#s,                     json="name";//
    strValue:#s,                    json="value";//
    strComment:#s,                  json="comment";//
    nStatus:#i,                     json="status";//
    strUser:#s,                     json="user";//
    strCreateTime:#s,               json="create_time";//
    strUpdateTime:#s,               json="update_time";//
}(json)

struct CChannelPosBatchInfo : {
    strChannelPosCati:#s,           json="channel_pos_cati";//
    strBatchNo:#s,                  json="batch_no";//
    strCheckinTime:#s,              json="checkin_time";//
    strTime:#s,                     json="time";//
}(json)


struct CSwipeCardCallbackInfo : {
    strOrderId:#s,                  json="order_id";//
    strCallbackUrl:#s,              json="callback_url";//
    strMessageHead:#s,              json="message_head";//
    strMessageBody:#s,              json="message_body";//
    nStatus:#i,                     json="status";//
    nCurrentNum:#i,                 json="currnt_num";//
    strStep:#s,                     json="step";//
    strMaxNum:#s,                   json="max_num";//
    strLastTime:#s,                 json="last_time";//
    strTime:#s,                     json="type";//
    nType:#i,                       json="";//
}(json)

struct CPosOperation : {
    strChannelPosCati:#s,           json="channel_pos_cati";//
    strChannelPosBatchNo:#s,        json="channel_pos_batch_no";//
    strChannelPosFlowId:#s,         json="channel_pos_flow_id";//
    strChannelMerchantId:#s,        json="channel_merchant_id";//
    strChannelPosShopId:#s,         json="channel_shop_id";//
    strChannelAgentId:#s,           json="channel_agent_id";//
    nOperationType:#i,              json="operation_type";//
    strOrderId:#s,                  json="order_id";//
    strTransactionId:#s,            json="transaction_id";//
    strShowCupsId:#s,               json="show_cups_id";//
    strShowCupsName:#s,             json="show_cups_name";//
    strResponseCode:#s,             json="response_code";//
}(json)

struct PosMerchantTradeControlInfo  : {
    strAgentID:#s,                  json="agent_id";//
    strTopAgentID:#s,               json="top_agent_id";//
    strMerchantID:#s,               json="merchant_id";//
    strCreateTime:#s,               json="create_time";//

    nAgentClass:#i,                 json="agent_class";//
    nTradeMode:#i,                  json="trade_mode";//
    bValid:#b,                      json="";//
}(json)

struct PosMerchantSwitchMccControlInfo  : {
    strMerchantID:#s,               json="merchant_id";//
    strMccCode:#s,                  json="mcc_code";//

    nAgentClass:#i,                 json="agent_class";//
    nStatus:#i,                     json="status";//
}(json)

struct CpsBusinessConfigInfo  : {
    nBusinessYype:#i,               json="business_type";//
    strModel:#s,                    json="model";//
    strParentId:#s,                 json="partner_id";//
    strPayType:#s,                  json="pay_type";//
    strPaymentSource:#s,            json="payment_source_type";//
    isCps:#i,                       json="is_cps";//
    isYkpay:#i,                     json="is_ykpay";//
    isPos2cps:#i,                   json="is_pos2cps";//
    strAppTypes:#s,                 json="app_types";//
}(json)

struct IsoPosInfo  : {
    strPinpadID:#s,                 json="pinpad_id";//
    strPinpadUUID:#s,               json="pinpad_uuid";//
    strTime:#s,                     json="time";//
    strPosType:#s,                  json="pos_type";//
    strVersion:#s,                  json="version";//

    nBatchNo:#i,                    json="batch_no";//
    nFlowID:#i,                     json="flow_id";//
    nRefNo:#i,                      json="ref_no";//
    bValid:#b,                      json="";//
}(json)

struct LeposParamInfo  : {
    strKey:#s,                      json="key";//
    strValue:#s,                    json="value";//
    bValid:#b,                      json="";//
}(json)

struct BaseStationInfo  : {
    strMcc:#s,                      json="mcc";//
    strMnc:#s,                      json="mnc";//
    strLac:#s,                      json="lac";//
    strCi:#s,                       json="ci";//
    strLongitude:#s,                json="lon";//
    strLatitude:#s,                 json="lat";//

    bValid:#b,                      json="";//
}(json)

struct Pos2DeductRegular  : {
    strRegularNo:#s,                json="regular_no";//
    strRegularName:#s,              json="regular_name";//
    strRegular:#s,                  json="regular";//
    nStatus:#i,                     json="status";//
    strTime:#s,                     json="time";//
}(json)