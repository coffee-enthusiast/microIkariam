#pragma once
#include <string>
#include "Research.h"
#include "Resource.h"

class Building
{
public:
	Building();
	Building(string n, Resources* tB, Researches* rS);
	string bName;
	string description;
	int currLevel;
	Resources *toBuild;
	bool canBeBuild(Resources available);
	bool build(Resources* available);

	Researches *researchRequired;
	bool isAvailable(Researches myResearches);
};

