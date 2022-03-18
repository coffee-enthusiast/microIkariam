#pragma once
#include "Resource.h"
#include "Research.h"
#include <string>
using namespace std;

enum UnitClass {
	Human,
	Machine
};

enum UnitType {
	Heavy_Infantry,
	Light_Infantry,
	Long_Range_Fighter,
	Artillery,
	Bomber,
	Fighter_Pilot,
	Support
};

class Unit
{
public:
	string name;
	string description;
	int hitPoints;
	int armour;
	int size;
	int cargoWeight;
	UnitClass uClass;
	UnitType uType;
	int speed;
	int citizenCost;
	Resources buildCost;
	int upkeep;
	float buildTime;
	int barracksLevel;
	float generals;
	int damage;
	float accuracy;

	Researches* researchRequired;
	bool isAvailable(Researches myResearches);
};


class Workers
{
public:
	Workers();
	// 0: wood, 1: marble, 2: sulfur, 3: crystal, 4: wine
	int workersList[5];
	void addWorkers(int index, int amount);
	void Simulate(float seconds, Resources* myResources, double* gold);

};

class Scientists
{
public:
	Scientists();
	Scientists(int s, int sM, time_t lM, time_t lU);
	int scientists;
	int scientistsMax;
	void addScientists(int amount);
	void Simulate(float seconds, double* researchPoints, double* gold);
};