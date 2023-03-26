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
	void AddEdgeToDirectedGraph(int from , int to);
	void AddEdgeToUnirectedGraph(int from , int to);

	
	
public:

	void GetGraphDetails();
	void CreateGraphFromDetails();
};

