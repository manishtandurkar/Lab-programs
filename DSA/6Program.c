#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 10
#define PRIME 7

int hashTable[TABLE_SIZE];
int size = 0;

int hash1(int key) {
    return key % TABLE_SIZE;
}

int hash2(int key) {
    return PRIME - (key % PRIME);
}

void insert(int key) {
    if(size == TABLE_SIZE) {
        printf("Hash table is full\n");
        return;
    }
    int index = hash1(key);
    int stepSize = hash2(key);
    while(hashTable[index] != -1) 
        index = (index + stepSize) % TABLE_SIZE;
    hashTable[index] = key;
    size++;
}

int search(int key) {
    int index = hash1(key);
    int stepSize = hash2(key);
    int initialIndex = index;
    while(hashTable[index] != -1) {
        if(hashTable[index] == key)
            return index;
        index = (index + stepSize) % TABLE_SIZE;
        if(index == initialIndex)
            return -1;
    }
    return -1;
}

void delete(int key) {
    int index = search(key);
    if(index == -1) {
        printf("Key not found\n");
        return;
    }
    hashTable[index] = -1;
    size--;
}

void display() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        if(hashTable[i] != -1) 
            printf("Index %d: %d\n", i, hashTable[i]);
        else 
            printf("Index %d: \n", i);
    }
}

int main() {
    for(int i = 0; i < TABLE_SIZE; i++) hashTable[i] = -1;
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    insert(70);
    insert(80);
    insert(90);
    insert(100);
    display();
    printf("Searching for 30: %s\n", search(30) != -1 ? "Found" : "Not Found");
    printf("Searching for 110: %s\n", search(110) != -1 ? "Found" : "Not Found");
    printf("Deleting 30\n");
    delete(30);
    display();
    printf("Deleting 110\n");
    delete(110);
    display();
}