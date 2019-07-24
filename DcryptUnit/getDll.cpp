#include "getDll.h"

using namespace std;

//�洢dll�ļ��ľ��
HMODULE nssLib;

auto LoadStatus = LOAD_FAIL;

//����ȫ�ֺ���
fpNSS_Init NSS_Init;
fpPL_Base64Decode PL_Base64Decode;
fpPK11SDR_Decrypt PK11SDR_Decrypt;
fpPK11_Authenticate PK11_Authenticate;
fpPK11_GetInternalKeySlot PK11_GetInternalKeySlot;
fpPK11_FreeSlot PK11_FreeSlot;
fpNSS_Shutdown NSS_Shutdown;

//���ڻ�ȡdll�ļ���������dll���䷵��ֵΪ������Ϣ
string loadDll() {
	const char nssLibName[] = "nss3.dll";

	string&& temp = getPath();//ͨ��getPath()������ȡ��װ·��
	if (temp == GET_FAIL)return LOAD_FAIL;

	SetCurrentDirectory(temp.c_str());

	nssLib = LoadLibrary(nssLibName);

	if (nssLib == NULL) {
		return LOAD_FAIL;
	}

	return LOAD_SUCCESS;
}

//���ڼ���dll�ļ��еĺ������䷵��ֵΪ������Ϣ
string loadFunc() {
	if (loadDll() == LOAD_FAIL) return LOAD_FAIL;

	NSS_Init = (fpNSS_Init)GetProcAddress(nssLib, "NSS_Init");
	PL_Base64Decode = (fpPL_Base64Decode)GetProcAddress(nssLib, "PL_Base64Decode");
	PK11SDR_Decrypt = (fpPK11SDR_Decrypt)GetProcAddress(nssLib, "PK11SDR_Decrypt");
	PK11_Authenticate = (fpPK11_Authenticate)GetProcAddress(nssLib, "PK11_Authenticate");
	PK11_GetInternalKeySlot = (fpPK11_GetInternalKeySlot)GetProcAddress(nssLib, "PK11_GetInternalKeySlot");
	PK11_FreeSlot = (fpPK11_FreeSlot)GetProcAddress(nssLib, "PK11_FreeSlot");
	NSS_Shutdown = (fpNSS_Shutdown)GetProcAddress(nssLib, "NSS_Shutdown");

	//��ȷ�˳�
	if (NSS_Init != NULL && PL_Base64Decode != NULL && PK11SDR_Decrypt != NULL && PK11_Authenticate != NULL && PK11_GetInternalKeySlot != NULL && PK11_FreeSlot != NULL && NSS_Shutdown != NULL) {
		LoadStatus = LOAD_SUCCESS;
	}
	else {
		//�����˳�
		LoadStatus = LOAD_FAIL;
	}

	return LoadStatus;
}

fpNSS_Init getNSS_Init() {
	if (LoadStatus == LOAD_SUCCESS)return NSS_Init;
	else return NULL;
}

fpPL_Base64Decode getPL_Base64Decode() {
	if (LoadStatus == LOAD_SUCCESS)return PL_Base64Decode;
	else return NULL;
}

fpPK11SDR_Decrypt getPK11SDR_Decrypt() {
	if (LoadStatus == LOAD_SUCCESS)return PK11SDR_Decrypt;
	else return NULL;
}

fpPK11_Authenticate getPK11_Authenticate() {
	if (LoadStatus == LOAD_SUCCESS)return PK11_Authenticate;
	else return NULL;
}

fpPK11_GetInternalKeySlot getPK11_GetInternalKeySlot() {
	if (LoadStatus == LOAD_SUCCESS)return PK11_GetInternalKeySlot;
	else return NULL;
}

fpPK11_FreeSlot getPK11_FreeSlot() {
	if (LoadStatus == LOAD_SUCCESS)return PK11_FreeSlot;
	else return NULL;
}

fpNSS_Shutdown getNSS_Shutdown() {
	if (LoadStatus == LOAD_SUCCESS)return NSS_Shutdown;
	else return NULL;
}