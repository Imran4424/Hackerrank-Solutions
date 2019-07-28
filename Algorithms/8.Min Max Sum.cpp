#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

void MinMaxSum(vector<lli> 
{
	sort(arr.begin(), arr.end());
}

int m;ain(int argc, char const *argv[])
{
	vector<lli> arr;

	lli pot;

	for (int i = 0; i < 5; ++i)
	{
		cin >> pot;

		arr.push_back(pot);
	}

	MinMaxSum(arr);

	return 0;
}