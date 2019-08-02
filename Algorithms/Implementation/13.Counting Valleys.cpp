#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) 
{
    int currentPos = 0, countValley = 0;

    for(int i = 0; i < n; i++)
    {
        if('D' == s[i])
        {
            currentPos--;
        }

        if('U' == s[i])
        {
            currentPos++;

            if(currentPos == 0)
            {
              countValley++;
            }
        }
    }


    return countValley;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
