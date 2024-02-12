/*
** EPITECH PROJECT, 2024
** my_str
** File description:
** str and write functions
*/

#include "../include/hashtable.h"

void int_to_string(int num, char *str, int *length)
{
    int index = 0;
    int rem;

    while (num != 0) {
        rem = num % 10;
        str[index] = rem + '0';
        index++;
        num /= 10;
    }
    *length = index;
}

void reverse_string(char *str, int length)
{
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void my_num(int num, char *str)
{
    int length;
    int isNegative = 0;

    if (num == 0){
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    if (num < 0){
        isNegative = 1;
        num = -num;
    }
    int_to_string(num, str, &length);
    reverse_string(str, length);
    if (isNegative){
        str[length] = '-';
        length++;
    }
    str[length] = '\0';
}
