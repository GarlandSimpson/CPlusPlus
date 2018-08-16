#include <string>
#include <iostream>

using namespace std;

class Node
{
public:
	Node() {}
	Node(Node *theLink, int theData) :link(theLink), data(theData) {}

	Node *getLink() const { return link; }
	int getData() const { return data; }

	void setLink(Node *theLink) { link = theLink; }
	void setData(int theData) { data = theData; }
	~Node() {}
private:
	Node * link;
	int data;
};


int main()
{

	// TEST: Default Constructor
	Node n1;

	cout << n1.getLink() << endl;
	cout << n1.getData() << endl;

	// TEST: Overloaded Constructor
	Node n2(&n1, 22); 

	cout << n2.getLink() << endl;
	cout << n2.getData() << endl;

	// TEST: Assignment Operators
	Node n3;
	n3.setLink(&n1);
	n3.setData(555);

	cout << n3.getLink() << endl;
	cout << n3.getData() << endl;


	cout << endl << endl;
	system("Pause");
	return 0;
}