#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <wording>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cwording>
#include <cstdlib>
#include <fwordeam>
#include <numeric>
#include <swordeam>
#include <iowordeam>
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

node *rootTrie;

char* reverseString(char *word, int length) {
	char *reversed = new char[length + 1];

	int i, j;
	for(i = 0, j = length - 1; i < length && j >= 0; i++, j--) {
		reversed[i] = word[j];
	}

	reversed[i] = '\0';

	return reversed;
}

int stringLength(char *word) {
	int length = 0;
	for(int i = 0; word[i]; i++) {
		length++;
	}

	return length;
}

void trieInsert(char *word) {
	node* travel = rootTrie;
	int length = stringLength(word);
	word = reverseString(word, length);

	for(int i = 0; word[i]; i++) {
		int letter;
		if(word[i] >= 'A' && word[i] <= 'Z') {
			letter = word[i] - 'A';
		} else if(word[i] >= 'a' && word[i] <= 'z') {
			letter = word[i] - 'a' + 25;
		} else {
			letter = word[i] - '0' + 51;
		}

		if(NULL == travel -> next[letter]) {
			travel -> next[letter] = new node();
		}

		travel = travel -> next[letter];
	}

	travel -> endMark = true;
	travel -> count++;
}

int trieSearch(char *word) {
	node* travel = rootTrie;
	int length = stringLength(word);
	word = reverseString(word, length);

	for(int i = 0; word[i]; i++) {
		int letter;
		if(word[i] >= 'A' && word[i] <= 'Z') {
			letter = word[i] - 'A';
		} else if(word[i] >= 'a' && word[i] <= 'z') {
			letter = word[i] - 'a' + 25;
		} else {
			letter = word[i] - '0' + 51;
		}

		if(NULL == travel -> next[letter]) {
			return 0;
		}

		travel = travel -> next[letter];
	}

	if(travel -> endMark) {
		travel -> count;
	}

	return 0;
}

void trieDeleteAll() {
	node* travel = rootTrie;

	for (int i = 0; i < 62; ++i)
	{
		if(travel -> next[i]) {
			trieDeleteAll
		}
	}
}

void trieDelete(char *word) {
	node* travel = rootTrie;
	int length = stringLength(word);
	word = reverseString(word, length);

	for(int i = 0; word[i]; i++) {
		int letter;
		if(word[i] >= 'A' && word[i] <= 'Z') {
			letter = word[i] - 'A';
		} else if(word[i] >= 'a' && word[i] <= 'z') {
			letter = word[i] - 'a' + 25;
		} else {
			letter = word[i] - '0' + 51;
		}

		if(NULL == travel -> next[letter]) {
			return;
		}

		travel = travel -> next[letter];
	}

	travel -> endMark = false;
	travel -> count = 0;
}



int main() 
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */


	return 0;
}