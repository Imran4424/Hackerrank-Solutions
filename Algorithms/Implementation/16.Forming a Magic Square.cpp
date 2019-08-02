#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> arr) 
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
