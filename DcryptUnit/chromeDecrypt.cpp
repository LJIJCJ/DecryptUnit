#include "chromeDecrypt.h"

//此函数用于调用Windows的内部函数对信息进行解密，返回值为报错信息或解密后的信息
BYTE* Decrypt(BYTE* enPassword, int len) {
	DATA_BLOB temp, out;
	temp.pbData = enPassword;
	temp.cbData = len;
	if (CryptUnprotectData(&temp, NULL, NULL, NULL, NULL, 0, &out)) {

		return out.pbData;
	}
	else {
		return (BYTE*)DECRYPT_DATA_FAIL;
	}
}

//下面是两种去除加密时增加的多余字符的方法，推荐第二种。
//用于暴力去除多余字符，有新的多余字符时需修改函数体。
string getPwd(BYTE* enPassword, int len) {
	string DecryptPassword;
	BYTE* temp = Decrypt(enPassword, len);
	if (temp != NULL) {
		DecryptPassword = (char*)temp;
		string::size_type n0 = DecryptPassword.find('\x1', 0);
		string::size_type n1 = min(n0, DecryptPassword.find('\x2', 0));
		string::size_type n2 = min(n1, DecryptPassword.find('\x3', 0));
		string::size_type n3 = min(n2, DecryptPassword.find('\x4', 0));
		string::size_type n4 = min(n3, DecryptPassword.find('\x5', 0));
		string::size_type n5 = min(n4, DecryptPassword.find('\x6', 0));
		string::size_type n6 = min(n5, DecryptPassword.find('\x7', 0));
		string::size_type n7 = min(n6, DecryptPassword.find('\x8', 0));
		string::size_type n8 = min(n7, DecryptPassword.find('\x9', 0));
		string::size_type n9 = min(n8, DecryptPassword.find('\a', 0));
		string::size_type n = min(n9, DecryptPassword.find('\b', 0));
		return DecryptPassword.substr(0, n);
	}
	else {
		return GET_DATA_FAIL;
	}

}

//基于不可见字符进行去除，需改的可能性不高
string _getPwd(BYTE* enPassword, int len) {
	string DecryptPassword;
	BYTE* temp = Decrypt(enPassword, len);
	if (temp != NULL) {
		DecryptPassword = (char*)temp;
		int length = DecryptPassword.size();
		int flag = 0;

		for (int i = 0; i < length; i++) {
			if (DecryptPassword[i] > 31 && DecryptPassword[i] < 127) {
				continue;
			}
			else {
				flag = i;
				break;
			}

		}
		return DecryptPassword.substr(0, flag);
	}
	return GET_DATA_FAIL;
}