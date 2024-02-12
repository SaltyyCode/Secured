/*
** EPITECH PROJECT, 2024
** my_str
** File description:
** str functions for secured
*/

#include "../include/hashtable.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

char *my_strdup(char *str)
{
    int len;
    char *dup;

    len = my_strlen(str) + 1;
    dup = malloc(len);
    if (dup == NULL)
        return NULL;
    for (int i = 0; i < len; i++){
        dup[i] = str[i];
    }
    return dup;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == '\0' || s2[i] == '\0')
            return (0);
        i++;
    }
    return (s1[i] - s2[i]);
}
