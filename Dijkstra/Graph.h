/*
 * Author: Garland Simpson
 * NOTE: LinkedList Class is fully tested and appears to be bug free
 */
#ifndef GRAPH_H
#define GRAPH_H


#include "LinkedList.h"
#include "MinHeap.h"
#include <queue>
#include <vector>
#include <functional>
#include <unordered_set>
#include <limits>


using namespace std;


const int DEFAULT_LENGTH = 10;
const int NIL = 0;
const int INF = numeric_limits<int>::max();

class Graph
{
public:

	//Default Constructor
	Graph();

	//Overloaded Constructor
	Graph(int theOrder);

	//getOrder(G) : returns the number of vertices in the graph
	int getOrder() const;

	//getSize(G) : returns the number of edges in the graph
	int getSize() const;

	//getSource() : returns the source vertice in the graph
	int getSource() const;

	//getDistance(v) : returns the distance associated with vertex v
	int getDistance(int v) const;

	//setDistance(v, dist) : sets the distance of vertex v to dist
	void setDistance(int v, int dist);

	//getParent(int v) : returns the parent of vertex v
	int getParent(int v) const;

	//setParent(v,p) : sets the parent of vertex v to p
	void setParent(int v, int p);

	//setSource(newSource) : sets the source vertex to newSource
	void setSource(int newSource);

	//getPathway() : returns the shortest path after running dijkstra and empties the container
	void getPathway();

	//getNeighbors(G, x) : lists all nodes y such that there is an edge from x to y.
	void getNeighbors(int x) const;

	//addEdge(G, x, y) : adds to G the edge from x to y, if it is not there.
	void addEdge(int x, int y);

	//removeEdge(G, x, y) : removes the edge from x to y, if it is there.
	void removeEdge(int x, int y);

	//get_edge_value(G, x, y) : returns the value associated to the edge(x, y).
	int getEdgeValue(int x, int y) const;

	//set_edge_value(G, x, y, v) : sets the value associated to the edge(x, y) to v.
	void setEdgeValue(int x, int y, int v);

	//Init_Single_Source(s) : initalized the graph with s as the source in preperation for dijkstras
	void Init_Single_Source(int s);

	//relax(u,v) : relaxes edge (u,v) in the undirected graph.
	void relax(int u, int v);

	//dijkstra(s,w) : returns the shortest path in the undirected graph from the source s to any vertice w.
	int dijkstra(int s, int w);

	//pringGraph() : prints to consol the adjList of the graph	
	void printGraph() const;

	//printParents() : prints the parents of each vertice after running dijkstras
	void printParents() const;

	//printDistance() : prints the distance of each vertice from the source after running dijkstras
	void printDistance() const;

	//Destructor
	~Graph();

private:

	vector<LinkedList> adjList;
	vector<int> pi;
	vector<int> d;
	//queue<int> pathway;
	LinkedList pathway;
	int order;
	int size;
};

#endif
