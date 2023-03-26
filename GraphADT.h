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
	int* ColorArray;
	int NumberOfNodes;
	int NumberOfEdges;
	char isGraphDirected;
	
	void AddEdge(int from , int to,bool &flag);


	
	
public:
	bool isAllDegreeEven();
	bool isDirectedGraphStronglyConnected();
	bool isUnDirectedGraphConnected();
	bool isGraphConnected();
	void GetGraphDetails(char, int, int);
	void CreateGraphFromDetails();
	void DFS();
	
};

