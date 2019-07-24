#include <sqlite3.h>
#include <stack>
#include "formatChange.h"
#include "chromeDecrypt.h"
#pragma comment(lib,"sqlite3.lib")
#pragma once

#ifndef _DBOPTION_RETURN
#define _DBOPTION_RETURN
//�궨�巵��ֵ
_DBOPTION_RETURN constexpr char* CONNECT_FAIL = (char*)"Connect failed";//�������ݿ�ʧ��
_DBOPTION_RETURN constexpr char* SELECT_SUCCESS = (char*)"Select successful";// ��ѯ�ɹ�

#endif

#ifndef _DBOPTION_VALUE
#define _DBOPTION_VALUE

//�û���Ϣ�洢�ṹ
_DBOPTION_VALUE struct UserDATA {
	const unsigned char* username = NULL;
	string password;
};

#endif

#ifndef _DBOPTION_FUNC
#define _DBOPTION_FUNC
//���������ݿ⽨�����ӣ�����ֵΪ�򿪵�״̬
_DBOPTION_FUNC int Connect2DB(char* name);
//�����ݿ�ִ��Select����,����ֵΪ�������
_DBOPTION_FUNC std::string Select4DB(char* command);
//���溯��������
_DBOPTION_FUNC std::string Select4DB(char* command, char* name);
//��ȡ�洢�û���Ϣ�Ķ�ջ
_DBOPTION_FUNC std::stack<UserDATA> GetUserStack();

#endif