#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<string> split_string(string);

lli *parent;

lli libraryNeed;
lli roadsNeed;

void MakeSet(lli vertex)
{
	parent[vertex] = vertex;
}

void InitDisjolli(lli vertex)
{
	for (lli i = 1; i <= vertex; ++i)
	{
		MakeSet(i);
	}
}

lli SearchParent(lli vertex)
{
	if (parent[vertex] == vertex)
	{
		return vertex;
	}

	return parent[vertex] = SearchParent(parent[vertex]);
}

void Union(lli xVertex, lli yVertex)
{
	lli xParent = SearchParent(xVertex);
	lli yParent = SearchParent(yVertex);

	if (xParent != yParent)
	{
		parent[yParent] = xParent;

		libraryNeed--;

		roadsNeed++;
	}
}

// Complete the roadsAndLibraries function below.
lli roadsAndLibraries(lli n, lli c_lib, lli c_road, vector<vector<lli>> cities) 
{
	parent = new lli[n + 1];
	InitDisjolli(n);

    libraryNeed = n;
	roadsNeed = 0;

	for (lli i = 0; i < cities.size(); ++i)
	{
		Union(cities[i][0], cities[i][1]);
	}


	lli totalCost = (libraryNeed * c_lib) + (roadsNeed * c_road);
	lli allLibraryCost = n * c_lib;

	if (allLibraryCost < totalCost)
	{
		return allLibraryCost;
	}

	return totalCost;
}

int main()
{

    ofstream fout(getenv("OUTPUT_PATH"));

    lli q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (lli q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        lli n = stoi(nmC_libC_road[0]);

        lli m = stoi(nmC_libC_road[1]);

        lli c_lib = stoi(nmC_libC_road[2]);

        lli c_road = stoi(nmC_libC_road[3]);

        vector<vector<lli>> cities(m);
        for (lli i = 0; i < m; i++) {
            cities[i].resize(2);

            for (lli j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        lli result = roadsAndLibraries(n, c_lib, c_road, cities);

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
