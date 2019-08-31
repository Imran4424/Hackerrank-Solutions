#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int *parent;
vector <bool> currentParent;

int roadsNeed;

void MakeSet(int vertex)
{
	parent[vertex] = vertex;
}

void InitDisjoint(int vertex)
{
	for (int i = 1; i <= vertex; ++i)
	{
		MakeSet(i);
	}
}

int SearchParent(int vertex)
{
	if (parent[vertex] == vertex)
	{
		return vertex;
	}

	return parent[vertex] = SearchParent(parent[vertex]);
}

void Union(int xVertex, int yVertex)
{
	int xParent = SearchParent(xVertex);
	int yParent = SearchParent(yVertex);

	if (xParent != yParent)
	{
		parent[yParent] = xParent;

		currentParent[yParent] = false;

		roadsNeed++;
	}
}

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) 
{
	parent = new int[n + 1];
	InitDisjoint(n);

	currentParent.resize(n+1, true);
	currentParent[0] = false;

	roadsNeed = 0;
	libraryNeed = 0;

	for (int i = 0; i < cities.size(); ++i)
	{
		Union(cities[i][0], cities[i][1]);
	}

	for (int i = 1; i < currentParent.size(); ++i)
	{
		if (currentParent[i])
		{
			libraryNeed++;
		}
	}

	int totalCost = (libraryNeed * c_lib) + (roadsNeed * c_road);
	int allLibraryCost = n * c_lib;

	if (allLibraryCost < totalCost)
	{
		return allLibraryCost;
	}

	return totalCost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
