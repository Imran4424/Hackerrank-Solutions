#include <bits/stdc++.h>

using namespace std;

vector <int> *adjacency;

void AddEdge(int source, int destination)
{
    adjacency[source].push_back(destination);
    adjacency[destination].push_back(source);
}

vector<string> split_string(string);

/*
 * Complete the rustMurdered function below.
 */
vector<int> RusMurderer(int source, int totalVertex) 
{
    queue <int> qList;

    vector <bool> visited(totalVertex+1, false);

    set <int> complement, given;

    for(int i = 1; i <= totalVertex; i++)
    {
        if (i != source)
        {
            complement.insert(i);
        }
    }

    vector <int> minDistance(totalVertex + 1, 0);

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
                complement.erase(adjacency[current][k]); // taking only the complement
                given.insert(adjacency[current][k]);  // storing the given for next iteration
            }
        }

        for(auto k = complement.begin(); k != complement.end(); k++)
        {
            visited[*k] = true;
            qList.push(*k);

            minDistance[*k] = minDistance[current] + 1; 
        }

        // for next test case
        complement = given; 
        given.clear();
    }

    return minDistance;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) 
    {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        adjacency = new vector <int> [n + 1];

        vector<vector<int>> roads(m);
        for (int roads_row_itr = 0; roads_row_itr < m; roads_row_itr++) {
            roads[roads_row_itr].resize(2);

            for (int roads_column_itr = 0; roads_column_itr < 2; roads_column_itr++) 
            {
                cin >> roads[roads_row_itr][roads_column_itr];
            }

            AddEdge(roads[roads_row_itr][0], roads[roads_row_itr][1]);

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = RusMurderer(s, n);

        for (int result_itr = 0; result_itr < result.size(); result_itr++) 
        {
            if(result[result_itr] != 0)
            {
                fout << result[result_itr] << " ";
            }

        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) 
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
