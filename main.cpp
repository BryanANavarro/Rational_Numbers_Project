// Bryan Navarro
// November 30, 2022
// Exam 3 

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include "input.h"
#include "Rational.h"

using namespace std;

void vectorMenu();
void displayVector(vector<Rational>);
void listMenu();
void displayList(list<Rational>);
void stackMenu();
void displayStack(stack<Rational>);
void queueMenu();
void queueRecursive(queue<Rational>&);
void displayQueue(queue<Rational>);

int main()
{
	do
	{
		system("cls");
		cout << "\n\t\t\t\t\t\t\t       in/out\t\t\t in\n";
		cout << "\n\t\t\t\t\t\t\ttop >>\t|1/2|\t\trear >> |5/6|";
		cout << "\n\t\t\t\t\t\t\t\t|   |\t\t\t|   |";
		cout << "\n\t\t\t\t\t\t\t\t|3/4|\t\t\t|3/4|";
		cout << "\n\t\t\t\t\t\t\t\t|   |\t\t\t|   |";
		cout << "\n\t1/2 - 3/4 - 5/6\t\t |1/2|>>|3/4|>>|5/6|\t\t|5/6|\t       front >> |1/2|";
		cout << "\n\t0     1     2\t\t head\t\t\t\t\t\t\t out\t";
		cout << "\n\t(index)\t\t\t(pointer)";
		cout << "\n\n\tVector (list array)\t    Linked List\t\t\tStack\t\t\tQueue";

		cout << "\n\n\tA container is a holder object that stores a collection of other objects (its elements). They";
		cout << "\n\tare implemented as class templates, which allows great flexibility in the types supported as";
		cout << "\n\telements. The container manages the storage space for its elements and provides member functions";
		cout << "\n\tto access them, either directly or through iterators(reference objects with similar properties";
		cout << "\n\tto pointers).\n";

		cout << "\n\tCMPR121 Exam 3: STL (Standard Template Library) Containers and Container Adaptors by Bryan Navarro";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t1. Vector Container";
		cout << "\n\t2. List Container";
		cout << "\n\t3. Stack (LIFO) Container Adaptor";
		cout << "\n\t4. Queue (FIFO) Container Adaptor";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t0. Return";
		cout << "\n\t" << string(100, char(205));
		
		switch (inputInteger("\n\tOption: ", 0, 4))
		{
		case 0: return 0;
		case 1: vectorMenu(); break;
		case 2: listMenu(); break;
		case 3: stackMenu(); break;
		case 4: queueMenu(); break;
		}

	} while (true);
	
	return 0;
}

/*
*****************
* VECTORS OPTION**
******************
*/
void vectorMenu()
{
	vector<Rational> num;

	do
	{
		system("cls");
		cout << "\n\tVectors (list array) are same as dynamic arrays with the ability to resize itself automatically";
		cout << "\n\twhen an element is inserted or deleted, that contains their storage being handled automatically";
		cout << "\n\tby the container. Vector elements are placed in contiguous storage so that they can be accessed";
		cout << "\n\tand traversed using iterators or indexes.";
		cout << "\n";
		
		//DISPLAY
		displayVector(num);

		cout << "\n";
		cout << "\n\t\tVector (list array) Menu Options";
		cout << "\n\t" + string(100, char(205));
		cout << "\n\t\t1. Add (push_back) an element";
		cout << "\n\t\t2. Insert an element at index";
		cout << "\n\t\t3. Retrieve an element from index";
		cout << "\n\t\t4. Erase element(s)";
		cout << "\n\t\t5. Sort the vector elements in ascending order";
		cout << "\n\t\t6. Clear all elements";
		cout << "\n\t" + string(100, char(196));
		cout << "\n\t\t0. Return";
		cout << "\n\t" + string(100, char(205));

		//Create rational number
		Rational rationalNum; 

		switch (int option = inputInteger("\n\t\tOption: ", 0, 6))
		{
		case 0: return;
		case 1:
		{
			try
			{
				//sets numerator
				cout << "\n\t\tInput a Rational number [numerator/denominator] to be added...";
				rationalNum.setNumerator(inputInteger("\n\t\t\tEnter a value (-9...9) for the numerator  : ", -9, 9));

				//sets denominator
				rationalNum.setDenominator(inputInteger("\t\t\tEnter a value (-9...9) for the denominator: ", -9, 9));
			}
			catch (Rational::ZeroDenominator)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << rationalNum << ", that contains a zero denominator value\n\n";
				system("pause");
				break;
			}	
			
			//display value
			cout << "\n\t\t [" << rationalNum.getNumerator() << '/' << rationalNum.getDenominator() << "] will be added to the back of the vector.";
			
			//add to vector
			num.push_back(rationalNum);

			cout << "\n\n";
			system("pause");
		}
		break;
		
		//INSERT AT A CERTAIN POSITION IN VECTOR
		case 2:
		{
			//INDEX
			int index = num.size();
			try
			{
				cout << "\n\t\tInput a Rational number [numerator/denominator] to be inserted...";

				//sets numerator
				rationalNum.setNumerator(inputInteger("\n\t\t\tEnter a value (-9...9) for the numerator  :", -9, 9));

				//sets denominator
				rationalNum.setDenominator(inputInteger("\t\t\tEnter a value (-9...9) for the denominator:", -9, 9));
			}
			
			catch (Rational::ZeroDenominator)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << rationalNum << ", that contains a zero denominator value\n\n";
				system("pause");
				break;
			}

			if (num.empty())
			{
				//0 position in vector if empty
				int indexChoice = 0;
				num.insert(num.begin() + indexChoice, rationalNum);
				cout << "\n\t\t[" << rationalNum.getNumerator() << '/' << rationalNum.getDenominator() << "] will be inserted at index " << indexChoice << " of the vector.";
				cout << "\n\n";
				system("pause");
				break;
			}
			
			//USERS INPUT FOR POSITION 
			int indexChoice = inputInteger("\n\t\tInsert the Rational number at index (0..." + to_string(num.size() - 1) + ") of the vector : ", 0, index - 1);

			cout << "\n\t\t[" << rationalNum.getNumerator() << '/' << rationalNum.getDenominator() << "] will be inserted at index " << indexChoice << " of the vector.";

			//INSERTS AT POSITION WITH VALUE
			num.insert(num.begin() + indexChoice, rationalNum);

			cout << "\n\n";
			system("pause");
		}
		break;
		
		//FIND VALUE AT A POSITION IN VECTOR
		case 3:
		{
			if (num.empty())
			{
				cout << "\n\t\tERROR: Retrieve operation cannot be performed from an empty vector.";
				cout << "\n\n";
				system("pause");

				break;
			}
			
			int index = num.size();
			int indexChoice = inputInteger("\n\tEnter an index (0..." + to_string(num.size() - 1) + ") of rational number to be retrieved: ", 0, index - 1);
			cout << "\n\t\t" << num[indexChoice] << " is located at at index(" << indexChoice << ") from the vector.";

			cout << "\n\n";
			system("pause");
			
		}
		break;
		
		case 4:
		{
			Rational element;
			try
			{
				if (num.empty())
				{
					cout << "\n\t\tERROR: Erase operation cannot be performed onto an empty vector.";
					cout << "\n\n";
					system("pause");

					break;
				}

				cout << "\n\t\tInput a Rational number [numerator/denominator] to be removed...";

				//SETS NUMERATOR
				element.setNumerator(inputInteger("\n\t\t\tEnter a value (-9...9) for the numerator  : ", -9, 9));

				//SETS DENOMINATOR
				element.setDenominator(inputInteger("\t\t\tEnter a value (-9...9) for the denominator: ", -9, 9));
			}
			catch (Rational::ZeroDenominator)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, [" << element << "], that contains a zero denominator value\n\n";
				system("pause");
				break;
			}
			//INDEX
			int index = 0;

			//COUNT INSTANCES
			int counter = 0;
			for (int i = 0; i < num.size(); i++)
			{
				if (element == num[i])
					counter++;
			}

			//FLAG
			bool flag = true;
			if (counter >= 1)
			{
				do
				{
					//char choice = inputChar("\n\t\tDo you want to remove(O - one or A - all) element(s) :", true);

					switch (toupper(inputChar("\n\t\tDo you want to remove(O - one or A - all) element(s) :", true)))
					{
					// DELETES ONLY ONE 
					case 'O':
					{
						for (int i = 0; i < num.size(); i++)
						{
							if (element == num[i])
							{
								num.erase(num.begin() + i); // DELETES ONLY ONE 
								flag = false; 
								cout << "\n\t\t[" << element.toString() << "] will be removed from the list.\n\n";
								break;
							}
						}

					}
					break;
					// DELETE ALL OPTION
					case 'A':
					{
						for (int i = 0; i < num.size(); i++)
						{
							if (element == num[i])
							{
								num.erase(remove(num.begin(), num.end(), element)); //LOOPS THROUGH AND DELETES EVERY FOUND ELEMENT 
								flag = false; 
							}
						}
						cout << "\n\t\t[" << element.toString() << "] will be removed from the list.\n\n";
					}
					break;

					default: cout << "\tERROR: Invalid option\n\n"; system("pause"); break;
					}
				} while (flag == true);

				system("pause");
				break;
			}

			cout << "\n\t\t[" << element << "] was not found from the vector.";

			cout << "\n\n";
			system("pause");
		}
		break;
		// SORTS VECTOR SORT()
		case 5:
		{
			if (num.empty())
			{
				cout << "\n\t\tERROR: Sort operation cannot be performed on an empty vector.";
				cout << "\n\n";
				system("pause");

				break;
			}

			cout << "\n\t\tThe vector of Rational numbers will be sorted in ascending order.";

			sort(num.begin(), num.end()); // SORT FROM BEGINNING OF VECTOR TO END OF VECTOR
			cout << "\n\n";
			system("pause");
		}
		break;
		
		//CLEAR VECTOR USING CLEAR()
		case 6:
		{
			if (num.empty())
			{
				cout << "\n\t\tERROR: Clear operation cannot be performed on an empty vector.";
				cout << "\n\n";
				system("pause");
				break;
			}

			cout << "\n\t\tThe Vector will be cleared of all Rational Element";
			cout << "\n\n";
			system("pause");
			num.clear(); //CLEARS THE VECTOR
		}
		break;
		
		default: cout << "\tERROR: Invalid option\n\n"; system("pause"); break;
		}

		cout << "\n\n";
	} while (true);

	system("pause");
}

/*
******************
* DISPLAY VECTOR**
******************
*/

void displayVector(vector<Rational> num)
{
	if (num.empty())
	{
		cout << "\n\tThe current Vector is empty.";
		return;
	}

	cout << "\n\tThe current vector contains " << num.size() << " elements: ";

	cout << "\n\n\t\t";
	for (int i = 0; i < num.size(); i++)
	{
		cout << '[' << num[i].toString() << ']';
	}

	cout << "\n\tIndex:\t";

	for (int i = 0; i < num.size(); i++)
	{
		cout << i << "    ";
	}

	cout << "\n\n\tMemory Address: " << &num; //ADDRESS
}

/*
**********************
* LINKED LIST OPTION**
**********************
*/

void listMenu()
{
	list<Rational> num;

	do
	{
		system("cls");
		cout << "\n\tLinked lists are sequence containers that allow non-contiguous memory allocation. As compared to";
		cout << "\n\tvector, the linked list has slow traversal, but once a position has been found, insertion and";
		cout << "\n\tdeletion are quicker.";
		cout << "\n";
		
		//DISPLAY LIST
		displayList(num);

		cout << '\n';

		cout << "\n\t\tLinked List Menu Options";
		cout << "\n\t" + string(100, char(205));
		cout << "\n\t\t1. Add (push) an element";
		cout << "\n\t\t2. Insert an element after";
		cout << "\n\t\t3. Remove element(s)";
		cout << "\n\t\t4. Sort the elements in ascending order";
		cout << "\n\t\t5. Clear all elements";
		cout << "\n\t" + string(100, char(196));
		cout << "\n\t\t0. Return";
		cout << "\n\t" + string(100, char(205));

		//create class
		Rational rationalNum;

		switch (int option = inputInteger("\n\t\tOption: ", 0, 5))
		{
		case 0: return;
		//ADDING A 
		case 1:
		{
			try
			{
				//SETS NUMERATOR
				cout << "\n\t\tInput a Rational number [numerator/denominator] to be added...";
				rationalNum.setNumerator(inputInteger("\n\t\t\tEnter a value (-9...9) for the numerator  : ", -9, 9));

				//SETS DENOMINATOR
				rationalNum.setDenominator(inputInteger("\t\t\tEnter a value (-9...9) for the denominator: ", -9, 9));
			}

			catch (Rational::ZeroDenominator)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, [" << rationalNum.toString() << "], that contains a zero denominator value\n\n";
				system("pause");
				break;
			}
			
			//PUSH FRONT IF EMPTY
			if (num.empty())
			{
				cout << "\n\t\t[" << rationalNum.getNumerator() << '/' << rationalNum.getDenominator() << "] will be added to the empty list.";

				num.push_front(rationalNum);

				cout << "\n\n";
				system("pause");
				break;
			}

			//FLAG
			bool flag = true;
			do
			{
				switch (toupper(inputChar("\n\t\tAdd to the (F-front) or from the (B-back): ", true)))
				{
				// PUSH_BACK() FUNCTION
				case 'B':
				{
					num.push_back(rationalNum); 
					cout << "\n\t\t[" << rationalNum.getNumerator() << '/' << rationalNum.getDenominator() << "] will be pushed to the back of the list.";
					flag = false;
				}
				break;
				
				// PUSH_FRONT() FUNCTION
				case 'F':
				{
					num.push_front(rationalNum); 
					cout << "\n\t\t[" << rationalNum.getNumerator() << '/' << rationalNum.getDenominator() << "] will be pushed to the front of the list.";
					flag = false; //so that it can break out
				}
				break;
					
				default: cout << "\tERROR: Invalid Input. Must be a 'F' or 'B' character\n\n"; break;
				}
			} while (flag == true);

			cout << "\n\n";
			system("pause");
		}
		break;
		// INSERTS AT A POSITION IN THE LIST
		case 2:
		{
			try
			{
				//SETS NUMERATOR
				cout << "\n\t\tInput a Rational number [numerator/denominator] to be added...";
				rationalNum.setNumerator(inputInteger("\n\t\t\tEnter a value (-9...9) for the numerator  : ", -9, 9));

				//SETS DENOMINATOR
				rationalNum.setDenominator(inputInteger("\t\t\tEnter a value (-9...9) for the denominator: ", -9, 9));
			}

			catch (Rational::ZeroDenominator)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, [" << rationalNum.toString() << "], that contains a zero denominator value\n\n";
				system("pause");
				break;
			}

			//PUSH_FRONT IF EMPTY LIST
			if (num.empty())
			{
				cout << "\n\t\t[" << rationalNum.getNumerator() << '/' << rationalNum.getDenominator() << "] will be added to the empty list.";

				num.push_front(rationalNum);

				cout << "\n\n";
				system("pause");
				break;
			}

			//USING ELEMENT TO FIND IN LIST
			Rational element;
			try
			{
				//SETS NUMERATOR
				cout << "\n\t\tInput an existing Rational number as the insert position to be added...";
				element.setNumerator(inputInteger("\n\t\t\tEnter a value (-9...9) for the numerator  :", -9, 9));

				//SETS DENOMINATOR
				element.setDenominator(inputInteger("\t\t\tEnter a value (-9...9) for the denominator:", -9, 9));
			}

			catch (Rational::ZeroDenominator)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, [" << element.toString() << "], that contains a zero denominator value\n\n";
				system("pause");
				break;
			}
			
			//FLAG
			bool flag = false;

			for (auto iter = num.begin(); iter != num.end(); iter++)
			{
				if (*iter == element)
				{
					do
					{
						switch (toupper(inputChar("\n\t\tInsert(B - before) or (A - after) the existing element : ")))
						{
						// INSERTS AFTER THE POSITION OF EXISTING ELEMENT
						case 'A':
						{
							// IF LIST IS SIZE OF 1, PUSH_BACK TO NOT ADD OUT OF SCOPE OF THE ITERATOR
							if (num.size() == 1)
							{
								cout << "\n\t[" << rationalNum.toString() << "] will be inserted after the existing element from the list.";
								num.push_back(rationalNum);
								flag = true;

								break;
							}
							// INSERTS AFTER THE POSITION OF THE EXISTING ELEMENT
							num.insert(++iter, rationalNum);
							cout << "\n\t[" << rationalNum.toString() << "] will be inserted after the existing element from the list.";
							flag = true;

							break;
						}
						// INSERTS BEFORE THE POSITION OF EXISTING ELEMENT
						case 'B':
						{
							num.insert(iter, rationalNum);
							cout << "\n\t[" << rationalNum.toString() << "] will be inserted after the existing element from the list.";
							flag = true;

							break;
						}
						default: cout << "\tERROR: Invalid input. Must be a 'B' or 'A' character : "; system("pause"); break;
						}
					} while (flag == false);
				}
			}

			// IF NOT FOUND
			if (flag == false)
			{
				cout << "\n\t\t[" << element.toString() << "] cannot be found from the list.";
			}
			cout << "\n\n";
			system("pause");
			
		}
		break;
		
		//DELETE IN LIST
		case 3:
		{
			Rational element;
			try
			{
				// IF EMPTY, RETURN
				if (num.empty())
				{
					cout << "\n\t\tERROR: Erase operation cannot be performed onto an empty list.";
					cout << "\n\n";
					system("pause");

					break;
				}

				cout << "\n\t\tInput a Rational number [numerator/denominator] to be removed...";

				//SETS NUMERATOR
				element.setNumerator(inputInteger("\n\t\t\tEnter a value (-9...9) for the numerator  : ", -9, 9));

				//SETS DENOMINATOR
				element.setDenominator(inputInteger("\t\t\tEnter a value (-9...9) for the denominator: ", -9, 9));
			}

			catch (Rational::ZeroDenominator)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, [" << element.toString() << "], that contains a zero denominator value\n\n";
				system("pause");
				break;
			}

			//COUNT HOW MANY IS FOUND IN LIST
			int counter = 0;
			for (auto it = num.begin(); it != num.end(); ++it)
			{
				if (*it == element)
					counter++;
			}

			//FLAG
			bool flag = true;
			
			if (counter >= 1)
			{
				do
				{
					
					switch (toupper(inputChar("\n\t\tDo you want to remove(O - one or A - all) element(s) :", true)))
					{
					// DELETES ONLY ONE INSTANCE
					case 'O':
					{
						for (auto it = num.begin(); it != num.end(); ++it)
						{
							if (*it == element)
							{
								num.erase(it);
								flag = false;
								cout << "\n\t\t[" << element.toString() << "] will be removed from the list.";
								break; // LOOPS ONCE AND BREAKS OUT 
							}
						}
					}
					break;
					// DELETES ALL INSTANCES
					case 'A':
					{
						for (auto it = num.begin(); it != num.end(); ++it)
						{
							num.remove(element); // REMOVE FUNCTION DELETES AT EVERY POSITION EQUAL TO THE VALUE OF THE ARGUMENT
							flag = false;
							cout << "\n\t\t[" << element.toString() << "] will be removed from the list.";
							break; 
						}
					}
					break;

					default: cout << "\tERROR: Invalid option\n\n"; system("pause"); break;
					}

				} while (flag == true);
			}
			// IF NOT FOUND
			if (flag == true)
			{
				cout << "\n\t\t[" << element.toString() << "] was not found from the list.";
			}
			
			cout << "\n\n";
			system("pause");
		}
		break;
		// SORTS THE LIST IN ASCENDING ORDER
		case 4:
		{
			if (num.empty())
			{
				cout << "\n\t\tERROR: Sort operation cannot be performed on an empty list.";
				cout << "\n\n";
				system("pause");

				break;
			}

			cout << "\n\t\tThe list of Rational numbers has been sorted.";
			num.sort(); // SORT FUNCTION

			cout << "\n\n";
			system("pause");
		}
		break;
		// CLEARS THE LIST
		case 5:
		{
			if (num.empty())
			{
				cout << "\n\t\tERROR: Empty operation cannot be performed on an empty list.";
				cout << "\n\n";
				system("pause");

				break;
			}

			num.clear(); // CLEARS THE LIST
			cout << "\n\n\tThe list has been cleared of all Rational element(s).";
			cout << "\n\n";
			system("pause");
		}
		break;
		
		default: cout << "\tERROR: Invalid option\n\n"; system("pause"); break;
		}

		cout << "\n\n";
	} while (true);

	system("pause");
}

/*
***********************
* LINKED LIST DISPLAY**
***********************
*/

void displayList(list<Rational> num)
{
	if (num.empty())
	{
		cout << "\n\tThe current list is empty.";
		return;
	}

	cout << "\n\tThe current linked list contains " << num.size() << " elements: ";
	cout << "\n\n\t";
	
	for (auto element : num)
	{
		cout << '[' << element << ']' << "->";
	}
	cout << "NULL";
	cout << "\n\n\tMemory Address: " << &num;
}


/*
*****************
* STACK OPTION **
*****************
*/

void stackMenu()
{
	stack<Rational> num;
	do
	{
		system("cls");
		cout << "\n\tStacks are a type of container adaptors with LIFO(Last In First Out) type of working, where";
		cout << "\n\ta new element is added(pushed) at one end(top) and an element is removed(popped) from that end";
		cout << "\n\tonly. Stack uses an encapsualted object of either vector or deque(by default) or list (sequential";
		cout << "\n\tcontainer class) as its underlying container, providing a specific set of member functions to";
		cout << "\n\taccess its elements.";
		cout << "\n";

		// DISPLAY STACK
		displayStack(num);

		cout << "\n";
		cout << "\n\t\tStack Menu Options";
		cout << "\n\t" + string(100, char(205));
		cout << "\n\t\t1. Push";
		cout << "\n\t\t2. Top";
		cout << "\n\t\t3. Pop";
		cout << "\n\t" + string(100, char(196));
		cout << "\n\t\t0. Return";
		cout << "\n\t" + string(100, char(205));


		Rational rationalNum;

		switch (int option = inputInteger("\n\t\tOption: ", 0, 3))
		{
		case 0: return;
			case 1: 
			{
				try
				{
					//SETS NUMERATOR
					cout << "\n\t\tInput a Rational number [numerator/denominator] to be pushed...";
					rationalNum.setNumerator(inputInteger("\n\t\t\tEnter a value (-9...9) for the numerator  : ", -9, 9));

					//SETS DENOMINATOR
					rationalNum.setDenominator(inputInteger("\t\t\tEnter a value (-9...9) for the denominator: ", -9, 9));

					cout << "\n\t\t [" << rationalNum.getNumerator() << '/' << rationalNum.getDenominator() << "] will be pushed onto the stack.";
				}
				catch (Rational::ZeroDenominator)
				{
					cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, [" << rationalNum.toString() << "], that contains a zero denominator value\n\n";
					system("pause");
					break;
				}
				num.push(rationalNum); // PUSH() FUNCTION PUSHES ONTO THE TOP OF THE STACK
				cout << "\n\n";
				system("pause");
			}
			break;
			// PEAKS AT THE TOP OF THE STACK
			case 2:
			{
				if (num.empty())
				{
					cout << "\n\t\tERROR: No top operation can be performed on an empty stack.";
					cout << "\n\n";
					system("pause");
					break;
				}

				cout << "\n\t[" << num.top() << "] is at the top of the stack."; // TOP() FUNCTION 
				cout << "\n\n";
				system("pause");

			}
			break;
			// POPS THE TOP OF THE STACK
			case 3:
			{
				if (num.empty())
				{
					cout << "\n\t\tERROR: No pop operation can be performed on an empty stack.";
					cout << "\n\n";
					system("pause");
					break;
				}

				cout << "\n\t[" << num.top() << "] will be popped from the stack.";
				num.pop(); // POP() FUNCTION
				cout << "\n\n";
				system("pause");
			}
			break;
		}
	} while (true);

	cout << "\n\n";
	system("pause");
}

/*
*******************
* RECURSIVE STACK**
*******************
*/

void displayStackRecursive(stack<Rational> stack)
{
	if (stack.empty())
		return;
	
	cout << "[" << stack.top() << "]";
	stack.pop();
	displayStackRecursive(stack);
}

/*
*******************
* STACK DISPLAY****
*******************
*/

void displayStack(stack<Rational> num)
{
	if (num.empty())
	{
		cout << "\n\tThe current stack is empty.";
		return;
	}

	cout << "\n\tThe current stack contains " << num.size() << " elements: ";

	cout << "\n\n\ttop ->";
	displayStackRecursive(num);

	cout << "\n\n\tMemory Address: " << &num;
}

/*
*******************
* QUEUE OPTION ****
*******************
*/
void queueMenu()
{
	queue<Rational> num;

	do 
	{
		system("cls");
		cout << "\n\tQueues are type of container adaptors that operate in a first in first out (FIFO) type of";
		cout << "\n\tarrangement. Elements are inserted/pushed(enqueued) at the rear and are removed/popped(dequeued)";
		cout << "\n\tfrom the front. Queues use an encapsulated object of deque or list(sequential container class)";
		cout << "\n\tas its underlying container, providing a specific set of member functions to access elements.";
		cout << "\n";
		
		queueRecursive(num); // REVERSES THE QUEUE
		displayQueue(num); // DISPLAYS THE REVERSE QUEUE
		queueRecursive(num); // REVERSES THE QUEUE BACK TO ORIGINAL QUEUE 

		cout << "\n";
		cout << "\n\t\tQueue Menu Options";
		cout << "\n\t" + string(100, char(205));
		cout << "\n\t\t1. Enqueue (Push into the Rear)";
		cout << "\n\t\t2. Rear";
		cout << "\n\t\t3. Front";
		cout << "\n\t\t4. Dequeue (Pop from the Front)";
		cout << "\n\t" + string(100, char(196));
		cout << "\n\t\t0. Return";
		cout << "\n\t" + string(100, char(205));

		Rational rationalNum;
		
		switch (int option = inputInteger("\n\t\tOption: ", 0, 4))
		{
		case 0: return;
		// ENQUEUE (PUSH INTO THE REAR)
		case 1: 
		{
			try
			{
				//SETS NUMERATOR
				cout << "\n\t\tInput a Rational number [numerator/denominator] to be enqueued (pushed)...";
				rationalNum.setNumerator(inputInteger("\n\t\t\tEnter a value (-9...9) for the numerator  : ", -9, 9));

				//SETS DENOMINATOR
				rationalNum.setDenominator(inputInteger("\t\t\tEnter a value (-9...9) for the denominator: ", -9, 9));

				cout << "\n\t\t [" << rationalNum.getNumerator() << '/' << rationalNum.getDenominator() << "] will be enqueued (pushed) onto the queue.";
			}
			catch (Rational::ZeroDenominator)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, [" << rationalNum.toString() << "], that contains a zero denominator value\n\n";
				system("pause");
				break;
			}

			num.push(rationalNum); // PUSH() FUNCTION PUSHES VALUE THROUGH THE QUEUE FROM THE REAR
			cout << "\n\n";
			system("pause");
		}
		break;
		// LOOK AT REAR OF THE QUEUE
		case 2:
		{
			if (num.empty())
			{
				cout << "\n\t\tERROR: No back operation can be retrieved from an empty queue.";
				cout << "\n\n";
				system("pause");
				break;
			}

			cout << "\n\t\t[" << num.back() << "] is at the back of the queue."; // BACK() FUNCTION SHOWS THE VALUE AT THE BACK OF THE QUEUE
			cout << "\n\n";
			system("pause");
		}
		break;
		// LOOK AT THE FRONT OF THE QUEUE
		case 3:
		{
			if (num.empty())
			{
				cout << "\n\t\tERROR: No front operation can be retrieved from an empty queue.";
				cout << "\n\n";
				system("pause");
				break;
			}

			cout << "\n\t\t[" << num.front() << "] is at the front of the queue."; // FRONT() FUNCTION SHOWS THE VALUE AT THE FRONT  OF THE QUEUE
			cout << "\n\n";
			system("pause");
		}
		break;
		// DEQUEUE (POP FROM THE FRONT)
		case 4:
		{
			if (num.empty())
			{
				cout << "\n\t\tERROR: No dequeue (pop) operation cannot be performed on an empty queue.";
				cout << "\n\n";
				system("pause");
				break;
			}

			cout << "\n\t\t[" << num.front() << "] will be dequeued (popped) from the queue."; // 
			num.pop(); // POP() FUNCTION POPS VALUE AT THE FRONT OF THE QUEUE
			cout << "\n\n";
			system("pause");
		}
		}
		

	} while (true);
	
	cout << "\n\n";
	system("pause");
}

/*
*******************
* QUEUE RECURSIVE *
*******************
*/
void queueRecursive(queue<Rational> &queue)
{
	if (queue.empty())
		return;
	
	Rational temp = queue.front(); //SAVE THE FRONT VALUE, POP FROM ARGUMENT
	queue.pop();
	queueRecursive(queue); //RECURSIVE TO KEEP SAVING THE VALUES
	queue.push(temp); // PUSHES VALUES INTO TEMP AND DISPLAYED IN REVERSE ORDER
	
}

/*
*******************
* QUEUE DISPLAY ***
*******************
*/
void displayQueue(queue<Rational>num)
{
	if (num.empty())
	{
		cout << "\n\tThe current queue is empty.";
		return;
	}

	cout << "\n\tThe current queue contains " << num.size() << " element: ";
	cout << "\n\n\tIn(Rear) -> ";
	
	while (!num.empty())
	{
		cout << "[" << num.front() << "]";
		num.pop();
	}
	
	cout << "-> out(front)";

	cout << "\n\n\tMemory Address: " << &num;
	
}
