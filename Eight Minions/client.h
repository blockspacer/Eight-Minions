#ifndef CLIENT_H
#define CLIENT_H

#include "resources.h"
#include "creep.h"
#include "tower.h"

#define CONNECTION_SUCCESSFUL 1
#define CONNECTION_FAILURE 0 //generic error
#define SERVER_NOT_FOUND -1

#define BOARD_X_OFFSET 100
#define BOARD_Y_OFFSET 100

class client
{
private:
	string server_addr;
	unsigned int port;
	IPaddress ip;
	TCPsocket sd;
	SDLNet_SocketSet socketset;
	UDPsocket UDPsock;
	UDPpacket *UDPpack;

	SDL_Surface* screen;
	SDL_Surface* background;
	SDL_Event event;

	vector<creep> creeps;

	queue<string> updateQueue;

	creep testc;
	creep testca;

public:
	int init();
	void cleanup();
	void display();
	void displayCreeps();
	void displayTowers();
	void displayMisc();
	void displayUI();
	int run();
	int testrun();
	void setServerAddress(string);
	void setPort(unsigned int);
	int connectToServer();
	int sendToServer(string);
	string recieveMessage();
	string recieveMessageUDP();
	void recieveMessageToQueue();
	int performUpdate(string upd);
	void parseQueue();

	void savePlayerProfile();
	//this function will take any of the players individual stats, experience, purchased upgrades, and any other
	//relevant data, save it to a file, lock it with the players password, and encrypt it so they cant cheat and modify it.
};

#endif