#pragma once
#include <iostream>
#include <fstream>
using namespace std;

const string Cstates[4] = { "unknown", "Solid" , "Liquid", "Gas" };
const string Ctypes[11] = { "unknown", "Actinide", "Alkali Metal", "Alkaline Earth Metal", "Halogen", "Lanthanide", "Metalloid", "Noble Gas", "Reactive Nonmetal", "Post-Transition Metal",  "Transition Metal" };

class elementC
{
private:
	int atomicNumber = 0;
	char name[25] = "unknown";
	char symbol[3] = "??";
	double atomicMass = 0.0;
	int state = 0;
	int type = 0;
	char discoverers[100] = "unknown";
	int discoveredYear = 0;
public:
	//Default Constructor
	//Precondition: NA
	//Postcondition: Sets all default values into each member
	elementC();

	//Accessors
	int getAtomicNumber() const;
	const char* getName() const;
	const char* getSymbol() const;
	double getAtomicMass() const;
	int getAtomicState() const;
	int getType() const;
	const char* getDiscoverers() const;
	int getDiscoveredYear() const;
	
	//Mutator
	void setAtomicNumber(int newAtomicNumber);
	void setName(char* newName);
	void setSymbol(char* newSymbol);
	void setAtomicMass(double newAtomicMass);
	void setAtomicState(int newState);
	void setType(int newType);
	void setDiscoverers(char* newDiscoverers);
	void setDiscoveredYear(int newDiscoveredYear);
	void display();
	//Overloaded Operators
	elementC operator=(elementC& right);

};


class PeriodTable
{
private:
	elementC list[118];
public:
	//implement constructor(s), mutators, and accessors
	//Precondition:N/A
	//Postcondition:Initializes all the elements in an array of 118 according to atomic Number
	PeriodTable();
	//Accessor
	elementC getElement(int i);

	//Mutator
	void setElement(elementC e, int i);

};