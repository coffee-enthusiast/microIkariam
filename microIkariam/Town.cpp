#include "Town.h"
#include "Research.h"
#include "Building.h"
#include "UnitClass.h"
#include "Resource.h"
#include <time.h>
#include <iostream>


Town::Town(Researches* rL)
{
	citizens = 60;
	citizensMax = 60;
	citizensFree = 60;
	myWorkers = new Workers();
	myScientists = new Scientists();
	myBuildings[0] = new Building("TownHall",nullptr);
	buildingsIndex = 1;
	myResources = new Resources(Resource(Wood, 50000), Resource(Marble,10000));
	myResearchLevels = rL;
}

Town::Town(int c, int cM, int cF, Workers* w, Scientists *sci, array<Building*, 13> b, int bI, Resources* rs, Researches* rL)
{
	citizens = c;
	citizensMax = cM;
	citizensFree = cF;
	myWorkers = w;
	myScientists = sci;
	myBuildings = b;
	buildingsIndex = bI;
	myResources = rs;
	myResearchLevels = rL;
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

void Town::ConstructBuilding(Building* b, int posIndex)
{
	if (myBuildings[posIndex] != nullptr)
	{
		cout << "Error: " << posIndex << " block already has a Building! Please choose another block!" << endl;
		return;
	}
	if (b->researchRequired == nullptr || b->isAvailable(*myResearchLevels))
	{
		if (b->build(myResources))
		{
			myBuildings[posIndex] = b;
			cout << "Building '" << b->bName << "' constructed!" << endl;
		}
		else
			cout << "Can't construct building '" << b->bName << "'! Not enough resources!" << endl;
	}
	else
		cout << "Can't construct building '" << b->bName << "'! Unlock requiered researches!" << endl;
}
