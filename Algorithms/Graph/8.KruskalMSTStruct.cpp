#include <bits/stdc++.h>
using namespace std;

struct EdgeInstance
{
    int source, destination, weight;

    bool operator<(const EdgeInstance &obj)
    {
        return weight < obj.weight;
    }
};

int *parent;

void InitDisjoint(int vertex)
{
    for (int i = 1; i <= vertex; ++i)
    {
        parent[i] = i;
    }
}

int SearchParent(int vertex)
{
    if (vertex == parent[vertex])
    {
        return vertex;
    }

    return parent[vertex] = SearchParent(parent[vertex]);
}

bool Union(int xVertex, int yVertex)
{
    int xParent = SearchParent(xVertex);
    int yParent = SearchParent(yVertex);

    if (xParent != yParent)
    {
        parent[yParent] = xParent;

        return true;
    }

    return false;
}

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) 
{
    parent = new int[g_nodes + 1];

    InitDisjoint(g_nodes);

    vector <EdgeInstance> EdgeList;

    EdgeInstance temp;

    for (int i = 0; i < g_from.size(); ++i)
    {
        temp.source = g_from[i];
        temp.destination = g_to[i];
        temp.weight = g_weight[i];

        EdgeList.push_back(temp);
    }

    sort(EdgeList.begin(), EdgeList.end());

    int minWeight = 0;

    for (int i = 0; i < EdgeList.size(); ++i)
    {
        if(Union(EdgeList[i].source, EdgeList[i].destination))
        {
            minWeight += EdgeList[i].weight;
        }
    }

    return minWeight;
}

int main()
{
    int g_nodes, g_edges;
    cin >> g_nodes >> g_edges;

    vector <int> g_to, g_from, g_weight;

    int source, destination, weight;

    for (int i = 0; i < g_edges; ++i)
    {
        cin >> source >> destination >> weight;

        g_to.push_back(source);
        g_from.push_back(destination);
        g_weight.push_back(weight);
    }

    cout << kruskals(g_nodes, g_to, g_from, g_weight);
    
    return 0;
}

