#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "resources.h"
#include "creep.h"
#include "tower.h"
#include "obstacle.h"
#include "mine.h"

class gameMap
{
private:
	vector<vector<structure*> > Tmap; //map of pointers to the towers, NULL if no tower
	vector<vector<bool> > Nodemap; //boolean map, false means passable
	vector<coord> obstructionList;

	cList<creep*> creepList; //the list of creeps, creeps contain their positions
	cList<structure*> towerList;

	creep *pathTestCreep;
public:
	gameMap();


	bool isEmptyLocation(int xLoc, int yLoc);
	int placeTower(int playerNumber, int towerType, int x, int y);
	bool changeStructure(int structureID, int newType);
	void updatePaths(int newX, int newY);
};
