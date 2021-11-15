/*
** EPITECH PROJECT, 2020
** time
** File description:
** time
*/

#include "tetris.h"

void nb_lin(game_t *gam)
{
    static int a = 0;

    if (a != 0)
        gam->score += 10;
    a++;
}

char *time_set(char *str)
{
    str[0] = '0';
    str[1] = '0';
    str[2] = ':';
    str[3] = '0';
    str[4] = '0';
    str[5] = '\0';
    return (str);
}

char *time_str(char *str, int timer)
{
    str = time_set(str);
    for (; timer != 0; timer--) {
        if (str[1] == 10 + '0') {
            str[4] = '0';
            str[3] = '0';
            str[1] = '0';
            str[0] += 1;
        }
        if (str[3] == '6') {
            str[4] = '0';
            str[3] = '0';
            str[1] += 1;
        }
        if (str[4] == 9 + '0') {
            str[3] += 1;
            str[4] = '0';
        }
        str[4] += 1;
    }
    return (str);
}
