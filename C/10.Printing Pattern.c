#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.

    for(int i= 1; i <= n*2-1; i++)
    {
        int seed = n-i+1, val = n; // seed for the middle point of the pattern, val is for each column
        bool done = false; // half column done or not

        if(seed < 1) // for printing the next half rows
        {
            seed = abs(seed-2);
        }

        for(int j=1; j <= n*2-1; j++)
        {
            if(val > seed && !done) // first half columns
            {
                printf("%d ", val);
                val--;
            }
            else if(val == seed && !done) // middle equal value columns
            {
                for(int k=1; k < seed*2; k++)
                {
                    printf("%d ", val);
                    j++;
                }

                j--;
                val++;
                done = true;
            }
            else  // last half columns
            {
                printf("%d ", val);
                val++;
            }
        }
        printf("\n");
    }    

    return 0;
}

