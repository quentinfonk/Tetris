/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** my_put_nbr.c
*/

#include "tetris.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int puissance(int nb)
{
    int t = 1;

    while (nb > 9) {
        nb = nb / 10;
        t = t * 10;
    }
    return (t);
}

int my_put_nbr(int nb)
{
    int a = 0;

    if (nb < 0) {
        write(1, "-", 1);
        my_put_nbr(nb * -1);
        return (0);
    }
    a = puissance(nb);
    while (a >= 1) {
        my_putchar(((nb / a) % 10) + '0');
        a = a / 10;
    }
    return (0);
}
