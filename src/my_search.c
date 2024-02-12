/*
** EPITECH PROJECT, 2024
** my_search
** File description:
** ht_search function
*/

#include "../include/hashtable.h"

char *ht_search(hashtable_t *ht, char *key) //takes a key as a parameter, then hashes it to access the index. If the value matches the hash, then the value is returned.
{
    int index;
    node_t *current;

    if (ht == NULL || key == NULL){
        return NULL;
    }
    index = ht->hash(key, ht->size) % ht->size;
    current = ht->place[index];
    while (current != NULL) {
        if (my_strcmp(current->key, key) == 0){
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}
