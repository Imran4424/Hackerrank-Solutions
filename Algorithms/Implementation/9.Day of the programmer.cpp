#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) 
{
    string date;

    if(year < 1918) // julian year
    {
        if (year % 4 == 0)
        {
            date += "12.09.";
        }
        else // Gregorian calendar
        {
            date += "13.09.";
        }
    }
    else
    {
        if (year % 4 == 0)
        {
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                {
                    date += "12.09.";
                }
                else
                {
                    date += "13.09.";
                }
            }
            else
            {
                date += "12.09.";
            }
        }
        else
        {
            date += "13.09.";
        }        
    }


    ostringstream converter;

    converter << year;

    string pYear = converter.str();

    date += pYear;

    return date;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) 
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) 
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
