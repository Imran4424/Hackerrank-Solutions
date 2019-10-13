#include <iostream>
using namespace std;

typedef long long int lli;

int main()
{
    lli siz;
    cin >> siz;

    lli ar[siz];

    for(lli i=0;i<siz;i++)
    {
        cin >> ar[i];
    }

    for(lli i=siz-1;i>0;i--)
    {
        cout << ar[i] << " ";
    }

    cout << ar[0] << endl;

    return 0;
}
