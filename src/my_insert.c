/*
** EPITECH PROJECT, 2024
** my_insert
** File description:
** insert function for secured
*/

#include "../include/hashtable.h"

node_t *create_node(char *key, char *value) //create a node for the hashtable
{
    node_t *new_node = malloc(sizeof(node_t));

    if (new_node == NULL)
        return NULL;
    new_node->key = my_strdup(key);
    if (new_node->key == NULL) {
        free(new_node);
        return NULL;
    }
    new_node->value = my_strdup(value);
    if (new_node->value == NULL) {
        free(new_node->key);
        free(new_node);
        return NULL;
    }
    return new_node;
}

int ht_insert(hashtable_t *ht, char *key, char *value) // insert a new element into the hash table
{
    int index;
    node_t *new_node;

    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    index = ht->hash(key, ht->size) % ht->size;
    new_node = create_node(key, value);
    if (new_node == NULL)
        return 84;
    new_node->next = ht->place[index];
    ht->place[index] = new_node;
    return 0;
}
