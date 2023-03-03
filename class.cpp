#include "class.h"

//Precondition: N/A
//Postcondition: Initalizing variables
elementC::elementC()
{
	int atomicNumber = 0;
	char name[25] = "unknown";
	char symbol[3] = "??";
	double atomicMass = 0.0;
	int state = 0;
	int type = 0;
	char discoverers[100] = "unknown";
	int discoveredYear = 0;
}

//Accessor
int elementC::getAtomicNumber() const
{
	return atomicNumber;
}
//Mutator
void elementC::setAtomicNumber(int newAtomicNumber)
{
	atomicNumber = newAtomicNumber;
} 
//Accessor
const char* elementC::getName() const 
{
	return name;
}
//Mutator
void elementC::setName(char* newName)
{
	strcpy_s(name, newName);
}
//Accessor
const char* elementC::getSymbol() const
{
	return symbol;
}

//Accessor
double elementC::getAtomicMass() const
{
	return atomicMass;
}

//Mutator
void elementC::setAtomicMass(double newAtomicMass)
{
	atomicMass = newAtomicMass;
}

//Accessor
int elementC::getAtomicState() const
{
	return state;
}

//Mutator
void elementC::setAtomicState(int newState)
{
	state = newState;
}

//Accessor
int elementC::getType() const
{
	return type;
}

//Mutator
void elementC::setType(int newType)
{
	type = newType;
}
//Mutator
void elementC::setSymbol(char* newSymbol)
{
	strcpy_s(symbol, newSymbol);
}

//Accessor
const char* elementC::getDiscoverers() const
{
	return discoverers;
}

//Mutator
void elementC::setDiscoverers(char* newDiscoverers)
{
	strcpy_s(discoverers, newDiscoverers);
}

//Accessor
int elementC::getDiscoveredYear() const
{
	return discoveredYear;
}

//Mutator
void elementC::setDiscoveredYear(int newDiscoveredYear)
{
	discoveredYear = newDiscoveredYear;
}

//Overloading = operator
elementC elementC::operator=(elementC& right)
{
	atomicNumber = right.getAtomicNumber();
	strcpy_s(name, right.getName());
	strcpy_s(symbol, right.getSymbol());
	atomicMass = right.getAtomicMass();
	state = right.getAtomicState();
	type = right.getType();
	strcpy_s(discoverers, right.getDiscoverers());
	discoveredYear = right.getDiscoveredYear();

	return *this;
}

//Display Function
void elementC::display()
{
	cout << "\n\tSelected Element Information";
	cout << "\n\t" << string(60, char(205));
	cout << "\n\tSymbol				: " << getSymbol();
	cout << "\n\tAtomic Number			: " << getAtomicNumber();
	cout << "\n\tAtomic Mass			: " << getAtomicMass();
	cout << "\n\tName				: " << getName();
	cout << "\n\tState				: " << Cstates[getAtomicState()];
	cout << "\n\tType				: " << Ctypes[getType()];
	cout << "\n\tDiscovered by			: " << getDiscoverers();
	cout << "\n\tYear Discovered			: " << getDiscoveredYear();
	cout << "\n\t" << string(60, char(205)) << "\n";
}

//Default Constructor for PeriodTable
//Precondition: N/A
//Postcondition: Initializes an array of all 118 elements
PeriodTable::PeriodTable()
{
	for (int i = 0; i < 118; i++)
	{
		list[i].setAtomicNumber(i + 1);
	}
}

//Accessor
elementC PeriodTable::getElement(int i)
{
	return list[i];
}

//Mutator
void PeriodTable::setElement(elementC e, int i)
{
	list[i] = e;
}

