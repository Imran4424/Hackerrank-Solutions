#include <bits/stdc++.h>

using namespace std;

int cellCount;

bool IsSafe(vector<vector<int>> matrix,int x, int y)
{
    if (x < 0 || y < 0)
    {
        return false;
    }

    if (x >= matrix.size() || y >= matrix[0].size())
    {
        return false;
    }

    return true;
}

void FindRegion(vector<vector<int>> matrix, vector < vector <bool> > &visited, int x, int y)
{
    visited[x][y] = true;

    cellCount++;

    if (IsSafe(matrix, x+1, y)) // lower column
    {
        if (!visited[x+1][y])
        {
            if (matrix[x+1][y])
            {
                FindRegion(matrix, visited, x + 1, y);
            }
            else
            {
                visited[x+1][y] = true;
            }
        }
    }

    if (IsSafe(matrix, x-1, y)) // upper column
    {
        if (!visited[x-1][y])
        {
            if (matrix[x-1][y])
            {
                FindRegion(matrix, visited, x - 1, y);
            }
            else
            {
                visited[x-1][y] = true;
            }
        }
    }

    if (IsSafe(matrix, x, y+1)) // right column
    {
        if (!visited[x][y+1])
        {
            if (matrix[x][y+1])
            {
                FindRegion(matrix, visited, x, y+1);
            }
            else
            {
                visited[x][y+1] = true;
            }
        }
    }

    if (IsSafe(matrix, x, y-1)) // left column
    {
        if (!visited[x][y-1])
        {
            if (matrix[x][y-1])
            {
                FindRegion(matrix, visited, x, y-1);
            }
            else
            {
                visited[x][y-1] = true;
            }
        }
    }

    if (IsSafe(matrix, x+1, y+1)) // lower right
    {
        if (!visited[x+1][y+1])
        {
            if (matrix[x+1][y+1])
            {
                FindRegion(matrix, visited, x+1, y+1);
            }
            else
            {
                visited[x+1][y+1] = true;
            }
        }
    }

    if (IsSafe(matrix, x-1, y+1)) // upper right
    {
        if (!visited[x-1][y+1])
        {
            if (matrix[x-1][y+1])
            {
                FindRegion(matrix, visited, x-1, y+1);
            }
            else
            {
                visited[x-1][y+1] = true;
            }
        }
    }

    if (IsSafe(matrix, x-1, y-1)) // upper left
    {
        if (!visited[x-1][y-1])
        {
            if (matrix[x-1][y-1])
            {
                FindRegion(matrix, visited, x-1, y-1);
            }
            else
            {
                visited[x-1][y-1] = true;
            }
        }
    }

    if (IsSafe(matrix, x+1, y-1)) // lower left
    {
        if (!visited[x+1][y-1])
        {
            if (matrix[x+1][y-1])
            {
                FindRegion(matrix, visited, x+1, y-1);
            }
            else
            {
                visited[x+1][y-1] = true;
            }
        }
    }

}

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) 
{
    vector <int> allCellCount;

    vector < vector<bool> > visited(matrix.size(), vector <bool> (matrix[0].size(), false));

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (!visited[i][j])
            {
                if (matrix[i][j])
                {
                    cellCount = 0;

                    FindRegion(matrix, visited, i, j);

                    allCellCount.push_back(cellCount);
                }
                else
                {
                    visited[i][j] = true;
                }

            }
        }
    }

    sort(allCellCount.rbegin(), allCellCount.rend());

    return allCellCount[0];
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
