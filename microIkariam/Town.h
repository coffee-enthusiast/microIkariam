#pragma once
#include "UnitClass.h"
#include "Building.h"

#include <array>

class Town
{

public:
	Town();
	Town(int c, int cM, int cF, Workers* w, Scientists *sci, array<Building, 13> b, int bI, Resources* rs);
	int citizens;
	int citizensFree;
	int citizensMax;
	Workers *myWorkers;
	Scientists *myScientists;
	array<Building, 13> myBuildings;
	int buildingsIndex;
	Resources* myResources;

	void AddWorkers(int index, int amount);
	void AddScientists(int amount);
	void Simulate(double seconds, double *rP, double *g);
};
