#pragma once
#include <string>
using namespace std;

enum ResearchType
{
	Seafaring,
	Economy,
	Science,
	Military
};

class ResearchLevel
{
public:
	ResearchLevel();
	ResearchLevel(ResearchType t, int l);
	ResearchType rType;
	int rLevel;
};

class Researches
{
public:
	Researches();
	Researches(int sea, int eco, int sci, int mil);
	ResearchLevel researchLevels[4];

	bool operator<=(Researches other);
};

class Research
{
public:
	Research(string n, ResearchType t, string d, int c, string e, Researches* r, int i);
	string rName;
	ResearchType rType;
	string rDescription;
	int rCost;	// The cost in research points
	string rEffect;
	Researches* requierements;

	int rIndex;	// The index of the research in it's research type list
};