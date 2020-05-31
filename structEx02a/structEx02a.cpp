// structEx02a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "listType.h"

using namespace std;

int displayMenu(); //prototype for menu choice

int main()
{
	int choice;
	bool success = false;
	int itemToAdd;
	int itemToDetele;

	//listType theList; //create the list (uninitialized)
	listObj theList;
	theList.initL(); //prepare the list for use - very important step!

	do
	{
		choice = displayMenu();
		switch (choice)
		{
		case 0: //exit
			cout << "Thank you, good bye.\n";
			break;
		case 1: //display
			theList.displayL();
			//displayL(theList);
			cout << endl;
			break;
		case 2: //add
			cout << "Enter item to add: ";
			cin >> itemToAdd;
			success = theList.addL(itemToAdd);
			if (success)
				cout << "add worked...";
			else
				cout << "unsuccessful add";
			cout << endl;
			break;
		case 3:
			cout << "Enter item to delete: ";
			cin >> itemToDetele;
			success = theList.deleteL(itemToDetele);
			if (success)
				cout << "delete worked...";
			else
				cout << "unsuccessful delete";
			cout << endl;
			break;
		case 4: //clear
			theList.clearL();
			cout << "\nSuccessfully, cleared the list\n";
			cout << endl;
			break;
		case 5: //bubble sort
			theList.bubbleSort();
			cout << "\nSuccessfully, conducted the bubble sort.\n";
			cout << endl;
			break;
		case 6: //selection sort
			theList.selectionSort();
			cout << "\nSuccessfully, conducted the selection sort.\n";
			cout << endl;
			break;
		case 7: //insertion sort
			theList.selectionSort();
			cout << "\nSuccessfully, conducted the insertion sort.\n";
			cout << endl;
			break;
		default:
			cout << "not yet supported choice..\n";
			break;

		}//end switch
	} while (choice != 0);


	system("pause");
	return 0;
}//end main

int displayMenu()
{
	int choice;
	cout << endl;
	cout << "==============================" << endl;
	cout << "choice 1: display " << endl;
	cout << "choice 2: add" << endl;
	cout << "choice 3: delete" << endl;
	cout << "choice 4: clear" << endl;
	cout << "choice 5: bubble sort" << endl;
	cout << "choice 6: selection sort" << endl;
	cout << "choice 7: insertion sort" << endl;
	cout << "enter 0 to quit." << endl;
	cout << "==============================" << endl;
	cin >> choice;
	return choice;
}
