/*
** EPITECH PROJECT, 2024
** my_table
** File description:
** create and destroy hashtable
*/

#include "../include/hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int size) //create new hashtable
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    if (ht == NULL || size <= 0){
        return NULL;
    }
    ht->place = malloc(sizeof(node_t *) * size);
    if (ht->place == NULL){
        free(ht);
        return NULL;
    }
    for (int i = 0; i < size; i++){
        ht->place[i] = NULL;
    }
    ht->size = size;
    ht->hash = hash;
    return ht;
}

int remove_node(hashtable_t *ht, node_t *prev, node_t *current, int index) // remove node from hastbale
{
    if (prev == NULL){
        ht->place[index] = current->next;
    } else {
        prev->next = current->next;
    }
    free(current->key);
    free(current->value);
    free(current);
    return 0;
}

int ht_delete(hashtable_t *ht, char *key) //delete a value from the table.
{
    int index;
    node_t *current;
    node_t *prev;

    if (ht == NULL || key == NULL) {
        return 84;
    }
    index = ht->hash(key, ht->size) % ht->size;
    current = ht->place[index];
    prev = NULL;
    while (current != NULL){
        if (my_strcmp(current->key, key) == 0){
            return remove_node(ht, prev, current, index);
        }
        prev = current;
        current = current->next;
    }
    return 0;
}

void delete_hashtable(hashtable_t *ht) //delete the hashtable
{
    node_t *current;
    node_t *temp;

    if (ht == NULL) {
        return;
    }
    for (int i = 0; i < ht->size; i++) {
        current = ht->place[i];
        while (current != NULL) {
            temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->place);
    free(ht);
}
