#include <stdio.h>
#include <stdlib.h>

struct hashNode {
    int key;
    int value;
    struct hashNode* next;
};

struct hashNode* createHashNode(int key, int value) {
    struct hashNode* node = (struct hashNode*)malloc(sizeof(struct hashNode));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

void insert(struct hashNode** hashTable, int key, int value) {
    int hashKey = abs(key) % 10000;
    struct hashNode* node = createHashNode(key, value);
    if (hashTable[hashKey] == NULL) {
        hashTable[hashKey] = node;
    } else {
        node->next = hashTable[hashKey];
        hashTable[hashKey] = node;
    }
}

// 哈希表操作：查找
struct hashNode* find(struct hashNode** hashTable, int key) {
    int hashKey = abs(key) % 10000;
    struct hashNode* node = hashTable[hashKey];
    while (node != NULL && node->key != key) {
        node = node->next;
    }
    return node;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct hashNode** hashTable = (struct hashNode**)calloc(10000, sizeof(struct hashNode*));
    for (int i = 0; i < numsSize; i++) {
        struct hashNode* node = find(hashTable, target - nums[i]);
        if (node != NULL) {
            int* result = (int*)malloc(sizeof(int) * 2);
            result[0] = node->value;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        insert(hashTable, nums[i], i);
    }
    *returnSize = 0;
    return NULL;    
}
