#include "Graph.h"


Graph::Graph()
{
	order = DEFAULT_LENGTH;
	size = 0;
	//maxVertex = order;

	adjList = vector<LinkedList>(order); //adjList = vector<LinkedList>(order);
	pi = vector<int>(order, NIL);
	d = vector<int>(order, INF);
}

Graph::Graph(int theOrder)
{
	order = theOrder;
	size = 0;
	//maxVertex = theOrder;

	adjList = vector<LinkedList>(order); //adjList = vector<LinkedList>(order);
}

//getOrder(G) : returns the number of vertices in the graph
int Graph::getOrder() const { return order; }

//getSize(G) : returns the number of edges in the graph
int Graph::getSize() const { return size; }

//getNeighbors(G, x) : lists all nodes y such that there is an edge from x to y.
void Graph::getNeighbors(int x) const
{
	// catching for bound errors by checking against order
	if (x <= order - 1 && adjList.at(x).getFirst() != NULL)
	{
		Node * current = adjList[x].getFirst();

		while (current != NULL)
		{
			cout << current->getVName() << " ";
			current = current->getNext();
		}
		cout << endl;
	}
}

//addEdge(G, x, y) : adds to G the edge from x to y, if it is not there.
void Graph::addEdge(int x, int y)
{
	if (adjList[x].inList(y))
	{
		cerr << "Graph Error:addEdge() edge (" << x << "," << y << ") already exists" << endl;
	}
	else if (x < 1)
	{
		cerr << "Graph Error:addEdge() " << x << "is not a positive number" << endl;
	}
	else if (y < 1)
	{
		cerr << "Graph Error:addEdge() " << y << "is not a positive number" << endl;
	}
	else if (x < order && y < order)
	{
		adjList[x].insertInOrder(y, -1);
		adjList[y].insertInOrder(x, -1);
		size++;
	}
	else
	{
		cerr << "Graph Error:addEdge(): edge to insert is greater than max vertex value" << endl;
	}
}

//removeEdge(G, x, y) : removes the edge from x to y, if it is there.
void Graph::removeEdge(int x, int y)
{
	if (!adjList[x].inList(y))
	{
		cerr << "Graph Error: edge (" << x << "," << y << ") does not exists" << endl;
	}
	else
	{
		adjList[x].removeNode(y);
		adjList[y].removeNode(x);
		size--;
	}
}

//get_edge_value(G, x, y) : returns the value associated to the edge(x, y).
int Graph::getEdgeValue(int x, int y) const
{
	if (adjList[x].inList(y))
	{
		Node *current = adjList[x].getFirst();

		while (current->getVName() != y)
			current = current->getNext();

		return current->getWeight(); 
	}
	else
		cerr << "Graph Error: weight cannot be found because the edge doesnt exist" << endl;
	return -1;
}

//set_edge_value(G, x, y, v) : sets the value associated to the edge(x, y) to v.
void Graph::setEdgeValue(int x, int y, int v)
{
	if (adjList[x].inList(y))
	{
		Node *current = adjList[x].getFirst();

		while (current->getVName() != y)
			current = current->getNext();

		current->setWeight(v);
		current = NULL;
	}
}
//graph class destructor
Graph::~Graph()
{
	vector<LinkedList>::const_iterator it = adjList.cbegin();
	
	while (it != adjList.end())
	{
		it->~LinkedList();
		++it;
	}

	adjList.clear();
}