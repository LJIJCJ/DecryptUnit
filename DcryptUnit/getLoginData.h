#pragma once
#include <Windows.h>
#include <iostream>
#include <ShlObj_core.h>

#ifndef _CHROME_LOGINDATA_RETURN
#define _CHROME_LOGINDATA_RETURN

//�궨�巵��ֵ�ͱ��ֵ
_CHROME_LOGINDATA_RETURN constexpr char* FIND_DATA_FAIL = (char*)"Find failed";//�����ļ�ʧ��
_CHROME_LOGINDATA_RETURN constexpr char* CHROME = (char*)"CHROME";//���Chrome
_CHROME_LOGINDATA_RETURN constexpr char* OPERA = (char*)"OPERA";//���Opera

#endif

#ifndef _CHROME_LOGINDATA_FUNC
#define _CHROME_LOGINDATA_FUNC
//���ڲ����û���Ϣ�ļ��洢��·��������ֵΪ·����Ϣ�򱨴���Ϣ
_CHROME_LOGINDATA_FUNC std::string findLoginData(char* name);

#endif