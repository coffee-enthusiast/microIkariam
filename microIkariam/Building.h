#pragma once
#include <string>
#include <vector>
#include "Research.h"
#include "Resource.h"

class Building
{
public:
	Building();
	Building(string n, Researches* rS);
	string bName;
	string description;
	int currLevel;
	// Pair for resources(Resources) need to upgrade and time(int) it takes to finish
	vector<pair<Resources, int>> *levelData;
	Resources getResourcesForNextLevel();
	Researches *researchRequired;	
	bool canBeBuild(Resources available);
	bool build(Resources* available);


	bool isAvailable(Researches myResearches);
	bool UpgradeBuilding(Resources* available);
	void InitLevelData(vector<pair<Resources,int>> *d);
};

