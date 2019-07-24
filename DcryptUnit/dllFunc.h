#pragma once

#ifndef _GETDLL_STRUCT
#define _GETDLL_STRUCT

//声明枚举类型及其内容	
_GETDLL_STRUCT typedef enum {
	siBuffer = 0,
	siClearDataBuffer = 1,
	siCipherDataBuffer = 2,
	siDERCertBuffer = 3,
	siEncodedCertBuffer = 4,
	siDERNameBuffer = 5,
	siEncodedNameBuffer = 6,
	siAsciiNameString = 7,
	siAsciiString = 8,
	siDEROID = 9,
	siUnsignedInteger = 10,
	siUTCTime = 11,
	siGeneralizedTime = 12,
	siVisibleString = 13,
	siUTF8String = 14,
	siBMPString = 15
} SECItemType;

//声明结构体及其别名
_GETDLL_STRUCT typedef struct SECItemStr SECItem;
//定义结构体内容
_GETDLL_STRUCT struct SECItemStr {
	SECItemType type;
	unsigned char* data;
	size_t len;
};

//声明枚举及定义
_GETDLL_STRUCT typedef enum _SECStatus {
	SECWouldBlock = -2,
	SECFailure = -1,
	SECSuccess = 0
} SECStatus;

//数据类型别名
_GETDLL_STRUCT typedef unsigned int PRUint32;//For PL_Base64Decode
_GETDLL_STRUCT typedef void PK11SlotInfo; // For PK11_Authenticate
_GETDLL_STRUCT typedef int PRBool; // For PK11_Authenticate


//声明动态函数
_GETDLL_STRUCT typedef SECStatus(*fpNSS_Init)(const char* configdir);
_GETDLL_STRUCT typedef char* (*fpPL_Base64Decode)(const char* src, PRUint32 srclen, char* dest);
_GETDLL_STRUCT typedef SECStatus(*fpPK11SDR_Decrypt)(SECItem* data, SECItem* result, void* cx);
_GETDLL_STRUCT typedef SECStatus(*fpPK11_Authenticate)(PK11SlotInfo* slot, PRBool loadCerts, void* wincx);
_GETDLL_STRUCT typedef PK11SlotInfo* (*fpPK11_GetInternalKeySlot)();
_GETDLL_STRUCT typedef void (*fpPK11_FreeSlot)(PK11SlotInfo* slot);
_GETDLL_STRUCT typedef SECStatus(*fpNSS_Shutdown)();

#endif