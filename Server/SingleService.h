#pragma once
#include "CommonServiceBase.h"

// ����������ҵ��ʵ��
class SingleService : public CommonServiceBase
{
public:
	static SingleService& getInstance()
	{
		static SingleService instance;
		return instance;
	}
	SingleService(const SingleService&) = delete;
	SingleService& operator=(const SingleService&) = delete;

	// login service
	virtual void login(const muduo::net::TcpConnectionPtr &con,
		json &json, muduo::Timestamp time)
	{
		LOG_INFO << "call SingleService::login!!!!!";
	}

	// register service
	virtual void reg(const muduo::net::TcpConnectionPtr &con,
		json &json, muduo::Timestamp time)
	{}

	// add friend service
	virtual void addFriend(const muduo::net::TcpConnectionPtr &con,
		json &json, muduo::Timestamp time)
	{}

	// one to one chat service
	virtual void oneChat(const muduo::net::TcpConnectionPtr &con,
		json &json, muduo::Timestamp time)
	{}

	// broadcast chat service
	virtual void broadChat(const muduo::net::TcpConnectionPtr &con,
		json &json, muduo::Timestamp time)
	{}
private:
	SingleService() {}
};

// ȫ�ֽӿڣ�����SingleService�����Ψһʵ��
static SingleService& App()
{
	return SingleService::getInstance();
}