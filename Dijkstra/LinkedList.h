/* Author: Garland Simpson
 *
 * List class header 
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream> // included for cerr
#include <string> // included for NULL

using namespace std;

class Node
{
public:
	Node() {}
	Node(int vertexName, int theWeight) { next = NULL; vName = vertexName; weight = theWeight; }
	Node *getNext() const { return next; }
	int getWeight() const { return weight; }
	int getVName() const { return vName; }
	void setNext(Node *newNode) { next = newNode; }
	void setWeight(int newWeight) { weight = newWeight; }
	void setVName(int newVertexName) { vName = newVertexName; }
	~Node() {}
private:
	Node * next;
	int vName;
	int weight;
};


class LinkedList
{
public:
	LinkedList();
	void insertInOrder(int newVertexName, int newWeight);
	Node *getFirst() const;
	bool inList(int vertexName) const;
	void insertInBack(int vertexName);
	void removeNode(int theData);
	void printList() const;
	~LinkedList();
private:
	Node * first;
	int count;
};

#endif