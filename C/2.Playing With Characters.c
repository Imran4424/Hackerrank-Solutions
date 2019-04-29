#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    char ch;
    char word[20];
    char line[50];

    scanf("%c", &ch);
    scanf("%s", word);
    getchar();
    scanf("%[^\n]%*c", line);

    printf("%c\n", ch);
    printf("%s\n", word);
    printf("%s\n", line);

    return 0;
}

