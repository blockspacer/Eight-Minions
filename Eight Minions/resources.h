#ifndef RESOURCES_H
#define RESOURCES_H

#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <cmath>
#include <cstdarg>
#include <vector>

#include "SDL.h"
#include "SDL_net.h"
#include "SDL_image.h"
#include "c_list.h"
#include "UpdMess.h"
#include "path.h"

//to calculate total number of lines, press ctrl + shift + f and search .cpp and .h files for the regular expression ^:b*[^:b#/]+.*$

#define TCP_NODELAY 1 // THIS LINE FIXES SLOWNESS!!!!

//Standard UpdMess Definitions
#define CREEP 0				// For an update on a creep
#define NEWCREEP 1			// For a new creep
#define PLAYERUPDATE 2		// For an update to the player
#define PURCHASEREQUEST 3	//from the client to the server, request to purchase something
#define TOWER 4				// For anything to do with a tower

// Tower UpdMess Definitions
#define TOWERCREATION 0
#define TOWERATTACK 1
#define TOWERPLACE 2
#define TOWERUPGRADE 3
#define TOWERCHANGE 4
#define TOWERTOGGLE 5
#define TOWERDELETE 6
#define TOWERSTRATEGY 7

//Creep type definitions
#define NUM_CREEPS 6 //the total number of creeps
#define NORM 0  // average everything
#define FAST 1  // low armor, low health, high speed, and medium numbers
#define TANK 2  // high armor, medium health, low speed, low numbers
#define SWARM 3 // low armor, low health, average speed, high numbers
#define TITAN 4 // high armor, high health, average speed, very low numbers
#define FATTY 5 // low armor, high health, low speed, medium numbers (could probably come up with a better name)

// Tower Type Constants
#define NUM_TOWERS 12
// Structure 
#define STRUCTURE 0
//
#define STRUCTURESTARTLEVEL 1
//*******Attack Towers*******
#define NORMTOWER 1
#define FASTTOWER 2
#define AOETOWER 3
#define HEAVYTOWER 4
#define MINETOWER 5
//
#define STANDARDTOWERSTARTLEVEL 1
//*******Spawners and Spawner Towers*******
const int creepBaseSpawnNum[NUM_CREEPS] = {8,9,5,8,2,5};
//Spawn Tower Definitions
#define NORMCREEPTOWER 6
#define FASTCREEPTOWER 7
#define TANKCREEPTOWER 8
#define SWARMCREEPTOWER	9
#define TITANCREEPTOWER 10
#define FATTYCREEPTOWER 11
//
#define CREEPTOWERSTARTLEVEL 1
#define CREEPTOWERDELAY 20
#define GETCREEPTYPE 6 // Subtract 5 to get the creep type
//*******Effect Towers*******
#define SLOWTOWER 12
#define SPEEDTOWER 13
#define HEALTOWER 14

//*******Obstacles*******
#define OBSTACLE 20

//Animation
#define ANIM_NUM 5

#define MAX_FPS 20

#define MAXCREEPLEVEL 5
#define MAXCREEPVARIABLES 6

//Creep types
// Health Armor Speed Reward Price Spawn
const int normCreepArr[MAXCREEPLEVEL][MAXCREEPVARIABLES] =		{{3,0,2,1,2,2},		{5,1,3,3,5,2},		{8,2,3,6,10,2},		{12,3,4,12,15,2},	{20,4,5,15,20,2}};
const int fastCreepArr[MAXCREEPLEVEL][MAXCREEPVARIABLES] =		{{2,0,4,1,3,2},		{3,0,5,2,5,2},		{5,1,5,4,8,2},		{8,1,6,8,12,2},		{12,2,7,10,15,2}};
const int tankCreepArr[MAXCREEPLEVEL][MAXCREEPVARIABLES] =		{{3,1,1,2,4,3},		{5,2,1,5,8,3},		{8,3,2,10,16,3},	{12,4,2,15,22,3},	{20,5,3,20,28,3}};
const int swarmCreepArr[MAXCREEPLEVEL][MAXCREEPVARIABLES]=		{{2,0,3,1,2,1},		{3,0,3,1,3,1},		{5,1,4,2,4,1},		{8,1,4,2,5,1},		{10,2,5,3,6,1}};
const int fattyCreepArr[MAXCREEPLEVEL][MAXCREEPVARIABLES] =		{{5,0,1,2,3,3},		{8,1,1,5,7,3},		{11,2,2,10,15,3},	{15,3,2,15,21,3},	{25,4,3,20,27,3}};
const int titanCreepArr[MAXCREEPLEVEL][MAXCREEPVARIABLES] =		{{10,2,2,5,10,5},	{20,3,2,15,25,5},	{35,4,3,25,50,5},	{50,5,3,50,100,5},	{100,7,4,100,250,5}};

//Map Constants
#define MAPSIZE_X 26
#define MAPSIZE_Y 20
#define BOARD_X_OFFSET 0
#define BOARD_Y_OFFSET 63
#define GRID_SIZE 24

//Screen Size Constants
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 608

//Number of Buttons 
#define NUM_BUTTONS 10

//Number of text objects
#define TEXT_NUM 20

//Movement Constant
#define CLOCK_CAP .50

//Player Base Location
#define PLAYERONEX 0
#define PLAYERONEY 10
#define PLAYERTWOX 25
#define PLAYERTWOY 10

// Attack Types
#define ATTACKCLOSESTTOTOWER	1
#define ATTACKCLOSESTTOBASE		2
#define AREAOFEFFECT			1
#define ATTACKONECREEP			2

// Tower Constants
#define MAXTOWERLEVEL 5
#define MAXTOWERVARIABLES 5

//Tower Types
// Damage ArmorPenetration Range Speed Cost
const int basicArr[MAXTOWERLEVEL][MAXTOWERVARIABLES] =			{{1,0,(3 * GRID_SIZE),60,5},	{3,1,(4 * GRID_SIZE),60,10},		{5,1,(4 * GRID_SIZE),50,22},	{10,2,(5 * GRID_SIZE),45,50},			{20, 3, (int)(5.5 * GRID_SIZE), 35, 120}};
const int fastArr[MAXTOWERLEVEL][MAXTOWERVARIABLES] =			{{1,0,(3 * GRID_SIZE),40,7},	{2,0,(3 * GRID_SIZE),35,12},		{4,1,(3 * GRID_SIZE),30,24},	{8,1,(4 * GRID_SIZE),25,60},			{15,2,(4 * GRID_SIZE),15,150}};
const int areaOfEffectArr[MAXTOWERLEVEL][MAXTOWERVARIABLES] =	{{1,0,(2 * GRID_SIZE),90,12},	{2,0,(2 * GRID_SIZE),80,20},		{4,1,(2 * GRID_SIZE),75,30},	{6,1,(int)(2.5 * GRID_SIZE),70,70},		{15,2,(3 * GRID_SIZE),55,180}};
const int heavyArr[MAXTOWERLEVEL][MAXTOWERVARIABLES] =			{{2,1,(2 * GRID_SIZE),90,15},	{4,2,(3 * GRID_SIZE),80,25},		{9,3,(4 * GRID_SIZE),70,40},	{13,4,(5 * GRID_SIZE),60,100},			{22,5,(int)(5.5 * GRID_SIZE),50,300}};
const int mineArr[MAXTOWERLEVEL][MAXTOWERVARIABLES] =			{{5,2,(1 * GRID_SIZE),0,3},		{10,3,((int)(1.5 * GRID_SIZE)),0,5},	{15,4,(2 * GRID_SIZE),0,8},		{20,5,((int)(2.5 * GRID_SIZE)),0,10},		{25,6,(3 * GRID_SIZE),0,15}};

const int towerDelays[5] =			{30,20,10,45,2};
#define BASICATTACKDELAY 30
#define FASTATTACKDELAY 20
#define AOEATTACKDELAY 10
#define HEAVYATTACKDELAY 45
#define MINEATTACKDELAY 2


// Usings
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;
using std::list;
using std::vector;
using std::fstream;
using std::ofstream;

SDL_Rect *newRect(int x, int y, int w, int h);
SDL_Color makeColor(int r, int g, int b);
SDL_Surface *LoadImageCK(string filename);

class structure;
class game_host;
class Spawner;

#endif