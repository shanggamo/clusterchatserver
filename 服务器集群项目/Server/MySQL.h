#pragma once

#include <mysql.h>
#include <string>
using namespace std;

// ���ݿ�������Ϣ
string server = "127.0.0.1";
string user = "root";
string password = "123456";
string dbname = "chat";

// ���ݿ������
class MySQL
{
public:
	// ��ʼ�����ݿ�����
	MySQL()
	{
		_conn = mysql_init(nullptr);
	}
	// �ͷ����ݿ�������Դ
	~MySQL()
	{
		if (_conn != nullptr)
			mysql_close(_conn);
	}
	// �������ݿ�
	bool connect()
	{
		 MYSQL *p = mysql_real_connect(_conn, server.c_str(), user.c_str(),
			password.c_str(), dbname.c_str(), 3306, nullptr, 0);
		 if (p != nullptr)
		 {
			 mysql_query(_conn, "set names gbk");
		 }
		 return p;
	}
	// ���²���
	bool update(string sql)
	{
		if (mysql_query(_conn, sql.c_str()))
		{
			cout << __FILE__ << ":" << __LINE__ << ":"
				<< sql << "����ʧ��!" << endl;
			return false;
		}
		return true;
	}
	// ��ѯ����
	MYSQL_RES* query(string sql)
	{
		if (mysql_query(_conn, sql.c_str()))
		{
			cout << __FILE__ << ":" << __LINE__ << ":"
				<< sql << "��ѯʧ��!" << endl;
			return nullptr;
		}
		return mysql_use_result(_conn);
	}
private:
	MYSQL *_conn;
};