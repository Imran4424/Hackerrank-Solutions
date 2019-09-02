#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

typedef pair <int, int> couple;

vector <couple> *adjacency;

vector <int> distanceFromSource;

void AddEdge(int source, int destination, int weight)
{
    adjacency[source].push_back(make_pair(destination, weight));

    adjacency[destination].push_back(make_pair(source, weight));
}

void Dijkstra(int startVertex, int totalVertex)
{

    distanceFromSource.resize(totalVertex + 1, INT_MAX);

    priority_queue<couple, vector <couple>, greater <couple> > weightedList;

    int iteration = (totalVertex / 2);

    while(iteration--)
    {

        vector <bool> visited(totalVertex + 1, false);

        weightedList.push(make_pair(0, startVertex));

        // following two statements won't create any problem for next iteration
        distanceFromSource[startVertex] = 0;
        visited[startVertex] = true;


        while(!weightedList.empty())
        {
            // cout << "Hi" << endl;

            couple hand = weightedList.top();
            weightedList.pop();

            int current = hand.second;

            for (int k = 0; k < adjacency[current].size(); ++k)
            {
                int neighbour = adjacency[current][k].first;
                int neighbourDistance = adjacency[current][k].second;

                if(distanceFromSource[current] + neighbourDistance < distanceFromSource[neighbour])
                {
                    distanceFromSource[neighbour] = distanceFromSource[current] + neighbourDistance;
                }

                if (!visited[neighbour])
                {
                    weightedList.push(make_pair(neighbourDistance, neighbour));

                    visited[neighbour] = true;
                }
            }
        }

    }

}

/*
 * Complete the 'shop' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. STRING_ARRAY centers
 *  4. 2D_INTEGER_ARRAY roads
 */

int shop(int n, int k, vector<string> centers, vector<vector<int>> roads) 
{
    adjacency = new vector <couple> [n + 1];

    for (int i = 0; i < roads.size(); ++i)
    {
        AddEdge(roads[i][0], roads[i][1], roads[i][2]);
    }

    vector <couple> shortestPath = Dijkstra(1, n);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    vector<string> centers(n);

    for (int i = 0; i < n; i++) 
    {
        string centers_item;
        getline(cin, centers_item);

        centers[i] = centers_item;
    }

    vector<vector<int>> roads(m);

    for (int i = 0; i < m; i++) 
    {
        roads[i].resize(3);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 3; j++) 
        {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    int res = shop(n, k, centers, roads);

    fout << res << "\n";

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

vector<string> split(const string &str) 
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) 
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
