#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<string> split_string(string);

// Complete the gridlandMetro function below.
lli gridlandMetro(lli n, lli m, lli k, vector<vector<lli>> track) 
{
    vector < vector <bool> > visited(n + 1, vector<bool> (m+1, false));

    lli trackCount = 0;

    for (lli i = 0; i < track.size(); ++i)
    {
        lli row = track[i][0];
        lli trackStart = track[i][1];
        lli trackEnd = track[i][2];

        for (lli x = trackStart; x <= trackEnd; ++x)
        {
            if (!visited[row][x])
            {
                visited[row][x] = true;

                trackCount++;
            }
        }
    }

    lli lampPosts = (n * m) - trackCount;

    return lampPosts;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nmk_temp;
    getline(cin, nmk_temp);

    vector<string> nmk = split_string(nmk_temp);

    lli n = stoi(nmk[0]);

    lli m = stoi(nmk[1]);

    lli k = stoi(nmk[2]);

    vector<vector<lli>> track(k);
    for (lli i = 0; i < k; i++) 
    {
        track[i].resize(3);

        for (lli j = 0; j < 3; j++) {
            cin >> track[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    lli result = gridlandMetro(n, m, k, track);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
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
