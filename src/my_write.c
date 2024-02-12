/*
** EPITECH PROJECT, 2024
** my_write
** File description:
** write functions for display
*/
#include "../include/hashtable.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

void print_place(node_t *place, int (*hash_func)(char *, int), int size) //print the current place 
{
    node_t *current = place;
    char numBuffer[100];
    int hash;

    while (current != NULL) {
        hash = hash_func(current->key, size);
        my_num(hash, numBuffer);
        my_putstr("\n> ");
        my_putstr(numBuffer);
        my_putstr(" - ");
        my_putstr(current->value);
        current = current->next;
    }
}
