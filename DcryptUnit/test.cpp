#include "test.h"

int main()
{
	int choice = 0;

	while (true) {
		cout << "��ѡ����ܳ���" << endl;
		cout << "0.�˳�" << endl;
		cout << "1.Firefox" << endl;
		cout << "2.Chrome" << endl;
		cout << "3.Opera" << endl;
		cout << "********************************************************" << endl;
		cin >> choice;

		switch (choice) {
		case 0:
			return 0;
			break;
		case 1:
			cout << firefoxDecrypt() << endl;
			break;
		case 2:
			cout << chromeDecrypt() << endl;
			break;
		case 3:
			cout << operaDecrypt() << endl;
			break;
		default:
			cout << "��������ȷѡ�����" << endl;
			break;
		}
	}
	

	return 0;
}
//���ڻ�ȡFirefox�Ľ�����Ϣ
string firefoxDecrypt() {
	stack<UserInfo> UserStack;
	cout << "firefox:" << endl;
	if (loginInfoDecrypt() == DECRYPT_FAIL) {
		cout << DECRYPT_FAIL << endl;
		return "FAIL";
	}

	UserStack = getUserInfo();

	for (; UserStack.size() > 0;) {
		cout << "Host:\t\t" << UserStack.top().Host << endl;
		cout << "Username:\t" << UserStack.top().Username << endl;
		cout << "Password:\t" << UserStack.top().Password << endl;
		cout << "================================================" << endl;
		UserStack.pop();
	}

	return "SUCCESS";
}
//���ڻ�ȡChrome�Ľ�����Ϣ
string chromeDecrypt() {
	stack<UserDATA> DataStack;
	cout << "Chrome:" << endl;
	string LoginDataPathChrome{ findLoginData(CHROME) };
	if (LoginDataPathChrome == FIND_DATA_FAIL)return "FAIL";
	if (Select4DB((char*)"select username_value,password_value from logins", (char*)LoginDataPathChrome.c_str()) == CONNECT_FAIL)return "FAIL";

	DataStack = GetUserStack();

	for (; DataStack.size() > 0;) {
		cout << "Username:\t" << DataStack.top().username << endl;
		cout << "Password:\t" << DataStack.top().password << endl;
		cout << "================================================" << endl;
		DataStack.pop();
	}

	return "SUCCESS";
}
//���ڻ�ȡOpera�Ľ�����Ϣ
string operaDecrypt() {
	stack<UserDATA> DataStack;
	cout << "Opera:" << endl;
	string LoginDataPathOpera{ findLoginData(OPERA) };
	if (LoginDataPathOpera == FIND_DATA_FAIL)return "FAIL";
	if (Select4DB((char*)"select username_value,password_value from logins", (char*)LoginDataPathOpera.c_str()) == CONNECT_FAIL)return "FAIL";

	DataStack = GetUserStack();

	for (; DataStack.size() > 0;) {
		cout << "Username:\t" << DataStack.top().username << endl;
		cout << "Password:\t" << DataStack.top().password << endl;
		cout << "================================================" << endl;
		DataStack.pop();
	}

	return "SUCCESS";
}