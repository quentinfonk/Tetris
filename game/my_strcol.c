/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** my_strcol.c
*/

#include <stddef.h>

int my_strcol(char **str)
{
    int i = 0;

    for (; str[i] != NULL; i++);
    return (i);
}
