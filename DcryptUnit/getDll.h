#pragma once
#include "getFileInfo.h"
#include "dllFunc.h"
/*
���ļ����ڼ��ؽ�������������ļ���nss3.dll��
�Լ����ڲ��ĺ�����
*/

#ifndef _GETDLL_RETURN
#define _GETDLL_RETURN

//�궨�巵��ֵ
_GETDLL_RETURN constexpr auto LOAD_FAIL = "load fail";//����dll�ļ�����ʧ��
_GETDLL_RETURN constexpr auto LOAD_SUCCESS = "load success";//����dll�ļ������ɹ�

#endif

#ifndef _GETDLL_FUNC
#define _GETDLL_FUNC

//���ڻ�ȡdll�ļ���������dll���䷵��ֵΪ������Ϣ
_GETDLL_FUNC std::string loadDll();

//���ڼ���dll�ļ��еĺ������䷵��ֵΪ������Ϣ
_GETDLL_FUNC std::string loadFunc();

_GETDLL_FUNC fpNSS_Init getNSS_Init();

_GETDLL_FUNC fpPL_Base64Decode getPL_Base64Decode();

_GETDLL_FUNC fpPK11SDR_Decrypt getPK11SDR_Decrypt();

_GETDLL_FUNC fpPK11_Authenticate getPK11_Authenticate();

_GETDLL_FUNC fpPK11_GetInternalKeySlot getPK11_GetInternalKeySlot();

_GETDLL_FUNC fpPK11_FreeSlot getPK11_FreeSlot();

_GETDLL_FUNC fpNSS_Shutdown getNSS_Shutdown();


#endif