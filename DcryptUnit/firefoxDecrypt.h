#pragma once
#include "getDll.h"
#include "formatChange.h"
#include <regex>
#include <stack>

#ifndef _FIREFOXDECRYPT_VALUE
#define _FIREFOXDECRYPT_VALUE
/*
���ļ����ڶԶ���ļ�����Ϣ���н���
*/
//�����û���Ϣ�����ݽṹ
_FIREFOXDECRYPT_VALUE struct UserInfo {
	char* Host;
	char* Username;
	char* Password;
};

#endif


#ifndef _FIREFOX_RETURN
#define _FIREFOX_RETURN

//�궨�巵��ֵ
_FIREFOX_RETURN constexpr auto DECRYPT_FAIL = "decrypt fail";//����ʧ��
_FIREFOX_RETURN constexpr auto DECRYPT_SUCCESS = "decrypt success";//���ܳɹ�

#endif

#ifndef _FIREFOX_FUNC
#define _FIREFOX_FUNC

//���ڲ�ѯ�����ַ������ض��ַ��ĸ���������ֵΪ�ַ�����
/*
Firefox��������������μ��ܣ��ڲ��������ܺ�base64���ܣ�
�����ڼ��ܺ���ַ������0-3����=�����˺�������ͳ�Ƽ���
�ġ�=������Ŀ��
*/
_FIREFOX_FUNC size_t char_count(const char* str, size_t size, const char ch);

//���ڽ�����ļ�����Ϣ����
_FIREFOX_FUNC unsigned char* decrypt(std::string encryptStr);

//���ý��ܺ�����������ܺ�Ľ��
_FIREFOX_FUNC std::string loginInfoDecrypt();

_FIREFOX_FUNC std::stack<UserInfo> getUserInfo();

#endif