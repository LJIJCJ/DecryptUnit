#pragma once
#include <iostream>
#include <Windows.h>
#include <shlobj_core.h>

/*
���ļ��ڵĺ������ڻ�ȡFirefox�İ�װĿ¼���˺���Ϣ�ļ�
�ȵ�λ����Ϣ��ͬʱ������ܺ���˺���Ϣ��
*/

#ifndef _GETFILE_RETURN
#define _GETFILE_RETURN

//�궨�巵��ֵ�Լ��ض�����
_GETFILE_RETURN constexpr auto READ_FAIL = "read fail";//��ע���ʧ��
_GETFILE_RETURN constexpr auto GET_FAIL = "get fail";//��ȡע���ʧ�ܻ��ȡ��Ϣʧ��
_GETFILE_RETURN constexpr auto FIND_FAIL = "find fail";//����APPDATAĿ¼ʧ��
_GETFILE_RETURN constexpr auto MY_BUFSIZE = 256;//·������ռ��С

#endif

#ifndef _GETFILE_FUNC
#define _GETFILE_FUNC

//��ȡFirefox�ĵ�ǰ�汾������Ϊע�����Mozilla Firefox��·��������ֵΪʧ����Ϣ��汾��Ϣ
_GETFILE_FUNC std::string getCurrentVersion(std::string path);

//��ȡFirefox�İ�װ·��,����ֵΪ��ȡʧ�ܵı�ǻ�װ·��
_GETFILE_FUNC std::string getPath();

//��ȡFirefox��logins.json���ļ�·�������д洢���ܺ���˺š�������Ϣ������ֵΪ·����Ϣ�򱨴���Ϣ
_GETFILE_FUNC std::string findLoginInfo();

//��ȡlogins.json������ݣ�����ֵΪ�ļ���Ϣ�򱨴���Ϣ
_GETFILE_FUNC std::string getLoginInfo(std::string profilePath);

//getLoginInfo����������
_GETFILE_FUNC std::string getLoginInfo();

#endif