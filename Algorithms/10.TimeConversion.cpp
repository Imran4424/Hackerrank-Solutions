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

    if (indicator == "PM")
    {
        hr += 12;

        ostringstream convertBack;

        convertBack << hr;

        hour.clear();

        hour = convertBack.str();

        s[0] = hour[0];
        s[0] = hour[0];
    }
    else
    {
        if (hr == 12)
        {
            s[0] = '0';
            s[1] = '0';
        }
    }


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
