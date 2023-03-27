#pragma once
#include "GraphADT.h"
#include <vector>
#include <list>
#include <iostream>

class GraphNode
{
public: 
	class edge
	{
	public:
		int nodeNumber;
		bool IsMarked = false;
	};
	int nodeNumber;
	list<edge> ListofEdges;
	GraphNode() {};
};

