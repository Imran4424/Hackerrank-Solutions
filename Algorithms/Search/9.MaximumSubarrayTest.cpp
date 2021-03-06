#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;


// Complete the maximumSum function below.
lli maximumSum(vector<lli> a, lli m) 
{
    vector <lli> prefixSum;

    prefixSum.push_back(a[0] % m);

    lli totalPrefix = 0;

    //cout << prefixSum[0] << " ";

    for (lli i = 1; i < a.size(); ++i)
    {
        prefixSum.push_back((prefixSum[i-1] + a[i]) % m);

        //cout << prefixSum[i] << " ";

        totalPrefix += prefixSum[i];
    }

    lli totalMod = totalPrefix % m;

    //cout << endl;

    //cout << totalPrefix << endl;

    sort(prefixSum.begin(), prefixSum.end());

    lli sortedMaxMod = prefixSum[prefixSum.size() - 1];

    lli maxMod = 0;

    for (lli i = 0; i < prefixSum.size(); ++i)
    {
        if ((m - prefixSum[i]) % m > maxMod)
        {
            maxMod = (m - prefixSum[i]) % m;
        }
    }
    
    return max(maxMod, max(sortedMaxMod, totalMod));
}

int main()
{
    lli test;
    cin >> test;

    while(test--)
    {
        lli num, modulo;
        cin >> num >> modulo;

        vector <lli> a;

        lli temp;

        for (int i = 0; i < num; ++i)
        {
            cin >> temp;

            a.push_back(temp);
        }

        cout << maximumSum(a, modulo) << endl;
    }
    

    return 0;
}

