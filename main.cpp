
#include "main.h"
using namespace std;

int main()
{
	GraphADT test;
	char isGraphDirected;
	int NumberOfNodes;
	int NumberOfEdges;
	bool isGraphEulerian;
	list<int> eulerianCircale;


	cout << "Is the graph directed: y/n: "<<endl;
	cin >> isGraphDirected;
	if (isGraphDirected != 'y' && isGraphDirected != 'n')
	{
		cout << "invalid input";
		exit(1);
	}
	cin >> NumberOfNodes;
	cin >> NumberOfEdges;
	if (NumberOfEdges <= 0 || NumberOfEdges <= 0)
	{
		cout << "invalid input";
		exit(1);
	}
	test.SetGraphDetailsAndInit(isGraphDirected, NumberOfNodes, NumberOfEdges);
	test.CreateGraphFromUserInput();
	isGraphEulerian = test.isGraphEulerian();

	if (isGraphEulerian)
	{
		eulerianCircale = test.GetEulerCircle();
		test.printEulerCircle(eulerianCircale);
	}
	else
	{
		cout << "The graph is not aulerian";
	}

	
	return 0;
}

