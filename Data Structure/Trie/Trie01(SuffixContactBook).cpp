#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct node
{
	bool endMark;
	int count;
	node *next[62];

	node () {
		endMark = false;
		count = 0;
		for(int i = 0; i < 62; i++) {
			next[i] = NULL;
		}
	}
};

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}