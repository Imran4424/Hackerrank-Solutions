#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<string> split_string(string);

// Complete the pairs function below.
lli pairs(lli k, vector<lli> arr) 
{
    sort(arr.begin(), arr.end());

    lli pairCount = 0;

    for (lli i = 0; i < arr.size(); ++i)
    {
        for (lli j = i + 1; arr[j] <= arr[i] + k && j < arr.size(); ++j)
        {
            if (abs(arr[i] - arr[j]) == k)
            {
                pairCount++;
            }
        }
    }

    return pairCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    lli n = stoi(nk[0]);

    lli k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<lli> arr(n);

    for (lli i = 0; i < n; i++) 
    {
        lli arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    lli result = pairs(k, arr);

    fout << result << "\n";

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
