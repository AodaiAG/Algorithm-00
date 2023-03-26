#pragma once

using namespace std;
#include"GraphNode.h"
#include <list>
#include <vector>
#include <string>


class GraphNode; // forward declaration
class GraphADT
{
private:
	vector<GraphNode> Graph;
	int NumberOfNodes;
	int NumberOfEdges;
	char isGraphDirected;
	void AddEdge(int from , int to,bool flag);
	bool isAllDegreeEven();

	
	
public:

	void GetGraphDetails();
	void CreateGraphFromDetails();
	
};

