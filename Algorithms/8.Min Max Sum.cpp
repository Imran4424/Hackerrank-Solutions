#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

void MinMaxSum(vector<lli> arr)
{
	sort(arr.begin(), arr.end());

	lli minSum = 0, maxSum = 0;

	for (int i = 0; i < arr.size(); ++i)
	{
		
	}
}

int m;
ain(int argc, char const *argv[])
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