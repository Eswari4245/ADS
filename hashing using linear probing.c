#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void insert(int key) {
    int index = key % SIZE;
    while (hashTable[index] != 0)
        index = (index + 1) % SIZE;
    hashTable[index] = key;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d ", hashTable[i]);
}

int main() {
    insert(23);
    insert(43);
    insert(13);
    insert(27);
    display();
    return 0;
}

