#pragma once
#include <windows.h>
// 网络连接断开回调函数原形
#define  LDWORD  DWORD
#define  LLONG  LONG
typedef long LONG;
#define DH_MAX_MAIL_ADDR_LEN              128              // 邮件发(收)地址最大长度
#define DH_MAX_MAIL_SUBJECT_LEN           64               // 邮件主题最大长度
#define DH_MAX_IPADDR_LEN                 16               // IP地址字符串长度
#define DH_MAX_IPADDR_LEN_EX              40               // 扩展IP地址字符串长度, 支持IPV6
#define DH_MACADDR_LEN                    40               // MAC地址字符串长度
#define DH_MAX_URL_LEN                    128              // URL字符串长度
#define DH_MAX_DEV_ID_LEN                 48               // 机器编号最大长度
#define DH_MAX_HOST_NAMELEN               64               // 主机名长度,
#define DH_MAX_HOST_PSWLEN                32               // 密码长度
#define DH_MAX_NAME_LEN                   16               // 通用名字字符串长度
#define DH_MAX_ETHERNET_NUM               2                // 以太网口最大个数
#define DH_MAX_ETHERNET_NUM_EX            10               // 扩展以太网口最大个数
#define DH_DEV_SERIALNO_LEN               48               // 序列号字符串长度
#define DH_DEV_CLASS_LEN                  16               // 设备类型字符串（如"IPC"）长度
#define DH_DEV_TYPE_LEN                   32               // 设备型号字符串（如"IPC-F725"）长度
#define DH_MAX_SAERCH_IP_NUM              256              // 最大搜索IP个数
#define DH_MAX_STRING_LEN                 128        
#define DH_MACHINE_NAME_NUM               64               // 机器名称长度
#define DH_USER_NAME_LENGTH_EX       16                 // 用户名长度
#define DH_USER_PSW_LENGTH_EX        16                 // 密码
#define MAX_IPV6_LEN              64   //IPv6地址最大长度
#define CFG_MAX_CHANNEL_NAME_LEN            256     // 通道名称最大长度 
#define NET_DVR_DEV_ADDRESS_MAX_LEN 129
#define NET_DVR_LOGIN_USERNAME_MAX_LEN 64
#define NET_DVR_LOGIN_PASSWD_MAX_LEN 64
#define SERIALNO_LEN		    48      //序列号长度
#define NET_DVR_SET_PICCFG_V40                      6180    //设置图象参数， 支持变长
#define CFG_CMD_CHANNELTITLE                "ChannelTitle"              // 通道名称(对应 AV_CFG_ChannelName)
#define NET_DVR_GET_PICCFG_V40                      6179    //获取图象参数 支持变长    NetSDK
#define MAX_TIMESEGMENT_V30        8       //9000设备最大时间段数
#define NAME_LEN			    32      //用户名长度
#define MAX_SHELTERNUM            4       //8000设备最大遮挡区域数
#define MAX_IP_ALARMOUT_V40     4096    //允许加入的最多报警输出数
#define MAX_ALARMOUT_V40             (MAX_IP_ALARMOUT_V40 +MAX_ANALOG_ALARMOUT) //4128
#define MAX_ANALOG_ALARMOUT     32      //最大32路模拟报警输出
#define MAX_DAYS                7       //每周天数
#define MAX_MULTI_AREA_NUM      24
#define MAX_CHANNUM_V40         512
#define DH_SERIALNO_LEN                   48    


typedef int					AV_int32;



// 对应CLIENT_SearchDevicesByIPs接口
typedef struct
{
	DWORD               dwSize;                                 // 结构体大小
	int                 nIpNum;                                 // 当前搜索的IP个数
	char                szIP[DH_MAX_SAERCH_IP_NUM][64];         // 具体待搜索的IP信息
}DEVICE_IP_SEARCH_INFO;
// 对应CLIENT_StartSearchDevices接口
typedef struct
{
	int                 iIPVersion;                             // 4 for IPV4, 6 for IPV6
	char                szIP[64];                               // IP IPV4形如"192.168.0.1" IPV6形如"2008::1/64"
	int                 nPort;                                  // tcp端口
	char                szSubmask[64];                          // 子网掩码 IPV6无子网掩码
	char                szGateway[64];                          // 网关
	char                szMac[DH_MACADDR_LEN];                  // MAC地址
	char                szDeviceType[DH_DEV_TYPE_LEN];          // 设备类型
	BYTE                byManuFactory;                          // 目标设备的生产厂商,具体参考EM_IPC_TYPE类    
	BYTE                byDefinition;                           // 1-标清 2-高清
	bool                bDhcpEn;                                // Dhcp使能状态, true-开, false-关
	BYTE                byReserved1;                            // 字节对齐
	char                verifyData[88];                         // 校验数据 通过异步搜索回调获取(在修改设备IP时会用此信息进行校验)
	char                szSerialNo[DH_DEV_SERIALNO_LEN];        // 序列号
	char                szDevSoftVersion[DH_MAX_URL_LEN];       // 设备软件版本号    
	char                szDetailType[DH_DEV_TYPE_LEN];          // 设备型号
	char                szVendor[DH_MAX_STRING_LEN];            // OEM客户类型
	char                szDevName[DH_MACHINE_NAME_NUM];         // 设备名称
	char                szUserName[DH_USER_NAME_LENGTH_EX];     // 登陆设备用户名（在修改设备IP时需要填写）
	char                szPassWord[DH_USER_NAME_LENGTH_EX];     // 登陆设备密码（在修改设备IP时需要填写）
	unsigned short      nHttpPort;                              // HTTP服务端口号
	WORD                wVideoInputCh;                          // 视频输入通道数
	WORD                wRemoteVideoInputCh;                    // 远程视频输入通道数
	WORD                wVideoOutputCh;                         // 视频输出通道数
	WORD                wAlarmInputCh;                          // 报警输入通道数
	WORD                wAlarmOutputCh;                         // 报警输出通道数
	char                cReserved[244];
}DEVICE_NET_INFO_EX;
// 结构体
typedef struct tagSADP_DEVICE_INFO
{
	char			szSeries[12];
	char			szSerialNO[48];
	char			szMAC[20];
	char			szIPv4Address[16];
	char			szIPv4SubnetMask[16];
	unsigned int	dwDeviceType;
	unsigned int	dwPort;
	unsigned int	dwNumberOfEncoders;
	unsigned int	dwNumberOfHardDisk;
	char			szDeviceSoftwareVersion[48];
	char			szDSPVersion[48];
	char			szBootTime[48];
	int				iResult;
	char			szDevDesc[24];       //设备类型描述
	char			szOEMinfo[24];       //OEM产商信息
	char			szIPv4Gateway[16];   //IPv4网关
	char			szIPv6Address[46];	 //IPv6地址
	char			szIPv6Gateway[46];   //IPv6网关
	unsigned char   byIPv6MaskLen;       //IPv6子网前缀长度
	unsigned char   bySupport;           //按位表示,对应为为1表示支持,0x01:是否支持Ipv6,0x02:是否支持修改Ipv6参数,0x04:是否支持Dhcp	0x08: 是否支持udp多播 0x10:是否含加密节点,0x20:是否支持恢复密码,0x40:是否支持重置密码,0x80:是否支持同步IPC密码			 
	unsigned char   byDhcpEnabled;       //Dhcp状态, 0 不启用 1 启用
	unsigned char   byDeviceAbility;	//0：设备不支持“‘设备类型描述’ 'OEM厂商' 'IPv4网关' ‘IPv6地址’ 'IPv6网关' ‘IPv6子网前缀’‘DHCP’”  1：支持上诉功能
	unsigned short	wHttpPort;			// Http 端口
	unsigned short	wDigitalChannelNum;
	char			szCmsIPv4[16];
	unsigned short	wCmsPort;
	unsigned char	byOEMCode;  //0-基线设备 1-OEM设备
	unsigned char   byActivated; //设备是否激活;0-激活，1-未激活（老的设备都是已激活状态）
	char			szBaseDesc[24];	//基线短型号，不随定制而修改的型号，用于萤石平台进行型号对比
	unsigned char   bySupport1; //按位表示,  1表示支持，0表示不支持
								//0x01:是否支持重置密码方式2 
								//0x02;是否支持设备锁定功能
	unsigned char   byRes[2];
	unsigned char   byEZVIZCode;    //0- 基线设备 1- 萤石设备
	unsigned int    dwDetailOEMCode;    //详细OEMCode信息:oemcode由客户序号（可变位,从1开始，1~429496)+菜单风格（2位）+区域号（2位）三部分构成。										//规则说明：oemcode最大值为4294967295，最多是十位数。
	unsigned char    byRes2[8];
}SADP_DEVICE_INFO, *LPSADP_DEVICE_INFO;

typedef struct DeviceInfo_admin
{
	char hk_admin[30];
	SADP_DEVICE_INFO hk_device_info;
	char hk_pwchar[30];
};

// 设备信息扩展
typedef struct
{
	BYTE                sSerialNumber[DH_SERIALNO_LEN];     // 序列号
	int                 nAlarmInPortNum;                    // DVR报警输入个数
	int                 nAlarmOutPortNum;                   // DVR报警输出个数
	int                 nDiskNum;                           // DVR硬盘个数
	int                 nDVRType;                           // DVR类型,见枚举NET_DEVICE_TYPE
	int                 nChanNum;                           // DVR通道个数
	BYTE                byLimitLoginTime;                   // 在线超时时间,为0表示不限制登陆,非0表示限制的分钟数
	BYTE                byLeftLogTimes;                     // 当登陆失败原因为密码错误时,通过此参数通知用户,剩余登陆次数,为0时表示此参数无效
	BYTE                bReserved[2];                       // 保留字节,字节对齐
	int                 nLockLeftTime;                      // 当登陆失败,用户解锁剩余时间（秒数）, -1表示设备未设置该参数
	char                Reserved[24];                       // 保留
} NET_DEVICEINFO_Ex, *LPNET_DEVICEINFO_Ex;
typedef enum tagEM_LOGIN_SPAC_CAP_TYPE
{
	EM_LOGIN_SPEC_CAP_TCP = 0,    // TCP登陆, 默认方式
	EM_LOGIN_SPEC_CAP_ANY = 1,    // 无条件登陆
	EM_LOGIN_SPEC_CAP_SERVER_CONN = 2,    // 主动注册的登入
	EM_LOGIN_SPEC_CAP_MULTICAST = 3,    // 组播登陆
	EM_LOGIN_SPEC_CAP_UDP = 4,    // UDP方式下的登入
	EM_LOGIN_SPEC_CAP_MAIN_CONN_ONLY = 6,    // 只建主连接下的登入
	EM_LOGIN_SPEC_CAP_SSL = 7,    // SSL加密方式登陆

	EM_LOGIN_SPEC_CAP_INTELLIGENT_BOX = 9,    // 登录智能盒远程设备
	EM_LOGIN_SPEC_CAP_NO_CONFIG = 10,   // 登录设备后不做取配置操作
	EM_LOGIN_SPEC_CAP_U_LOGIN = 11,   // 用U盾设备的登入
	EM_LOGIN_SPEC_CAP_LDAP = 12,   // LDAP方式登录
	EM_LOGIN_SPEC_CAP_AD = 13,   // AD（ActiveDirectory）登录方式
	EM_LOGIN_SPEC_CAP_RADIUS = 14,   // Radius 登录方式 
	EM_LOGIN_SPEC_CAP_SOCKET_5 = 15,   // Socks5登陆方式
	EM_LOGIN_SPEC_CAP_CLOUD = 16,   // 云登陆方式
	EM_LOGIN_SPEC_CAP_AUTH_TWICE = 17,   // 二次鉴权登陆方式
	EM_LOGIN_SPEC_CAP_TS = 18,   // TS码流客户端登陆方式
	EM_LOGIN_SPEC_CAP_P2P = 19,   // 为P2P登陆方式
	EM_LOGIN_SPEC_CAP_MOBILE = 20,   // 手机客户端登陆
	EM_LOGIN_SPEC_CAP_INVALID                   // 无效的登陆方式
}EM_LOGIN_SPAC_CAP_TYPE;


// 通道名称
struct AV_CFG_ChannelName
{
	AV_int32			nStructSize;
	AV_int32			nSerial;						// 摄像头唯一编号
	char				szName[CFG_MAX_CHANNEL_NAME_LEN];// 通道名
};

//NET_DVR_Login_V30()参数结构
typedef struct
{
	BYTE sSerialNumber[SERIALNO_LEN];  //序列号
	BYTE byAlarmInPortNum;                //报警输入个数
	BYTE byAlarmOutPortNum;                //报警输出个数
	BYTE byDiskNum;                    //硬盘个数
	BYTE byDVRType;                    //设备类型, 1:DVR 2:ATM DVR 3:DVS ......
	BYTE byChanNum;                    //模拟通道个数
	BYTE byStartChan;                    //起始通道号,例如DVS-1,DVR - 1
	BYTE byAudioChanNum;                //语音通道数
	BYTE byIPChanNum;                    //最大数字通道个数，低位  
	BYTE byZeroChanNum;            //零通道编码个数 //2010-01-16
	BYTE byMainProto;            //主码流传输协议类型 0-private, 1-rtsp,2-同时支持private和rtsp
	BYTE bySubProto;                //子码流传输协议类型0-private, 1-rtsp,2-同时支持private和rtsp
	BYTE bySupport;        //能力，位与结果为0表示不支持，1表示支持，
						   //bySupport & 0x1, 表示是否支持智能搜索
						   //bySupport & 0x2, 表示是否支持备份
						   //bySupport & 0x4, 表示是否支持压缩参数能力获取
						   //bySupport & 0x8, 表示是否支持多网卡
						   //bySupport & 0x10, 表示支持远程SADP
						   //bySupport & 0x20, 表示支持Raid卡功能
						   //bySupport & 0x40, 表示支持IPSAN 目录查找
						   //bySupport & 0x80, 表示支持rtp over rtsp
	BYTE bySupport1;        // 能力集扩充，位与结果为0表示不支持，1表示支持
							//bySupport1 & 0x1, 表示是否支持snmp v30
							//bySupport1 & 0x2, 支持区分回放和下载
							//bySupport1 & 0x4, 是否支持布防优先级    
							//bySupport1 & 0x8, 智能设备是否支持布防时间段扩展
							//bySupport1 & 0x10, 表示是否支持多磁盘数（超过33个）
							//bySupport1 & 0x20, 表示是否支持rtsp over http    
							//bySupport1 & 0x80, 表示是否支持车牌新报警信息2012-9-28, 且还表示是否支持NET_DVR_IPPARACFG_V40结构体
	BYTE bySupport2; /*能力，位与结果为0表示不支持，非0表示支持
					 bySupport2 & 0x1, 表示解码器是否支持通过URL取流解码
					 bySupport2 & 0x2,  表示支持FTPV40
					 bySupport2 & 0x4,  表示支持ANR
					 bySupport2 & 0x8,  表示支持CCD的通道参数配置
					 bySupport2 & 0x10,  表示支持布防报警回传信息（仅支持抓拍机报警 新老报警结构）
					 bySupport2 & 0x20,  表示是否支持单独获取设备状态子项
					 bySupport2 & 0x40,  表示是否是码流加密设备*/
	WORD wDevType;              //设备型号
	BYTE bySupport3; //能力集扩展，位与结果为0表示不支持，1表示支持
					 //bySupport3 & 0x1, 表示是否多码流
					 // bySupport3 & 0x4 表示支持按组配置， 具体包含 通道图像参数、报警输入参数、IP报警输入、输出接入参数、
					 // 用户参数、设备工作状态、JPEG抓图、定时和时间抓图、硬盘盘组管理 
					 //bySupport3 & 0x8为1 表示支持使用TCP预览、UDP预览、多播预览中的"延时预览"字段来请求延时预览（后续都将使用这种方式请求延时预览）。而当bySupport3 & 0x8为0时，将使用 "私有延时预览"协议。
					 //bySupport3 & 0x10 表示支持"获取报警主机主要状态（V40）"。
					 //bySupport3 & 0x20 表示是否支持通过DDNS域名解析取流

	BYTE byMultiStreamProto;//是否支持多码流,按位表示,0-不支持,1-支持,bit1-码流3,bit2-码流4,bit7-主码流，bit-8子码流
	BYTE byStartDChan;        //起始数字通道号,0表示无效
	BYTE byStartDTalkChan;    //起始数字对讲通道号，区别于模拟对讲通道号，0表示无效
	BYTE byHighDChanNum;        //数字通道个数，高位
	BYTE bySupport4;        //能力集扩展，位与结果为0表示不支持，1表示支持
							//bySupport4 & 0x4表示是否支持拼控统一接口
							// bySupport4 & 0x80 支持设备上传中心报警使能。表示判断调用接口是 NET_DVR_PDC_RULE_CFG_V42还是 NET_DVR_PDC_RULE_CFG_V41
	BYTE byLanguageType;// 支持语种能力,按位表示,每一位0-不支持,1-支持  
						//  byLanguageType 等于0 表示 老设备
						//  byLanguageType & 0x1表示支持中文
						//  byLanguageType & 0x2表示支持英文
	BYTE byVoiceInChanNum;   //音频输入通道数 
	BYTE byStartVoiceInChanNo; //音频输入起始通道号 0表示无效
	BYTE  bySupport5;  //按位表示,0-不支持,1-支持,bit0-支持多码流
					   //bySupport5 &0x01表示支持wEventTypeEx ,兼容dwEventType 的事件类型（支持行为事件扩展）--先占住，防止冲突
					   //bySupport5 &0x04表示是否支持使用扩展的场景模式接口
					   /*
					   bySupport5 &0x08 设备返回该值表示是否支持计划录像类型V40接口协议(DVR_SET_RECORDCFG_V40/ DVR_GET_RECORDCFG_V40)(在该协议中设备支持类型类型13的配置)
					   之前的部分发布的设备，支持录像类型13，则配置录像类型13。如果不支持，统一转换成录像类型3兼容处理。SDK通过命令探测处理)
					   */
	BYTE  bySupport6;   //能力，按位表示，0-不支持,1-支持
						//bySupport6 0x1  表示设备是否支持压缩 
						//bySupport6 0x2 表示是否支持流ID方式配置流来源扩展命令，DVR_SET_STREAM_SRC_INFO_V40
						//bySupport6 0x4 表示是否支持事件搜索V40接口
						//bySupport6 0x8 表示是否支持扩展智能侦测配置命令
						//bySupport6 0x40表示图片查询结果V40扩展
	BYTE  byMirrorChanNum;    //镜像通道个数，<录播主机中用于表示导播通道>
	WORD wStartMirrorChanNo;  //起始镜像通道号
	BYTE bySupport7;   //能力,按位表示,0-不支持,1-支持
					   // bySupport7 & 0x1  表示设备是否支持 INTER_VCA_RULECFG_V42 扩展
					   // bySupport7 & 0x2  表示设备是否支持 IPC HVT 模式扩展
					   // bySupport7 & 0x04  表示设备是否支持 返回锁定时间
					   // bySupport7 & 0x08  表示设置云台PTZ位置时，是否支持带通道号
					   // bySupport7 & 0x10  表示设备是否支持双系统升级备份
					   // bySupport7 & 0x20  表示设备是否支持 OSD字符叠加 V50
					   // bySupport7 & 0x40  表示设备是否支持 主从跟踪（从摄像机）
					   // bySupport7 & 0x80  表示设备是否支持 报文加密
	BYTE  byRes2;        //保留
}NET_DVR_DEVICEINFO_V30, *LPNET_DVR_DEVICEINFO_V30;

typedef void (CALLBACK *fLoginResultCallBack) (LONG lUserID, DWORD dwResult, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo, void* pUser);
typedef struct
{
	char sDeviceAddress[NET_DVR_DEV_ADDRESS_MAX_LEN];
	BYTE byUseTransport;    //是否启用能力集透传，0--不启用透传，默认，1--启用透传
	WORD wPort;
	char sUserName[NET_DVR_LOGIN_USERNAME_MAX_LEN];
	char sPassword[NET_DVR_LOGIN_PASSWD_MAX_LEN];
	fLoginResultCallBack cbLoginResult;
	void *pUser;
	BOOL bUseAsynLogin;
	BYTE byProxyType; //0:不使用代理，1：使用标准代理，2：使用EHome代理
	BYTE byUseUTCTime;    //0-不进行转换，默认,1-接口上输入输出全部使用UTC时间,SDK完成UTC时间与设备时区的转换,2-接口上输入输出全部使用平台本地时间，SDK完成平台本地时间与设备时区的转换
	BYTE byJiaFaEncypt;	//0-默认（基线设备），1-加密类型1（佳发巡查设备），2-加密类型2（佳发平安设备）
	BYTE byRes2;
	LONG iProxyID;    //代理服务器序号，添加代理服务器信息时，相对应的服务器数组下表值    
	BYTE byRes3[120];
}NET_DVR_USER_LOGIN_INFO, *LPNET_DVR_USER_LOGIN_INFO;
typedef struct tagNET_DVR_DEVICEINFO_V40
{
	NET_DVR_DEVICEINFO_V30 struDeviceV30;
	BYTE  bySupportLock;        //设备支持锁定功能，该字段由SDK根据设备返回值来赋值的。bySupportLock为1时，dwSurplusLockTime和byRetryLoginTime有效
	BYTE  byRetryLoginTime;        //剩余可尝试登陆的次数，用户名，密码错误时，此参数有效
	BYTE  byPasswordLevel;      //admin密码安全等级0-无效，1-默认密码，2-有效密码,3-风险较高的密码。当用户的密码为出厂默认密码（12345）或者风险较高的密码时，上层客户端需要提示用户更改密码。      
	BYTE  byProxyType;  //代理类型，0-不使用代理, 1-使用socks5代理, 2-使用EHome代理
	DWORD dwSurplusLockTime;    //剩余时间，单位秒，用户锁定时，此参数有效
	BYTE  byCharEncodeType;     //字符编码类型
	BYTE  bySupportDev5;//支持v50版本的设备参数获取，设备名称和设备类型名称长度扩展为64字节
	BYTE  byRes2[254];
}NET_DVR_DEVICEINFO_V40, *LPNET_DVR_DEVICEINFO_V40;
typedef struct
{
	BYTE byBrightness;      /*亮度,0-255*/
	BYTE byContrast;        /*对比度,0-255*/
	BYTE bySaturation;      /*饱和度,0-255*/
	BYTE byHue;                /*色调,0-255*/
}NET_DVR_COLOR, *LPNET_DVR_COLOR;
//时间段(子结构)
typedef struct
{
	//开始时间
	BYTE byStartHour;
	BYTE byStartMin;
	//结束时间
	BYTE byStopHour;
	BYTE byStopMin;
}NET_DVR_SCHEDTIME, *LPNET_DVR_SCHEDTIME;

typedef struct
{
	NET_DVR_COLOR      struColor[MAX_TIMESEGMENT_V30];/*图象参数(第一个有效，其他三个保留)*/
	NET_DVR_SCHEDTIME  struHandleTime[MAX_TIMESEGMENT_V30];/*处理时间段(保留)*/
}NET_DVR_VICOLOR, *LPNET_DVR_VICOLOR;

//遮挡区域(子结构)
typedef struct
{
	WORD wHideAreaTopLeftX;                /* 遮挡区域的x坐标 */
	WORD wHideAreaTopLeftY;                /* 遮挡区域的y坐标 */
	WORD wHideAreaWidth;                /* 遮挡区域的宽 */
	WORD wHideAreaHeight;                /*遮挡区域的高*/
}NET_DVR_SHELTER, *LPNET_DVR_SHELTER;

typedef struct
{
	DWORD dwEnableVILostAlarm;                /* 是否启动信号丢失报警 ,0-否,1-是*/
											  /* 信号丢失触发报警输出 */
	DWORD   dwHandleType;        //异常处理,异常处理方式的"或"结果   
								 /*0x00: 无响应*/
								 /*0x01: 监视器上警告*/
								 /*0x02: 声音警告*/
								 /*0x04: 上传中心*/
								 /*0x08: 触发报警输出*/
								 /*0x10: 触发JPRG抓图并上传Email*/
								 /*0x20: 无线声光报警器联动*/
								 /*0x40: 联动电子地图(目前只有PCNVR支持)*/
								 /*0x200: 抓图并上传FTP*/
								 /*0x1000:抓图上传到云*/
	DWORD   dwMaxRelAlarmOutChanNum; //触发的报警输出通道数（只读）最大支持数量
	DWORD   dwRelAlarmOut[MAX_ALARMOUT_V40]; /*触发报警输出号，按值表示,采用紧凑型排列，从下标0 - dwRelAlarmOut -1有效，如果中间遇到0xffffffff,则后续无效*/
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*布防时间*/
	BYTE    byVILostAlarmThreshold;    /*信号丢失报警阈值，当值低于阈值，认为信号丢失，取值0-99*/
	BYTE    byRes[63]; //保留
}NET_DVR_VILOST_V40, *LPNET_DVR_VILOST_V40;    //信号丢失报警
typedef struct tagNET_DVR_ETHERNET_IPV6_CFG
{
	DWORD        dwSize;
	BYTE  byState; //IPv6状态，0-路由分配，1-自动设置
	BYTE  byRes1[3];
	BYTE  byIPv6[MAX_IPV6_LEN]; //IPv6地址
	BYTE  byRes[64];      //保留
}NET_DVR_ETHERNET_IPV6_CFG, *LPNET_DVR_ETHERNET_IPV6_CFG;

typedef struct
{
	BYTE byHour;//0~24
	BYTE byMinute;//0~60
	BYTE bySecond;//0~60
	BYTE byRes;
	WORD wMilliSecond; //0~1000
	BYTE byRes1[2];
}NET_DVR_DAYTIME, *LPNET_DVR_DAYTIME;

typedef struct
{
	NET_DVR_DAYTIME  struStartTime; //开始时间
	NET_DVR_DAYTIME  struStopTime; //结束时间
}NET_DVR_SCHEDULE_DAYTIME, *LPNET_DVR_SCHEDULE_DAYTIME;
//区域框结构
typedef struct
{
	BYTE byObjectSize;//占比参数(0~100)
	BYTE byMotionSensitive; /*移动侦测灵敏度, 0 - 5,越高越灵敏,0xff关闭*/
	BYTE byRes[6];
}NET_DVR_DNMODE, *LPNET_DVR_DNMODE;
typedef struct tagNET_VCA_RECT
{
	float fX;               //边界框左上角点的X轴坐标, 0.001~1
	float fY;               //边界框左上角点的Y轴坐标, 0.001~1
	float fWidth;           //边界框的宽度, 0.001~1
	float fHeight;          //边界框的高度, 0.001~1
}NET_VCA_RECT, *LPNET_VCA_RECT;
typedef struct
{
	BYTE byAreaNo;//区域编号(IPC- 1~8)
	BYTE byRes[3];
	NET_VCA_RECT struRect;//单个区域的坐标信息(矩形) size = 16;
	NET_DVR_DNMODE  struDayNightDisable;//关闭模式
	NET_DVR_DNMODE  struDayModeParam;//白天模式
	NET_DVR_DNMODE  struNightModeParam;//夜晚模式
	BYTE byRes1[8];
}NET_DVR_MOTION_MULTI_AREAPARAM, *LPNET_DVR_MOTION_MULTI_AREAPARAM;
typedef struct
{
	BYTE byDayNightCtrl;//日夜控制 0~关闭,1~自动切换,2~定时切换(默认关闭)
	BYTE byAllMotionSensitive; /*移动侦测灵敏度, 0 - 5,越高越灵敏,0xff关闭，全部区域的灵敏度范围*/
	BYTE byRes[2];//
	NET_DVR_SCHEDULE_DAYTIME struScheduleTime;//切换时间  16
	NET_DVR_MOTION_MULTI_AREAPARAM struMotionMultiAreaParam[MAX_MULTI_AREA_NUM];//最大支持24个区域
	BYTE byRes1[60];
}NET_DVR_MOTION_MULTI_AREA, *LPNET_DVR_MOTION_MULTI_AREA; //1328

typedef struct
{
	BYTE byMotionScope[64][96];        /*侦测区域,0-96位,表示64行,共有96*64个小宏块,目前有效的是22*18,为1表示是移动侦测区域,0-表示不是*/
	BYTE byMotionSensitive;            /*移动侦测灵敏度, 0 - 5,越高越灵敏,0xff关闭*/
	BYTE byRes[3];
}NET_DVR_MOTION_SINGLE_AREA, *LPNET_DVR_MOTION_SINGLE_AREA;

typedef struct
{
	NET_DVR_MOTION_SINGLE_AREA  struMotionSingleArea; //普通模式下的单区域设
	NET_DVR_MOTION_MULTI_AREA struMotionMultiArea; //专家模式下的多区域设置    
}NET_DVR_MOTION_MODE_PARAM, *LPNET_DVR_MOTION_MODE_PARAM;
typedef struct
{
	NET_DVR_MOTION_MODE_PARAM  struMotionMode; //(5.1.0新增)
	BYTE byEnableHandleMotion;        /* 是否处理移动侦测 0－否 1－是*/
	BYTE byEnableDisplay;    /*启用移动侦测高亮显示，0-否，1-是*/
	BYTE byConfigurationMode; //0~普通,1~专家(5.1.0新增)
	BYTE byRes1; //保留字节
				 /* 异常处理方式 */
	DWORD   dwHandleType;        //异常处理,异常处理方式的"或"结果   
								 /*0x00: 无响应*/
								 /*0x01: 监视器上警告*/
								 /*0x02: 声音警告*/
								 /*0x04: 上传中心*/
								 /*0x08: 触发报警输出*/
								 /*0x10: 触发JPRG抓图并上传Email*/
								 /*0x20: 无线声光报警器联动*/
								 /*0x40: 联动电子地图(目前只有PCNVR支持)*/
								 /*0x200: 抓图并上传FTP*/
								 /*0x1000: 抓图上传到云*/
	DWORD   dwMaxRelAlarmOutChanNum; //触发的报警输出通道数（只读）最大支持数量
	DWORD   dwRelAlarmOut[MAX_ALARMOUT_V40]; //实际触发的报警输出号，按值表示,采用紧凑型排列，从下标0 - dwRelAlarmOut -1有效，如果中间遇到0xffffffff,则后续无效
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*布防时间*/
																	/*触发的录像通道*/
	DWORD     dwMaxRecordChanNum;   //设备支持的最大关联录像通道数-只读
	DWORD     dwRelRecordChan[MAX_CHANNUM_V40];     /* 实际触发录像通道，按值表示,采用紧凑型排列，从下标0 - dwRelRecordChan -1有效，如果中间遇到0xffffffff,则后续无效*/
	BYTE  byRes[128]; //保留字节
}NET_DVR_MOTION_V40, *LPNET_DVR_MOTION_V40;
typedef struct
{
	DWORD dwEnableHideAlarm;                /* 是否启动遮挡报警，0-否，1-低灵敏度，2-中灵敏度，3-高灵敏度*/
	WORD wHideAlarmAreaTopLeftX;            /* 遮挡区域的x坐标 */
	WORD wHideAlarmAreaTopLeftY;            /* 遮挡区域的y坐标 */
	WORD wHideAlarmAreaWidth;                /* 遮挡区域的宽 */
	WORD wHideAlarmAreaHeight;                /*遮挡区域的高*/
											  /* 信号丢失触发报警输出 */
	DWORD   dwHandleType;        //异常处理,异常处理方式的"或"结果   
								 /*0x00: 无响应*/
								 /*0x01: 监视器上警告*/
								 /*0x02: 声音警告*/
								 /*0x04: 上传中心*/
								 /*0x08: 触发报警输出*/
								 /*0x10: 触发JPRG抓图并上传Email*/
								 /*0x20: 无线声光报警器联动*/
								 /*0x40: 联动电子地图(目前只有PCNVR支持)*/
								 /*0x200: 抓图并上传FTP*/
								 /*0x1000:抓图上传到云*/
	DWORD   dwMaxRelAlarmOutChanNum; //触发的报警输出通道数（只读）最大支持数量
	DWORD   dwRelAlarmOut[MAX_ALARMOUT_V40]; /*触发报警输出号，按值表示,采用紧凑型排列，从下标0 - dwRelAlarmOut -1有效，如果中间遇到0xffffffff,则后续无效*/
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*布防时间*/
	BYTE  byRes[64]; //保留
}NET_DVR_HIDEALARM_V40, *LPNET_DVR_HIDEALARM_V40; //遮挡报警
typedef struct
{
	BYTE byRed;        //RGB颜色三分量中的红色
	BYTE byGreen;    //RGB颜色三分量中的绿色
	BYTE byBlue;    //RGB颜色三分量中的蓝色
	BYTE byRes;        //保留
}NET_DVR_RGB_COLOR, *LPNET_DVR_RGB_COLOR;
typedef struct
{
	DWORD  dwSize;
	BYTE  sChanName[NAME_LEN];
	DWORD  dwVideoFormat;    /* 只读 视频制式 1-NTSC 2-PAL  */
	NET_DVR_VICOLOR struViColor;//    图像参数按时间段设置
								//显示通道名
	DWORD  dwShowChanName; // 预览的图象上是否显示通道名称,0-不显示,1-显示
	WORD    wShowNameTopLeftX;                /* 通道名称显示位置的x坐标 */
	WORD    wShowNameTopLeftY;                /* 通道名称显示位置的y坐标 */
											  //隐私遮挡
	DWORD  dwEnableHide;        /* 是否启动遮挡 ,0-否,1-是*/
	NET_DVR_SHELTER struShelter[MAX_SHELTERNUM];
	//OSD
	DWORD  dwShowOsd;// 预览的图象上是否显示OSD,0-不显示,1-显示
	WORD   wOSDTopLeftX;                /* OSD的x坐标 */
	WORD   wOSDTopLeftY;                /* OSD的y坐标 */
	BYTE    byOSDType;                    /* OSD类型(主要是年月日格式) */
										  /* 0: XXXX-XX-XX 年月日 */
										  /* 1: XX-XX-XXXX 月日年 */
										  /* 2: XXXX年XX月XX日 */
										  /* 3: XX月XX日XXXX年 */
										  /* 4: XX-XX-XXXX 日月年*/
										  /* 5: XX日XX月XXXX年 */
										  /*6: xx/xx/xxxx(月/日/年) */
										  /*7: xxxx/xx/xx(年/月/日) */
										  /*8: xx/xx/xxxx(日/月/年)*/
	BYTE    byDispWeek;                /* 是否显示星期 */
	BYTE    byOSDAttrib;                /* OSD属性:透明，闪烁 */
										/* 0: 不显示OSD */
										/* 1: 透明，闪烁 */
										/* 2: 透明，不闪烁 */
										/* 3: 不透明，闪烁 */
										/* 4: 不透明，不闪烁 */
	BYTE    byHourOSDType;                /* OSD小时制:0-24小时制,1-12小时制 */
	BYTE    byFontSize;      //16*16(中)/8*16(英)，1-32*32(中)/16*32(英)，2-64*64(中)/32*64(英)  3-48*48(中)/24*48(英) 4-24*24(中)/12*24(英) 5-96*96(中)/48*96(英) 6-128*128(中)/64*128(英) 0xff-自适应(adaptive)
	BYTE    byOSDColorType;     //0-默认（黑白）；1-自定义
	BYTE    byAlignment;//对齐方式 0-自适应，1-右对齐, 2-左对齐
	BYTE    byOSDMilliSecondEnable;//视频叠加时间支持毫秒；0~不叠加, 1-叠加
	NET_DVR_VILOST_V40 struVILost;  //视频信号丢失报警（支持组）
	NET_DVR_VILOST_V40 struAULost;  /*音频信号丢失报警（支持组）*/
	NET_DVR_MOTION_V40 struMotion;  //移动侦测报警（支持组）
	NET_DVR_HIDEALARM_V40 struHideAlarm;  //遮挡报警（支持组）
	NET_DVR_RGB_COLOR    struOsdColor;//OSD颜色
	BYTE    byRes[124];
}NET_DVR_PICCFG_V40, *LPNET_DVR_PICCFG_V40;
//待修改的设备网络参数
typedef struct tagSADP_DEV_NET_PARAM
{
	char			szIPv4Address[16];		// IPv4地址
	char			szIPv4SubNetMask[16];	// IPv4子网掩码
	char			szIPv4Gateway[16];		// IPv4网关
	char			szIPv6Address[128];		// IPv6地址
	char			szIPv6Gateway[128];		// IPv6网关
	unsigned short	wPort;					// 设备监听端口
	unsigned char	byIPv6MaskLen;			// IPv6掩码长度
	unsigned char	byDhcpEnable;			// DHCP使能
	unsigned short	wHttpPort;				//HTTP端口
	unsigned char	byRes[126];
}SADP_DEV_NET_PARAM, *LPSADP_DEV_NET_PARAM;
// 初始化参数
typedef struct tagNETSDK_INIT_PARAM
{
	int                 nThreadNum;         // 指定NetSDK常规网络处理线程数, 当值为0时, 使用内部默认值
	BYTE                bReserved[1024];    // 保留字节
}NETSDK_INIT_PARAM, *LPNETSDK_INIT_PARAM;
// 设置登入时的相关参数
typedef struct
{
	int                 nWaittime;                              // 等待超时时间(毫秒为单位),为0默认5000ms
	int                 nConnectTime;                           // 连接超时时间(毫秒为单位),为0默认1500ms
	int                 nConnectTryNum;                         // 连接尝试次数,为0默认1次
	int                 nSubConnectSpaceTime;                   // 子连接之间的等待时间(毫秒为单位),为0默认10ms
	int                 nGetDevInfoTime;                        // 获取设备信息超时时间,为0默认1000ms
	int                 nConnectBufSize;                        // 每个连接接收数据缓冲大小(字节为单位),为0默认250*1024
	int                 nGetConnInfoTime;                       // 获取子连接信息超时时间(毫秒为单位),为0默认1000ms
	int                 nSearchRecordTime;                      // 按时间查询录像文件的超时时间(毫秒为单位),为0默认为3000ms
	int                 nsubDisconnetTime;                      // 检测子链接断线等待时间(毫秒为单位),为0默认为60000ms
	BYTE                byNetType;                              // 网络类型, 0-LAN, 1-WAN
	BYTE                byPlaybackBufSize;                      // 回放数据接收缓冲大小（M为单位）,为0默认为4M
	BYTE                bDetectDisconnTime;                     // 心跳检测断线时间(单位为秒),为0默认为60s,最小时间为2s
	BYTE                bKeepLifeInterval;                      // 心跳包发送间隔(单位为秒),为0默认为10s,最小间隔为2s
	int                 nPicBufSize;                            // 实时图片接收缓冲大小（字节为单位）,为0默认为2*1024*1024
	BYTE                bReserved[4];                           // 保留字段字段
} NET_PARAM;

// 异步搜索设备回调(pDevNetInfo内存由SDK内部申请释放)
typedef void (CALLBACK *fSearchDevicesCB)(DEVICE_NET_INFO_EX *pDevNetInfo, void* pUserData);
typedef void (CALLBACK *fDisConnect)(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);
// 网络连接恢复回调函数原形
typedef void (CALLBACK *fHaveReConnect)(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);
typedef void (CALLBACK *PDEVICE_FIND_CALLBACK)(const SADP_DEVICE_INFO *lpDeviceInfo, void *pUserData);

typedef BOOL (__stdcall *cLIENT_Init)(fDisConnect cbDisConnect, LDWORD dwUser);
typedef void (__stdcall *cLIENT_SetAutoReconnect)(fHaveReConnect cbAutoConnect, LDWORD dwUser);
typedef void (__stdcall *cLIENT_SetConnectTime)(int nWaitTime, int nTryTimes);
typedef LLONG (__stdcall *cLIENT_StartSearchDevices)(fSearchDevicesCB cbSearchDevices, void* pUserData, char* szLocalIp );
typedef BOOL (__stdcall *cLIENT_SearchDevicesByIPs)(DEVICE_IP_SEARCH_INFO* pIpSearchInfo, fSearchDevicesCB cbSearchDevices, LDWORD dwUserData, char* szLocalIp, DWORD dwWaitTime);
typedef BOOL (__stdcall *sADP_Start_V30)(PDEVICE_FIND_CALLBACK pDeviceFindCallBack, int bInstallNPF, void* pUserData);
typedef BOOL (__stdcall *sADP_Stop)(void);
typedef BOOL (__stdcall *sADP_GetDeviceConfig)(const char* sDevSerialNO, unsigned int dwCommand, void* lpInBuffer, unsigned int  dwinBuffSize, void *lpOutBuffer, unsigned int  dwOutBuffSize);
typedef LLONG (__stdcall *cLIENT_LoginEx2)(const char *pchDVRIP, WORD wDVRPort, const char *pchUserName, const char *pchPassword, EM_LOGIN_SPAC_CAP_TYPE emSpecCap, void* pCapParam, LPNET_DEVICEINFO_Ex lpDeviceInfo, int *error);
typedef BOOL  (__stdcall *cLIENT_PacketData)(char* szCommand, LPVOID lpInBuffer, DWORD dwInBufferSize, char* szOutBuffer, DWORD dwOutBufferSize);
typedef BOOL (__stdcall *cLIENT_SetNewDevConfig)(LLONG lLoginID, char* szCommand, int nChannelID, char* szInBuffer, DWORD dwInBufferSize, int *error, int *restart, int waittime);
typedef LONG (__stdcall *nET_DVR_Login_V40)(LPNET_DVR_USER_LOGIN_INFO pLoginInfo, LPNET_DVR_DEVICEINFO_V40 lpDeviceInfo);
typedef BOOL (__stdcall *nET_DVR_Init)();
typedef BOOL (__stdcall *nET_DVR_SetReconnect)(DWORD dwInterval, BOOL bEnableRecon);
typedef BOOL (__stdcall *nET_DVR_GetDVRConfig)(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
typedef BOOL (__stdcall *nET_DVR_SetDVRConfig)(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize);
typedef DWORD (__stdcall *cLIENT_GetLastError)();
typedef BOOL  (__stdcall *cLIENT_GetNewDevConfig)(LLONG lLoginID, char* szCommand, int nChannelID, char* szOutBuffer, DWORD dwOutBufferSize, int *error, int waittime);
typedef BOOL  (__stdcall *cLIENT_ParseData)(char* szCommand, char* szInBuffer, LPVOID lpOutBuffer, DWORD dwOutBufferSize, void* pReserved);
typedef BOOL (__stdcall *cLIENT_ModifyDevice)(DEVICE_NET_INFO_EX   *pDevNetInfo,DWORD dwWaitTime,int *iError,char *szLocalIp,void *reserved);
typedef BOOL (__stdcall *sADP_ModifyDeviceNetParam)(const char* sMAC, const char* sPassword, const SADP_DEV_NET_PARAM* lpNetParam);
typedef BOOL (__stdcall *cLIENT_Logout)(LLONG lLoginID);
typedef BOOL (__stdcall *nET_DVR_Logout)(LONG lUserID);
typedef BOOL (__stdcall *cLIENT_InitEx)(fDisConnect cbDisConnect, LDWORD dwUser, LPNETSDK_INIT_PARAM lpInitParam);
typedef void (__stdcall *cLIENT_SetNetworkParam)(NET_PARAM *pNetParam);
typedef unsigned int(__stdcall *sADP_GetLastError)(void);
typedef BOOL (__stdcall *sADP_ActivateDevice)(const char* sDevSerialNO, const char* sCommand);
typedef DWORD (__stdcall *nET_DVR_GetLastError)();



