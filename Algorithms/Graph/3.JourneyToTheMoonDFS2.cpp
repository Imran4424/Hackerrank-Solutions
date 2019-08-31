#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<string> split_string(string);

vector <lli> *adjacency;
lli countMembers;

void AddEdge(lli source, lli destination)
{
    adjacency[source].push_back(destination);
    adjacency[destination].push_back(source);
}

void DFS(lli current, vector <bool> &visited)
{
    for(lli k = 0; k < adjacency[current].size(); k++)
    {
        if (!visited[adjacency[current][k]])
        {
            visited[adjacency[current][k]] = true;

            countMembers++;

            DFS(adjacency[current][k], visited);
        }
    }
}


// Complete the journeyToMoon function below.
lli journeyToMoon(lli n, vector<vector<lli>> astronaut) 
{
    adjacency = new vector <lli> [n+1];

    vector <bool> visited(n+1, false);

    for (lli i = 0; i < astronaut.size(); ++i)
    {
        AddEdge(astronaut[i][0], astronaut[i][1]);
    }

    vector <lli> countries;

    for (lli i = 0; i < n; ++i) // vertex count starts from 0
    {
        if (!visited[i])
        {
            visited[i] = true;

            countMembers = 1;

            DFS(i, visited);

            countries.push_back(countMembers); // starting the count as 1 cause 
        }                                           //  i is already a country member
    }

    lli pairCount = 0;

    for (lli i = 0; i < countries.size(); ++i)
    {
        for (lli j = i+1; j < countries.size(); ++j)
        {
            // this is combination but as we know nC1 = n
            // we skip the calculation for better time complexity

            pairCount += countries[i] * countries[j]; 
            
        }
    }

    return pairCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    lli n = stoi(np[0]);

    lli p = stoi(np[1]);

    vector<vector<lli>> astronaut(p);
    for (lli i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (lli j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    lli result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
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
