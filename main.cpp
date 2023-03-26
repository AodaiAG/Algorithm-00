
#include <iostream>
#include <vector>
#include "GraphADT.h"
using namespace std;

void main()
{
	GraphADT test;
	test.GetGraphDetails();
	test.CreateGraphFromDetails();

}

void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
	cin.clear();

}