#pragma once
#include <iostream>
#include <Windows.h>
#include <shlobj_core.h>

/*
此文件内的函数用于获取Firefox的安装目录，账号信息文件
等的位置信息，同时读入加密后的账号信息。
*/

#ifndef _GETFILE_RETURN
#define _GETFILE_RETURN

//宏定义返回值以及特定参数
_GETFILE_RETURN constexpr auto READ_FAIL = "read fail";//打开注册表失败
_GETFILE_RETURN constexpr auto GET_FAIL = "get fail";//读取注册表失败或读取信息失败
_GETFILE_RETURN constexpr auto FIND_FAIL = "find fail";//查找APPDATA目录失败
_GETFILE_RETURN constexpr auto MY_BUFSIZE = 256;//路径缓存空间大小

#endif

#ifndef _GETFILE_FUNC
#define _GETFILE_FUNC

//获取Firefox的当前版本，输入为注册表中Mozilla Firefox的路径，返回值为失败信息或版本信息
_GETFILE_FUNC std::string getCurrentVersion(std::string path);

//获取Firefox的安装路径,返回值为获取失败的标记或安装路径
_GETFILE_FUNC std::string getPath();

//获取Firefox的logins.json的文件路径，其中存储加密后的账号、密码信息，返回值为路径信息或报错信息
_GETFILE_FUNC std::string findLoginInfo();

//获取logins.json里的内容，返回值为文件信息或报错信息
_GETFILE_FUNC std::string getLoginInfo(std::string profilePath);

//getLoginInfo函数的重载
_GETFILE_FUNC std::string getLoginInfo();

#endif