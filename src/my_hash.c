/*
** EPITECH PROJECT, 2024
** my_hash
** File description:
** hash function for secured
*/

#include "../include/hashtable.h"

int hash(char *key, int len)
{
    int hash = 4007;
    int a = *key;
    int i = 250;

    (void)len;
    while (a){
        hash = ((hash << 5) + hash) * (a * i);
        key++;
        a = *key;
        i++;
    }
    hash = hash > 0 ? hash : hash * -1;
    return hash;
}

void ht_dump(hashtable_t *ht) //displays the state of the hash table
{
    char *numBuffer = malloc(100);

    if (ht == NULL){
        my_putstr("Hash table is NULL\n");
        return;
    }
    for (int i = 0; i < ht->size; i++){
        my_putstr("[");
        my_num(i, numBuffer);
        my_putstr(numBuffer);
        my_putstr("]:");
        print_place(ht->place[i], ht->hash, ht->size);
        my_putstr("\n");
    }
    free(numBuffer);
}
