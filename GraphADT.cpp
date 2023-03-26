#include "GraphADT.h"
#include <vector>
#include <list>
#include <iostream>

void GraphADT::GetGraphDetails()
{
	cout << "Is the graph directed: y/n"<<endl;
	cin >> this->isGraphDirected;
	cout << "Please Enter The Number Of Verdicts";
	cin >> this->NumberOfNodes;
	cout << "Please Enter The Number Of Edges";
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
	
	for (int i = 0; i < NumberOfEdges; i++)
	{
		cin >> from;
		cin >> to;


		if (this->isGraphDirected == 'y')
		{
			AddEdgeToDirectedGraph(from, to);
		}
		else
		{
			AddEdgeToUnirectedGraph(from, to);
		}
	}

}
void GraphADT::AddEdgeToDirectedGraph(int from, int to)
{
	GraphNode tempnode = Graph[from];

	Graph[from].ListofEdges.push_back(to);

}
void GraphADT::AddEdgeToUnirectedGraph(int from, int to)
{


}