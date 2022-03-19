#pragma once

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
	float amount;
public:
	Resource();
	Resource(ResourceType t, float a);

	bool operator<=(Resource other);
	bool operator+(float value);
	bool operator-(float value);

	float getAmount();
	ResourceType getType();
};

class Resources
{
public:
	// 0:wood, 1:marble, 2:sulfur, 3:crystal, 4:wine
	Resource allResources[5] = { Resource() };

	Resources();
	Resources(Resource r1);
	Resources(Resource r1, Resource r2);
	Resources(Resource r1, Resource r2, Resource r3, Resource r4, Resource r5);

	void operator+(Resource other);

	bool operator<=(Resources other);
	void operator+(Resources other);
	void operator-(Resources other);

	void toString();
};

