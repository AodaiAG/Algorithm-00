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
	GraphADT BuildTransposeGraph(GraphADT G);
	void initColorArray();
	void GetGraphDetailsAndInit(char, int, int);
	void CreateGraphFromUserInput();
	void Visit(GraphNode Vertex);
	void DFS();
	
};

