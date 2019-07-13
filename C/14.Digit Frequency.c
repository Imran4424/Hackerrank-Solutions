#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int digit[10] = {0};

    char str[1001];

    scanf("%[^\n]%*c", str);

    for(int i=0; i<strlen(str); i++)
    {
        if(str[i]>= '0' && str[i] <= '9')
        {
            int index = (int) str[i] - 48;

            digit[index]++;
        }
    }

    for(int i=0; i<10; i++)
    {
        printf("%d ", digit[i]);
    }

    return 0;
}
