#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> couple;

vector<couple> *adjacency;

vector<string> split_string(string);

void AddEdge(int source, int destination, int weight)
{
    adjacency[source].push_back(make_pair(weight, destination));
    adjacency[destination].push_back(make_pair(weight, source));
}

// Complete the prims function below.
int prims(int totalVertex, int start) 
{
    int minimumWeight = 0;

    priority_queue<couple, vector<couple> , greater<couple> > weightedList;

    vector<bool> visited(totalVertex+1, false);
    int visitedCount = totalVertex;

    visited[start] = true;
    visitedCount--;

    for(int k = 0; k < adjacency[start].size(); k++)
    {
        weightedList.push(adjacency[start][k]);
    }

    while(!weightedList.empty() && visitedCount)
    {
        couple hand = weightedList.top();
        weightedList.pop();

        if(!visited[hand.second])
        {
            minimumWeight += hand.first;

            int current = hand.second;

            visited[current] = true;
            visitedCount--;

            for(int k = 0; k < adjacency[current].size(); k++)
            {
                couple helper = adjacency[current][k];

                if(!visited[helper.second])
                {
                    weightedList.push(helper);
                }
            }
        }
    }

    return minimumWeight;
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    adjacency = new vector<couple>[vertex+1];

    int source, destination, weight;

    for (int i = 0; i < edges; ++i)
    {
        cin >> source >> destination >> weight;

        AddEdge(source, destination, weight);
    }

    int start;
    cin >> start;

    cout << prims(vertex, start) << endl;

    return 0;
}
