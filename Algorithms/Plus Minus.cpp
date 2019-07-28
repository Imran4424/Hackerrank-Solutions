#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int size;
	cin >> size;

	int positiveCount = 0, negativeCount = 0, zeroCount = 0;

	int bucket;

	for (int i = 0; i < size; ++i)
	{
		cin >> bucket;

		if (bucket > 0)
		{
			positiveCount++;
		}
		else if(bucket < 0)
		{
			negativeCount++;
		}
		else
		{
			zeroCount++;
		}
	}

	cout << fixed << setprecision(6) << (double)positiveCount/size << endl;
	cout << fixed << setprecision(6) << (double)positiveCount/size << endl;
	cout << fixed << setprecision(6) << (double)positiveCount/size << endl;

	return 0;
}