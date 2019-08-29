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
		int cities, roads, libraryCost, roadCost;
		cin >> cities >> roads >> libraryCost >> roadCost;

		adjacency = new vector <int> [cities+1];

		int u, v;

		for (int i = 0; i < roads; ++i)
		{
			cin >> u >> v;

			AddEdge(u, v);
		}
	}
	
	return 0;
}