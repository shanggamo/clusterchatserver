#pragma once

#include <muduo/net/TcpClient.h>
#include <muduo/net/EventLoop.h>
#include <muduo/base/Logging.h>
#include <boost/bind.hpp>
/*
�ͻ���ʵ�֣�����C++ muduo�����
*/
class ChatClient
{
public:
	ChatClient(muduo::net::EventLoop *loop,
		const muduo::net::InetAddress &addr)
		:_client(loop, addr, "ChatClient")
	{
		// ���ÿͻ���TCP���ӻص��ӿ�
		_client.setConnectionCallback(bind(&ChatClient::onConnection,
			this, _1));

		// ���ÿͻ��˽������ݻص��ӿ�
		_client.setMessageCallback(bind(&ChatClient::onMessage,
			this, _1, _2, _3));
	}
	// ���ӷ�����
	void connect()
	{
		_client.connect();
	}
private:
	// TcpClient�󶨻ص������������ӻ��߶Ͽ�������ʱ����
	void onConnection(const muduo::net::TcpConnectionPtr &con);
	// TcpClient�󶨻ص��������������ݽ���ʱ����
	void onMessage(const muduo::net::TcpConnectionPtr &con,
		muduo::net::Buffer *buf,
		muduo::Timestamp time);

	muduo::net::TcpClient _client;
};