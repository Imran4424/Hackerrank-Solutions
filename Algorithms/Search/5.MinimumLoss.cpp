#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<string> split_string(string);

// Complete the minimumLoss function below.
lli minimumLoss(vector<lli> price) 
{
    vector <lli> sortedPrice = price;

    sort(sortedPrice.rbegin(), sortedPrice.rend());

    lli minLoss = 99999999999999999;

    for (lli i = 0; i < sortedPrice.size(); ++i)
    {

        if (sortedPrice[i] - sortedPrice[i+1] < minLoss && price[i] > price[i+1])
        {
            minLoss = price[i] - price[j];
        }

    }

    return minLoss;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    lli n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string price_temp_temp;
    getline(cin, price_temp_temp);

    vector<string> price_temp = split_string(price_temp_temp);

    vector<long> price(n);

    for (lli i = 0; i < n; i++) 
    {
        long price_item = stol(price_temp[i]);

        price[i] = price_item;
    }

    lli result = minimumLoss(price);

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
