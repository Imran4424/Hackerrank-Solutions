#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

typedef pair <lli, lli> couple;

vector<string> split_string(string);

// Complete the gridlandMetro function below.
lli gridlandMetro(lli n, lli m, lli k, map <lli, vector<couple> > track) 
{
    //vector < vector <bool> > visited(n + 1, vector<bool> (m+1, false));

    lli trackCount = 0;

    map <lli, vector<couple> > :: iterator it;

    for (it = track.begin(); it != track.end(); ++it)
    {
        lli row = it -> first;
        
        vector<couple> helper = it -> second;

        for (int i = 0; i < helper.size(); ++i)
        {
            lli trackStart = helper[i].first;
            lli trackEnd = helper[i].second;
            
            trackCount += (trackEnd - trackStart + 1);
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

    lli row, trackStart, trackEnd;

    map<lli, vector <couple> > track;

    for (lli i = 0; i < k; i++) 
    {
        cin >> row >> trackStart >> trackEnd;

        

        if(track.count(lli(row)))
        {
            bool merged = false;

            for(lli m = 0; m < track[row].size(); m++)
            {
                if (trackStart < track[row][m].first)
                {
                    track[row][m].first = trackStart;

                    merged = true;
                }

                if (trackEnd > track[row][m].second)
                {
                    track[row][m].second = trackEnd;

                    merged = true;
                }
            }

            if (!merged)
            {
                track[row].push_back(make_pair(trackStart, trackEnd));
            }
        }
        else
        {
            track[row].push_back(make_pair(trackStart, trackEnd));
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    lli result = gridlandMetro(n, m, k, track);

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
