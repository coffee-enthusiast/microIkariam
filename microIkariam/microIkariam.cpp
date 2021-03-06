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
#include <list>
#include <array>
#include "Research.h"
#include "Resource.h"
#include "Town.h"
#include "Building.h"
#include "Player.h"




void printNestedList(list<list<Research>> nested_list)
{
	cout << "[\n";

	// nested_list`s iterator(same type as nested_list)
	// to iterate the nested_list
	list<list<Research> >::iterator nested_list_itr;

	// Print the nested_list
	for (nested_list_itr = nested_list.begin();
		nested_list_itr != nested_list.end();
		++nested_list_itr) {

		cout << "  [";

		// normal_list`s iterator(same type as temp_list)
		// to iterate the normal_list
		list<Research>::iterator single_list_itr;

		// pointer of each list one by one in nested list
		// as loop goes on
		list<Research>& single_list_pointer = *nested_list_itr;

		for (single_list_itr = single_list_pointer.begin();
			single_list_itr != single_list_pointer.end();
			single_list_itr++) {
			cout << " " << single_list_itr->rName << " ";
		}
		cout << "]\n";
	}
	cout << "]";
}

int main()
{
	// List of Researches
	list<list<Research>> researchList;
	list<Research> singleList;

	Research r1((string)"Research 1", (ResearchType)0, (string)"Description 1", 8, (string)"Effect 1", new Researches(0,0,0,0),1);
	Research r2((string)"Research 2", (ResearchType)0, (string)"Description 2", 30, (string)"Effect 2", new Researches(0, 1, 0, 0),2);
	Research r3((string)"Research 3", (ResearchType)0, (string)"Description 3", 80, (string)"Effect 3", new Researches(0, 1, 1, 1),3);
	singleList.push_back(r1);
	singleList.push_back(r2);
	singleList.push_back(r3);
	researchList.push_back(singleList);
	singleList.erase(singleList.begin(), singleList.end());

	Research r4((string)"Research 4", (ResearchType)1, (string)"Description 4", 12, (string)"Effect 4", new Researches(1, 0, 0, 0),1);
	Research r5((string)"Research 5", (ResearchType)1, (string)"Description 5", 65, (string)"Effect 5", new Researches(1, 0, 1, 0),2);
	Research r6((string)"Research 6", (ResearchType)1, (string)"Description 6", 100, (string)"Effect 6", new Researches(2, 0, 2, 1),3);
	singleList.push_back(r4);
	singleList.push_back(r5);
	singleList.push_back(r6);
	researchList.push_back(singleList);
	singleList.erase(singleList.begin(), singleList.end());

	Research r7((string)"Research 7", (ResearchType)2, (string)"Description 7", 8, (string)"Effect 7", new Researches(0, 0, 0, 0),1);
	Research r8((string)"Research 8", (ResearchType)2, (string)"Description 8", 25, (string)"Effect 8", new Researches(0, 0, 0, 0),2);
	singleList.push_back(r7);
	singleList.push_back(r8);
	researchList.push_back(singleList);
	singleList.erase(singleList.begin(), singleList.end());

	Research r9((string)"Research 9", (ResearchType)3, (string)"Description 9", 18, (string)"Effect 9", new Researches(1, 1, 0, 0),1);
	singleList.push_back(r9);
	researchList.push_back(singleList);
	singleList.erase(singleList.begin(), singleList.end());

	cout << "PrintList Begin" << endl;
	printNestedList(researchList);
	cout << "PrintList Ended" << endl;

	// Some Buildings
	Building academy = Building("Academy", nullptr);
	Building barracks = Building("Barracks", nullptr);
	Building hideOut = Building("HideOut", new Researches(1,1,1,1));

	// Init level data for the buildings...
	vector<pair<Resources, int>> *tempVec = new vector<pair<Resources, int>>();
	tempVec->push_back({ Resources(Resource((ResourceType)0, (float)140)), 80 });
	academy.InitLevelData(tempVec);

	tempVec = new vector<pair<Resources, int>>();
	tempVec->push_back({ Resources(Resource((ResourceType)1, (float)70)), 37 });
	barracks.InitLevelData(tempVec);

	tempVec = new vector<pair<Resources, int>>();
	tempVec->push_back({ Resources(Resource((ResourceType)4, (float)270)), 111 });
	hideOut.InitLevelData(tempVec);
	//...


	Player marios;
	marios.CreateTown("My City");

	Town *myTown = *marios.myTowns.begin();
	cout << "Buildings Index: " << myTown->buildingsIndex << endl;
	cout << "Building[0]: " << myTown->myBuildings[0]->bName << endl;
	myTown->AddScientists(60);

	bool exitProgram = false;
	while (!exitProgram)
	{
		myTown->myResources->toString();
		int input;
		cin >> input;
		if(input == 0)
			marios.Simulate();
		if (input == 1)
			exitProgram = true;
		if (input == 2)
		{
			int index;
			cin >> index;
			switch (index)
			{
			case 1:
				marios.UnlockResearch(r1);
				break;
			case 2:
				marios.UnlockResearch(r2);
				break;
			case 3:
				marios.UnlockResearch(r3);
				break;
			case 4:
				marios.UnlockResearch(r4);
				break;
			case 5:
				marios.UnlockResearch(r5);
				break;
			case 6:
				marios.UnlockResearch(r6);
				break;
			case 7:
				marios.UnlockResearch(r7);
				break;
			case 8:
				marios.UnlockResearch(r8);
				break;
			case 9:
				marios.UnlockResearch(r9);
				break;
			default:
				break;
			}
		}
		if (input == 3)
		{
			int index;
			cin >> index;
			switch (index)
			{
			case 1:
				myTown->ConstructBuilding(&academy,1);
				break;
			case 2:
				myTown->ConstructBuilding(&barracks,5);
				break;
			case 3:
				myTown->ConstructBuilding(&hideOut,8);
				break;
			default:
				break;
			}
		}
	}
}






