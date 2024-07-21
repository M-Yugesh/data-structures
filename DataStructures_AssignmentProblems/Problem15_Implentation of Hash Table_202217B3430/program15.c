#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node
struct node {
    char* key; // key is string
    char* value; // value is also string
    struct node* next;
};

// Function to set node key and value
void setNode(struct node* node, const char* key, const char* value) {
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;
}

// HashMap structure
struct hashMap {
    int numOfElements, capacity;
    struct node** arr;
};

// Function to initialize HashMap
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100;
    mp->numOfElements = 0;
    mp->arr = (struct node*)calloc(mp->capacity, sizeof(struct node));
}

// Simple hash function for string keys
int hashFunction(struct hashMap* mp, const char* key) {
    int hash = 0;
    int prime = 31;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * prime + key[i]) % mp->capacity;
    }
    return hash;
}

// Function to insert key-value pair into HashMap
void insert(struct hashMap* mp, const char* key, const char* value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, key, value);

    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    } else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
    mp->numOfElements++;
}

// Function to delete a key from HashMap
void delete(struct hashMap* mp, const char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];

    while (currNode != NULL) {
        if (strcmp(currNode->key, key) == 0) {
            if (prevNode == NULL) {
                mp->arr[bucketIndex] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            mp->numOfElements--;
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Function to search for a value by key in HashMap
char* search(struct hashMap* mp, const char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* bucketHead = mp->arr[bucketIndex];

    while (bucketHead != NULL) {
        if (strcmp(bucketHead->key, key) == 0) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }
    return "Oops! No data found.\n";
}

// Driver function to test the HashMap
int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);

    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");

    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));
    printf("%s\n", search(mp, "randomKey"));

    printf("\nAfter deletion:\n");
    delete(mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy"));
}
