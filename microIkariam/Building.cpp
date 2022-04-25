#include "Building.h"
#include "Resource.h"
#include "Research.h"
#include <iostream>

Building::Building()
{
}

Building::Building(string n, Researches* rS)
{
	bName = n;
	researchRequired = rS;
	currLevel = 0;
}

bool Building::canBeBuild(Resources available)
{
	if ((*levelData)[0].first <= available)
		return true;
	return false;
}

bool Building::build(Resources* available)
{
	if (canBeBuild(*available))
	{
		*available - (*levelData)[currLevel].first;
		currLevel++;
		return true;
	}
	return false;
}

bool Building::isAvailable(Researches myResearches)
{
	if (*researchRequired <= myResearches)
		return true;
	return false;
}

Resources Building::getResourcesForNextLevel()
{
	return (*levelData)[currLevel + 1].first;
}

bool Building::UpgradeBuilding(Resources* available)
{
	if (getResourcesForNextLevel() <= *available)
	{
		*available - (*levelData)[currLevel++].first;
		return true;
	}
	cout << "Can't upgrade " << bName << "! Not enough resources!" << endl;
	return false;
}

void Building::InitLevelData(vector<pair<Resources, int>> *d)
{
	levelData = d;
}
