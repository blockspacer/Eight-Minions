#include "client.h"


int client::init()
{
	//Start SDL
	if(SDL_Init( SDL_INIT_EVERYTHING ) == -1)
	{
		cout << "SDL Failed to initialize...\n";
		return -1;
	}

	//Sets window caption
	SDL_WM_SetCaption( "Eight Minions", NULL );
	//create screen, params are width in pixels, height in pixels, bpp, and flags
	screen = SDL_SetVideoMode(840,550,32,SDL_SWSURFACE);
	this->background = IMG_Load("background.png");
	
	socketset = SDLNet_AllocSocketSet(1);
	SDLNet_TCP_AddSocket(socketset, this->sd);
	creep n(1,1,20,20);
	this->testc = n;
	creep q(2,1,200,200);
	this->testca = q;
	return 1;
}

void client::cleanup()
{
	//do all freeing of memory and cleanup type stuff here
	SDL_free(background);
	SDL_Quit();
}
void client::display()
{
	//put down background image
	SDL_BlitSurface(background, NULL, screen, NULL);
	this->testc.displayCreep(screen);
	this->testca.displayCreep(screen);
	SDL_Flip(screen);
}

int client::run()
{
	if(this->init() == -1)
	{
		cout << "Function Init failed to complete.\n";
		return -1;
	}
	//main run loop
	int cx = 1;
	int cy = 1;
	int run = 1;
	while(run)
	{
		//gather input
		
		while(SDLNet_CheckSockets(socketset, 1) > 0)
		{
			cout << "socket has data, attempting to read\n";
			if(SDLNet_SocketReady(sd))
			{
				this->performUpdate(this->recieveMessage());
			}
		}
		cout << this->recieveMessage() << "\n";
		this->display();

		if(this->testca.getX() > 400)
			cx = -1;
		if(this->testca.getX() < 120)
			cx = 1;
		if(this->testca.getY() > 450)
			cy = -1;
		if(this->testca.getY() < 80)
			cy = 1;
		this->testca.setX(testca.getX() + cx);
		this->testca.setY(testca.getY() + cy);
		
		//temp
		
		
		//end temp
		SDL_Delay(20);
	}

	this->cleanup();
	return 0;
}

void client::setServerAddress(string address)
{
	//Last Changed: 3-2-12 @ 5:15
	//changelog:
	//made function set address
	//todo:
	//error checking, ensure input is valid

	this->server_addr = address;
}

void client::setPort(unsigned int setPort)
{
	//Last Changed: 3-5-12 @ 12:13
	//changelog:
	//made function set port
	//validated the input
	//added confirmation
	//todo:
	//
	if(setPort > 65535)
	{
		cout << "INVALID PORT!\n";
		system("pause");
		exit(1);
	}else
	{
		this->port = setPort;
		cout << "Port Set!\n";
	}
}

int client::connectToServer()
{
	if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	if (SDLNet_ResolveHost(&ip, this->server_addr.c_str(), this->port) < 0)
	{
		fprintf(stderr, "SDLNet_ResolveHost: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	if (!(sd = SDLNet_TCP_Open(&ip)))
	{
		fprintf(stderr, "SDLNet_TCP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}


	/* test sending something to the server */
	string buff = "Client Connected!";
	SDLNet_TCP_Send(sd, (void *)buff.c_str(), buff.length()+1);

	//should create connection to given address on given port
	//class needs to keep track of the socket and have dedicated function to read from it

	return 1;
}

int client::sendToServer(string buff)
{
	if(!this->sd)
	{
		cout << "No Connection!\n";
		return -1;
	}
	else
	{
		if(SDLNet_TCP_Send(sd, (void *)buff.c_str(), buff.length()+1) < buff.length() + 1)
		{
			cout << "Message to server failed to send...\n";
			return -1;
		}
	}
	return 1;
}

int client::performUpdate(string upd)
{

	//temporary testing code starts here;
	if(upd[5] == '1')
	{
		int x = (1000 * (upd[6] - '0')) + (100 * (upd[7] - '0')) + (10 * (upd[8] - '0')) + (upd[9] - '0');
		this->testc.setX(x);
		cout << "X value changed to: " << x << "\n";
	}
	if(upd[5] == '2')
	{
		int y = (1000 * (upd[6] - '0')) + (100 * (upd[7] - '0')) + (10 * (upd[8] - '0')) + (upd[9] - '0');
		this->testc.setY(y);
		cout << "Y value changed to: " << y << "\n";
	}

	return 0;
}

string client::recieveMessage()
{
	char buff[512];
	while(!SDLNet_TCP_Recv(this->sd, buff, 16 /*512*/));
	//cout << buff << "\n";
	string ret = buff;
	return buff;
}

void client::recieveMessageToQueue()
{

}