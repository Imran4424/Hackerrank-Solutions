#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int row, queries;

    cin >> row >> queries;

    vector <int> ar[row];

    for(int i = 0 ; i < row; i++)
    {
        int elements;
        cin >> elements;

        for(int j = 1; j <= elements; j++)
        {
            int input;

            cin >> input;

            ar[i].push_back(input);
        }
    }  

    for(int k = 0; k < queries; k++)
    {
        int r, c;

        cin >> r >> c;

        cout << ar[r][c] << endl;
    }  

    return 0;
}

