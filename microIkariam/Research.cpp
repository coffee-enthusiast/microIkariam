#include "Research.h"

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
	for (int i = 0; i < 4; i++)
	{
		if (researchLevels[0].rLevel <= other.researchLevels[0].rLevel)
			continue;
		else return false;
	}

	return true;
}

Research::Research(string n, ResearchType t, string d, int c, string e, Researches* r)
{
	rName = n;
	rType = t;
	rDescription = d;
	rCost = c;
	rEffect = e;
	requierements = r;
}

ResearchLevel::ResearchLevel()
{
}

ResearchLevel::ResearchLevel(ResearchType t, int l)
{
	rType = t;
	rLevel = l;
}