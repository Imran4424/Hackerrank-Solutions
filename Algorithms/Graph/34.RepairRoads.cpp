#include <bits/stdc++.h>

using namespace std;

vector <int> *adjacency;

void AddEdge(int source, int destination)
{
    adjacency[source].push_back(destination);
    adjacency[destination].push_back(source);
}

void DFS(int source, vector <bool> &visited)
{
    queue <int> qList;

    visited[source] = true;

    qList.push(source);

    while(!qList.empty())
    {
        int current = qList.front();
        qList.pop();

        for(int k = 0; k < adjacency[current].size(); k++)
        {
            if (!visited[adjacency[current][k]])
            {
                visited[adjacency[current][k]] = true;

                qList.push(adjacency[current][k]);
            }
        }
    }
}

int repairRoads(int n, vector<vector<int>> roads) 
{
    adjacency = new vector<int> [n+1];

    for(int i = 0; i < roads.size(); i++)
    {
        if (i != roads.size() - 1)
        {
            if (roads[i][0] != roads[i+1][0] && roads[i][0] != roads[i+1][1] && roads[i][1] != roads[i+1][0] && roads[i][1] != roads[i+1][1])
            {
                continue;
            }
        }

        AddEdge(roads[i][0], roads[i][1]);
    }

    vector <bool> visited(n+1, false);

    int robotCount = 0;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            DFS(i, visited);

            robotCount++;
        }
    }

    return robotCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> roads(n-1);
        for (int roads_row_itr = 0; roads_row_itr < n-1; roads_row_itr++) {
            roads[roads_row_itr].resize(2);

            for (int roads_column_itr = 0; roads_column_itr < 2; roads_column_itr++) {
                cin >> roads[roads_row_itr][roads_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = repairRoads(n, roads);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
