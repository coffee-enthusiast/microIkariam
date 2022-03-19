#include "Building.h"
#include "Resource.h"
#include "Research.h"

Building::Building()
{
}

Building::Building(string n, Resources* tB, Researches* rS)
{
	bName = n;
	toBuild = tB;
	researchRequired = rS;
}

bool Building::canBeBuild(Resources available)
{
	if (*toBuild <= available)
		return true;
	return false;
}

bool Building::build(Resources* available)
{
	if (canBeBuild(*available))
	{
		*available - *toBuild;
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
