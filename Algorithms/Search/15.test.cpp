#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int lli;

vector<string> split_string(string);

// Complete the minimumPasses function below.
lli minimumPasses(lli m, lli w, lli p, lli n) 
{
    if (n <= p)
    {
        return ceil(n / (m * w));
    }

    lli phases = 0;

    lli countingCandies = 0;

    lli phasesAlter = 9999999999999999;

    while(countingCandies < n)
    {
        
        if (countingCandies < p)
        {
            lli steps = ceil((p - countingCandies) / (m * n));

            phases += steps;

            countingCandies += (steps * m * n);

            continue;
        }
    
        lli buyResource = countingCandies / p;

        countingCandies = countingCandies % p;

        lli totalResource = m + w + buyResource;

        lli halfResource = floor(totalResource / 2);

        if (m > w)
        {
            m = halfResource; // smaller or equal
            w = totalResource - halfResource; // bigger or equal
        }
        else
        {
            w = halfResource; // smaller or equal
            m = totalResource - halfResource; // bigger or equal
        }
        
        phases++;

        countingCandies += (m * w);

        phasesAlter = min(phasesAlter, ceil((n - countingCandies) / ( m * w) ) );
    }

    return min(phases, phasesAlter);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string mwpn_temp;
    getline(cin, mwpn_temp);

    vector<string> mwpn = split_string(mwpn_temp);

    lli m = stol(mwpn[0]);

    lli w = stol(mwpn[1]);

    lli p = stol(mwpn[2]);

    lli n = stol(mwpn[3]);

    lli result = minimumPasses(m, w, p, n);

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
