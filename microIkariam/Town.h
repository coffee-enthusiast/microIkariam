#pragma once
#include "UnitClass.h"
#include "Building.h"

#include <array>
class Town
{
public:
	Town();
	Town(int c, int cM, Workers* w, int sci, Researches* r, array<Building, 13> b, int bI, Resources* rs, int g);
	int citizens;
	int citizensMax;
	Workers* myWorkers;
	int scientists;
	Researches* myResearchLevels;
	array<Building, 13> myBuildings;
	int buildingsIndex;
	Resources* myResources;
	int gold;
};
