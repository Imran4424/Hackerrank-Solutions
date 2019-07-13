#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    int n;
    cin >> n;

    vector<int> ar(n);

    for(int i=0; i<ar.size(); i++)
    {
        cin >> ar[i];
    }

    for(int i=ar.size()-1; i>=0; i--)
    {
        cout << ar[i] << " ";
    }
    return 0;
}
