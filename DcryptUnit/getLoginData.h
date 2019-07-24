#pragma once
#include <Windows.h>
#include <iostream>
#include <ShlObj_core.h>

#ifndef _CHROME_LOGINDATA_RETURN
#define _CHROME_LOGINDATA_RETURN

//宏定义返回值和标记值
_CHROME_LOGINDATA_RETURN constexpr char* FIND_DATA_FAIL = (char*)"Find failed";//查找文件失败
_CHROME_LOGINDATA_RETURN constexpr char* CHROME = (char*)"CHROME";//标记Chrome
_CHROME_LOGINDATA_RETURN constexpr char* OPERA = (char*)"OPERA";//标记Opera

#endif

#ifndef _CHROME_LOGINDATA_FUNC
#define _CHROME_LOGINDATA_FUNC
//用于查找用户信息文件存储的路径，返回值为路径信息或报错信息
_CHROME_LOGINDATA_FUNC std::string findLoginData(char* name);

#endif