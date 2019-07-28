#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int lli;

void MinMaxSum(vector<lli> arr)
{
	sort(arr.begin(), arr.end());

	lli minSum = 0, maxSum = 0;

	for (int i = 0; i < 4; ++i)
	{
		minSum += arr[i];
	}
	
	for (int i = 0; i < 4; ++i)
	{
		maxSum += arr[i];
	}

	cout << minSum << " " << maxSum << endl;
}

int main(int argc, char const *argv[])
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