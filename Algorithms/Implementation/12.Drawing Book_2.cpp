#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) 
{
    int frontTurn = p / 2;

    int backTurn = (n / 2) - frontTurn;

    if (frontTurn < backTurn)
    {
        return frontTurn;
    }

    return backTurn;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
