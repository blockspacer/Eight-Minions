#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "networking.h"

#define CONNECTION_SUCCESSFUL 1
#define CONNECTION_FAILURE 0 //generic error
#define SERVER_NOT_FOUND -1

class client
{
private:
	string server_addr;
	unsigned int port;

public:
	void display();
	void processInput();
	int run();
	void setServerAddress(string);
	void setPort(unsigned int);
	int connect();

};
