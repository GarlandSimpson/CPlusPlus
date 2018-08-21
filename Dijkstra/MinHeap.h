/*
* Author: Garland Simpson
* NOTE: LinkedList Class is fully tested and appears to be bug free
*/
#ifndef MINHEAP_H
#define MINHEAP_H

#include <string>
#include <iostream>

using namespace std;


/*
- This Edge class works very similar to Node class. Main difference is
the private member variables. I relabled it to Vert for the MinHeap which i
store all my edges in.
*/

class Vert
{
public:
	Vert() {}
	Vert(int vName, int theWeight) { next = NULL; v = vName; weight = theWeight; }
	Vert *getNext() const { return next; }
	int getWeight() const { return weight; }
	int getVName() const { return v; }
	void setNext(Vert *newNode) { next = newNode; }
	void setWeight(int newWeight) { weight = newWeight; }
	void setVName(int newVName) { v = newVName; }
	~Vert() {}

private:
	Vert * next;
	int v;
	int weight;
};


class MinHeap
{
public:
	MinHeap();
	void insertInOrder(int newVName, int newWeight);
	Vert *getFirst() const;
	bool inList(int vName) const;
	int getSize() const;
	void deleteFirst();
	bool empty() const;
	~MinHeap();

private:
	Vert * first;
	int size;
};

#endif
