#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) 
{
    int front = p-1;

    int frontTurn, backTurn;

    if (front % 2 == 0)
    {
        frontTurn = front / 2;
    }
    else
    {
        frontTurn = (front / 2 )+ 1;
    }

    int back = n - p;

    if(n % 2 == 0)
    {
        
    }

    if (back % 2 == 0)
    {
        backTurn = back / 2;
    }
    else
    {
        backTurn = (back / 2) + 1;
    }

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
