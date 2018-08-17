/*
	Simpson, Garland
	CS A250
	April (4), (2015)

	Ex 12
*/

#include "DLL_ChildClass.h"

// Definition of copy constructor
DLL_ChildClass::DLL_ChildClass(const DLL_ChildClass& other) 
{	
	Node *current = other.first; // Pointer to the rhs
	
	while (current != NULL) // Traverse the list
	{
		insertBack(current->getData()); // Insert to back the data at current
		current = current->getNextLink(); // Move current
	}
	current = NULL; 
}

// Definition of overloaded assignment operator
DLL_ChildClass& DLL_ChildClass::operator=(const DLL_ChildClass& other)
{
	if (this == &other) // CASE: lhs == rhs
		cerr << "Attempted assignment to itself";

	else if (count == 0) // CASE: lhs is empty
	{
		Node *current = other.first; // pointer to lhs

		while (current != NULL) // Fill lhs with rhs data
		{
			insertBack(current->getData());
			current = current->getNextLink();
		}
		current = NULL;
	}
	else if (other.count == 0) // CASE: rhs is empty
		destroyList();

	else 
	{
		Node *current = first; // Pointer to lhs

		// make lhs and rhs the same size
		while (count != other.count)
		{
			if (count < other.count) // CASE: lhs < rhs 
				insertBack(0); // increase lhs size

			else // CASE: lhs > rhs
			{
				//Shorten lhs(removing from the front)
				first = first->getNextLink();
				delete current;
				current = first;
				count--;
			}
		}

		Node *otherCurrent = other.first; 

		//Travers the list
		while (current != NULL)
		{
			// set lhs data to rhs data
			current->setData(otherCurrent->getData());

			// move the pointers
			current = current->getNextLink();
			otherCurrent = otherCurrent->getNextLink();
		}
		current = NULL;
		otherCurrent = NULL;
	}
	return *this; // return a pointer to this
}
