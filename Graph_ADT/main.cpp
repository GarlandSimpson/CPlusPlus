#include "LinkedList.h"
#include "Graph.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// all is good with default constructor: valgrind checked
	Graph g1;
	
    // all is goood with addEdge: valgrind checked
	g1.addEdge(1, 2);
	g1.addEdge(1, 3);
	g1.addEdge(2, 4);
	g1.addEdge(2, 5);
	g1.addEdge(3, 4);
	g1.addEdge(3, 5);
	g1.addEdge(4, 6);
	g1.addEdge(5, 6);
	g1.addEdge(1, 9);
	
	// all is good with getNeighbors(): valgrind checked
	cout << "\nThe neighbors of 1 are ";g1.getNeighbors(1);
	cout << "\nThe neighbors of 2 are ";g1.getNeighbors(2);
	cout << "\nThe neighbors of 3 are ";g1.getNeighbors(3);
	cout << "\nThe neighbors of 4 are ";g1.getNeighbors(4);
	cout << "\nThe neighbors of 5 are ";g1.getNeighbors(5);
	cout << "\nThe neighbors of 6 are ";g1.getNeighbors(6);
	cout << "\nThe neighbors of 8 are ";g1.getNeighbors(8); // test node with no neighbors

	
	// all is good with removeEdge(): valgrind checked
	g1.removeEdge(1, 2);
	g1.removeEdge(1, 3);
	g1.removeEdge(2, 4);
	g1.removeEdge(2, 5);
	g1.removeEdge(3, 4);
	g1.removeEdge(3, 5);
	g1.removeEdge(4, 6);
	g1.removeEdge(5, 6);
	g1.removeEdge(1, 8);// test non existant edge
	g1.removeEdge(1, 9);
	//g1.~Graph();



	
	cout << endl << endl;
	system("Pause");
	return 0;
} 