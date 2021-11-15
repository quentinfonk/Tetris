/*
** EPITECH PROJECT, 2019
** int
** File description:
** str
*/

#include "tetris.h"

char *int_str(int a)
{
    char *str = malloc(sizeof(char) * (a + 2));
    int i = 0;
    char *src = "0";

    if (a == 0)
        return (src);
    for (; a != 0; i++) {
        str[i] = a % 10 + 48;
        a = a / 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}
