#include <iostream>
#include <string>

using namespace std;

int main() 
{
	// Complete the program

    string first, second;

    cin >> first >> second;

    cout << first.size() << " " << second.size() << endl;
    
    cout << first + second << endl;

    swap(first[0],second[0]);

    cout << first << " " << second << endl;
   
    return 0;
}

