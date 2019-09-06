#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int lli;

// Complete the minimumPasses function below.
lli minimumPasses(lli machine, lli workers, lli price, lli n) 
{
    if (n <= price)
    {
        return ceil(n / (machine * workers));
    }

    lli phases = 0;

    lli countingCandies = 0;

    lli phasesAlter = 1844674407370955161;

    while(countingCandies < n)
    {
        
        if (countingCandies < price && (price - countingCandies) > (machine * workers))
        {
            lli candyOneIterate = (machine * workers);

            lli steps = ceil((price - countingCandies) / candyOneIterate);

            phases += steps;

            countingCandies += (steps * candyOneIterate);

            continue;
        }
    
        lli buyResource = countingCandies / price;

        countingCandies = (countingCandies - (buyResource * price));

        lli totalResource = machine + workers + buyResource;

        lli halfResource = totalResource / 2;

        if (machine > workers)
        {
            machine = max(machine, halfResource); // smaller or equal
            workers = totalResource - machine; // bigger or equal
        }
        else
        {
            workers = max(workers, halfResource); // smaller or equal
            machine = totalResource - workers; // bigger or equal
        }
        
        phases++;

        countingCandies += (machine * workers);

        lli candyOneIterate = (machine * workers);

        lli helper = ceil((n - countingCandies) / candyOneIterate );

        phasesAlter = min(phasesAlter, helper);
    }

    return phases;
}

int main()
{
    lli m, w, p, n;

    cin >> m >> w >> p >> n;

    lli result = minimumPasses(m, w, p, n);

    cout << result << "\n";


    return 0;
}


