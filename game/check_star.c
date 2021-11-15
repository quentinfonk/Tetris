/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** check_star.c
*/

#include "tetris.h"

void check_star(char **map, int i, int o, game_t *gam)
{
    if (map[i][o] == '*') {
//        if (i == 0)
//            gam->error = 84;
        map[i][o] = gam->color + 48;
    }
}
