
#include <iostream>
#include <vector>
#include "GraphADT.h"
using namespace std;

int main()
{
	GraphADT test;
	char isGraphDirected;
	int NumberOfNodes;
	int NumberOfEdges;
	bool isGraphEulerian;
	list<int> eulerianCircale;


	cout << "Is the graph directed: y/n: ";
	cin >> isGraphDirected;
	cout << "Please Enter The Number Of Nodes: ";
	cin >> NumberOfNodes;
	cout << "Please Enter The Number Of Edges: ";
	cin >> NumberOfEdges;

	test.GetGraphDetailsAndInit(isGraphDirected, NumberOfNodes, NumberOfEdges);
	test.CreateGraphFromUserInput();
	isGraphEulerian = test.isGraphEulerian();

	if (isGraphEulerian)
	{
		eulerianCircale = test.GetEulerCircle();
		test.printEulerCircle(eulerianCircale);
	}
	else
	{
		cout << "The Graph is Not Eulerian";
	}

	
	return 0;
}

void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
	cin.clear();

}