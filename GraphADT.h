#pragma once

using namespace std;
#include"GraphNode.h"
#include <list>
#include <vector>
#include <string>

enum Colors{White,Gray,Black};
class GraphNode; // forward declaration

class GraphADT
{
private:
	vector<GraphNode> Graph;
	Colors* ColorArray;
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
	void Visit(GraphNode Vertex);
	void DFS();
	
};

