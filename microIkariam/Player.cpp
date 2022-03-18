#include "Player.h"
#include <time.h>
#include <iostream>

Player::Player()
{
	myGold = 1000000;
	myResearchPoints = 60;
	lastModified = time(NULL);
	lastUpdate = time(NULL);
	myResearchLevels = new Researches(0, 0, 0, 0);
}

void Player::Simulate()
{
	double seconds = difftime(time(NULL), lastModified) - difftime(lastUpdate, lastModified);
	for (auto t = myTowns.begin(); t != myTowns.end(); t++)
	{
		(*t)->Simulate(seconds, &myResearchPoints, &myGold);
	}

	lastModified = time(NULL);
	lastUpdate = time(NULL);
}

void Player::CreateCity(string cName)
{
	myTowns.push_back(new Town());
}

void Player::UnlockResearch(Research r)
{
	if (r.rCost < myResearchPoints)
	{
		if (r.rIndex == myResearchLevels->researchLevels[r.rType].rLevel + 1)
		{
			if (*(r.requierements) <= *myResearchLevels)
			{
				myResearchLevels->researchLevels[r.rType].rLevel++;
				myResearchPoints -= r.rCost;
				cout << "Research '" << r.rName << "' unlocked!" << endl;
			}
			else
				cout << "Can't unlock research '" << r.rName << "' due to requierements not being met!" << endl;
		}
		else
			cout << "Can't unlock research '" << r.rName << "' due to Research is not the next one!" << endl;
	}
	else
		cout << "Can't unlock research '" << r.rName << "' due to not enough RP!" << endl;
}
