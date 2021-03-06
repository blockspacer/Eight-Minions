#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "resources.h"
#include "creep.h"
#include "tower.h"
#include "obstacle.h"
#include "mine.h"
#include "creep_tower.h"
#include "player.h"
#include "attackAnim.h"
#include "aoeAnim.h"
#include "projectileAnim.h"

class player;

class gameMap
{
protected:
	vector<vector<structure*> > Tmap; //map of pointers to the towers, NULL if no tower
	vector<vector<bool> > Nodemap; //boolean map, false means passable
	vector<coord> obstructionList;

	cList<creep*> creepList; //the list of creeps, creeps contain their positions
	cList<structure*> towerList;

	list<attackAnim*> attacks;

	creep *pathTestCreep;
	player *p[2];

	coord Bases[2]; //more modular
	Spawner *p1Spawner;
	Spawner *p2Spawner;
public:
	gameMap();
	gameMap(player *clientA);

	bool isEmptyLocation(int xLoc, int yLoc);
	int placeTower(int playerNumber, int towerType, int x, int y);
	bool changeStructure(int structureID, int newType);
	void updatePaths(int newX, int newY);

	player *getPlayer(int pnum);
	cList<creep*> *getCreepList();
	bool removeTowerLocal(int towerID);
	bool placeTowerForced(int playerNumber, int towerType, int x, int y, int towerID);
	void addAttackAnim( int pNum,int x,int y, int creepNum, int attackType );
	friend class client;
	friend class game_host;
	friend class Spawner;
};
#endif