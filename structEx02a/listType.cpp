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

void listObj::bubbleSort() {

	int start;
	int end;
	int tempNum;

	if (!emptyL()) {
		for (start = 1; start < lastIndex; start++)
		{
			for (end = lastIndex; end >= start; end--)
			{
				if (aList[end - 1] > aList[end])
				{
					tempNum = aList[end - 1];
					aList[end - 1] = aList[end];
					aList[end] = tempNum;
				}
			}
		}
	}
	else
	{
		//list is empty
		cout << "list is empty..." << endl;
	}//end else

}

void listObj::selectionSort()
{
	int start; // an index indicates the array head
	int end;   // an index indicates the rest of array
	int min;   // an index having the minimum
	int temp;  // a varuable for storing

	if (!emptyL()) {
		for (start = 0; start < lastIndex; start++) {
			min = start; // define min as the array head
			for (end = start + 1; end < lastIndex + 1; end++) { // comparison loop
				if (aList[end] < aList[min]) {
					min = end; //update the min index
				}
			}
			//swap the min index with array head index.
			temp = aList[start];
			aList[start] = aList[min];
			aList[min] = temp;
		}
	}
	else
	{
		//list is empty
		cout << "list is empty..." << endl;
	}//end else

}

void listObj::insertionSort()
{
	int i, j;

	if (!emptyL()) {

		for (i = 1; i < lastIndex; i++) { //indicate the not sorted array head

			j = i; // an index for element swap

			// if already sorted, no process
			while ((j > 0) && (aList[j - 1] > aList[j])) {
				// sway two sequencial and not sorted valueables 
				swap(&aList[j - 1], &aList[j]);

				// update the index
				j--;
			}
		}
	}
	else
	{
		//list is empty
		cout << "list is empty..." << endl;
	}//end else

}

void listObj::swap(int *p_from, int *p_to) {
	int tmp;
	tmp = *p_from;
	*p_from = *p_to;
	*p_to = tmp;
}