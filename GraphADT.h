#pragma once
using namespace std;
#include <list>
#include <vector>
#include <string>
class GraphADT
{
private:
	vector<list<int>> Graph;
	int NumberOfVerdicts;
	int NumberOfEdges;
	char isGraphDirected;
	void AddEdgeToDirectedGraph(int from , int to);
	void AddEdgeToUnirectedGraph(int from , int to);

	
	
public:

	void CreateDirectedGraph();
	void CreateUndirectedGraph();
	void GetGraphDetails();
	void CreateGraphFromDetails();
};

