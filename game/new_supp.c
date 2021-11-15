/*
** EPITECH PROJECT, 2020
** new
** File description:
** supp
*/

#include "tetris.h"

int get_rand(node_t *node)
{
    void *first = node;
    int count = 0;

    while (node != NULL) {
        node = node->next;
        count++;
    }
    node = first;
    return (count);
}

void put_new_tetri_on_map(char **map, node_t *node)
{
    for (int i = 0; node->tetri.tabb[i] != NULL; i++)
        for (int o = 0; node->tetri.tabb[i][o] != '\0'; o++)
            if (node->tetri.tabb[i][o] != ' ')
                map[i][o] = node->tetri.tabb[i][o];
}

void new(char **map, node_t *node, game_t *gam)
{
    void *first = node;
    int random = get_rand(node);

    nb_lin(gam);
    gam->tetri_nb = gam->next;
    for (int i = 0; map[i] != NULL; i++)
        for (int o = 0; map[i][o] != '\0'; o++)
            check_star(map, i, o, gam);
    if (gam->error == 84)
        return;
    for (int a = gam->next; a != 0; a--)
        node = node->next;
    while (node != NULL && node->tetri.error == 84)
        node = node->next;
    if (node == NULL)
        node = first;
    put_new_tetri_on_map(map, node);
    gam->color = node->tetri.color;
    gam->next = rand()% random;
    node = first;
}

char **supp_line(char **map, int i)
{
    i--;
    for (; i != -1; i--)
        for (int o = 0; map[i][o] != '\0'; o++)
            map[i+1][o] = map[i][o];
    for (int o = 0; map[0][o] != '\0'; o++)
        map[0][o] = '.';
    return (map);
}

char **check_line(char **map, game_t *gam)
{
    gam->error = 0;
    for (int i = 0, a = 0; map[i] != NULL; i++, a = 0) {
        for (int o = 0; map[i][o] != '\0'; o++)
            if (map[i][o] == '.' || map[i][o] == '*')
                a++;
        if (a == 0) {
            supp_line(map, i);
            gam->score += 100;
            gam->nb_line += 1;
            usleep(100000);
        }
    }
    return (map);
}
