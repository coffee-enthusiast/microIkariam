#include "UnitClass.h"

#include <time.h>
#include <iostream>

#include "Resource.h"
#include "Research.h"

Workers::Workers()
{
	for (int i = 0; i < 5; i++)
	{
		workersList[i] = 100;
	}
	lastModified = time(NULL);
	lastUpdate = time(NULL);
}

void Workers::addWorkers(int index, int amount)
{
	workersList[index] += amount;
	lastModified = time(NULL);
	lastUpdate = time(NULL);
}

void Workers::Simulate(Resources* myResources)
{
	float seconds = difftime(time(NULL), lastModified) - difftime(lastUpdate, lastModified);
	cout << seconds << " seconds passed" << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "You have " << (float)workersList[i] << " workers for " << i << endl;
		float amount = ((float)workersList[i] * seconds) / 3600;
		cout << "Amount: " << amount << endl;
		myResources->allResources[i] + amount;	// 60 minutes * 60 seconds of each minute = 3600 total seconds
	}

	lastUpdate = time(NULL);
}

bool Unit::isAvailable(Researches myResearches)
{
	if (*researchRequired <= myResearches)
		return true;
	return false;
}