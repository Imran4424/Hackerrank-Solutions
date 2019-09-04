#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

typedef pair<lli, lli> couple;

vector<string> split_string(string);


// Complete the maximumSum function below.
lli maximumSum(vector<lli> a, lli m) 
{
    vector <lli> prefixSum;

    prefixSum.push_back(a[0] % m);

    lli totalPrefix = prefixSum[0];

    for (lli i = 1; i < a.size(); ++i)
    {
        prefixSum.push_back((prefixSum[i-1] + a[i]) % m);

        totalPrefix += prefixSum[i];
    }

    sort(prefixSum.begin(), prefixSum.end());

    lli sortedMaxMod = prefixSum[prefixSum.size() - 1];

    lli maxMod = 0;

    for (lli i = 0; i < prefixSum.size(); ++i)
    {
        if ((totalPrefix - prefixSum[i]) % m > maxMod)
        {
            maxMod = (totalPrefix - prefixSum[i]) % m;
        }
    }
    
    return max(maxMod, sortedMaxMod);
}

int main()
{

    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) 
    {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        lli m = (lli) stol(nm[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<lli> a(n);

        for (int i = 0; i < n; i++) 
        {
            lli a_item = stol(a_temp[i]);

            a[i] = a_item;
        }

        lli result = maximumSum(a, m);

        fout << result << "\n";
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
