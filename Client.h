#pragma once
#include <netinet/in.h>
#include <string>

class SockClient
{
private:
	sockaddr_in addr;
	int sock = -1;

public:
	std::string Recvest();
	~SockClient();

	bool Connect(std::string name,int duration,const char* ip,int port);	
	bool Send(std::string Text);

};


