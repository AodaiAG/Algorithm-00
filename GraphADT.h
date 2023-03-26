#pragma once
using namespace std;
#include <list>
#include <vector>
class GraphADT
{
private:
	vector<list<int>> Graph;
	
	
public:

	void CreateDirectedGraph(int size);
	void CreateUndirectedGraph(int size);
};

