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
vector<int> rustMurdered(int n, vector<vector<int>> roads) 
{
    /*
     * Write your code here.
     */

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        adjacency = vector <int> [n + 1];

        vector<vector<int>> roads(m);
        for (int roads_row_itr = 0; roads_row_itr < m; roads_row_itr++) {
            roads[roads_row_itr].resize(2);

            for (int roads_column_itr = 0; roads_column_itr < 2; roads_column_itr++) 
            {
                cin >> roads[roads_row_itr][roads_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = rustMurderer(n, roads);

        for (int result_itr = 0; result_itr < result.size(); result_itr++) {
            fout << result[result_itr];

            if (result_itr != result.size() - 1) {
                fout << " ";
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
