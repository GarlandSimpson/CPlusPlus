/*
	Simpson, Garland
	CS A250
	April (4), (2015)

	Ex 12
*/

#include "DLL_ChildClass.h"

#include <iostream>
using namespace std;

int main()
{
	DLL_ChildClass firstList;
	
	firstList.insertBack(43);
	firstList.insertBack(82);
	firstList.insertBack(35);
	firstList.insertBack(12);
	firstList.insertBack(91);
	firstList.insertBack(67);

	/**************************************************************************
		 Test copy constructor			
	**************************************************************************/
	
	DLL_ChildClass secondList(firstList);

	// Make sure lists are different
	cout << "First node of first list is at: " 
		<< &firstList.getFirstNodeAddress() << endl;
	cout << "First node of second list is at: " 
		<< &secondList.getFirstNodeAddress() << endl;
	cout << "Last node of first list is at: " 
		<< &firstList.getLastNodeAddress() << endl;
	cout << "Last node of second list is at: " 
		<< &secondList.getLastNodeAddress() << endl;

	// Make sure both lists have the same number of nodes
	cout << "First list has " << firstList.getCount() 
		<< " nodes." << endl;
	cout << "Second list has " << secondList.getCount() 
		<< " nodes." << endl;

	/**************************************************************************
		 Test copy constructor		
	**************************************************************************/
		
	DLL_ChildClass thirdList = firstList;

	// Make sure lists are different
	cout << "First node of first list is at: " 
		<< &firstList.getFirstNodeAddress() << endl;
	cout << "First node of third list is at: " 
		<< &thirdList.getFirstNodeAddress() << endl;
	cout << "Last node of first list is at: " 
		<< &firstList.getLastNodeAddress() << endl;
	cout << "Last node of third list is at: " 
		<< &thirdList.getLastNodeAddress() << endl;

	// Make sure both lists have the same number of nodes
	cout << "First list has " << firstList.getCount() 
		<< " nodes." << endl;
	cout << "Third list has " << thirdList.getCount() 
		<< " nodes." << endl;

	/**************************************************************************
		 Test assignment operator		
	**************************************************************************/
		
	DLL_ChildClass fourthList;
	fourthList = firstList;

	// Make sure lists are different
	cout << "First node of first list is at: " 
		<< &firstList.getFirstNodeAddress() << endl;
	cout << "First node of fourth list is at: " 
		<< &fourthList.getFirstNodeAddress() << endl;
	cout << "Last node of first list is at: " 
		<< &firstList.getLastNodeAddress() << endl;
	cout << "Last node of fourth list is at: " 
		<< &fourthList.getLastNodeAddress() << endl;

	// Make sure both lists have the same number of nodes
	cout << "First list has " << firstList.getCount() 
		<< " nodes." << endl;
	cout << "Fourth list has " << fourthList.getCount() 
		<< " nodes." << endl;


	firstList.destroyList();
	secondList.destroyList();

	/**************************************************************************
	Test assignment operator (more efficient implementation)
	**************************************************************************/

	DLL_ChildClass list1, list2, list3, list4, list5, list6;

	// list1 is empty, list2 has 3 nodes
	list2.insertBack(1);
	list2.insertBack(2);
	list2.insertBack(3);
	list1 = list2;

	// list3 has 2 nodes, list2 has 3 nodes
	list3.insertBack(10);
	list3.insertBack(11);
	list3 = list2;

	// list4 has 3 nodes, list2 has 3 nodes
	list4.insertBack(20);
	list4.insertBack(21);
	list4.insertBack(22);
	list4 = list2;

	// list5 has 8 nodes, list2 has 3 nodes
	list5.insertBack(10);
	list5.insertBack(20);
	list5.insertBack(30);
	list5.insertBack(40);
	list5.insertBack(50);
	list5.insertBack(60);
	list5.insertBack(70);
	list5.insertBack(80);
	list5 = list2;

	// list2 has 3 nodes, list6 is empty
	list2 = list6;

	// assignment to itself
	list2 = list2;


	cout << endl << endl;
	system("Pause");
	return 0;
}
