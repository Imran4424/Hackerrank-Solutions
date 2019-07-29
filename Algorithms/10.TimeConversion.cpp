#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) 
{
    string indicator;

    indicator += s[s.size()-2];
    indicator += s[s.size()-1];

    string hour += s[0];
    hour[1] += s[1];

    stringstream converter(hour);

    int hr = 0;

    converter >> hr;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
