#include "LinkedList.h"
#include "Graph.h"

#include <iostream>
#include <string>
//#include <queue>
//#include <vector>
#include <functional>
#include <cmath>
#include <random>
#include <set>

using namespace std;


int main()
{
	Graph g1(9);
	g1.addEdge(1, 2);
	g1.addEdge(1, 5);
	g1.addEdge(1, 7);
	g1.addEdge(2, 3);
	g1.addEdge(2, 6);
	g1.addEdge(3, 4);
	g1.addEdge(3, 6);
	g1.addEdge(4, 6);
	g1.addEdge(4, 9);
	g1.addEdge(5, 6);
	g1.addEdge(5, 9);
	g1.addEdge(6, 8);
	g1.addEdge(7, 8);
	g1.addEdge(8, 9);



	g1.setEdgeValue(1, 2, 3);
	g1.setEdgeValue(1, 5, 2);
	g1.setEdgeValue(1, 7, 2);
	g1.setEdgeValue(2, 3, 4);
	g1.setEdgeValue(2, 6, 3);
	g1.setEdgeValue(3, 4, 2);
	g1.setEdgeValue(3, 6, 3);
	g1.setEdgeValue(4, 6, 4);
	g1.setEdgeValue(4, 9, 3);
	g1.setEdgeValue(5, 6, 4);
	g1.setEdgeValue(5, 9, 6);
	g1.setEdgeValue(6, 8, 2);
	g1.setEdgeValue(7, 8, 5);
	g1.setEdgeValue(8, 9, 2);


	cout << "\nThere are, " << 13 << " edges generated." << endl;
	cout << 1 << ", " << 2 << ": " << 3 << endl;
	cout << 1 << ", " << 5 << ": " << 2 << endl;
	cout << 1 << ", " << 7 << ": " << 2 << endl;
	cout << 2 << ", " << 3 << ": " << 4 << endl;
	cout << 2 << ", " << 6 << ": " << 3 << endl;
	cout << 3 << ", " << 4 << ": " << 2 << endl;
	cout << 3 << ", " << 6 << ": " << 3 << endl;
	cout << 4 << ", " << 6 << ": " << 4 << endl;
	cout << 4 << ", " << 9 << ": " << 3 << endl;
	cout << 5 << ", " << 6 << ": " << 4 << endl;
	cout << 5 << ", " << 9 << ": " << 6 << endl;
	cout << 6 << ", " << 8 << ": " << 2 << endl;
	cout << 7 << ", " << 8 << ": " << 5 << endl;
	cout << 8 << ", " << 9 << ": " << 2 << endl;

	/*
	g1.printParents();
	cout << endl;
	g1.printDistance();
	*/


	cout << "\nadjancy list" << endl;
	g1.printGraph();

	int d = g1.dijkstra(1, 4);

	g1.printParents();
	cout << endl;
	g1.printDistance();
	/*
	// Get graph size
	cout << "\nEnter the number of vertices for the graph: ";
	int graphSize;
	cin >> graphSize;
	cout << "\nThe graph size is : " << graphSize << endl;

	// Get edge density
	cout << "\nEnter the edge density for the graph: ";
	double edgeDensity;
	cin >> edgeDensity;
	cout << "\nThe edge density is: " << edgeDensity << endl;

	// Get edge distance range
	cout << "\nEnter the distance range for the graph: ";
	int distanceRange;
	cin >> distanceRange;
	cout << "\nThe distance range is: " << distanceRange << endl;

	//int graphSize = 50;
	//double edgeDensity = 0.1;
	//int distanceRange = 6;


	// Create Graph
	Graph g1(graphSize);

	// Generate random edges
	double numRandomEdges = edgeDensity * graphSize;
	if (numRandomEdges > graphSize) numRandomEdges = graphSize;

	cout << "\nThere are, " << numRandomEdges << " random edges generated." << endl;

	numRandomEdges = floor(numRandomEdges);
	int randomUVertex;
	int randomVVertex;
	int randomWeight;

	// random vertex generator
	default_random_engine vertex_generator;
	uniform_int_distribution<int> distribution(1, graphSize);
	distribution(vertex_generator);

	// random edge weight generator
	default_random_engine weight_generator;
	uniform_int_distribution<int> distribution2(1, distanceRange);
	distribution2(weight_generator);

	set<int> vert;
	// populate the graph
	for (int i = 0; i < numRandomEdges; ++i) {
	randomUVertex = distribution(vertex_generator);
	randomVVertex = distribution(vertex_generator);

	while(randomUVertex == randomVVertex)  // make sure there are not self loops
	randomVVertex = distribution(vertex_generator);
	vert.insert(randomUVertex);
	vert.insert(randomVVertex);

	g1.addEdge(randomUVertex, randomVVertex);
	randomWeight = distribution2(weight_generator);
	g1.setEdgeValue(randomUVertex, randomVVertex, randomWeight);
	cout << randomUVertex << ", " << randomVVertex << ": " << randomWeight << endl;
	}

	// List all vertices in the graph;
	cout << "Vertices are: ";
	set<int>::const_iterator it = vert.cbegin();
	while(it != vert.cend()) {
	cout << *it << " ";
	++it;
	}
	cout << endl;

	int srcVert;
	int destVert;

	cout << "About to calculate shortes path.";
	cout << "\n\tPlease enter a source vertex: ";
	cin >> srcVert;
	cout << "\n\tPlease enter a destination vertex: ";
	cin >> destVert;

	int shortestPath = g1.dijkstra(srcVert, destVert);

	if (shortestPath != INF) {
	cout << "The path length from " << srcVert << "-" << destVert << "= " << shortestPath << endl;
	g1.getPathway();
	}
	else
	cout << "There is no shortest pth from " << srcVert << "-" << destVert << endl;

	g1.~Graph();
	*/
	cout << endl << endl;
	system("Pause"); // Uncomment this for use in visual studios
	return 0;
}
