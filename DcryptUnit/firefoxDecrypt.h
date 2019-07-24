#pragma once
#include "getDll.h"
#include "formatChange.h"
#include <regex>
#include <stack>

#ifndef _FIREFOXDECRYPT_VALUE
#define _FIREFOXDECRYPT_VALUE
/*
此文件用于对读入的加密信息进行解密
*/
//定义用户信息的数据结构
_FIREFOXDECRYPT_VALUE struct UserInfo {
	char* Host;
	char* Username;
	char* Password;
};

#endif


#ifndef _FIREFOX_RETURN
#define _FIREFOX_RETURN

//宏定义返回值
_FIREFOX_RETURN constexpr auto DECRYPT_FAIL = "decrypt fail";//解密失败
_FIREFOX_RETURN constexpr auto DECRYPT_SUCCESS = "decrypt success";//解密成功

#endif

#ifndef _FIREFOX_FUNC
#define _FIREFOX_FUNC

//用于查询加密字符串中特定字符的个数，返回值为字符个数
/*
Firefox对密码进行了两次加密，内部函数加密和base64加密，
并且在加密后的字符串添加0-3个‘=’，此函数用于统计加入
的‘=’的数目。
*/
_FIREFOX_FUNC size_t char_count(const char* str, size_t size, const char ch);

//用于将输入的加密信息解密
_FIREFOX_FUNC unsigned char* decrypt(std::string encryptStr);

//调用解密函数，输出解密后的结果
_FIREFOX_FUNC std::string loginInfoDecrypt();

_FIREFOX_FUNC std::stack<UserInfo> getUserInfo();

#endif