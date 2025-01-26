#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

void initialize() {
    for(int i = 0; i < TABLE_SIZE; i++) 
        hashTable[i] = EMPTY;
}

int hash1(int key) {
    return key % TABLE_SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);
}

void insert(int key) {
    int index = hash1(key);
    int stepSize = hash2(key);
    int initialIndex = index;
    while(hashTable[index] != EMPTY) {
        index = (index + stepSize) % TABLE_SIZE;
        if(index == initialIndex) {
            printf("Hash table is full, cannot insert key %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
}

int search(int key) {
    int index = hash1(key);
    int stepSize = hash2(key);
    while(hashTable[index] != EMPTY) {
        if(hashTable[index] == key) 
            return index;
        index = (index + stepSize) % TABLE_SIZE;
    }
    return -1;
}

void delete(int key) {
    int index = search(key);
    if(index != -1) 
        hashTable[index] = EMPTY;
    else 
        printf("Key not found\n");
}

void display() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        if(hashTable[i] != EMPTY) 
            printf("Index %d: %d\n", i, hashTable[i]);
        else 
            printf("Index %d: EMPTY\n", i);
    }
}

int main() {
    int choice, key;
    initialize();
    while(1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int index = search(key);
                if(index != -1) 
                    printf("Key %d found at index %d\n", key, index);
                else 
                    printf("Key %d not found\n", key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}