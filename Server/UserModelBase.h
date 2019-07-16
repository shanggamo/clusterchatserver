#pragma once

#include "UserDO.h"
#include "MySQL.h"

// Model层的抽象类
class UserModelBase
{
public:
	// 增加用户
	virtual bool add(UserDO &user) = 0;
};

// User表的Model层操作，给上层业务提供DO数据表示
class UserModel : public UserModelBase
{
public:
	// 重写add接口方法，实现增加用户操作
	bool add(UserDO &user)
	{
		// 组织sql语句
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
				// 插入新行以后，返回新插入用户的id（MySQL自动生成的记录主键）
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