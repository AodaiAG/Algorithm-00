#include "GraphADT.h"
#include <vector>
#include <list>
#include <iostream>

void GraphADT::GetGraphDetails()
{
	cout << "Is the graph directed: y/n: "<<endl;
	cin >> this->isGraphDirected;
	cout << "Please Enter The Number Of Verdicts: "<<endl;
	cin >> this->NumberOfNodes;
	cout << "Please Enter The Number Of Edges: "<<endl;
	cin >> this->NumberOfEdges;

	this->Graph.reserve(NumberOfNodes+1);
	

	for (int i = 0; i < NumberOfNodes + 1; i++)
	{
		GraphNode temp;
		temp.nodeNumber = i + 1;


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
		AddEdge(from, to,&flag);
			if (flag) // means edge already added
			{
				i--;
				flag = false;
			}

	}

}

void GraphADT::AddEdge(int from, int to,bool flag)
{
	list<int> tempnodeList = Graph[from].ListofEdges;
	bool Flag = false;
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
		cout << "Edge is Already Added !! "; // throw
	}
		

}
