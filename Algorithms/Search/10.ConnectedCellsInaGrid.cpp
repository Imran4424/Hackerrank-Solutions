#include <bits/stdc++.h>

using namespace std;

bool IsSafe(int x, int y)
{
    if (x < 0 || y < 0)
    {
        return false;
    }

    return true;
}

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) 
{
    vector < vector<bool> > visited(matrix.size(), vector <bool> (matrix[0].size(), false));

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            /* code */
        }
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}
