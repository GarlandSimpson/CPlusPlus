/*
 * Author: Garland Simpson
 * NOTE: LinkedList Class is fully tested and appears to be bug free
 */
#include "Graph.h"

// Definition of Graph() Constructor
Graph::Graph()
{
	order = DEFAULT_LENGTH + 1;
	size = 0;
	//src = NIL;

	adjList = vector<LinkedList>(order);
	pi = vector<int>(order, NIL);
	d = vector<int>(order, INF);
	//pathway = queue<int>();
	pathway = LinkedList();
}

// Definition of overloaded Graph Constructor
Graph::Graph(int theOrder)
{
	order = theOrder + 1;
	size = 0;
	//src = NIL;

	adjList = vector<LinkedList>(order);
	pi = vector<int>(order, NIL);
	d = vector<int>(order, INF);
	//pathway = queue<int>();
	pathway = LinkedList();
}

//getOrder() : returns the number of vertices in the graph
int Graph::getOrder() const { return order; }

//getSize() : returns the number of edges in the graph
int Graph::getSize() const { return size; }

//getSource() : returns the source vertex
//int Graph::getSource() const { return src; }

//setSource(newSource) : sets the source vertex
//void Graph::setSource(int newSource) { src = newSource; }

//getDistance(v) : gets the distance from the source to vertex v
int Graph::getDistance(int v) const { return d[v]; }

//setDistance(v,dist) : sets the distance of vertex v to dist
void Graph::setDistance(int v, int dist) { d[v] = dist; }

//getParent(v) : returns the parent of vertex v
int Graph::getParent(int v) const { return pi[v]; }

//setParent(v,p) : sets the parent of vertex v to p
void Graph::setParent(int v, int p) { pi[v] = p; }

void Graph::getPathway()
{
	Node *current = pathway.getFirst();
	while (current != NULL)
	{
		cout << current->getVName() << " ";
		current = current->getNext();
	}

	/*while (!pathway.empty())
	{
	cout << pathway.front() << " ";
	pathway.pop();
	}*/

}

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
		cerr << "Graph Error:addEdge(): edge to insert is greater than max vertex value" << endl;
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
	return NIL;
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
	if (adjList[y].inList(x))
	{
		Node *current = adjList[y].getFirst();

		while (current->getVName() != x)
			current = current->getNext();

		current->setWeight(v);
		current = NULL;
	}
}

void Graph::Init_Single_Source(int s)
{
	for (int v = 1; v < order; ++v) // for each v in V
	{
		d[v] = INF; //d[v] <- infinity
		pi[v] = NIL; // pi[v] <- NIL
	}

	d[s] = 0; 	//d[s] <- 0;
	pi[s] = INF;
}

void Graph::relax(int u, int v)
{
	if (d[u] == INF)
	{
		if (d[v] > getEdgeValue(u, v))
		{
			d[v] = getEdgeValue(u, v);
			pi[v] = u; // pi[v] <- u;
		}
	}
	else
	{
		if (d[v] > d[u] + getEdgeValue(u, v)) // if d[v] > d[u] + w(u,v)
		{
			d[v] = d[u] + getEdgeValue(u, v);
			pi[v] = u; // pi[v] <- u;
		}
	}
}

int Graph::dijkstra(int s, int w)
{
	Init_Single_Source(s); //Init_Single_Source(V,s);
						   // S  = NULL;
	//src = s;
	MinHeap Q; // Q = V

	for (int u = 1; u < order; ++u)
	{
		Q.insertInOrder(u, d[u]);
	}

	int u;

	while (!Q.empty())// while Q is not empty
	{
		u = Q.getFirst()->getVName(); // S <- S + {u}
		Q.deleteFirst();

		Node *current = adjList[u].getFirst();
		while (current != NULL) //for each vertex u in adj[u]
		{
			relax(u, current->getVName()); //relax(u,v,w);
			current = current->getNext();
		}
	}
	pathway.insertInBack(w);
	return d[w];
}

void Graph::printGraph() const {

	for (int i = 1; i < order; ++i) {
		cout << "[" << i << "]:";
		adjList[i].printList();
	}
}

void Graph::printParents() const {

	for (int v = 1; v < order; ++v) {

		cout << "pi[" << v << "]: " << pi[v] << endl;
	}
}

void Graph::printDistance() const {

	for (int v = 1; v < order; ++v) {

		cout << "d[" << v << "]: " << d[v] << endl;
	}
}

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
