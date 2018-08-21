/*
* Author: Garland Simpson
* NOTE: LinkedList Class is fully tested and appears to be bug free
*/
#include "MinHeap.h"


/* Default constructor */
MinHeap::MinHeap()
{
	first = NULL;
	size = 0;
}

void MinHeap::insertInOrder(int newVName, int newWeight)
{
	if (!inList(newVName))
	{
		Vert *newNode = new Vert(newVName, newWeight);

		if (first == NULL)
		{
			first = newNode;
		}
		else if (size == 1)
		{
			if (first->getWeight() > newWeight)
			{
				newNode->setNext(first);
				first = newNode;
			}
			else
				first->setNext(newNode);

		}
		else if (first->getWeight() > newWeight)
		{
			newNode->setNext(first);
			first = newNode;
		}
		else
		{
			Vert *current = first->getNext();
			Vert *tail = first;

			while (current != NULL && current->getWeight() <= newWeight)
			{
				current = current->getNext();
				tail = tail->getNext();
			}
			tail->setNext(newNode);
			newNode->setNext(current);
			tail = current = NULL;
		}
		size++;
	}
	else cerr << "Value to to insert is already in use" << endl;
}

Vert *MinHeap::getFirst() const { return first; }

bool MinHeap::inList(int vName) const
{
	if (first != NULL)
	{
		Vert * current = first;

		while (current != NULL)
		{
			if (current->getVName() == vName)
			{
				current = NULL;
				return true;
			}
			current = current->getNext();
		}
	}
	return false;
}

int MinHeap::getSize() const { return size; }

void MinHeap::deleteFirst()
{
	if (first != NULL)
	{
		Vert *temp = first;
		first = first->getNext();
		delete temp;
		size--;
	}
}

bool MinHeap::empty() const { return size == 0; }

MinHeap::~MinHeap()
{
	Vert *temp;

	while (first != NULL)
	{
		temp = first;
		first = first->getNext();
		delete temp;
		temp = NULL;
	}
}
