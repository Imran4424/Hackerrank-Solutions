#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<string> split_string(string);

lli *bits;

// lli maxRemSum;
vector < vector <lli> > dpRemSum;

lli Binary(lli i,lli sum, vector<lli> a, lli m)
{
    if (-1 != dpRemSum[i][sum])
    {
        return dpRemSum[i][sum];
    }

    if (a.size() == i)
    {
        return dpRemSum[i][sum] = sum % m;
    }


    bits[i] = 0;
    int left = Binary(i+1, sum, a, m);


    bits[i] = 1;
    int right = Binary(i+1, (sum + a[i]) % m, a, m);

    if (left > right)
    {
        dpRemSum[i][sum] = left;
    }
    else
    {
        dpRemSum[i][sum] = right;
    }

    return dpRemSum[i][sum];
}

// Complete the maximumSum function below.
lli maximumSum(vector<lli> a, lli m) 
{
    bits = new lli[a.size()];

    dpRemSum.resize(a.size()+1, vector<lli> (a.size()*2, -1));

    // maxRemSum = 0;

    return Binary(0, 0, a, m);
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

        lli m = stol(nm[1]);

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
