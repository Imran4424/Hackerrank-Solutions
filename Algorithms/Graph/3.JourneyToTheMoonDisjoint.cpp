#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<string> split_string(string);

lli *parent;
lli *countryMembers;

void MakeSet(lli vertex)
{
    parent[vertex] = vertex;
}

void InitDisjoint(lli vertex)
{
    for (lli i = 0; i < vertex; ++i)
    {
        MakeSet(i);

        countryMembers[i] = 0; // starting the count as 1 cause i is already a country member
    }
}

lli SearchMother(lli vertex)
{
    if (parent[vertex] == vertex)
    {
        return vertex;
    }

    return parent[vertex] = SearchMother(parent[vertex]);
}

void Union(lli xVertex, lli yVertex)
{
    lli xParent = SearchMother(xVertex);
    lli yParent = SearchMother(yVertex);

    if (xParent != yParent)
    {
        parent[yParent] = xParent;

        countryMembers[xParent]++;
        countryMembers[yParent]--;
    }

}

// Complete the journeyToMoon function below.
lli journeyToMoon(lli n, vector<vector<lli>> astronaut) 
{
    parent = new lli[n];
    countryMembers = new lli[n];

    InitDisjoint(n);

    vector <lli> countries;

    for (lli i = 0; i < n; ++i)
    {
        if (countryMembers[i] > 0)
        {
            countries.push_back(countryMembers[i]);
        }
    }

    lli pairCount = 0;

    for (lli i = 0; i < countries.size(); ++i)
    {
        for (lli j = i+1; j < countries.size(); ++j)
        {
            // this is combination but as we know nC1 = n
            // we skip the calculation for better time complexity

            pairCount += countries[i] * countries[j]; 
            
        }
    }

    return pairCount;
}

int main()
{
    freopn("input.txt", "r", stdin);

    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    lli n = stoi(np[0]);

    lli p = stoi(np[1]);

    vector<vector<lli>> astronaut(p);
    for (lli i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (lli j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    lli result = journeyToMoon(n, astronaut);

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
