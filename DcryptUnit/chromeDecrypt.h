#include <Windows.h>
#include <iostream>
#pragma comment(lib,"crypt32.lib")
#pragma once

/*
此文件用于解密Chrome和Opera的登录信息
*/

using namespace std;

#ifndef _ChromeDecryptReturn
#define _ChromeDecryptReturn

//宏定义返回值
_ChromeDecryptReturn constexpr char* DECRYPT_DATA_FAIL = (char*)"Decrypt failed";//解密失败
_ChromeDecryptReturn constexpr char* GET_DATA_FAIL = (char*)"Get failed";

#endif //_ChromeDecryptReturn



#ifdef _ChromeDecryptReturn
#define _ChromeDecrypt
//此函数用于调用Windows的内部函数对信息进行解密，返回值为报错信息或解密后的信息
_ChromeDecrypt BYTE* Decrypt(BYTE* enPassword, int len);

//下面是两种去除加密时增加的多余字符的方法，推荐第二种。
//用于暴力去除多余字符，有新的多余字符时需修改函数体。
_ChromeDecrypt string getPwd(BYTE* enPassword, int len);

//基于不可见字符进行去除，需改的可能性不高
_ChromeDecrypt string _getPwd(BYTE* enPassword, int len);

#endif //_ChromeDecrypt1