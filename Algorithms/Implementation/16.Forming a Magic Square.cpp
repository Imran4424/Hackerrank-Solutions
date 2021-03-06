#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> arr) //// not solved yet
{
    int primaryDiagonal = 0, secondaryDiagonal = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
        {
            if (i == j)
            {
                primaryDiagonal += arr[i][j];
            }

            if (i + j == arr.size() - 1)
            {
                secondaryDiagonal += arr[i][j];
            }
        }
    }

    int max;

    if (primaryDiagonal > secondaryDiagonal)
    {
        max = primaryDiagonal;
    }
    else
    {
        max = secondaryDiagonal;
    }

    int cost = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
        {
            int rowSum = 0, colSum = 0, sDiagonal, pDiagonal;

            for (int k = 0; k < arr.size(); ++k)
            {
                if(j != k)
                {
                    rowSum += arr[i][k];
                }

                if(i != k)
                {
                    colSum += arr[k][j];
                }
            }

            if(i == j)
            {
                pDiagonal = (primaryDiagonal - arr[i][j]);
            }


            if (i + j == arr.size() - 1)
            {
                sDiagonal = (secondaryDiagonal - arr[i][j]);
            }

            if (rowSum == colSum && (rowSum + arr[i][j]) < max)
            {
                cost += abs((max - rowSum) - arr[i][j]); 
            }
        }
    }

    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    
    for (int i = 0; i < 3; i++) 
    {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) 
        {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
