/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef HASHTABLE_H
    #define HASHTABLE_H

typedef struct node_s {
    char *key;
    char *value;
    struct node_s *next;
} node_t;

typedef struct hashtable_s {
    node_t **place;
    int size;
    int (*hash)(char *, int);
} hashtable_t;


int hash(char *key, int len);
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
void my_putchar(char c);
void my_putstr(char const *str);
void reverse_string(char *str, int length);
void int_to_string(int num, char *str, int *length);
void my_num(int num, char *str);
void print_place(node_t *place, int (*hash_func)(char *, int), int size);
int my_strlen(char const *str);
char *my_strdup(char *str);
int my_strcmp(char const *s1, char const *s2);
node_t *create_node(char *key, char *value);
int remove_node(hashtable_t *ht, node_t *prev, node_t *current, int index);

#endif /* HASHTABLE_H */
