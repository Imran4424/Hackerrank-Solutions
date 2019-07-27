#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int size, rotations;

	cin >> size >> rotations;

	vector<int> arr;

	for (int i = 0; i < size; ++i)
	{
		int hand;
		arr.push_back(cin >> hand);
	}

	return 0;
}