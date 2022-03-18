#pragma once
#include <string>
#include <list>

#include "Town.h"
#include "Research.h"
using namespace std;

class Player
{
private:
	time_t lastModified;
	time_t lastUpdate;
public:
	Player();
	string pName;
	list<Town*> myTowns;

	double myGold;
	double myResearchPoints;
	Researches* myResearchLevels;

	void Simulate();
	void CreateCity(string cName);
	void UnlockResearch(Research r);
};

