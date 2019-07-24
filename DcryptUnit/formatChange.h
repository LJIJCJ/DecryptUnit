#pragma once
#include <iostream>
#include <Windows.h>

/*
此文件用于个格式转换，将UTF-8转换为gbk编码，以防止中文乱码
*/
#ifndef _FORMATCHANGE_FUNC
#define _FORMATCHANGE_FUNC

_FORMATCHANGE_FUNC char* U2G(const char* utf8);

#endif