#include "LinkedList.h"


LinkedList::LinkedList()
{
	first = NULL;
	count = 0;
}

void LinkedList::insertInOrder(int newVertexName, int newWeight)
{
	if (!inList(newVertexName)) 
	{
		Node *newNode = new Node(newVertexName, newWeight);

		if (first == NULL)
		{
			first = newNode;
		}
		else if (count == 1)
		{
			if (first->getVName() > newVertexName) 
			{
				newNode->setNext(first);
				first = newNode;
			}
			else
				first->setNext(newNode);
			
		}
		else if (first->getVName() > newVertexName)
		{
			newNode->setNext(first);
			first = newNode;
		}
		else
		{
			Node *current = first->getNext();
			Node *tail = first;
		
			while (current != NULL && current->getVName() < newVertexName)
			{
				current = current->getNext();
				tail = tail->getNext();
			}
			tail->setNext(newNode);
			newNode->setNext(current);
			tail = current = NULL;
		}
		count++;
	}
	else cerr << "Value to to insert is already in use" << endl;
	
}

Node *LinkedList::getFirst() const
{
	return first;
}

bool LinkedList::inList(int vertexName) const
{
	if (first != NULL)
	{
		Node * current = first;

		while (current != NULL)
		{
			if (current->getVName() == vertexName)
			{
				current = NULL;
				return true;
			}
			current = current->getNext();
		}
	}
	return false;
}

void LinkedList::removeNode(int theVertexName)
{
	if (!inList(theVertexName)) // CASE: element is not in list
	{
		cerr << "List error: Node to delete is not in List" << endl;
	}
	else if (first == NULL) // CASE: list to delete from is empty
	{
		cerr << "List error: cannot delete from empty list" << endl;
	}
	else
	{
		// CASE: item to delete is the first element OR list contains only one element
		if (first->getVName() == theVertexName || count == 1) 
		{
			Node *temp = first;
			first = first->getNext();
			delete temp;

		}
		else
		{
			Node *current = first->getNext();
			Node *tail = first;

			while (current->getVName() != theVertexName)
			{
				current = current->getNext();
				tail = tail->getNext();
			}

			tail->setNext(current->getNext());
			delete current;
			tail = NULL;
		}
		count--;
	}
}

LinkedList::~LinkedList()
{
	Node *temp;

	while (first != NULL)
	{
		temp = first;
		first = first->getNext();
		delete temp;
		temp = NULL;
	}
}
