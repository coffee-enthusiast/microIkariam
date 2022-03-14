// microIkariam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;


#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <cstdlib>
#include <fstream>

enum ResourceType {
	Wood = 0,
	Marble,
	Sulfur,
	Crystal,
	Wine
};

class Resource
{
	ResourceType type;
	int amount;
public:
	Resource();
	Resource(ResourceType t, int a);
	bool operator<=(Resource other);

	bool operator+(int value);
	int getAmount();
	ResourceType getType();
};

class Resources
{
public:
	// 0:wood, 1:marble, 2:sulfur, 3:crystal, 4:wine
	Resource allResources[5] = { Resource() };

	Resources();
	Resources(Resource r1, Resource r2);
	Resources(Resource r1, Resource r2, Resource r3, Resource r4, Resource r5);

	void operator+(Resource other);
	bool operator<=(Resources other);
	void operator+(Resources other);
	void operator-(Resources other);

	void ToString();
};

enum ResearchType
{
	Seafaring,
	Economy,
	Science,
	Military
};

class Research
{
public:
	string rName;
	ResearchType rType;
	string rDescription;
	int rCost;	// The cost in research points
	string rEffect;
	Researches* requierements;

	int rIndex;	// The index of the research in it's research type list
};

class ResearchLevel
{
public:
	ResearchType rType;
	int rLevel;
};

class Researches
{
public:
	ResearchLevel researchLevels[4];

	bool operator<=(Researches other);
};

class Building
{
public:
	string name;
	string description;
	int currLevel;
	Resources toBuild;
	bool canBeBuild(Resources available);
	bool build(Resources* available);

	Researches *researchRequired;
	bool isAvailable(Researches myResearches);
};

class Workers 
{
public:
	Workers();
	// 0: wood, 1: marble, 2: sulfur, 3: crystal, 4: wine
	int workersList[5];

	void Simulate(Resources* myResources);

private:
	time_t lastUpdate;
};

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

	Researches *researchRequired;
	bool isAvailable(Researches myResearches);
};

class Town
{
	int citizens;
	int citizensMax;
	Workers myWorkers;
	int scientists;
	Building myBuildings[13];
	int buildingsIndex;
	Resources myResources;
	int gold;
};

int main()
{
	ifstream buildingsFile("./BuildingsList.txt");
	string bName;
	buildingsFile >> bName;
	cout << "First building: " << bName << endl;

	Resource w(Wood, 675);
	cout << "w.type=" << w.getType() << ", w.amount=" << w.getAmount() << endl;
	Resource m(Marble, 120);
	cout << "m.type=" << m.getType() << ", m.amount=" << m.getAmount() << endl;
	Resources storeRes(w,m);
	storeRes.ToString();

	Building store;
	store.currLevel = 0;
	store.toBuild = storeRes;

	Resource w2(Wood, 3775);
	Resource m2(Marble, 4120);
	Resource s2(Sulfur, 4260);
	Resource c2(Crystal, 120);
	Resource wi2(Wine, 4760);

	Resources myRes = Resources(w2,m2,s2,c2,wi2);


	Workers myWorkers = Workers();
	myWorkers.Simulate(&myRes);

	bool exitProgram = false;
	while (!exitProgram)
	{
		myRes.ToString();
		int input;
		cin >> input;
		if(input == 0)
			myWorkers.Simulate(&myRes);
		if (input == 1)
			exitProgram = true;
	}
}

bool Building::canBeBuild(Resources available)
{
	if (toBuild <= available)
		return true;
	return false;
}

bool Building::build(Resources* available)
{
	if (canBeBuild(*available))
	{
		*available - toBuild;
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

Resources::Resources()
{
	for (int i = 0; i < 5; i++)
		allResources[i] = Resource(static_cast<ResourceType>(i), 0);
}

Resources::Resources(Resource r1, Resource r2)
{
	for (int i = 0; i < 5; i++)
		allResources[i] = Resource(static_cast<ResourceType>(i), 0);

	allResources[r1.getType()] = r1;
	allResources[r2.getType()] = r2;
}

Resources::Resources(Resource r1, Resource r2, Resource r3, Resource r4, Resource r5)
{
	allResources[r1.getType()] = r1;
	allResources[r2.getType()] = r2;
	allResources[r3.getType()] = r3;
	allResources[r4.getType()] = r4;
	allResources[r5.getType()] = r5;
}

void Resources::operator+(Resource other)
{
	allResources[other.getType()] + other.getAmount();
}

bool Resources::operator<=(Resources other)
{

	for (int i = 0; i < 5; i++)
	{
		if (allResources[i] <= other.allResources[i])
			continue;
		else
			return false;
	}
	return true;
}

void Resources::operator+(Resources other)
{
	for (int i = 0; i < 5; i++)
	{
		allResources[i] + (other.allResources[i].getAmount());
	}
}

void Resources::operator-(Resources other)
{
	for (int i = 0; i < 5; i++)
	{
		allResources[i] + (-1 * other.allResources[i].getAmount());
	}
}

void Resources::ToString()
{

	for (int i = 0; i < 5; i++)
		cout << allResources[i].getType() << ':' << allResources[i].getAmount() << ' ';
	cout << endl;
}

Workers::Workers()
{
	lastUpdate = time(NULL);
	for (int i = 0; i < 5; i++)
	{
		workersList[i] = 100;
	}
}

void Workers::Simulate(Resources* myResources)
{
	float seconds = difftime(time(NULL), lastUpdate);
	cout << seconds << " seconds passed" << endl;

	for (int i = 0; i < 5; i++)
	{
		myResources->allResources[i] + (int)(workersList[i] * seconds) / 3600;	// 60 minutes * 60 seconds of each minute = 3600 total seconds
	}

	lastUpdate = time(NULL);
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

bool Unit::isAvailable(Researches myResearches)
{
	if (*researchRequired <= myResearches)
		return true;
	return false;
}

bool Resource::operator+(int value)
{
	if (value < 0 && abs(value) > abs(amount))
		return false;

	amount += value;
	return true;
}

int Resource::getAmount()
{
	return amount;
}

ResourceType Resource::getType()
{
	return type;
}

Resource::Resource()
{
	type = Wood;
	amount = 0;
}

Resource::Resource(ResourceType t, int a)
{
	type = t;
	amount = a;
}

bool Resource::operator<=(Resource other)
{
	if (type == other.type)
	{
		if (amount <= other.getAmount())
			return true;
	}
	return false;
}
