#pragma once

#include <string>
using namespace std;

// User表的领域模型类
class UserDO
{
public:
	int id;
	string name;
	string password;
	string state;
};
