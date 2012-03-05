#ifndef RESOURCES_H
#define RESOURCES_H

#include <iostream>
#include <string>
#include <list>
#include <queue>
#include "SDL.h"
#include "SDL_net.h"
#include "SDL_image.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;
using std::list;

class location
{
private:
	int x;
	int y;
public:
	location();
	int getX();
	int getY();
	void setX(int new_x);
	void setY(int new_y);
};


#endif