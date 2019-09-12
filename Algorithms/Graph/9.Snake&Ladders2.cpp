/*
    This solution is not accepted
*/

#include <bits/stdc++.h>
using namespace std;

map <int, int> powerMoves;


// Complete the quickestWayUp function below.
int QuickestWayUp() 
{
    int start = 1;

    queue <int> qList;

    vector <bool> visited(101, false);
    vector <int> dist(101, 0);

    visited[start] = true;
    dist[start] = 0;

    qList.push(start);

    while(!qList.empty())
    {
        int current = qList.front();
        qList.pop();

        int nextMove;

        for(int k = 1; k <= 6; k++)
        {
            if(powerMoves.count(current + k) != 0)
            {
                nextMove = powerMoves[current + k];
            }
            else
            {
                nextMove = current + k;
            }

            if(nextMove >= 1 && nextMove <= 100 && !visited[nextMove])
            {
                visited[nextMove] = true;
                qList.push(nextMove);

                dist[nextMove] = dist[current] + 1;
            }
        }
    }

    if(!visited[100])
    {
        return -1;
    }

    return dist[100];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            cin >> ladders[i][0] >> ladders[i][1];

            powerMoves[ladders[i][0]] = ladders[i][1];

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            cin >> snakes[i][0] >> snakes[i][1];

            powerMoves[snakes[i][0]] = snakes[i][1];

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = QuickestWayUp();

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
