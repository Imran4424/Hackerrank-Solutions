#include <iostream>
#include <stdio.h>
using namespace std;

const int tSize = 65;

struct node
{
    bool endMark;
    int count;
    node *next[tSize];

    node () {
        endMark = false;
        count = 0;
        for(int i = 0; i < tSize; i++) {
            next[i] = NULL;
        }
    }
};

node *rootTrie;

void reverseString(char *word, int length) {
    int availSize = length - 1;
    
    for(int i = 0; i < length / 2; i++) {

        // using a third variable to swap two variables
        char temp = word[i];
            word[i] = word[availSize - i];
            word[availSize - i] = temp;
    }
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
    reverseString(word, length);

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
    reverseString(word, length);

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

void trieDeleteAll(node* travel) {
    
    for (int i = 0; i < tSize; ++i)
    {
        if(travel -> next[i]) {
            trieDeleteAll(travel -> next[i]);
        }
    }

    delete(travel);
}

void trieDelete(char *word) {
    node* travel = rootTrie;
    int length = stringLength(word);
    reverseString(word, length);

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

void trieDeleteSuffix(char *word) {
    node* travel = rootTrie;
    int length = stringLength(word);
    reverseString(word, length);

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

    trieDeleteAll(travel);
}

void triePrintAll(node* travel, char *word, int pos) {
    if(NULL == travel) {
        return;
    }

    if(travel -> endMark) {
        word[pos] = '\0';
        reverseString(word, pos);

        for(int i = 0; i < travel -> count; i++) {
            printf("%s\n", word);
        }
    }

    for (int i = 0; i < tSize; ++i)
    {
        if(travel -> next[i]) {
            if(i >= 0 && i <= 25) {
                word[pos] = i + 'A';
            } else if(i >= 26 && i <= 51) {
                word[pos] = (i + 'a' - 25);
            } else {
                word[pos] = i + '0' - 51;
            }

            
            triePrintAll(travel -> next[i], word, pos + 1);
        }
    }
}

void triePrintSuffix(char *word) {
    node* travel = rootTrie;
    int length = stringLength(word);
    reverseString(word, length);

    int i;
    for(i = 0; word[i]; i++) {
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

    triePrintAll(travel, word, i);
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    rootTrie = new node();

    char *word = new char[12];
    int command;

    while(cin >> command) {
        if(0 == command) {
            triePrintAll(rootTrie, word, 0);
        } else if (1 == command) {
            cin >> word;

            trieInsert(word);
        } else if (2 == command) {
            cin >> word;
            printf("%d\n", trieSearch(word));
        } else if (3 == command) {
            cin >> word;

            trieDelete(word);
        } else if(4 == command) {
            cin >> word;

            triePrintSuffix(word);
        } else if(5 == command) {
            cin >> word;

            trieDeleteSuffix(word);
        }
    }


    return 0;
}