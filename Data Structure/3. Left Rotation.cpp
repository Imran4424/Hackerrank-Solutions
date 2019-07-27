#include <iostream>
#include <vector>
using namespace std;

vector<int> LeftRotation(vector<int> arr)
{
	int hold = arr.front();

	arr.erase(arr.begin());

	arr.push_back(hold);

	return arr;
}

vector<int> RotationsHandler(vector<int> arr, int rotations)
{
	for (int i = 0; i < rotations; ++i)
	{
		arr = LeftRotation(arr);
	}

	return arr;
}

int main(int argc, char const *argv[])
{
	int size, rotations;

	cin >> size >> rotations;

	vector<int> arr;

	for (int i = 0; i < size; ++i)
	{
		int hand;
		cin >> hand;
		
		arr.push_back(hand);
	}

	arr = RotationsHandler(arr, rotations);

	for (int i = 0; i < arr.size(); ++i)
	{
		if (i == arr.size()-1)
		{
			cout << arr[i] << endl;
		}

		cout << arr[i] << " ";
	}

	return 0;
}