#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main() 
{
    // Complete the code.

    int a;
    long b;
    char c;
    float d;
    double e;

    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);   

    // cin >> a >> b >> c >> d;

    cout << a << endl; 
    cout << b << endl;
    cout << c << endl;

    cout << fixed << setprecision(3) << d << endl;
    cout << fixed << setprecision(9) << e << endl;

    // printf("%d\n", a);
    // printf("%ld\n", b);
    // printf("%c\n", c);
    // printf("%.3f\n", d);
    // printf("%.9lf\n", e);


    return 0;
}

