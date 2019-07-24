#pragma once
#include "getFileInfo.h"
#include "dllFunc.h"
/*
此文件用于加载解密所需的依赖文件：nss3.dll，
以及其内部的函数。
*/

#ifndef _GETDLL_RETURN
#define _GETDLL_RETURN

//宏定义返回值
_GETDLL_RETURN constexpr auto LOAD_FAIL = "load fail";//加载dll文件或函数失败
_GETDLL_RETURN constexpr auto LOAD_SUCCESS = "load success";//加载dll文件或函数成功

#endif

#ifndef _GETDLL_FUNC
#define _GETDLL_FUNC

//用于获取dll文件，并加载dll，其返回值为报错信息
_GETDLL_FUNC std::string loadDll();

//用于加载dll文件中的函数，其返回值为报错信息
_GETDLL_FUNC std::string loadFunc();

_GETDLL_FUNC fpNSS_Init getNSS_Init();

_GETDLL_FUNC fpPL_Base64Decode getPL_Base64Decode();

_GETDLL_FUNC fpPK11SDR_Decrypt getPK11SDR_Decrypt();

_GETDLL_FUNC fpPK11_Authenticate getPK11_Authenticate();

_GETDLL_FUNC fpPK11_GetInternalKeySlot getPK11_GetInternalKeySlot();

_GETDLL_FUNC fpPK11_FreeSlot getPK11_FreeSlot();

_GETDLL_FUNC fpNSS_Shutdown getNSS_Shutdown();


#endif