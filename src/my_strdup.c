/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_strdup.c
*/

#include "tetris.h"

char *my_strdup(char *arg)
{
    char *str;
    int i = 0;
    int size = my_strlen(arg);

    str = malloc(sizeof(char) * (size + 1));
    while (i < size) {
        str[i] = arg[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
