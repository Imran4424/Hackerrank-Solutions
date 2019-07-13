#include <cstdio>
#include <bits/stdc++.h>

void update(int *a,int *b) 
{
    // Complete this function

    int ta = *a, tb = *b;

    *a = ta + tb;
    *b = abs(ta - tb);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    
    update(pa, pb);
    
    printf("%d\n%d", a, b);

    return 0;
}

