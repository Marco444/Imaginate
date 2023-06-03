#include "hashmap.h"

unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % SIZE;
}

void initHashMap(HashMap hashmap) {
    for (int i = 0; i < SIZE; i++) {
        hashmap[i] = NULL;
    }
}

int put(HashMap hashmap, const char *id, Value value) {
    unsigned long index = hash(id);
    HashNode *node = malloc(sizeof(HashNode));
    if (!node)
        return 0; // memory allocation failed
    node->id = strdup(id);
    if (!node->id) {
        free(node);
        return 0; // memory allocation failed
    }
    node->value = malloc(sizeof(Value));
    if (!node->value) {
        free(node->id);
        free(node);
        return 0; // memory allocation failed
    }
    memcpy(node->value, &value, sizeof(Value));
    node->next = hashmap[index];
    hashmap[index] = node;
    return 1; // operation succeeded
}

Value* getOrDefault(HashMap hashmap, const char *id, Value * defaultValue) {
    unsigned long index = hash(id);
    for (HashNode *node = hashmap[index]; node != NULL; node = node->next) {
        if (strcmp(node->id, id) == 0) {
            return node->value;
        }
    }
    return defaultValue;
}

int exists(HashMap hashmap, const char *id) {
    unsigned long index = hash(id);
    for (HashNode *node = hashmap[index]; node != NULL; node = node->next) {
        if (strcmp(node->id, id) == 0) {
            return 1;
        }
    }
    return 0;
}

void destroy(HashMap hashmap) {
    for (int i = 0; i < SIZE; i++) {
        HashNode *node = hashmap[i];
        while (node != NULL) {
            HashNode *temp = node;
            node = node->next;
            free(temp->id);
            free(temp->value);
            free(temp);
        }
        hashmap[i] = NULL;
    }
}

