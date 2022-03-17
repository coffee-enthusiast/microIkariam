#include "Town.h"
#include "Research.h"
#include "Building.h"
#include "UnitClass.h"
#include "Resource.h"


Town::Town()
{
	citizens = 0;
	citizensMax = 60;
	myWorkers = new Workers();
	scientists = 0;
	myResearchLevels = new Researches(0, 0, 0, 0);
	myBuildings[0] = Building("TownHall");
	buildingsIndex = 1;
	myResources = new Resources();
}

Town::Town(int c, int cM, Workers* w, int sci, Researches* r, array<Building, 13> b, int bI, Resources* rs, int g)
{
	citizens = c;
	citizensMax = cM;
	myWorkers = w;
	scientists = sci;
	myResearchLevels = r;
	myBuildings = b;
	buildingsIndex = bI;
	myResources = rs;
	gold = g;
}