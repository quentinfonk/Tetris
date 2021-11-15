/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** my_isnum.c
*/

#include <stddef.h>
#include "tetris.h"

int my_isnum(char *av)
{
    int b = 0;
    if (av == NULL)
        return (84);
    if (av[0] == 0)
        return (84);
    for (; av[b] != '\0'; b++)
        if (av[b] < '0' || av[b] > '9')
            return (84);
    return (0);
}
