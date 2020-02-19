#include <iostream>
#include <stdio.h>
using namespace std;

const int tSize = 63;

/// string merge sort

/// compare String
int compareString(char *source, char *destination) {
    int i;
    for(i = 0; source[i]; i++) {
        if(source[i] != destination[i]) {
            return source[i] - destination[i];
        }
    }

    return source[i] - destination[i];
}

/// copy string
void copyString(char *dest, char *source) {
    int i;
    for(i = 0; source[i]; i++) {
        dest[i] = source[i];
    }

    dest[i] = '\0';
}

void merge(char arr[][12], char left[][12], int leftSize, char right[][12], int rightSize) {
    int i = 0, j = 0, index = 0;

    while(i < leftSize && j < rightSize) {
        if(compareString(left[i], right[j]) <= 0) {
            copyString(arr[index], left[i++]);
        } else {
            copyString(arr[index], right[j++]);
        }

        index++;
    }

    while(i < leftSize) {
        copyString(arr[index++], left[i++]);
    }

    while(j < rightSize) {
        copyString(arr[index++], right[j++]);
    }
}

void mergeSort(char (*arr)[12], int aSize) {
    if(aSize < 2) {
        return;
    }

    int mid = aSize / 2;
    char left[mid][12];
    char right[aSize - mid][12];

    int index = 0;

    for(int i = 0; i < mid; i++) {
        copyString(left[i], arr[index++]);
    }

    for(int i = 0; i < aSize - mid; i++) {
        copyString(right[i], arr[index++]);
    }

    mergeSort(left, mid);
    mergeSort(right, aSize - mid);

    merge(arr, left, mid, right, aSize - mid);
}


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
            letter = word[i] - 'a' + 26;
        } else {
            letter = word[i] - '0' + 52;
        }

        if(NULL == travel -> next[letter]) {
            travel -> next[letter] = new node();
        }

        travel = travel -> next[letter];
    }

    travel -> endMark = true;
    travel -> count = travel -> count + 1;
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
            letter = word[i] - 'a' + 26;
        } else {
            letter = word[i] - '0' + 52;
        }

        if(NULL == travel -> next[letter]) {
            return 0;
        }

        travel = travel -> next[letter];
    }

    return travel -> count;
}

void trieDeleteAll(node* travel) {

    for (int i = 0; i < tSize; ++i)
    {
        if(travel -> next[i]) {
            trieDeleteAll(travel -> next[i]);
        }
    }

    travel -> endMark = false;
    travel -> count = 0;
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
            letter = word[i] - 'a' + 26;
        } else {
            letter = word[i] - '0' + 52;
        }

        if(NULL == travel -> next[letter]) {
            return;
        }

        travel = travel -> next[letter];
    }

    /// deletion
    travel -> endMark = false;
    travel -> count = 0;
}

void trieDeleteSuffix(char *word) {
    node* travel = rootTrie;
    int length = stringLength(word);
    word = reverseString(word, length);

    for(int i = 0; word[i]; i++) {
        int letter;
        if(word[i] >= 'A' && word[i] <= 'Z') {
            letter = word[i] - 'A';
        } else if(word[i] >= 'a' && word[i] <= 'z') {
            letter = word[i] - 'a' + 26;
        } else {
            letter = word[i] - '0' + 52;
        }

        if(NULL == travel -> next[letter]) {
            return;
        }

        travel = travel -> next[letter];
    }

    trieDeleteAll(travel);
}

char arrTrie[100][12];
int indexTrie;

void triePrintAll(node* travel, char *word, int pos) {
    if(NULL == travel) {
        return;
    }

    if(travel -> endMark) {
        word[pos] = '\0';
        word = reverseString(word, pos);
        copyString(arrTrie[indexTrie++], word);
    }

    for (int i = 0; i < tSize; ++i)
    {
        if(travel -> next[i]) {
            if(i >= 0 && i <= 25) {
                word[pos] = i + 'A';
            } else if(i >= 26 && i <= 51) {
                word[pos] = (i + 'a' - 26);
            } else {
                word[pos] = i + '0' - 52;
            }


            triePrintAll(travel -> next[i], word, pos + 1);
        }
    }
}

void triePrintSuffix(char *word) {
    node* travel = rootTrie;
    int length = stringLength(word);
    word = reverseString(word, length);

    int i;
    for(i = 0; word[i]; i++) {
        int letter;
        if(word[i] >= 'A' && word[i] <= 'Z') {
            letter = word[i] - 'A';
        } else if(word[i] >= 'a' && word[i] <= 'z') {
            letter = word[i] - 'a' + 26;
        } else {
            letter = word[i] - '0' + 52;
        }

        if(NULL == travel -> next[letter]) {
            return;
        }

        travel = travel -> next[letter];
    }

    indexTrie = 0;
    triePrintAll(travel, word, i);
    mergeSort(arrTrie, indexTrie);
    for(int x = 0; x < indexTrie; x++) {
        printf("%s\n", arrTrie[x]);
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    rootTrie = new node();

    char word[12];
    int command;

    while(scanf("%d", &command) != EOF) {
        if(0 == command) {
            indexTrie = 0;
            triePrintAll(rootTrie, word, 0);
            mergeSort(arrTrie, indexTrie);
            for(int x = 0; x < indexTrie; x++) {
                printf("%s\n", arrTrie[x]);
            }
        } else if (1 == command) {
            scanf("%s", word);

            trieInsert(word);
        } else if (2 == command) {
            scanf("%s", word);
            printf("%d\n", trieSearch(word));
        } else if (3 == command) {
            scanf("%s", word);

            trieDelete(word);
        } else if(4 == command) {
            scanf("%s", word);

            triePrintSuffix(word);
        } else if(5 == command) {
            scanf("%s", word);

            trieDeleteSuffix(word);
        }
    }


    return 0;
}
