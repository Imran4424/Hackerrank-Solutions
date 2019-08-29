#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

vector <int> *adjacency;

void AddEdge(int u, int v) // unidirected
{
	adjacency[u].push_back(v);
	adjacency[v].push_back(u);
}


int main(int argc, char const *argv[])
{
	int test;
	cin >> test;

	while(test--)
	{
		int vertex;
		adjacency = new vector <int> [vertex+1];


	}
	
	return 0;
}