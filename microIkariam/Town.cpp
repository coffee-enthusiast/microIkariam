#include "Town.h"
#include "Research.h"
#include "Building.h"
#include "UnitClass.h"
#include "Resource.h"
#include <time.h>
#include <iostream>


Town::Town()
{
	citizens = 60;
	citizensMax = 60;
	citizensFree = 60;
	myWorkers = new Workers();
	myScientists = new Scientists();
	myBuildings[0] = Building("TownHall");
	buildingsIndex = 1;
	myResources = new Resources();

}

Town::Town(int c, int cM, int cF, Workers* w, Scientists *sci, array<Building, 13> b, int bI, Resources* rs)
{
	citizens = c;
	citizensMax = cM;
	citizensFree = cF;
	myWorkers = w;
	myScientists = sci;
	myBuildings = b;
	buildingsIndex = bI;
	myResources = rs;
}

void Town::AddWorkers(int index, int amount)
{
	if (amount > citizensFree)
		amount = citizensFree;
	myWorkers->addWorkers(index, amount);
	citizensFree -= amount;

}

void Town::AddScientists(int amount)
{
	if (amount > citizensFree)
		amount = citizensFree;
	myScientists->addScientists(amount);
	citizensFree -= amount;
}

void Town::Simulate(double seconds, double *rP, double *g)
{
	
	*g += ((double)citizensFree * 3 * seconds) / 3600;
	myWorkers->Simulate(seconds, myResources, g);
	myScientists->Simulate(seconds, rP, g);

	cout << "Gold: " << *g << ", ResearchP: " << *rP << endl;
	cout << "Citizens: " << citizens << "(" << citizensFree << ")" << endl;
}
