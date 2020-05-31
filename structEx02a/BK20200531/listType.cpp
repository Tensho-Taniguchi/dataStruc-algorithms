#include "stdafx.h"
#include <iostream>
#include "listType.h"
using namespace std;

void listObj::initL()
{
	lastIndex = -1;

}//end initialize the List

bool listObj::addL(int x)
{
	if (isFull())
		return false; //not able to add
					  //the list is full
	else
	{//ok to add
		lastIndex++;
		aList[lastIndex] = x;
		return true;
	}//add to the list

}//end add to the list

bool listObj::deleteL(int itemToDelete) {

	int index;

	//search method to find where the delete number exists or not
	index = searchL(itemToDelete);
	if (index == -1) {
		return false;
	}
	else if (index == 0 && lastIndex == 0) {
		lastIndex = -1;
		return true;
	}
	else
	{
		for (int j = index; j < lastIndex; j++) {
			aList[j] = aList[j + 1];
		}
		lastIndex--;
		return true;
	}
}

void listObj::displayL()
{
	if (!emptyL())
	{
		cout << "\nDisplaying the list\n";
		for (int j = 0; j <= lastIndex; j++)
		{
			cout << "item [" << j + 1 << "] = " << aList[j] << endl;
		}//end for
	}
	else
	{
		//list is empty
		cout << "list is empty..." << endl;
	}//end else

}//end display

bool listObj::emptyL()
{
	if (lastIndex == -1)
		return true;
	else
		return false;
}//end is Full

int listObj::searchL(int key) {
	if (emptyL()) {
		//not found
		return -1;
	}
	else {
		//debugging
		for (int i = 0; i <= lastIndex; i++) {
			if (aList[i] == key) {
				return i;
			}
		}//end for
		 //after checking all elements 
		 //item is not on the list
		return -1;
	}//end if
}//end search

void listObj::clearL() {
	lastIndex = -1;
}

bool listObj::isFull()
{
	if (lastIndex == (MAX - 1))
		return true;
	else
		return false;
}//end is Full




