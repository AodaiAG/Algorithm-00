#pragma once
using namespace std;
#include <list>
#include <vector>
#include <string>
#include"GraphNode.h"
class GraphADT
{
private:
	vector<GraphNode> Graph;
	int NumberOfNodes;
	int NumberOfEdges;
	char isGraphDirected;
	void AddEdge(int from , int to,bool flag);


	
	
public:

	void GetGraphDetails();
	void CreateGraphFromDetails();
};

