#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<string> split_string(string);

// Complete the minimumPasses function below.
lli minimumPasses(lli m, lli w, lli p, lli n) 
{   
    lli phases = 0;

    lli countingCandies = 0;

    while(countingCandies < n)
    {
        phases++;
        lli producedCandies = m * w;

        if(producedCandies + countingCandies >= n)
        {
            break;
        }

        

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
