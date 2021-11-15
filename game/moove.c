/*
** EPITECH PROJECT, 2020
** moove
** File description:
** moove
*/

#include "tetris.h"

char **right_map(char **map)
{
    int a = my_strlen(map[0]) - 1;
    int x = my_strcol(map) - 1;

    for (int v = 0; map[v] != NULL; v++)
        for (a = 0; map[v][a] != '\0'; a++)
            if (map[v][a] == '*' && map[v][a+1] != '.' && map[v][a+1] != '*')
                return (map);
    for (int c = x; c != -1; c--)
        if (map[c][a] == '*')
            return (map);
    for (; x != -1; x--)
        for (int o = a; o != -1; o--)
            if (map[x][o] == '*' && map[x][o+1] != '\0' &&
                map[x][o+1] == '.') {
                map[x][o+1] = '*';
                map[x][o] = '.';
            }
    return (map);
}

char **left_map(char **map)
{
    int a = 0;
    int x = 0;

    for (; map[x] != NULL; x++)
        if (map[x][a] == '*')
            return (map);
    for (x = 0; map[x] != NULL; x++)
        for (a = 0; map[x][a] != '\0'; a++)
            if (map[x][a] == '*' && map[x][a-1] != '.' && map[x][a-1] != '*')
                return (map);
    for (x = 0; map[x] != NULL; x++)
        for (a = 0; map[x][a] != '\0'; a++)
            if (map[x][a] == '*' && map[x][a-1] != '\0') {
                map[x][a-1] = '*';
                map[x][a] = '.';
            }
    return (map);
}

char **fall(char **map)
{
    int i = 0;

    for (; map[i] != NULL; i++);
    i--;
    for (; i != -1; i--)
        for (int o = 0; map[i][o] != '\0'; o++) {
            if (map[i][o] != '.' && map[i][o] != '*' && map[i-1][o] == '*')
                return (map);
            if (map[i][o] == '*') {
                map[i][o] = '.';
                map[i+1][o] = 'o';
            }
        }
    for (int i = 0; map[i] != NULL; i++)
        for (int o = 0; map[i][o] != '\0'; o++)
            if (map[i][o] == 'o')
                map[i][o] = '*';
    return (map);
}
