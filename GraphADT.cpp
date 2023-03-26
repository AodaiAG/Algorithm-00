#include "GraphADT.h"
#include <vector>
#include <list>
#include <iostream>

void GraphADT::GetGraphDetails()
{
	cout << "Is the graph directed: y/n";
	cin >> this->isGraphDirected;
	cout << "Please Enter The Number Of Verdicts";
	cin >> this->NumberOfVerdicts;
	cout << "Please Enter The Number Of Edges";
	cin >> this->NumberOfEdges;


}
void GraphADT::CreateDirectedGraph()
{
	
}

void GraphADT::CreateUndirectedGraph()
{

}

void GraphADT::CreateGraphFromDetails()
{

}
void GraphADT::AddEdgeToDirectedGraph(int from, int to)
{

}
void GraphADT::AddEdgeToUnirectedGraph(int from, int to)
{

}