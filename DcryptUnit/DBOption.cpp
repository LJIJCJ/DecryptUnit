#include "DBOption.h"

using namespace std;

UserDATA temp;
static stack<UserDATA> DataStack;

static sqlite3* db = NULL;
static sqlite3_stmt* stmt = NULL;

//���������ݿ⽨�����ӣ�����ֵΪ�򿪵�״̬
int Connect2DB(char* name) {
	for (; !DataStack.empty();) {
		DataStack.pop();
	}
	return sqlite3_open(name, &db);
}

//�����ݿ�ִ��Select����,����ֵΪ�������
string Select4DB(char* command) {
	sqlite3_prepare(db, command, -1, &stmt, NULL);

	for (; sqlite3_step(stmt) == SQLITE_ROW;) {
		temp.username = (BYTE*)U2G((char*)sqlite3_column_text(stmt, 0));
		temp.password = _getPwd((BYTE*)sqlite3_column_text(stmt, 1), sqlite3_column_bytes(stmt, 1) + 1);
		DataStack.push(temp);

	}
	sqlite3_close(db);
	return SELECT_SUCCESS;

}

//���溯��������
string Select4DB(char* command, char* name) {
	int temp = Connect2DB(name);
	if (temp == SQLITE_OK) {
		return Select4DB(command);
	}
	else {
		return CONNECT_FAIL;
	}
}

//��ȡ�洢�û���Ϣ�Ķ�ջ
stack<UserDATA> GetUserStack() {
	return DataStack;
}