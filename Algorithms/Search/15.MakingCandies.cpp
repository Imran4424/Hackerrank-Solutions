#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int lli;

vector<string> split_string(string);

// Complete the minimumPasses function below.
lli minimumPasses(lli machine, lli workers, lli price, lli n) 
{
    if (n <= price)
    {
        return ceil(n / (machine * workers));
    }

    lli phases = 0;

    lli countingCandies = 0;

    lli phasesAlter = 1844674407370955161;

    while(countingCandies < n)
    {
        
        if (countingCandies < price && (price - countingCandies) > (machine * workers))
        {
            lli candyOneIterate = (machine * workers);

            lli steps = ceil((price - countingCandies) / candyOneIterate);

            phases += steps;

            countingCandies += (steps * candyOneIterate);

            continue;
        }
    
        lli buyResource = countingCandies / price;

        countingCandies = (countingCandies - (buyResource * price));

        lli totalResource = machine + workers + buyResource;

        lli halfResource = totalResource / 2;

        if (machine > workers)
        {
            machine = max(machine, halfResource); // smaller or equal
            workers = totalResource - machine; // bigger or equal
        }
        else
        {
            workers = max(workers, halfResource); // smaller or equal
            machine = totalResource - workers; // bigger or equal
        }
        
        phases++;

        countingCandies += (machine * workers);

        lli candyOneIterate = (machine * workers);

        lli helper = ceil((n - countingCandies) / candyOneIterate );

        phasesAlter = min(phasesAlter, helper);
    }

    return min(phases,phasesAlter);
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
