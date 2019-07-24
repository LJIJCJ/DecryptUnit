#include <sqlite3.h>
#include <stack>
#include "formatChange.h"
#include "chromeDecrypt.h"
#pragma comment(lib,"sqlite3.lib")
#pragma once

#ifndef _DBOPTION_RETURN
#define _DBOPTION_RETURN
//宏定义返回值
_DBOPTION_RETURN constexpr char* CONNECT_FAIL = (char*)"Connect failed";//链接数据库失败
_DBOPTION_RETURN constexpr char* SELECT_SUCCESS = (char*)"Select successful";// 查询成功

#endif

#ifndef _DBOPTION_VALUE
#define _DBOPTION_VALUE

//用户信息存储结构
_DBOPTION_VALUE struct UserDATA {
	const unsigned char* username = NULL;
	string password;
};

#endif

#ifndef _DBOPTION_FUNC
#define _DBOPTION_FUNC
//用于与数据库建立链接，返回值为打开的状态
_DBOPTION_FUNC int Connect2DB(char* name);
//对数据库执行Select操作,返回值为操作结果
_DBOPTION_FUNC std::string Select4DB(char* command);
//上面函数的重载
_DBOPTION_FUNC std::string Select4DB(char* command, char* name);
//获取存储用户信息的堆栈
_DBOPTION_FUNC std::stack<UserDATA> GetUserStack();

#endif