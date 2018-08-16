#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node
{
public:
	Node() {}
	Node(Node *theLink, int theData):link(theLink), data(theData) {}
	
	Node *getLink() const { return link; }
	int getData() const { return data; }
	
	void setLink(Node *theLink) { link = theLink; }
	void setData(int theData) { data = theData; }
	~Node() {}
private:
	Node * link;
	int data;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
};

#endif