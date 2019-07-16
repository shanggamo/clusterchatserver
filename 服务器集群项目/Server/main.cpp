#include <iostream>
using namespace std;

#include "UserDO.h"
#include "UserModelBase.h"
#include "ChatServer.h"

int main()
{
	LOG_INFO << "main pid:" << getpid();
	LOG_INFO << "main tid:" << pthread_self();
	muduo::net::EventLoop loop;
	muduo::net::InetAddress listenAddr(9999);
	ChatServer server(&loop, listenAddr);
	server.start();
	loop.loop();

	/*UserDO user;
	user.name = "zhang san";
	user.password = "123456";
	user.state = "offline";
	UserModel *p = new UserModel();
	p->add(user);

	cout << "user.id:" << user.id << endl;
	*/
    return 0;
}