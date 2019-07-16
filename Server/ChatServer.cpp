#include "ChatServer.h"
#include "SingleService.h"
#include <thread>

/*
��ChatServer���յ������ӻ������ж�ʱ������øûص�����������������Ϣ��װ��
TcpConnection��ͨ���������ݽ���
*/
void ChatServer::onConnection(const muduo::net::TcpConnectionPtr &con)
{
	// muduoʹ��ʾ������
	LOG_INFO << "ChatServer:" << con->peerAddress().toIpPort() << "->"
		<< con->localAddress().toIpPort() << " state:"
		<< (con->connected() ? "UP" : "DOWN");
	LOG_INFO << "onConnection tid:" << pthread_self();
}

/*
��ChatServer�Ѵ������ӽ��յ�������ʱ������øûص��������������ݷ�װ��
Buffer��ͨ���������ݽ���
*/
void ChatServer::onMessage(const muduo::net::TcpConnectionPtr &con,
	muduo::net::Buffer *buf,
	muduo::Timestamp time)
{
	// muduoʹ��ʾ������
	muduo::string msg(buf->retrieveAllAsString());
	LOG_INFO << con->name() << " echo:" << msg.size() << "bytes, "
		<< "data receive at time:" << time.toString();
	con->send(msg);
	LOG_INFO << "onMessage tid:" << pthread_self();

	/*
	��Ӵ��룬��ô��������ƣ�ChatServer::onMessage���յ������ݣ��þ����
	Service������
	*/
}