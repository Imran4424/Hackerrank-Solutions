#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) 
{
    long singleCount = 0, totalCount = 0;

    for(long i =0; i < s.size(); i++)
    {
        if(s[i] == 'a')
        {
            singleCount++;
        }
    }

    long div = n / s.size();

    long rem = n % s.size();

    totalCount = div * singleCount;

    for (long i = 0; i < rem; i++) 
    {
        if (s[i] == 'a') 
        {
            totalCount++;
        }
    }

    return totalCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
