//Bryan Navarro
//Exam 2 - Periodic Table - Class Implementation
// November 1, 2022

#include "input.h"
#include "structure.h"
#include "class.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

int updateMenu();

void readFile(PeriodTable&);
void displayClassTable(PeriodTable&);
void findElementBySymbol(PeriodTable&);
void writeFile(PeriodTable&);
void searchUpdate(PeriodTable&);
void searchByState(PeriodTable&);
void searchByType(PeriodTable&);
void updateSymbol(int, PeriodTable&);
void updateName(int, PeriodTable&);
void updateAtomicMass(int, PeriodTable&);
void updateState(int, PeriodTable&);
void updateType(int, PeriodTable&);
void updateDiscoveredBy(int, PeriodTable&);
void updateYearDiscovered(int, PeriodTable&);
void updateAll(int, PeriodTable&);


int main()
{
	PeriodTable P1;
	do
	{
		system("cls");
		cout << "\n\tPeriodic Table of Elements (Class Implementation by Bryan Navarro)";
		cout << "\n\t" << string(60, char(205));
		cout << "\n\t1. Read CLASS.DAT";
		cout << "\n\t2. Display Periodic Table of Elements";
		cout << "\n\t3. Find the element by Symbol";
		cout << "\n\t4. Write CLASS.DAT";
		cout << "\n\t5. Search by Atomic Number and update the element's information";
		cout << "\n\t6. Find element by State";
		cout << "\n\t7. Find elements by Classification Type";
		cout << "\n\t" << string(60, char(205));
		cout << "\n\t0. Return";
		cout << "\n\t" << string(60, char(196));
		
		
		switch (inputInteger("\n\tOption: ",0, 7))
		{
		case 0: return 0;
		case 1: readFile(P1); break;
		case 2: displayClassTable(P1); system("pause"); break;
		case 3: findElementBySymbol(P1); break;
		case 4: writeFile(P1); break;
		case 5: searchUpdate(P1); break;
		case 6: searchByState(P1); break;
		case 7: searchByType(P1); break;

		}

	} while (true);
		return 0;
}

//Works by reading in the class.dat file into each element in the object of PeriodTable P1 (all 118 elements now reads)
void readFile(PeriodTable &P1)
{
	fstream file;
	file.open("CLASS.DAT", ios::binary | ios::in);
	file.read(reinterpret_cast<char*> (&P1), sizeof(P1));
	file.close();

	cout << "\n\tFile CLASS.DAT has been read." << "\n";
	system("pause");
}

//Write File
void writeFile(PeriodTable& P1)
{

	fstream file;
	file.open("CLASS.DAT", ios::out | ios::binary);
	file.write(reinterpret_cast<char*> (&P1), sizeof(P1));
	file.close();

	cout << "\n\tFile CLASS.DAT has been written." << "\n";
	system("pause");
}
//Update menu list
int updateMenu()
{
	cout << "\n\tUpdate Information Options";
	cout << "\n\t" << string(60, char(205));
	cout << "\n\t1. Symbol";
	cout << "\n\t2. Name";
	cout << "\n\t3. Atomic Mass";
	cout << "\n\t4. State";
	cout << "\n\t5. Type";
	cout << "\n\t6. Discovered By";
	cout << "\n\t7. Year Discovered";
	cout << "\n\t" << string(60, char(196));
	cout << "\n\t8. All Properties";
	cout << "\n\t" << string(60, char(196));
	cout << "\n\t0. Return";
	cout << "\n\t" << string(60, char(196));

	return inputInteger("\nOption: ", 0, 8);
}

//Displays The Atomic Number of the Elements
void displayAtomicTable(PeriodTable &P1)
{
	system("cls");
	
	cout << "\n\n";
	for (int i = 0; i < 57; i++)
	{
		if (i < 56 || i > 70)
			cout << "[" << setw(3) << right << P1.getElement(i).getAtomicNumber() << "]";
		if (i == 56)
			cout << "  *  ";
		if (i == 0)
			cout << string(80, ' ');
		if (i == 3 || i == 11)
			cout << string(50, ' ');
		if (i == 1 || i == 9 || i == 17 || i == 35 || i == 53 || i == 85)
			cout << "\n";
	}
	for (int j = 71; j < 88; j++)
	{
		cout << "[" << setw(3) << right << P1.getElement(j).getAtomicNumber() << "]";
		if (j == 85)
			cout << "\n";
		if (j == 87)
			cout << "  ** ";
	}
	for (int k = 103; k < 118; k++)
	{
		cout << "[" << setw(3) << right << P1.getElement(k).getAtomicNumber() << "]";
	}
	cout << "\n\n\t     * ";
	for (int m = 56; m < 71; m++)
	{
		cout << "[" << setw(3) << right << P1.getElement(m).getAtomicNumber() << "]";
	}
	cout << "\n\t     **";
	for (int n = 88; n < 103; n++)
	{
		cout << "[" << setw(3) << right << P1.getElement(n).getAtomicNumber() << "]";
	}

}

//Displays Symbols of the Periodic Table
void displayClassTable(PeriodTable &P1)
{

	system("cls");

	cout << "\n\n";
	for (int i = 0; i < 57; i++)
	{
		if (i < 56 || i > 70)
			cout << "[" << setw(3) << right << P1.getElement(i).getSymbol() << "]";
		if (i == 56)
			cout << "  *  ";
		if (i == 0)
			cout << string(80, ' ');
		if (i == 3 || i == 11)
			cout << string(50, ' ');
		if (i == 1 || i == 9 || i == 17 || i == 35 || i == 53 || i == 85)
			cout << "\n";
	}
	for (int j = 71; j < 88; j++)
	{
		cout << "[" << setw(3) << right << P1.getElement(j).getSymbol() << "]";
		if (j == 85)
			cout << "\n";
		if (j == 87)
			cout << "  ** ";
	}
	for (int k = 103; k < 118; k++)
	{
		cout << "[" << setw(3) << right << P1.getElement(k).getSymbol() << "]";
	}
	cout << "\n\n\t     * ";
	for (int m = 56; m < 71; m++)
	{
		cout << "[" << setw(3) << right << P1.getElement(m).getSymbol() << "]";
	}
	cout << "\n\t     **";
	for (int n = 88; n < 103; n++)
	{
		cout << "[" << setw(3) << right << P1.getElement(n).getSymbol() << "]";
	}

	cout << "\n\nNonmetals:				 Metalloids:				Metals:";
	cout << "\n===========				============			==================";
	cout << "\n1.Reactive Nonmetals							1. Actinoids";
	cout << "\n2.Noble Gases								2. Alkali metals";
	cout << "\n									3. Alkaline earth Metals";
	cout << "\n									4. Lanthanoids";
	cout << "\n									5. Post-Transition metals";
	cout << "\n									6. Transition metals";

	cout << "\n\n";
}

//searches for atomic number to update information
void searchUpdate(PeriodTable& P1)
{

	displayAtomicTable(P1);

	int searchNumber = inputInteger("\n\n\tEnter an atomic number #1...118 of an element to update: ", 1, 118);

	for (int i = 0; i < 118; i++)
	{
		if (searchNumber == P1.getElement(i).getAtomicNumber())
		{
			P1.getElement(i).display();

			switch (updateMenu())
			{
			case 0: return;
			case 1: updateSymbol(searchNumber, P1); break;
			case 2: updateName(searchNumber, P1); break;
			case 3: updateAtomicMass(searchNumber, P1); break;
			case 4: updateState(searchNumber, P1); break;
			case 5: updateType(searchNumber,P1); break;
			case 6: updateDiscoveredBy(searchNumber, P1); break;
			case 7: updateYearDiscovered(searchNumber, P1); break;
			case 8: updateAll(searchNumber, P1); break;
			}
		}
	}
}
//Finding the element by symbol
void findElementBySymbol(PeriodTable &P1)
{

	displayClassTable(P1);

	char symbol[3];
	bool found = false;
	string symbolSearch;

	symbolSearch = inputString("\n\tEnter the Symbol to lookup or \"STOP\" to exit: ", false);
	
	if (symbolSearch == "STOP")
		return;

	else if (symbolSearch.length() > 2)
	{
		do
		{
			cout << "\n\tERROR: Symbol can only be 2 characters";
			symbolSearch = inputString("\n\tEnter the symbol to replace with or \"STOP\" to exit: ", false);
			if (symbolSearch == "STOP")
				return;

		} while (symbolSearch.length() > 2);

		strcpy_s(symbol, symbolSearch.c_str());
		symbol[0] = toupper(symbol[0]);
		if (strlen(symbol) > 1)
			symbol[1] = tolower(symbol[1]);
	}

	else
	{
		strcpy_s(symbol, symbolSearch.c_str());
		symbol[0] = toupper(symbol[0]);
		if (strlen(symbol) > 1)
			symbol[1] = tolower(symbol[1]);
	}
	
	for (int i = 0; i < 118; i++)
	{
		if (strcmp(P1.getElement(i).getSymbol(), symbol) == 0)
		{
			system("cls");
			P1.getElement(i).display();
			found = true;
			system("pause");
		}	
	}
	if (!found)
	{
		cout << "\n\tERROR:The symbol, " << symbol << ", was not found.\n";
		system("pause");
	}
}

//updates symbol
void updateSymbol(int search, PeriodTable &P1)
{
	displayClassTable(P1);
	
	elementC e1;
	char newSymbol[3];
	char newName[25];
	char newDiscoverers[100];
	
	string newN;
	string newD;
	string newS;

	for (int i = 0; i < 118; i++)
	{
		if (search == P1.getElement(i).getAtomicNumber())
		{
			P1.getElement(i).display();
			do
			{
				newS = inputString("\n\tEnter the New Symbol or \"STOP\" to exit: ", false);
				if (newS == "STOP")
					return;

				else if (newS.length() > 2)
					cout << "\n\tERROR: Symbol can only be 2 characters";

				else
					break;
			}while (true);
			
			strcpy_s(newSymbol, newS.c_str());
			newSymbol[0] = toupper(newSymbol[0]);
			if (strlen(newSymbol) > 1)
				newSymbol[1] = tolower(newSymbol[1]);

			newD = P1.getElement(i).getDiscoverers();
			strcpy_s(newDiscoverers, newD.c_str());
			newN = P1.getElement(i).getName();
			strcpy_s(newName, newN.c_str());

			e1.setSymbol(newSymbol);
			e1.setAtomicNumber(P1.getElement(i).getAtomicNumber());
			e1.setAtomicMass(P1.getElement(i).getAtomicMass());
			e1.setName(newName);
			e1.setAtomicState(P1.getElement(i).getAtomicState());
			e1.setType(P1.getElement(i).getType()); 
			e1.setDiscoverers(newDiscoverers);
			e1.setDiscoveredYear(P1.getElement(i).getDiscoveredYear());
			P1.setElement(e1, i);
		}
	}
	cout << "\n\tThe New Symbol has been Saved!";
	system("pause");
}
//Updates Name
void updateName(int search, PeriodTable& P1)
{
	displayClassTable(P1);

	elementC e1;

	char newSymbol[3];
	string newS;

	char newName[30];
	string newN;

	char newDiscoverers[100];
	string newD;

	for (int i = 0; i < 118; i++)
	{
		if (search == P1.getElement(i).getAtomicNumber())
		{
			P1.getElement(i).display();

			newS = P1.getElement(i).getSymbol();
			newD = P1.getElement(i).getDiscoverers();
			newN = inputString("\n\tEnter the name: ", true);
			
			strcpy_s(newName, newN.c_str());
			strcpy_s(newDiscoverers,newD.c_str());
			strcpy_s(newSymbol, newS.c_str());

			e1.setSymbol(newSymbol);
			e1.setAtomicNumber(P1.getElement(i).getAtomicNumber());
			e1.setAtomicMass(P1.getElement(i).getAtomicMass());
			e1.setName(newName);
			e1.setAtomicState(P1.getElement(i).getAtomicState());
			e1.setType(P1.getElement(i).getType());
			e1.setDiscoverers(newDiscoverers);
			e1.setDiscoveredYear(P1.getElement(i).getDiscoveredYear());

			P1.setElement(e1, i);
		}
	}
	cout << "\n\tThe New Name has been Saved!";
	system("pause");
}
//Updates Atomic Mass
void updateAtomicMass(int search, PeriodTable &P1)
{
	displayClassTable(P1);
	elementC e1;

	char newSymbol[3];
	string newS;
	char newName[25];
	string newN;
	char newDiscoverers[100];
	string newD;
	
	for (int i = 0; i < 118; i++)
	{
		if (search == P1.getElement(i).getAtomicNumber())
		{
			P1.getElement(i).display();

			newS = P1.getElement(i).getSymbol();
			newD = P1.getElement(i).getDiscoverers();
			newN = P1.getElement(i).getName();

			strcpy_s(newName, newN.c_str());
			strcpy_s(newDiscoverers, newD.c_str());
			strcpy_s(newSymbol, newS.c_str());

			e1.setSymbol(newSymbol);
			e1.setAtomicNumber(P1.getElement(i).getAtomicNumber());
			e1.setAtomicMass(inputDouble("\n\tEnter the new atomic mass: ", 0.0, 500.0));
			e1.setName(newName);
			e1.setAtomicState(P1.getElement(i).getAtomicState());
			e1.setType(P1.getElement(i).getType());
			e1.setDiscoverers(newDiscoverers);
			e1.setDiscoveredYear(P1.getElement(i).getDiscoveredYear());

			P1.setElement(e1, i);
		}
	}
	cout << "\n\tThe New Atomic Mass has been Saved!";
	system("pause");
	
}
//Updates element state
void updateState(int search, PeriodTable& P1)
{
	displayClassTable(P1);
	elementC e1;

	char newSymbol[3];
	string newS;
	char newName[25];
	string newN;
	char newDiscoverers[100];
	string newD;

	for (int i = 0; i < 118; i++)
	{
		if (search == P1.getElement(i).getAtomicNumber())
		{
			P1.getElement(i).display();

			newS = P1.getElement(i).getSymbol();
			newD = P1.getElement(i).getDiscoverers();
			newN = P1.getElement(i).getName();

			strcpy_s(newName, newN.c_str());
			strcpy_s(newDiscoverers, newD.c_str());
			strcpy_s(newSymbol, newS.c_str());

			e1.setSymbol(newSymbol);
			e1.setAtomicNumber(P1.getElement(i).getAtomicNumber());
			e1.setAtomicMass(P1.getElement(i).getAtomicMass());
			e1.setName(newName);
			e1.setAtomicState(inputInteger("\n\tEnter the new atomic state(0 - Unknown, 1 - Solid, 2 - Liquid, or 3 - Gas", 0, 3));
			e1.setType(P1.getElement(i).getType());
			e1.setDiscoverers(newDiscoverers);
			e1.setDiscoveredYear(P1.getElement(i).getDiscoveredYear());

			P1.setElement(e1, i);
		}
	}
	cout << "\n\tThe New State has been Saved!";
	system("pause");
}
//Updates type
void updateType(int search, PeriodTable& P1)
{
	displayClassTable(P1);
	elementC e1;

	char newSymbol[3];
	string newS;
	char newName[25];
	string newN;
	char newDiscoverers[100];
	string newD;

	for (int i = 0; i < 118; i++)
	{
		if (search == P1.getElement(i).getAtomicNumber())
		{
			P1.getElement(i).display();

			newS = P1.getElement(i).getSymbol();
			newD = P1.getElement(i).getDiscoverers();
			newN = P1.getElement(i).getName();

			strcpy_s(newName, newN.c_str());
			strcpy_s(newDiscoverers, newD.c_str());
			strcpy_s(newSymbol, newS.c_str());

			e1.setSymbol(newSymbol);
			e1.setAtomicNumber(P1.getElement(i).getAtomicNumber());
			e1.setAtomicMass(P1.getElement(i).getAtomicMass());
			e1.setName(newName);
			e1.setAtomicState(P1.getElement(i).getAtomicState());
			e1.setType(inputInteger("\n\tEnter the new type (0-Unknown, 1-Actinide, 2-Alkali Metal, 3-Alkaline Earth Metal, 4-Halogens, 5-Lanthanide, 6-Metalloid, 7-Noble Gas, 8-Reactive Nonmetal, 9-Post-Transition Metal, or 10-Transition Metal): ", 0, 10));
			e1.setDiscoverers(newDiscoverers);
			e1.setDiscoveredYear(P1.getElement(i).getDiscoveredYear());

			P1.setElement(e1, i);
		}
	}
	cout << "\n\tThe New Type has been Saved!";
	system("pause");
}
//updates the discoverers
void updateDiscoveredBy(int search, PeriodTable& P1)
{
	displayClassTable(P1);
	elementC e1;

	char newSymbol[3];
	string newS;
	char newName[25];
	string newN;
	char newDiscoverers[100];
	string newD;

	for (int i = 0; i < 118; i++)
	{
		if (search == P1.getElement(i).getAtomicNumber())
		{
			P1.getElement(i).display();

			newS = P1.getElement(i).getSymbol();
			newD = P1.getElement(i).getDiscoverers();
			newN = P1.getElement(i).getName();

			strcpy_s(newName, newN.c_str());
			strcpy_s(newDiscoverers, newD.c_str());
			strcpy_s(newSymbol, newS.c_str());

			e1.setSymbol(newSymbol);
			e1.setAtomicNumber(P1.getElement(i).getAtomicNumber());
			e1.setAtomicMass(P1.getElement(i).getAtomicMass());
			e1.setName(newName);
			e1.setAtomicState(P1.getElement(i).getAtomicState());
			e1.setType(P1.getElement(i).getType());
			
			newD = inputString("\n\tEnter the new discoverers: ", true);
			strcpy_s(newDiscoverers, newD.c_str());
			
			e1.setDiscoverers(newDiscoverers);
			e1.setDiscoveredYear(P1.getElement(i).getDiscoveredYear());

			P1.setElement(e1, i);
		}
	}
	cout << "\n\tThe New Discoverers has been Saved!";
	system("pause");
}
//Updates the year discovered
void updateYearDiscovered(int search, PeriodTable& P1)
{
	displayClassTable(P1);
	elementC e1;

	char newSymbol[3];
	string newS;
	char newName[25];
	string newN;
	char newDiscoverers[100];
	string newD;

	for (int i = 0; i < 118; i++)
	{
		if (search == P1.getElement(i).getAtomicNumber())
		{
			P1.getElement(i).display();

			newS = P1.getElement(i).getSymbol();
			newD = P1.getElement(i).getDiscoverers();
			newN = P1.getElement(i).getName();

			strcpy_s(newName, newN.c_str());
			strcpy_s(newDiscoverers, newD.c_str());
			strcpy_s(newSymbol, newS.c_str());

			e1.setSymbol(newSymbol);
			e1.setAtomicNumber(P1.getElement(i).getAtomicNumber());
			e1.setAtomicMass(P1.getElement(i).getAtomicMass());
			e1.setName(newName);
			e1.setAtomicState(P1.getElement(i).getAtomicState());
			e1.setType(P1.getElement(i).getType());

			e1.setDiscoverers(newDiscoverers);
			e1.setDiscoveredYear(inputInteger("\n\tEnter the new year discovered: ", true));

			P1.setElement(e1, i);
		}
	}
	cout << "\n\tThe New Discovered Year has been Saved!";
	system("pause");
}
//Updates all members of elementC object
void updateAll(int search, PeriodTable &P1)
{
	displayClassTable(P1);
	elementC e1;

	char newSymbol[3];
	string newS;
	char newName[25];
	string newN;
	char newDiscoverers[100];
	string newD;
	for (int i = 0; i < 118; i++)
	{
		if (search == P1.getElement(i).getAtomicNumber())
		{
			do
			{
				newS = inputString("\n\tEnter the New Symbol or \"STOP\" to exit: ", false);
				if (newS == "STOP")
					return;

				else if (newS.length() > 2)
					cout << "\n\tERROR: Symbol can only be 2 characters";

				else
					break;
			} while (true);

			strcpy_s(newSymbol, newS.c_str());
			newSymbol[0] = toupper(newSymbol[0]);
			if (strlen(newSymbol) > 1)
				newSymbol[1] = tolower(newSymbol[1]);

			e1.setSymbol(newSymbol);
			
			newN = inputString("\n\tEnter the new name: ", true);
			strcpy_s(newName, newN.c_str());
			e1.setName(newName);
			e1.setAtomicNumber(P1.getElement(i).getAtomicNumber());
			e1.setAtomicMass(inputDouble("\n\tEnter the new atomic mass: ", 0.0, 500.0));
			e1.setAtomicState(inputInteger("\n\tEnter the new atomic state(0 - Unknown, 1 - Solid, 2 - Liquid, or 3 - Gas): ", 0, 3));
			e1.setType(inputInteger("\n\tEnter the new type (0-Unknown, 1-Actinide, 2-Alkali Metal, 3-Alkaline Earth Metal, 4-Halogen, 5-Lanthanide, 6-Metalloid, 7-Noble Gas, 8-Reactive Nonmetal, 9-Post-Transition Metal, or 10-Transition Metal): ", 0, 10));

			newD = inputString("\n\tEnter the new discoverers: ", true);
			strcpy_s(newDiscoverers, newD.c_str());

			e1.setDiscoverers(newDiscoverers);
			e1.setDiscoveredYear(inputInteger("\n\tEnter the new year discovered: ", true));

			P1.setElement(e1, i);
		}
	}
	
	cout << "\n\tThe New Information has been Saved!\n";
	system("pause");
}

//Searches by State
void searchByState(PeriodTable &P1)
{
	cout << "\n\t" << string(60, char(205));
	cout << "\n\tStates of Matter";
	cout << "\n\t0. Unknown";
	cout << "\n\t1. Solid";
	cout << "\n\t2. Liquid";
	cout << "\n\t3. Gas";
	cout << "\n\t" << string(60, char(196));
	cout << "\n\tX. Return";
	cout << "\n\t" << string(60, char(205));

	do
	{
		char option = inputChar("\n\tOption: ");
		cout << "\n\n";
		if (option == 'X' || option == 'x')
			return;

		else if (option == '0')
		{
			int count = 0;
			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getAtomicState() == 0)
				{
					count++;
				}
			}
			cout << "\n\t(" << count << ")" << "Unknown Elements\n";
			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getAtomicState() == 0)
				{
					cout << P1.getElement(i).getSymbol() << " ";
				}
			}
			cout << "\n\n";
			system("pause");
			break;
		}

		else if (option == '1')
		{
			int count = 0;
			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getAtomicState() == 1)
				{
					count++;
				}
			}
			cout << "\n\t(" << count << ")" << "Solid Elements\n";
			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getAtomicState() == 1)
				{
					cout << P1.getElement(i).getSymbol() << " ";
				}
			}
			cout << "\n\n";
			system("pause");
			break;
		}

		else if (option == '2')
		{
			int count = 0;
			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getAtomicState() == 2)
				{
					count++;
				}
			}
			cout << "\n\t(" << count << ")" << "Liquid Elements\n";
			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getAtomicState() == 2)
				{
					cout << P1.getElement(i).getSymbol() << " ";
				}
			}
			cout << "\n\n";
			system("pause");
			break;
		}

		else if (option == '3')
		{
			int count = 0;
			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getAtomicState() == 3)
				{
					count++;
				}
			}

			cout << "\n\t(" << count << ")" << "Gas Elements\n";
			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getAtomicState() == 3)
				{
					cout << P1.getElement(i).getSymbol() << " ";
				}
			}
			cout << "\n\n";
			system("pause");
			break;
		}

		else
		{
			cout << "\n\tInvalid input. Must be a character from the list of '0', '1', '2', '3', or 'X'";
		}

	} while (true);

}
// Searches by Type
void searchByType(PeriodTable &P1)
{

	cout << "\n\t" << string(60, char(205));
	cout << "\n\tClassification Type";
	cout << "\n\t1. Non-metals";
	cout << "\n\t2. Metalloids";
	cout << "\n\t3. Metals";
	cout << "\n\t" << string(60, char(196));
	cout << "\n\tX. Return";
	cout << "\n\t" << string(60, char(205));
	
	do
	{
		char option = inputChar("\n\tOption: ");
		cout << "\n";
		if (option == 'X' || option == 'x')
			return;

		else if (option == '1')
		{
			cout << "\n\tNon - metals are elements on the right of the periodic table.Non - metals can be gases,";
			cout << "\n\tliquids or solids.Non - metals are dull in colour, not shiny like metals.\n";
			int count1 = 0;
			int count2 = 0;
			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 7)
				{
					count1++;
				}
			}

			cout << "\n\t(" << count1 << ")" << "Noble Gases: \n";
			cout << "\t\t";

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 7)
				{
					cout << P1.getElement(i).getSymbol() << " ";
				}
			}

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 8)
				{
					count2++;
				}
			}

			cout << "\n\t(" << count2 << ")" << "Reactive Nonmetals: \n";
			cout << "\t\t";

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 8)
				{
					cout << P1.getElement(i).getSymbol() << " ";
				}
			}

			cout << "\n\n";
			system("pause");
			break;
		}

		else if (option == '2')
		{
			cout << "\n\tMetalloids are a small group of elements founds in the periodic table of elements";
			cout << "\n\talong the zigzag line that distinguishes metals from non - metals.\n";
			int count = 0;
			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 6)
				{
					count++;
				}
			}

			cout << "\n\t(" << count << ")" << "Metalloids: \n";
			cout << "\t\t";

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 6)
				{
					cout << P1.getElement(i).getSymbol() << " ";
				}
			}

			cout << "\n\n";
			system("pause");
			break;
		}

		else if (option == '3')
		{
			cout << "\n\tMetals are elements on the periodic table that are malleable, lose electrons easily,";
			cout << "\n\tgood conductors of heat or electricity, and typically appear reflective.\n";

			int count1 = 0;
			int count2 = 0;
			int count3 = 0;
			int count4 = 0;
			int count5 = 0;
			int count6 = 0;
			int count7 = 0;

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 1)
				{
					count1++;
				}
			}

			cout << "\n\t(" << count1 << ")" << "Actinoids: \n";
			cout << "\t\t";

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 1)
				{
					cout << P1.getElement(i).getSymbol() << " ";
				}
			}

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 2)
				{
					count2++;
				}
			}

			cout << "\n\t(" << count2 << ")" << "Alkali Metals: \n";
			cout << "\t\t";

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 2)
				{
					cout << P1.getElement(i).getSymbol() << " ";
				}
			}

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 3)
				{
					count3++;
				}
			}

			cout << "\n\t(" << count3 << ")" << "Alkaline Earth Metals: \n";
			cout << "\t\t";

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 3)
				{
					cout << P1.getElement(i).getSymbol() << " ";
				}
			}

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 4)
				{
					count4++;
				}
			}

			cout << "\n\t(" << count4 << ")" << "Halogens: \n";
			cout << "\t\t";

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 4)
				{
					cout << P1.getElement(i).getSymbol() << " ";
				}
			}

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 5)
				{
					count5++;
				}
			}

			cout << "\n\t(" << count5 << ")" << "Lanthanoids: \n"; //******************************************There weren't any in the file????***************************//
			cout << "\t\t";

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 5)
				{
					cout << P1.getElement(i).getSymbol() << " ";
				}
			}

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 10)
				{
					count6++;
				}
			}

			cout << "\n\t(" << count6 << ")" << "Transition Metals: \n";
			cout << "\t\t";

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 10)
				{
					cout << P1.getElement(i).getSymbol() << " ";
				}
			}

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 9)
				{
					count7++;
				}
			}

			cout << "\n\t(" << count7 << ")" << "Post-Transition Metals: \n";
			cout << "\t\t";

			for (int i = 0; i < 118; i++)
			{
				if (P1.getElement(i).getType() == 9)
				{
					cout << P1.getElement(i).getSymbol() << " ";
				}
			}

			cout << "\n\n";
			system("pause");
			break;
		}

		else
		{
			cout << "\n\tInvalid input. Must be a character from the list of '1', '2', '3', or 'X'";
		}

	} while (true);
	
}