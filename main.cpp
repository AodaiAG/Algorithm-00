
#include <iostream>
#include <vector>
#include "GraphADT.h"
using namespace std;

void main()
{
	GraphADT test;
	char isGraphDirected;
	int NumberOfNodes;
	int NumberOfEdges;


	cout << "Is the graph directed: y/n: ";
	cin >> isGraphDirected;
	cout << "Please Enter The Number Of Nodes: ";
	cin >> NumberOfNodes;
	cout << "Please Enter The Number Of Edges: ";
	cin >> NumberOfEdges;

	test.GetGraphDetailsAndInit(isGraphDirected, NumberOfNodes, NumberOfEdges);
	test.CreateGraphFromUserInput();

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