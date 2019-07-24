#pragma once

#ifndef _GETDLL_STRUCT
#define _GETDLL_STRUCT

//����ö�����ͼ�������	
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

//�����ṹ�弰�����
_GETDLL_STRUCT typedef struct SECItemStr SECItem;
//����ṹ������
_GETDLL_STRUCT struct SECItemStr {
	SECItemType type;
	unsigned char* data;
	size_t len;
};

//����ö�ټ�����
_GETDLL_STRUCT typedef enum _SECStatus {
	SECWouldBlock = -2,
	SECFailure = -1,
	SECSuccess = 0
} SECStatus;

//�������ͱ���
_GETDLL_STRUCT typedef unsigned int PRUint32;//For PL_Base64Decode
_GETDLL_STRUCT typedef void PK11SlotInfo; // For PK11_Authenticate
_GETDLL_STRUCT typedef int PRBool; // For PK11_Authenticate


//������̬����
_GETDLL_STRUCT typedef SECStatus(*fpNSS_Init)(const char* configdir);
_GETDLL_STRUCT typedef char* (*fpPL_Base64Decode)(const char* src, PRUint32 srclen, char* dest);
_GETDLL_STRUCT typedef SECStatus(*fpPK11SDR_Decrypt)(SECItem* data, SECItem* result, void* cx);
_GETDLL_STRUCT typedef SECStatus(*fpPK11_Authenticate)(PK11SlotInfo* slot, PRBool loadCerts, void* wincx);
_GETDLL_STRUCT typedef PK11SlotInfo* (*fpPK11_GetInternalKeySlot)();
_GETDLL_STRUCT typedef void (*fpPK11_FreeSlot)(PK11SlotInfo* slot);
_GETDLL_STRUCT typedef SECStatus(*fpNSS_Shutdown)();

#endif