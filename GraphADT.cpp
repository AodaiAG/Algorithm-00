#include "GraphADT.h"
#include <vector>
#include <list>
#include <iostream>
#include "main.h"

void GraphADT::DFS()
{
	for (int i = 1; i < NumberOfNodes + 1; i++)
	{
		ColorArray[i] = White;
	}

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
	list<int> AdjList = Vertex.ListofEdges;
	list<int>::iterator itr;

	for (itr=AdjList.begin();itr!=AdjList.end();itr++)
	{
		if (ColorArray[*itr] == White)
		{
			// mark edge 
			Visit(Graph[*itr]);
		}
	}

	ColorArray[Vertex.nodeNumber] = Black;
}

void GraphADT::GetGraphDetails(char isGraphDirected, int NumberOfNodes,int NumberOfEdges)
{
	this->isGraphDirected = isGraphDirected;
	this->NumberOfNodes = NumberOfNodes;
	this->NumberOfEdges = NumberOfEdges;
	Graph.push_back(GraphNode()); // so we can start from index 1 
	for (int i = 0; i < NumberOfNodes + 1; i++) // init graph
	{
		GraphNode temp;
		temp.nodeNumber = i + 1;
		Graph.push_back(temp);
	}
}


void GraphADT::CreateGraphFromDetails()
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
	list<int> tempnodeList = Graph[from].ListofEdges;
	for (list<int>::iterator itr = tempnodeList.begin(); itr != tempnodeList.end(); ++itr)
	{
		if (*itr == to)
		{
			Flag = true; // edge already Added
		}
	}

	if (!Flag)
	{
		if (this->isGraphDirected == 'y')
		{
			Graph[from].ListofEdges.push_back(to);
		}
		
		else
		{
			Graph[from].ListofEdges.push_back(to);
			Graph[to].ListofEdges.push_back(from);
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
	if (sum / 2 == 0)
		return true;
	else
		return false;
}

bool GraphADT::isDirectedGraphStronglyConnected()
{
	return false;
}

bool GraphADT::isUnDirectedGraphConnected()
{
	return false;
}
bool GraphADT::isGraphConnected()
{
	if (this->isGraphDirected == 'y')
		return isDirectedGraphStronglyConnected();
	else
		return isUnDirectedGraphConnected();
}