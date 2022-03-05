// microIkariam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>

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
