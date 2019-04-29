#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.

    for(int i=a; i<=b; i++)
    {
        if (1 == i) 
        {
            printf("one\n");
        } 
        else if (2 == i) 
        {
            printf("two\n");
        } 
        else if (3 == i) 
        {
            printf("three\n");
        } 
        else if (4 == i) 
        {
            printf("four\n");
        } 
        else if (5 == i) 
        {
            printf("five\n");
        } 
        else if (6 == i) 
        {
            printf("six\n");
        } 
        else if (7 == i) 
        {
            printf("seven\n");
        } 
        else if (8 == i) 
        {
            printf("eight\n");
        } 
        else if (9 == i) 
        {
            printf("nine\n");
        } 
        else 
        {
            if(i % 2 == 0)
            {
                printf("even\n");
            }
            else
            {
                printf("odd\n");
            }
        }
    }

    return 0;
}

