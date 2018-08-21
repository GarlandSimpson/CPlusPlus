/* Author: Garland Simpson
 *
 * List class source
 */
#include "LinkedList.h"


/* Default constructor */
LinkedList::LinkedList()
{
	first = NULL;
	count = 0;
}

/* InsertInOrder(int,int): inserts elements in order of vertex name and checks for duplicates*/
void LinkedList::insertInOrder(int newVertexName, int newWeight)
{
	//CASE: Element to insert is not already in the list
	if (!inList(newVertexName))
	{
		Node *newNode = new Node(newVertexName, newWeight);

		if (first == NULL)  //CASE: List is empty
		{
			first = newNode;
		}
		else if (count == 1)  //CASE: List has one element
		{
			//CASE: Vertex name is less that that of the first element in the list
			if (first->getVName() > newVertexName)
			{
				newNode->setNext(first);
				first = newNode;
			}
			else
				first->setNext(newNode);

		}
		//CASE: Vertex name is less that that of the first element in the list
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

/* getFirst(): returns a pointer to the first element in the list */
Node *LinkedList::getFirst() const
{
	return first;
}

/*inList(int): Checks if the given intger is already in the list */
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

void LinkedList::insertInBack(int vertexName)
{
	if (!inList(vertexName))
	{
		Node * newNode = new Node(vertexName, -1);
		if (count == 0)
		{
			first = newNode;
			first->setNext(NULL);

		}
		else
		{
			Node * current = first;
			while (current->getNext() != NULL) current = current->getNext();
			current->setNext(newNode);
			current = NULL;
		}
		++count;
	}
}


/*removeNode(int): removes the given node if it exists in the list*/
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

/* printList(): prints the list as space seperated integer values*/
void LinkedList::printList() const
{
	if (first != nullptr)
	{
		Node * current = first;

		while (current != nullptr)
		{
			cout << current->getVName() << " ";
			current = current->getNext();
		}
		cout << endl;
	}
}

/* List Destructor*/
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