#include "UnitClass.h"

#include <time.h>
#include <iostream>

#include "Resource.h"
#include "Research.h"

Workers::Workers()
{
	for (int i = 0; i < 5; i++)
	{
		workersList[i] = 0;
	}
}

void Workers::addWorkers(int index, int amount)
{
	workersList[index] += amount;
}

void Workers::Simulate(float seconds, Resources* myResources, double* gold)
{
	cout << seconds << " seconds passed" << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "You have " << (float)workersList[i] << " workers for " << i << endl;
		float amount = ((float)workersList[i] * seconds) / 3600;
		cout << "Amount: " << amount << endl;
		myResources->allResources[i] + amount;	// 60 minutes * 60 seconds of each minute = 3600 total seconds
		*gold -= ((float)workersList[i] * 3 * seconds)/ 3600;
	}

}

bool Unit::isAvailable(Researches myResearches)
{
	if (*researchRequired <= myResearches)
		return true;
	return false;
}

Scientists::Scientists()
{
	scientists = 0;
	scientistsMax = 60;
}

Scientists::Scientists(int s, int sM, time_t lM, time_t lU)
{
	scientists = s;
	scientistsMax = sM;
}

void Scientists::addScientists(int amount)
{
	scientists += amount;

	if (scientists > scientistsMax)
		scientists = scientistsMax;
}

void Scientists::Simulate(float seconds, double* researchPoints, double* gold)
{
	cout << seconds << " seconds passed" << endl;
	
	cout << "You have " << scientists << " scientists";
	float amount = ((float)scientists * seconds) / 3600;
	cout << "Amount: " << amount << endl;

	*researchPoints += amount;	// 60 minutes * 60 seconds of each minute = 3600 total seconds
	*gold -= ((float)scientists * 6 * seconds) / 3600;


}
