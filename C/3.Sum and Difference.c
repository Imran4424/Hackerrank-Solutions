#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int a,b;
    double m,n;

    scanf("%d %d", &a, &b);
    scanf("%lf %lf", &m, &n);

    printf("%d %d\n", a+b, a-b);
    printf("%.1lf %.1lf\n", m+n, m-n);

    return 0;
}

