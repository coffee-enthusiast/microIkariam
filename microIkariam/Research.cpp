#include "Research.h"
#include <iostream>

Researches::Researches()
{
}

Researches::Researches(int sea, int eco, int sci, int mil)
{
	researchLevels[0] = ResearchLevel((ResearchType)0, sea);
	researchLevels[1] = ResearchLevel((ResearchType)1, eco);
	researchLevels[2] = ResearchLevel((ResearchType)2, sci);
	researchLevels[3] = ResearchLevel((ResearchType)3, mil);
}

bool Researches::operator<=(Researches other)
{
	cout << "Research compare!" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "First: " <<researchLevels[i].rLevel << ", other:" << other.researchLevels[i].rLevel << endl;
		if (researchLevels[i].rLevel <= other.researchLevels[i].rLevel)
			continue;
		else
			return false;
	}

	return true;
}

Research::Research(string n, ResearchType t, string d, int c, string e, Researches* r, int i)
{
	rName = n;
	rType = t;
	rDescription = d;
	rCost = c;
	rEffect = e;
	requierements = r;
	rIndex = i;
}

ResearchLevel::ResearchLevel()
{
}

ResearchLevel::ResearchLevel(ResearchType t, int l)
{
	rType = t;
	rLevel = l;
}