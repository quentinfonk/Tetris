/*
** EPITECH PROJECT, 2020
** option
** File description:
** option
*/

#include "tetris.h"

char **start_map(options_t *option)
{
    int x = option->map_size.x;
    int y = option->map_size.y;
    char **map = malloc(sizeof(char *) * (y + 1));

    for (int i = 0; i != y; i++)
        map[i] = malloc(sizeof(char) * (x + 1));
    for (int i = 0; i != y; i++) {
        for (int o = 0; o != x; o++)
            map[i][o] = '.';
        map[i][x] = '\0';
    }
    map[y] = NULL;
    return (map);
}
