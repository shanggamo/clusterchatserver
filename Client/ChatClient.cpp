#include "ChatClient.h"

// TcpClient�󶨻ص������������ӻ��߶Ͽ�������ʱ����
void ChatClient::onConnection(const muduo::net::TcpConnectionPtr &con)
{
	/*
	���ӷ������ɹ��󣬿����ͷ������Ľ���ͨ�Ź���
	*/
}

// TcpClient�󶨻ص��������������ݽ���ʱ����
void ChatClient::onMessage(const muduo::net::TcpConnectionPtr &con,
	muduo::net::Buffer *buf,
	muduo::Timestamp time)
{
	/*
	������շ�������Ӧ����Ϣ���ڿͻ��˽�����ʾ
	*/
}