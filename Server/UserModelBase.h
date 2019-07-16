#pragma once

#include "UserDO.h"
#include "MySQL.h"

// Model��ĳ�����
class UserModelBase
{
public:
	// �����û�
	virtual bool add(UserDO &user) = 0;
};

// User���Model����������ϲ�ҵ���ṩDO���ݱ�ʾ
class UserModel : public UserModelBase
{
public:
	// ��дadd�ӿڷ�����ʵ�������û�����
	bool add(UserDO &user)
	{
		// ��֯sql���
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,password,state) values('%s', '%s', '%s')", 
			user.name.c_str(), 
			user.password.c_str(), 
			user.state.c_str());
		
		MySQL mysql;
		if (mysql.connect())
		{
			if (mysql.update(sql))
			{
				// ���������Ժ󣬷����²����û���id��MySQL�Զ����ɵļ�¼������
				MYSQL_RES *res = mysql.query("select last_insert_id()");
				if (res != nullptr)
				{
					MYSQL_ROW row = mysql_fetch_row(res);
					user.id = atoi(row[0]);
					mysql_free_result(res);
					return true;
				}
			}
		}
		return false;
	}
};