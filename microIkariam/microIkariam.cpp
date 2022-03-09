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
class Resources
{
public:
	int wood;
	int wine;
	int crystal;
	int marble;
	int sulfur;

	bool operator<=(Resources other);
};

class Researches
{
	int seaferingLevel;
	int economyLevel;
	int scienceLevel;
	int militaryLevel;
};

class Building
{
public:
	int currLevel;
	Resources toBuild;
	bool canBeBuild(Resources available);
	bool build(Resources* available);
};

class Workers 
{
public:
	Workers();
	int woodWorkers;
	int wineWorkers;
	int crystalWorkers;
	int marbleWorkers;
	int sulfurWorkers;


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

	Researches researchRequired;
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
    std::cout << "Hello World!\n";
	Resources storeRes;
	storeRes.wood = 675;
	storeRes.marble = 120;
	storeRes.crystal = 0;
	storeRes.sulfur = 0;
	storeRes.wine = 0;

	Building store;
	store.currLevel = 0;
	store.toBuild = storeRes;

	Resources myRes;
	myRes.wood = 3775;
	myRes.marble = 4120;
	myRes.crystal = 0;
	myRes.wine = 4760;
	myRes.sulfur = 4260;



	Workers myWorkers = Workers();
	myWorkers.Simulate(&myRes);

	std::cout << store.canBeBuild(myRes) << std::endl;
	std::cout << store.build(&myRes) << std::endl;
	std::cout << myRes.wood << std::endl;
	std::cout << store.currLevel << std::endl;
	std::cout << store.build(&myRes) << std::endl;
	std::cout << myRes.wood << std::endl;
	std::cout << store.currLevel << std::endl;
	std::cout << store.build(&myRes) << std::endl;
	std::cout << myRes.wood << std::endl;
	std::cout << store.currLevel << std::endl;
	std::cout << store.build(&myRes) << std::endl;
	std::cout << myRes.wood << std::endl;
	
	bool exitProgram = false;
	while (!exitProgram)
	{
		std::cout << "Wood: " << myRes.wood << std::endl;
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
		available->wood -= toBuild.wood;
		available->crystal -= toBuild.crystal;
		available->marble -= toBuild.marble;
		available->wine -= toBuild.wine;
		available->sulfur -= toBuild.sulfur;
		currLevel++;
		return true;
	}
	return false;
}

bool Resources::operator<=(Resources other)
{
	if (wood <= other.wood && wine <= other.wine &&
		crystal <= other.crystal && marble <= other.marble &&
		sulfur <= other.sulfur)
	{
		return true;
	}
	return false;
}

Workers::Workers()
{
	lastUpdate = time(NULL);
	woodWorkers = 1000;
}

void Workers::Simulate(Resources* myResources)
{
	float seconds = difftime(time(NULL), lastUpdate);
	cout << seconds << " seconds passed" << endl;

	myResources->wood += (woodWorkers * seconds) / 3600;	// 60 minutes * 60 seconds of each minute = 3600 total seconds
	myResources->crystal += (crystalWorkers * seconds) / 3600;
	myResources->marble += (marbleWorkers * seconds) / 3600;
	myResources->wine += (wineWorkers * seconds) / 3600;
	myResources->sulfur += (sulfurWorkers * seconds) / 3600;

	lastUpdate = time(NULL);
}
