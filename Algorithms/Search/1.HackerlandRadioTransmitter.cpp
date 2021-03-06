#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<string> split_string(string);

// Complete the hackerlandRadioTransmitters function below.
lli hackerlandRadioTransmitters(vector<lli> x, lli k) 
{
    sort(x.begin(), x.end());

    lli current = 0;
    lli transmitterCount = 0;

    while(current < x.size())
    {
        lli upperRange = x[current] + k;

        lli j = current;


        while(x[j] <= upperRange && j < x.size())
        {
            j++;
        }
    
        j--; // transmitter position

        upperRange = x[j] + k;

        while(x[j] <= upperRange && j < x.size())
        {
            j++;
        }

        transmitterCount++;

        current = j;
    }

    return transmitterCount;    
}

int main()
{
    //freopen("input.txt", "r", stdin);

    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    lli n = stoi(nk[0]);

    lli k = stoi(nk[1]);

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split_string(x_temp_temp);

    vector<lli> x(n);

    for (lli i = 0; i < n; i++) 
    {
        lli x_item = stoi(x_temp[i]);

        x[i] = x_item;
    }

    lli result = hackerlandRadioTransmitters(x, k);

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
