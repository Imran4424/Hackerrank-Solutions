#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long arr[10000110] = {0};

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) 
{
    long sIndex, eIndex, update;

    for(long i=0; i < queries.size(); i++)
    {
        sIndex = queries[i][0];
        eIndex = queries[i][1];
        update = queries[i][2];

        arr[sIndex-1] += update;
        arr[eIndex] -= update;
    }

    long max = arr[0], sum = arr[0];

    for(long i=1; i<n; i++)
    {
        sum += arr[i];

        if(max < sum)
        {
            max = sum;
        }
    }

    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    
    for (int i = 0; i < m; i++) 
    {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) 
        {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) 
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) 
    {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') 
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) 
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
