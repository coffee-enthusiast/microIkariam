#include "Resource.h"
#include <math.h>
#include <iostream>
using namespace std;

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

Resources::Resources(Resource r1)
{
	for (int i = 0; i < 5; i++)
		allResources[i] = Resource(static_cast<ResourceType>(i), 0);

	allResources[r1.getType()] = r1;
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

void Resources::toString()
{

	for (int i = 0; i < 5; i++)
		cout << allResources[i].getType() << ':' << (int)allResources[i].getAmount() << ' ';
	cout << endl;
}

bool Resource::operator+(float value)
{
	amount += value;
	return true;
}

bool Resource::operator-(float value)
{
	if (abs(value) > abs(amount))
		return false;

	amount -= value;
	return true;
}

float Resource::getAmount()
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

Resource::Resource(ResourceType t, float a)
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
