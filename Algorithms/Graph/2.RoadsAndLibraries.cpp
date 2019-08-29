#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

vector <lli> *adjacency;

void AddEdge(lli u, lli v) // unidirected
{
	adjacency[u].push_back(v);
	adjacency[v].push_back(u);
}

lli FindMinimumCost(lli cities, lli libraryCost, lli roadCost)
{
	
}


int main(int argc, char const *argv[])
{
	lli test;
	cin >> test;

	while(test--)
	{
		lli cities, roads, libraryCost, roadCost;
		cin >> cities >> roads >> libraryCost >> roadCost;

		adjacency = new vector <lli> [cities+1];

		lli u, v;

		for (lli i = 0; i < roads; ++i)
		{
			cin >> u >> v;

			AddEdge(u, v);
		}


	}
	
	return 0;
}