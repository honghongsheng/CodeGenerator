
    struct Merchant{
        bool bValid;
        std::string strMerchantId;
        std::string strUnionPayMerchantId;
        std::string strMerchantName;
        std::string strAgentId;
        std::string strTopAgentId;
        std::string strMccCode;
        std::string strRealMccCode;
        std::string strApplicant;
        std::string strBankArea;
        std::string strBankAccount;
        std::string strBankCity;
        std::string strbankHolder;
        std::string strProvince;
        std::string strCity;
        std::string strCreateTime;
        std::string strStartTimeLimit;
        std::string strEndTimeLimit;
        std::string strIdCard;
        std::string strLatitude;
        std::string strLongitude;
        std::string strUnionpayCode;
        std::string strChannelMerchantId;
        std::string strMobile;
        std::string strUserName;
        std::string strMerchantKey;
        std::string strBankName;
        int	nSpId;
        int	nBankAccountType;
        int	nMiaodaoActivity;
        int	nChannelId;
        int	nMerchantFlag;
        int	nPosLevel;
        int	nPreauthLevel;
        int nPreAuthorizationFlag;//F_pre_authorization_flag
        int	nQuickLevel;
        int	nUnionScanLevel;
        int	nWxLevel;
        int	nState;
        int	nBitFlag;
        int	nMerchantType;
        int	nPinfreeState;
        int	nRegisterStatus;
        int nPosRefundFlag;
        int nCategory_id;
        int nIsdel;
        int nStatus;
        int64_t nPinfreeLimit;
        int64_t nAlipaySingleMaxAmount;
        int64_t nAlipayOrdermaxAmount;
        int64_t nCreditMouthMaxAmount;
        int64_t nCreditOrderMaxAmount;
        int64_t nCreditSingleMaxAmount;
        int64_t nDebitMouthMaxAmount;
        int64_t nDebitOrderMaxAmount;
        int64_t nDebitSingleMaxAmount;
        int64_t nMaxCommissionOneTransaction;
        int64_t nCommission;
        int64_t nCommissionDudect;
        int64_t nCommissionByWeixin;
        int64_t nIsBackUpCommission;
        int64_t nBackUpCommission;
        int64_t nBackUpMaxCommissionOneTransaction;
        int64_t nSaasMultiAmountWarnVolume;
        int64_t nSettlementTimeFlag;
        int64_t nActiveDays;
    };

    struct MerchantCommission{
        bool bValid;
        std::string strMerchantId;
        std::string strCreateTime;
        int nPreferentialType;
        int64_t nT1DebitCardCommission;
        int64_t nT1DebitCardMaxFee;
        int64_t nT1CreditCardCommission;
        int64_t nT1OverseasCardCommission;
        int64_t nT0DebitCardCommission;
        int64_t nT0CreditCardCommission;
        int64_t nT0OverseasCardCommission;
        int64_t nT0CommissionFixed;
    };

    struct MerchantCommissionByPlanId{
        bool bValid;
        int nPlanId;
        int64_t nRateByMillion;
        int64_t nMaxFeeByMillion;
    };
            

    struct Agent{
        bool bValid;
        std::string strAgentId;
        std::string strAgentName;
        std::string strParentId;
        std::string strThirdPartyPublicKey;
        int nproperty;
        int nAgentType;
        int nAgentClass;
        int nStatus;
        int nProfitRuleType;
        std::string strCreateTime;
    };


    struct AgentCommission{
        bool bValid;
        std::string strAgentId;
        std::string strStartDate;
        std::string strUpdateTime;
        int nPreferentialType;
        int64_t nT1DebitCommissionBymillion;
        int64_t nT1DebitMaxFeeBymillion;
        int64_t nT1CreditCommissionBymillion;
        int64_t nT1OverseasCommissionBymillion;
        int64_t nT0DebitCommissionBymillion;
        int64_t nT0CreditCommissionBymillion;
        int64_t nT0OverseasCommissionBymillion;
        int64_t nT0DebitBlendCommissionBymillion;
        int64_t nT0CreditBlendCommissionBymillion;
        int64_t nT0OverseasBlendCommissionBymillion;
    };

    struct PinpadCheckin{
        std::string strPinpadId;
        std::string strTakByLmk;
        std::string strTakByTmk;
        std::string strCheckInTime;
    };

    struct Pinpad{

        struct pinpad_info{
            bool bValid;
            int		 nHasEncryptor;
            int		 nState;
            std::string strPinpadId;
            std::string strMerchantId;
            std::string strSerialNum;
            std::string strTTK;
            std::string strTmkByLmk;
            std::string strTpkByTmk;
            std::string strTpkByLmk;
            std::string strPinpadUuid;
        };

        struct pinpad_uuid_info{
            bool bValid;
            int nStatus;
            int nMaxUnbindTimes;
            int nEnable;
            int nRepairCounts;
            int nLoadTmkAllowNum;
            std::string strPinpadUuid;
            std::string strPinpadId;
            std::string strDeviceId;
            std::string strCreateTime;
            std::string strStartUsingTime;
            std::string strStartUsingDay;
            std::string strLastRepairTime;
            std::string strSn;
            std::string strIndustryName;
            std::string strIndustryModel;
            std::string strPinpadCreateTime;
            std::string strPinpadCommuication;
            std::string strPinpadOrganNo;
            std::string strPosType;
            std::string strIndustryCode;
            std::string strStoreTime;
            std::string strDeliverTime;
            std::string strLeshuaModel;
            std::string strAuthCode;
        };
    };

    struct MerchantBindCups{
        bool bValid;
        std::string strMerchantId;
        std::string strChannelMerchantId;
        std::string strShowChannelMerchantId;
        std::string strBindTime;
        int nBindType;
        int nBindKey;
    };

    struct CupsMerchant{
        bool bValid;
        std::string strCupsId;
        std::string strTerminalId;
        std::string strMerchantName;
        std::string strTerminalSn;
        std::string strZmk;
        std::string strZmkByLmk;
        std::string strMccCode;
        std::string strOrganNo;
        std::string strSource;
        std::string strCreateTime;
        std::string strUpdateTime;
        int	 nHasEncryptor;
        int64_t nCommision;
        int64_t nCommissionExt;
        int64_t nMinCommissionOneTransaction;
        int64_t nMaxCommissionOneTransaction;
        int64_t nCommissionByDebitBymillion;
        int64_t nMinCommissionDebit;
        int64_t nMaxCommissionDebit;
        int64_t nCommissionByCreditBymillion;
        int64_t nMinCommissionCredit;
        int64_t nMaxCommissionCredit;
        int64_t nCommissionByOverseasBymillion;
        int64_t nMinCommissionOverseas;
        int64_t nMaxCommissionOverseas;
        int64_t nPinfreeLimit;
        int64_t nDailyLimit;
        int	 nPreferentialType;
        int	 nPinfreeState;
        int	 nEnable;
        int	 nContactless;
        int	 nEnableLimit;
        int	 nChargingType;
    };

    struct RouteDetails{
        std::string strRegularNo;
        std::string strMerchantId;
        std::string strOrderId;
        std::string strTransactionId;
        std::string strSettlementAccount;
        std::string strPaychannelMerchantId;
        std::string strPaychannelTerminalId;
        std::string strPaychannelMerchantName;
        std::string strTopAgentId;
        std::string strPinpadUuid;
        std::string strMerchantOrganId;
        std::string strMerchantMccCode;
        std::string strPaychannelMerchantOrganId;
        std::string strPaychannelMerchantMccCode;
        std::string strEncryptCardId;
        int nBankCardType;
        int nPaychannelId;
        int nTerminalType;
        int64_t nAmount;
        int nMerchantPreferentialType;
        int nPaychannelMerchantPreferentialType;
    };

    struct ChannelPosInfo{
        std::string strPosSn;
        std::string strChannelMerchantId;
        std::string strChannelAgentId;
        std::string strTerminalId;
        std::string strTerminalType;
        int nChannelCatiStatus;
        int nChannelBusiFlag; //电签版加收手续费便签
        int nChannelTjBusiFlag;//携机存量商户调价便签
    };

    struct ChannelMerchantInfo{
        std::string strChannelAgentId;
        std::string strChannelShopId;
        std::string strMerchantId;
        int nChannelMerchantStatus;
        int nChannelMerchantInsuranceFlag;
        int nChannelMerchantDebitT0Flag;
        int nChannelMerchantCreditT0Flag;
        int nChannelMerchantNocturnalT0Flag;
        int nChannelMerchantDebitCardAmountLimit;
        int nChannelMerchantCreditCardAmountLimit;
        int nChannelMerchantToWalletT0Flag;
    };

    struct TransactionInfo{
        std::string strPaymentChannelMerchantDd;
        std::string strTransactionId;
        std::string strTime;
        int nPaymentChannelId;
        int nPanType;
        int nPanOverseas;
    };

    struct LeshuaPosOrder{
        std::string strPinpadId;
        std::string strBatchNo;
        std::string strFlowId;
        std::string strMerchantId;
        std::string strOrderId;
        std::string strEncryptCardId;
        std::string strCardId;

        bool        bValid;
    };

    struct LeshuaPreAuthOrder{
        std::string strPinpadId;
        std::string strBatchNo;
        std::string strFlowId;
        std::string strPreAuthCode;
        std::string strMerchantId;
        std::string strOrderId;
        std::string strEncryptCardId;
        std::string strTrackData;
        std::string strDate;

        bool        bValid;
    };

    struct ChannelPosOrder{
        std::string strChannelPosCati;
        std::string strChannelBatchNo;
        std::string strChannelFlowId;
        std::string strChannelMerchantId;
        std::string strMerchantId;
        std::string strOrderId;
        std::string strTerminalId;
        std::string strEncryptCardId;
    };

    struct Order{
        bool bValid;
        std::string strOrderId;
        std::string strMerchantId;
        std::string strUserName;
        std::string strGoodsType;
        std::string strGoodsName;
        std::string strGoodsDetails;
        std::string strThirdOrderId;
        std::string strReserverParam;
        std::string strTime;
        std::string strRoyalty;
        std::string strVocherId;
        std::string strClientIp;
        std::string strCallbackUrl;
        std::string strMerchantShopNo;
        std::string strMerchantPosNo;
        std::string strCustomerId;
        std::string strVoucherInfo;
        std::string strQrCode;
        std::string strErrorMsg;
        std::string strAttach;
        int		 nState;
        int64_t	 nAmount;
        int64_t	 nRefundAmount;
        int		 nPayMode;
        int64_t 	nDepositComm;
        int64_t	 nThirdPlatComm;
        int		 nPaychannelId;
        int		 nPanType;
        int		 nPanClass;
        int		 nPanProducts;
        int		 nPanOverseas;
        int		 nT0Flag;
        int		 nScanMethod;
        int		 nDeductPayType;
        int		 nPaySourceType;
        int		 nErrorType;
    };

    struct Transaction{
        bool bValid;
        std::string strTransactionId;
        std::string strOrderId;
        std::string strMerchantId;
        std::string strPinpadId;
        std::string strLongitude;
        std::string strLatitude;
        std::string strUserName;
        int64_t	 nAmount;
        int		 nOperationType;
        std::string strTime;
        std::string strCardId;
        std::string strCardBank;
        std::string strCardValid;
        std::string strCardSeqNum;
        std::string strIcField55;
        std::string strIcAid;
        std::string strIcAtc;
        std::string strIcTc;
        int		 nCardType;
        int		 nPanType;
        int		 nPanClass;
        int		 nPanProducts;
        int		 nPanOverseas;
        int		 nNoPwdFlag;
        int		 nPaychannelId;
        std::string strChlMerchantId;
        std::string strChlTerminalId;
        int		 nApptype;
        std::string strMobileId;
        std::string strChlOrderId;
        std::string strChlRefNum;
        std::string strChlSettleDate;
        std::string strChlAuthCode;
        std::string strChlBatchNum;
        std::string strChlErrCode;
        std::string strThirdTime;
        std::string strPinpadUuid;
        int		 nFlag;
        std::string strEncryptCardId;
        std::string strRecvBankCode;
        std::string strTopAgentId;
        std::string strRefundId;
        int64_t	 nOrderAmount;
        int64_t	 nCouponAmount;
        std::string strChlMcc;
        std::string strCardHoldSign;
    };

    struct simpleRisk{
        std::string strOrderId;
        std::string strMerchantId;
        int64_t	 nAmount;
        int		 nT0Flag;
        int		 nChlId;
        std::string strRequest;
        std::string strOperationType;
    };

    struct leposParam{
        bool bValid;
        std::string strKey;
        std::string strValue;
    };

    struct mccInfo{
        bool bValid;
        std::string strMccCode;
        std::string strFatherMccCode;
        std::string strGrandpaMccCode;
        int nMccType;
        int64_t nDailyLimit;
        int nPinFreeFlag;
    };

    struct offlineOrder{
        bool bValid;
        std::string strField55;
        std::string strOrderId;
        std::string strMerchantId;
        std::string strPinpadUuid;
        int64_t	 nAmount;
    };

    struct offlineParam{
        bool	bValid;
        int64_t nOfflineMerchantWhitelstFlag;
        std::string strOffLowBound;
    };

    struct merchantFirstPayInfo{
        bool	bValid;
        std::string strMerchantId;
        std::string strOrderId;
        std::string strTopAgentId;
        std::string strEncryptCardId;
        int		 nAgentClass;
        int64_t	 nAmount;
    };//商户首笔交易信息

    struct pinFreeCard{
        std::string strEncryptCardId;
        std::string strCreateTime;
    };

    struct delayInsurace{
        std::string strMerchantId;
        std::string strTopAgentId;
        std::string strOrderId;
        int		 nState;
        int		 nCompany;
    };

    struct channelTransaction{
        std::string strTransactionId;
        int		 nChannelId;
        std::string strChannelMerchantId;
        std::string strChannelTerminalId;
        int64_t		 nAmount;
        int		 nOperationType;
        std::string strTime;
        std::string strThirdTime;
    };

    struct merchantTransaction{
        std::string strTransactionId;
        int		 nChannelId;
        std::string strChannelMerchantId;
        std::string strChannelTerminalId;
        std::string strOrderId;
        std::string strMerchantId;
        int64_t		 nAmount;
        int		 nOperationType;
        int		 nTradeStatus;
        std::string strTime;
        std::string strThirdTime;
        std::string strThirdChannelSettleDate;
        int		 nCardType;
        int		 nPanType;
        int		 nPanClass;
        int		 nPanProducts;
        int		 nPanOverseas;
        int		 nFlag;
        int		 nPaySource;
        int		 nDeductType;
        std::string strVoucherInfo;
    };

    struct holdTransaction{
        std::string strTransactionId;
        std::string strMerchantId;
        int		 nChannelId;
        std::string strChannelMerchantId;
        std::string strChannelTerminalId;
        int64_t		 nAmount;
        int		 nOperationType;
        std::string strTime;
    };

    struct orderExternInfo {
        std::string strOrderID;
        int nPinAndSignFreeFlag;
        int nYunShanFuFlag; 
        std::string strOrderExtInfo
    };

    struct leposOrganization{
        bool	bValid;
        std::string strOrganizationNo;
        std::string strUseOrganizationNo;
        std::string strProvince;
        std::string strCity;
        std::string strCounty;
        std::string strAlias;
        int 		nCupsBlackRegionFlag;
    };

    struct BankCardBin{
        std::string strBankId;
        std::string strBankName;
        std::string strCardType;
        std::string strCardBin;
        std::string strFinInstitutionCode;
        int		 nCardLength;
        int		 nContactless;
        int		 nOversea;
        int		 nDoubleFree;
    };

    struct BankInstitutionCode{
        std::string strFinInstitutionCode;
        std::string strEnSimpleName;
    };

    /* Note: ChannelAgent,对应letrade.t_channel_agent_info表信息
     * Author: janyhong
     */
    struct ChannelAgent {
        std::string strAgentId;			  //F_agent_id | 代理商编号
        std::string strTopAgentId;		   //F_top_agent_id | 顶级代理商编号
        std::string strAgentParentId;		//F_agent_parent_id | 父级代理商编号
        std::string strAllSuperAgentAgentId; //F_all_super_agent_id | 代理商所有上级编号 如2代： 10_20
        std::string strCoopNo;			   //F_coop_no | 合作商编号
        std::string strAgentName;			//F_agent_name | 代理商名称
        int		 nAgentLevel;		   //F_agent_level | 代理商等级
        int		 nAgentClass;		   //F_agent_class | 类别,0:合作商1:代理商
        int		 nAgentType;			//F_agent_type | 0企业1个人
    };

    struct HappyposAgentWithdrawInfo {
        std::string strAgentID;
        int         nUsageType;
    };
    /* breif : CardNoMerchantId,银行卡商户关联表collectpay.t_card_no_merchant_id
     * author: janyhong
     */
    struct CardNoMerchantId {
        std::string strCradNo;          //F_card_no | 银行卡号, 经过加密处理
        std::string strCustomerId;      //F_customer_id | 客户ID
        std::string strCreateTime;      //F_create_time | 创建时间
        std::string strCpsBindId;       //F_cps_bind_id | cps bind ID, 代收模块产生，唯一
        int         nChannelId;	        //F_channel_id | 交易通道ID
        int         nStatus;            //F_status | 绑定状态
        std::string strUpdateTime;      //F_update_time | 更新时间
    };

    struct CPolicyParam{	
        bool	bValid;
        int     nId;                      //F_id | 
        std::string strPolicyId;          //F_policy_id | 
        std::string strName;              //F_name | 
        std::string strValue;             //F_value | 
        std::string strComment;           //F_comment | 
        int         nStatus;              //F_status | 
        std::string strUser;              //F_user | 
        std::string strCreateTime;        //F_create_time | 
        std::string strUpdateTime;        //F_update_time | 
    };

    struct CChannelPosBatchInfo{
        std::string strChannelPosCati;       //F_channel_pos_cati | 
        std::string strBatchNo;              //F_batch_no | 
        std::string strCheckinTime;          //F_checkin_time | 
        std::string strTime;                 //F_time | 
    };


    struct CSwipeCardCallbackInfo{
        std::string strOrderId;           //F_order_id | 
        std::string strCallbackUrl;       //F_callback_url | 
        std::string strMessageHead;       //F_message_head | 
        std::string strMessageBody;       //F_message_body | 
        int         nStatus;              //F_status | 
        int         nCurrentNum;          //F_currnt_num | 
        std::string strStep;              //F_step | 
        std::string strMaxNum;            //F_max_num | 
        std::string strLastTime;          //F_last_time | 
        std::string strTime;              //F_time | 
        int         nType;                //F_type | 
    };

    struct CPosOperation{
        std::string strChannelPosCati;           //F_channel_pos_cati | 渠道终端号
        std::string strChannelPosBatchNo;        //F_channel_pos_batch_no | 渠道POS批次号
        std::string strChannelPosFlowId;         //F_channel_pos_flow_id | 渠道POS流水号
        std::string strChannelMerchantId;        //F_channel_merchant_id | 渠道商户号
        std::string strChannelPosShopId;         //F_channel_shop_id | 渠道POS网点号
        std::string strChannelAgentId;           //F_channel_agent_id | 渠道POS代理商ID
        int         nOperationType;              //F_operation_type | 操作类型：0-签到，1-交易，2-撤销，3-冲正'
        std::string strOrderId;                  //F_order_id | 订单号
        std::string strTransactionId;            //F_transaction_id | 操作流水号
        std::string strShowCupsId;               //F_show_cups_id | POS显示CUPS商户号
        std::string strShowCupsName;             //F_show_cups_name | POS显示CUPS商户名
        std::string strResponseCode;             //F_response_code | POS返回码
    };

    struct PosMerchantTradeControlInfo {
        std::string strAgentID;
        std::string strTopAgentID;
        std::string strMerchantID;
        std::string strCreateTime;

        int         nAgentClass;
        int         nTradeMode;
        bool        bValid;
    };

    struct PosMerchantSwitchMccControlInfo {
        std::string strMerchantID;
        std::string strMccCode;

        int         nAgentClass;
        int         nStatus;
    };

    struct CpsBusinessConfigInfo {
        int         nBusinessYype;
        std::string strModel;          //提供给业务的model参数
        std::string strParentId;       //业务ID
        std::string strPayType;      
        std::string strPaymentSource;       
        int         isCps;	        
        int         isYkpay;           
        int         isPos2cps;
        std::string strAppTypes;      
    };

    struct IsoPosInfo {
        std::string strPinpadID;
        std::string strPinpadUUID;
        std::string strTime;
        std::string strPosType;
        std::string strVersion;

        int         nBatchNo;
        int         nFlowID;
        int         nRefNo;
        bool        bValid;
    };

    struct LeposParamInfo {
        std::string strKey;
        std::string strValue;
        bool        bValid;
    };

    struct BaseStationInfo {
        std::string strMcc;
        std::string strMnc;
        std::string strLac;
        std::string strCi;
        std::string strLongitude;
        std::string strLatitude;

        bool bValid;
    };

    struct Pos2DeductRegular {
        std::string strRegularNo;
        std::string strRegularName;
        std::string strRegular;
        int         nStatus;
        std::string strTime;
    };