#include "Client.h"
#include <iostream>
#include <strstream>
#include <chrono>
#include <thread>
#include <sys/time.h>

std::string currentDateTime() {
	time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	struct tm tstruct;
	char buf[80];
	timeval start;
	
	gettimeofday(&start, NULL);
	strftime(buf, sizeof(buf), "%Y-%m-%d %T", localtime(&now));
	std::string s = buf;
	s += ".";
	int ms = start.tv_usec;
	s += std::to_string(ms/1000);
	return s;
}

int main(int argc, char** argv)
{
	SockClient cli;

   	std::strstream ss;


	if(argc<=3)
	{
		std::cout<<"Исполльзование:\n Client <name> <port> <duration>\n Пример:\n Client Name1 3000 1\n";
		exit(1);
	}

	ss<<argv[1];
	std::string name;
	ss>>name;
	ss.clear();

	ss<<argv[2];
	int port;
	ss>>port;
	ss.clear();

	ss<<argv[3];
	int d;
	ss>>d;

	cli.Connect(name, d,"127.0.0.1",port);
	
	
	while(true)
	{
		std::string logtext = '[' + currentDateTime() +"] " ; 
		logtext += " ";
		logtext += name;
		if(!cli.Send(logtext.c_str()))
			std::cout<<"failed ro send data to server";
		std::chrono::seconds timespan(d);
		std::this_thread::sleep_for(timespan);
	}

	cli.~SockClient();
	return 0;
}
