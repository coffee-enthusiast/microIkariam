#pragma once
#include "UnitClass.h"
#include "Building.h"

#include <array>

class Town
{
private:
	time_t lastModified;
	time_t lastUpdate;

public:
	Town();
	Town(int c, int cM, int cF, Workers* w, Scientists *sci, time_t lM, time_t lU, Researches* r, array<Building, 13> b, int bI, Resources* rs, int g);
	int citizens;
	int citizensFree;
	int citizensMax;
	Workers *myWorkers;
	Scientists *myScientists;
	float researchPoints;
	Researches* myResearchLevels;
	array<Building, 13> myBuildings;
	int buildingsIndex;
	Resources* myResources;
	double gold;

	void AddWorkers(int index, int amount);
	void AddScientists(int amount);
	void Simulate();
};
