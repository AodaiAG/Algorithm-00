#include "GraphADT.h"
#include <vector>
#include <list>
#include <iostream>
#include "main.h"

void GraphADT::DFS()
{

	initColorArray();

	for (int i = 1; i < NumberOfNodes + 1; i++)
	{
		if (ColorArray[i] == White)
		{
			Visit(Graph[i]);
		}
	}


}

void GraphADT::Visit(GraphNode &Vertex)
{

	ColorArray[Vertex.nodeNumber] = Gray;
	list<GraphNode::edge> AdjList = Vertex.ListofEdges;
	list<GraphNode::edge>::iterator itr;
	
	for (itr=AdjList.begin();itr!=AdjList.end();itr++)
	{
		if (ColorArray[itr->nodeNumber] == White)
		{
			// mark edge 
			Visit(Graph[itr->nodeNumber]);
		}
	}

	ColorArray[Vertex.nodeNumber] = Black;
}

void GraphADT::SetGraphDetailsAndInit(char isGraphDirected, int NumberOfNodes,int NumberOfEdges)
{

	this->isGraphDirected = isGraphDirected;
	this->NumberOfNodes = NumberOfNodes;
	this->NumberOfEdges = NumberOfEdges;
	Graph.push_back(GraphNode()); // so we can start from index 1 
	for (int i = 1; i < NumberOfNodes + 1; i++) // init graph
	{
		GraphNode temp;
		temp.nodeNumber = i;
		Graph.push_back(temp);
	}
}


void GraphADT::CreateGraphFromUserInput ()
{
	int from, to;
	bool flag = false; // To know whether an edge already exists or not
	
	for (int i = 0; i < NumberOfEdges; i++)
	{
		cin >> from;
		cin >> to;
		AddEdge(from, to,flag);
			if (flag) // means edge already added
			{
				i--;
				flag = false;
			}

	}
	

}

void GraphADT::AddEdge(int from, int to,bool &Flag)
{
	GraphNode::edge toEdge;
	GraphNode::edge fromEdge;
	fromEdge.nodeNumber = from;
	toEdge.nodeNumber = to;
	list<GraphNode::edge> tempnodeList = Graph[from].ListofEdges;


	for (list<GraphNode::edge>::iterator itr = tempnodeList.begin(); itr != tempnodeList.end(); ++itr)
	{
		if (itr->nodeNumber == to)
		{
			Flag = true; // edge already Added
		}
	}

	if (!Flag)
	{
		if (this->isGraphDirected == 'y')
		{
			Graph[from].ListofEdges.push_back(toEdge);
		}
		else
		{
			Graph[from].ListofEdges.push_back(toEdge);
			Graph[to].ListofEdges.push_back(fromEdge);
		}		
	}
	
	else
	{
		cout << "Edge is Already Added !! "<<endl; // throw
	}
}
bool GraphADT::isAllDegreeEven()
{
	int sum = 0;

	for (int i = 1; i < NumberOfNodes+1; i++)
	{
		sum = sum + this->Graph[i].ListofEdges.size();
	}

	if (sum % 2 == 0)
		return true;
	else
		return false;
}

void GraphADT::initColorArray()
{
	Colors temp = White;

	for (int i = 0; i < NumberOfNodes + 1; i++)
	{
		this->ColorArray.push_back(temp);
	}

}
GraphADT GraphADT::BuildTransposeGraph(GraphADT G)
{
	bool flag=false;
	GraphADT res;
	list<GraphNode::edge> AdjList;
	res.GetGraphDetailsAndInit(G.isGraphDirected, G.NumberOfNodes, G.NumberOfEdges);

	for (int i = 1; i < G.NumberOfNodes+1; i++)
	{

		AdjList = G.Graph[i].ListofEdges;
		for (list<GraphNode::edge>::iterator itr = AdjList.begin(); itr != AdjList.end(); ++itr)
		{
			res.AddEdge(itr->nodeNumber, i, flag);
		}

	}

	return res;
}

bool GraphADT::isDirectedGraphStronglyConnected()
{
	
	int RandomNode = (rand() % NumberOfNodes) + 1; // Randomly choosing a node to DFS it

	Visit(Graph[RandomNode]);
	for (int i = 1; i < NumberOfNodes + 1; i++)
	{
		if (ColorArray[i] != Black)
			return false;
	}
	
	GraphADT Gtranspose = BuildTransposeGraph(*this);
	Gtranspose.initColorArray();
	Gtranspose.Visit(Gtranspose.Graph[RandomNode]);
	for (int i = 1; i < Gtranspose.NumberOfNodes + 1; i++)
	{
		if (Gtranspose.ColorArray[i] != Black)
			return false;
	}

	return true;
}

bool GraphADT::isGraphEulerian()
{

	return (  isGraphConnected() && isAllDegreeEven()  );
}

bool GraphADT::isUnDirectedGraphConnected()
{
	initColorArray();
	Visit(Graph[1]);
	for (int i = 1; i < NumberOfNodes+1; i++)
	{
		if (ColorArray[i] != Black)
			return false;
	}

	return true;
}

bool GraphADT::isGraphConnected()
{
	if (this->isGraphDirected == 'y')
		return isDirectedGraphStronglyConnected();
	else
		return isUnDirectedGraphConnected();
}

list<int> GraphADT::FindCircuit( GraphNode &v0)
{
	GraphNode v = v0;
	list<int> L;
	L.push_back(v.nodeNumber);
	while (!isAllEdgesMarked(v))
	{
		GraphNode u = getFirstUnmarkedEdge(v);
		if (this->isGraphDirected == 'y')
		{
			MarkEdgeAsUsed(v.nodeNumber, u.nodeNumber);
			u = Graph[u.nodeNumber];
		}

		else
		{
			MarkEdgeAsUsed(v.nodeNumber, u.nodeNumber);
			MarkEdgeAsUsed(u.nodeNumber, v.nodeNumber);
			u = Graph[u.nodeNumber];
		}
		L.push_back(u.nodeNumber);
		v = u;
		
	}

	return L;

}

list<int> GraphADT::GetEulerCircle()
{

	list<int> L = FindCircuit(this->Graph[1]);
	list<int> L1;
	bool flag = false;
	list<int>::iterator vertex = L.begin();

	while (!flag)
	{
		if (!isAllEdgesMarked(Graph[*vertex]))
		{
			L1 = FindCircuit(Graph[*vertex]);
			L = PasteLists(L, L1);
			vertex = L.begin();
		}

		vertex++;
		if (vertex == L.end())
			break;
		if (isAllEdgesMarked(Graph[*vertex]) && vertex == L.end())
			break;
	}

	return L;
      
}

list<int> GraphADT::PasteLists(list<int> source, list<int> target)
{

	list<int> res;
	list<int>::iterator Titr = target.begin();
	list<int>::iterator Sitr = source.begin();

	for (; Sitr != source.end(); Sitr++)
	{
		if(*Sitr!=*Titr)
		res.push_back(*Sitr);
		else
		{
			for (; Titr != target.end(); Titr++)
			{
				res.push_back(*Titr);
			}

			Sitr++;

			for (; Sitr != source.end(); Sitr++)
			{
				res.push_back(*Sitr);
			}
			break;
		}
	}

	return res;
}
bool GraphADT::isAllEdgesMarked(GraphNode &v0)
{
	list<GraphNode::edge> AdjList = v0.ListofEdges;

	for (list<GraphNode::edge>::iterator itr = AdjList.begin(); itr != AdjList.end(); ++itr)
	{
		if (itr->IsMarked == false)
		return false;
	}

	return true;
}
void GraphADT::MarkEdgeAsUsed(int from, int to)
{

	list<GraphNode::edge> & AdjList = this->Graph[from].ListofEdges;
	for (auto &itr : AdjList)
	{

		if (itr.nodeNumber == to)
		{
			itr.IsMarked = true;
			return;
		}
		
	}

}
GraphNode GraphADT::getFirstUnmarkedEdge(GraphNode &v)
{
	list<GraphNode::edge> &AdjList = Graph[v.nodeNumber].ListofEdges;

	for (list<GraphNode::edge>::iterator itr = AdjList.begin(); itr != AdjList.end(); ++itr)
	{
		if (itr->IsMarked == false)
		return this->Graph[itr->nodeNumber];
	}
}

void GraphADT::printEulerCircle(list<int> ListOfNodes)
{

	for (auto node = ListOfNodes.begin(); node != ListOfNodes.end(); ++node)
	{
		if (node == ListOfNodes.begin())
		{
			cout << "The graph is aulerian" << endl;
			cout << "("<<*node<<",";
			continue;
		}
		if (node == --ListOfNodes.end())
		{
			cout << *node <<")";
		}
		else
		{
			cout << *node << ",";
		}

	}

	
}