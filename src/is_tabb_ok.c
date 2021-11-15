/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** is_tabb_ok.c
*/

#include "tetris.h"

int my_strlen_tetri(char *str)
{
    int oui = my_strlen(str) - 1;

    while (str[oui] == ' ')
        oui--;
    return (oui + 1);
}

int is_tabb_ok(char *str, tetri_t *tetri)
{
    int b = my_strlen_tetri(str);

    if (b > tetri->width)
        return (84);
    for (int a = 0; str[a] != '\0'; a++)
        if (str[a] != ' ' && str[a] != '*')
            return (84);
    return (0);
}
