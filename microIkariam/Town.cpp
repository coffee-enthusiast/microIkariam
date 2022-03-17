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
	myResearchLevels = new Researches(0, 0, 0, 0);
	myBuildings[0] = Building("TownHall");
	buildingsIndex = 1;
	myResources = new Resources();
	gold = 1000;

	lastModified = time(NULL);
	lastUpdate = time(NULL);
}

Town::Town(int c, int cM, int cF, Workers* w, Scientists *sci, time_t lM, time_t lU, Researches* r, array<Building, 13> b, int bI, Resources* rs, int g)
{
	citizens = c;
	citizensMax = cM;
	citizensFree = cF;
	myWorkers = w;
	myScientists = sci;
	lastModified = lM;
	lastUpdate = lU;
	myResearchLevels = r;
	myBuildings = b;
	buildingsIndex = bI;
	myResources = rs;
	gold = g;
}

void Town::AddWorkers(int index, int amount)
{
	if (amount > citizensFree)
		amount = citizensFree;
	myWorkers->addWorkers(index, amount);
	citizensFree -= amount;


	lastModified = time(NULL);
}

void Town::AddScientists(int amount)
{
	if (amount > citizensFree)
		amount = citizensFree;
	myScientists->addScientists(amount);
	citizensFree -= amount;


	lastModified = time(NULL);
}

void Town::Simulate()
{
	float seconds = difftime(time(NULL), lastModified) - difftime(lastUpdate, lastModified);

	gold += ((float)citizensFree * 3 * seconds) / 3600;
	myWorkers->Simulate(seconds, myResources, &gold);
	myScientists->Simulate(seconds, &researchPoints, &gold);

	lastUpdate = time(NULL);

	cout << "Gold: " << gold << ", ResearchP: " << researchPoints << endl;
	cout << "Citizens: " << citizens << "(" << citizensFree << ")" << endl;
}
