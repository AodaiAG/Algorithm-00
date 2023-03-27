#include "GraphADT.h"
#include <vector>
#include <list>
#include <iostream>
#include "main.h"

void GraphADT::DFS()
{
	initColorArray();

	for (int i = 1; i < NumberOfNodes + 1; i++)
	{
		if (ColorArray[i] == White)
		{
			Visit(Graph[i]);
		}
	}


}

void GraphADT::Visit(GraphNode Vertex)
{
	ColorArray[Vertex.nodeNumber] = Gray;
	list<GraphNode::edge> AdjList = Vertex.ListofEdges;
	list<GraphNode::edge>::iterator itr;
	
	for (itr=AdjList.begin();itr!=AdjList.end();itr++)
	{
		if (ColorArray[itr->nodeNumber] == White)
		{
			// mark edge 
			Visit(Graph[itr->nodeNumber]);
		}
	}

	ColorArray[Vertex.nodeNumber] = Black;
}

void GraphADT::GetGraphDetailsAndInit(char isGraphDirected, int NumberOfNodes,int NumberOfEdges)
{
	this->isGraphDirected = isGraphDirected;
	this->NumberOfNodes = NumberOfNodes;
	this->NumberOfEdges = NumberOfEdges;
	Graph.push_back(GraphNode()); // so we can start from index 1 
	for (int i = 1; i < NumberOfNodes + 1; i++) // init graph
	{
		GraphNode temp;
		temp.nodeNumber = i;
		Graph.push_back(temp);
	}
}


void GraphADT::CreateGraphFromUserInput ()
{
	int from, to;
	bool flag = false; // To know whether an edge already exists or not
	
	for (int i = 0; i < NumberOfEdges; i++)
	{
		cin >> from;
		cin >> to;
		AddEdge(from, to,flag);
			if (flag) // means edge already added
			{
				i--;
				flag = false;
			}

	}
	this->ColorArray = new Colors[NumberOfNodes];
}

void GraphADT::AddEdge(int from, int to,bool &Flag)
{
	GraphNode::edge toEdge;
	GraphNode::edge fromEdge;
	fromEdge.nodeNumber = from;
	toEdge.nodeNumber = to;

	list<GraphNode::edge> tempnodeList = Graph[from].ListofEdges;
	for (list<GraphNode::edge>::iterator itr = tempnodeList.begin(); itr != tempnodeList.end(); ++itr)
	{
		if (itr->nodeNumber == to)
		{
			Flag = true; // edge already Added
		}
	}

	if (!Flag)
	{
		if (this->isGraphDirected == 'y')
		{
			Graph[from].ListofEdges.push_back(toEdge);
		}
		
		else
		{

			Graph[from].ListofEdges.push_back(toEdge);
			Graph[to].ListofEdges.push_back(fromEdge);
		}
			
	}
	
	else
	{
		cout << "Edge is Already Added !! "<<endl; // throw
	}
		

}
bool GraphADT::isAllDegreeEven()
{
	int sum = 0;
	for (int i = 0; i < NumberOfNodes+1; i++)
	{
		sum = sum + this->Graph[i + 1].ListofEdges.size();

	}
	if (sum % 2 == 0)
		return true;
	else
		return false;
}

void GraphADT::initColorArray()
{
	for (int i = 1; i < NumberOfNodes + 1; i++)
	{
		ColorArray[i] = White;
	}

}
GraphADT GraphADT::BuildTransposeGraph(GraphADT G)
{
	bool flag=false;
	GraphADT res;
	list<GraphNode::edge> AdjList;
	res.GetGraphDetailsAndInit(G.isGraphDirected, G.NumberOfNodes, G.NumberOfEdges);

	for (int i = 1; i < G.NumberOfNodes+1; i++)
	{

		AdjList = G.Graph[i].ListofEdges;
		for (list<GraphNode::edge>::iterator itr = AdjList.begin(); itr != AdjList.end(); ++itr)
		{

			res.AddEdge(itr->nodeNumber, i, flag);
		}
		

	}

	return res;
}

bool GraphADT::isDirectedGraphStronglyConnected()
{
	
	int RandomNode = (rand() % NumberOfNodes) + 1; // Randomly choosing a node to DFS it

	Visit(Graph[RandomNode]);
	for (int i = 1; i < NumberOfNodes + 1; i++)
	{
		if (ColorArray[i] != Black)
			return false;
	}
	
	GraphADT Gtranspose = BuildTransposeGraph(*this);
	Gtranspose.initColorArray();
	Gtranspose.Visit(Gtranspose.Graph[RandomNode]);
	for (int i = 1; i < Gtranspose.NumberOfNodes + 1; i++)
	{
		if (Gtranspose.ColorArray[i] != Black)
			return false;
	}

	return true;
}

bool GraphADT::isGraphEulerian()
{
	return (  isGraphConnected() && isAllDegreeEven()  );
}

bool GraphADT::isUnDirectedGraphConnected()
{

	initColorArray();
	Visit(Graph[1]);
	for (int i = 1; i < NumberOfNodes+1; i++)
	{
		if (ColorArray[i] != Black)
			return false;
	}

	return true;
}

bool GraphADT::isGraphConnected()
{
	if (this->isGraphDirected == 'y')
		return isDirectedGraphStronglyConnected();
	else
		return isUnDirectedGraphConnected();
}

list<int> GraphADT::FindCircuit( GraphNode v0)
{
	GraphNode &v = v0;
	list<int> L;
	L.push_back(v.nodeNumber);
	while (!isAllEdgesMarked(v))
	{
		GraphNode &u = getFirstUnmarkedEdge(v);
		MarkEdgeAsUsed(v.nodeNumber, u.nodeNumber);
		L.push_back(u.nodeNumber);
		v = u;
		
	}

	return L;

}

list<int> GraphADT::GetEulerCircle()

{


}

bool isAllEdgesMarked(GraphNode v0)

{
	list<GraphNode::edge> AdjList = v0.ListofEdges;

	for (list<GraphNode::edge>::iterator itr = AdjList.begin(); itr != AdjList.end(); ++itr)
	{

		if (itr->IsMarked == false);
		return false;
	}

	return true;
}
void GraphADT::MarkEdgeAsUsed(int from, int to)
{

	list<GraphNode::edge> & AdjList = this->Graph[from].ListofEdges;
	for (list<GraphNode::edge>::iterator itr = AdjList.begin(); itr != AdjList.end(); ++itr)
	{

		if (itr->nodeNumber == to)
		{
			itr->IsMarked = true;
		}
		
	}

}
GraphNode& GraphADT::getFirstUnmarkedEdge(GraphNode &v)
{
	list<GraphNode::edge> &AdjList = v.ListofEdges;
	for (list<GraphNode::edge>::iterator itr = AdjList.begin(); itr != AdjList.end(); ++itr)
	{

		if (itr->IsMarked == false)
		return this->Graph[itr->nodeNumber];
	}
}