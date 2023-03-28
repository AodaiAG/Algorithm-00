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
	vector<Colors> ColorArray;
	int NumberOfNodes;
	int NumberOfEdges;
	char isGraphDirected;
	void AddEdge(int from , int to,bool &flag);


	
	
public:
	bool isAllDegreeEven();
	bool isDirectedGraphStronglyConnected();
	bool isUnDirectedGraphConnected();
	bool isGraphConnected();
	bool isGraphEulerian();
	bool isAllEdgesMarked(GraphNode& v0);
	GraphADT BuildTransposeGraph(GraphADT G);
	list<int> FindCircuit(GraphNode &v);
	list<int> GetEulerCircle();
	list<int> PasteLists(list<int> source, list<int> target);
	GraphNode getFirstUnmarkedEdge(GraphNode &v);
	void initColorArray();
	void printEulerCircle(list<int> ListOfNodes);
	void MarkEdgeAsUsed(int from, int to);
	void SetGraphDetailsAndInit(char, int, int);
	void CreateGraphFromUserInput();
	void Visit(GraphNode &Vertex);
	void DFS();
	
	
};

