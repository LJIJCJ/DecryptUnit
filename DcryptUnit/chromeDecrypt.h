#include <Windows.h>
#include <iostream>
#pragma comment(lib,"crypt32.lib")
#pragma once

/*
���ļ����ڽ���Chrome��Opera�ĵ�¼��Ϣ
*/

using namespace std;

#ifndef _ChromeDecryptReturn
#define _ChromeDecryptReturn

//�궨�巵��ֵ
_ChromeDecryptReturn constexpr char* DECRYPT_DATA_FAIL = (char*)"Decrypt failed";//����ʧ��
_ChromeDecryptReturn constexpr char* GET_DATA_FAIL = (char*)"Get failed";

#endif //_ChromeDecryptReturn



#ifdef _ChromeDecryptReturn
#define _ChromeDecrypt
//�˺������ڵ���Windows���ڲ���������Ϣ���н��ܣ�����ֵΪ������Ϣ����ܺ����Ϣ
_ChromeDecrypt BYTE* Decrypt(BYTE* enPassword, int len);

//����������ȥ������ʱ���ӵĶ����ַ��ķ������Ƽ��ڶ��֡�
//���ڱ���ȥ�������ַ������µĶ����ַ�ʱ���޸ĺ����塣
_ChromeDecrypt string getPwd(BYTE* enPassword, int len);

//���ڲ��ɼ��ַ�����ȥ������ĵĿ����Բ���
_ChromeDecrypt string _getPwd(BYTE* enPassword, int len);

#endif //_ChromeDecrypt1