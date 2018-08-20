#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"
#include <vector>


using namespace std;


const int DEFAULT_LENGTH = 10;
const int NIL = 0;
const int INF = -2;

class Graph
{
public:

	//Default Constructor
	Graph();

	Graph(int theOrder);

	//getOrder(G) : returns the number of vertices in the graph
	int getOrder() const;

	//getSize(G) : returns the number of edges in the graph
	int getSize() const;

	//getNeighbors(G, x) : lists all nodes y such that there is an edge from x to y.
	void getNeighbors(int x) const;

	//addEdge(G, x, y) : adds to G the edge from x to y, if it is not there.
	void addEdge(int x,int y);

	//removeEdge(G, x, y) : removes the edge from x to y, if it is there.
	void removeEdge(int x, int y);

	//get_edge_value(G, x, y) : returns the value associated to the edge(x, y).
	int getEdgeValue(int x, int y) const;

	//set_edge_value(G, x, y, v) : sets the value associated to the edge(x, y) to v.
	void setEdgeValue(int x, int y, int v);

	//Destructor
	~Graph();
private:
	
	//LinkedList **adjList;
	vector<LinkedList> adjList;
	vector<int> pi;
	vector<int> d;

	int order;
	int size;
	int maxVertex;
};

#endif