/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <time.h>
#include "tetris.h"

static void game(char **map, node_t *node, options_t *option, game_t *gam)
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    while (1) {
        map = check_line(map, gam);
        pr_map(map, gam, node, option);
        if (check(map) == 1)
            new(map, node, gam);
        if (gam->error != 0)
            break;
        if (check_ch(map, option, gam) == 1)
            break;
    }
}

int gamme(node_t *node, options_t *option)
{
    char **map = start_map(option);
    game_t gam = {0, 0, 0, 0, 0, 0, 0};

    if (map == NULL || are_tetris_valid(node) == 84)
        exit (84);
    srand(time(NULL));
    game(map, node, option, &gam);
    endwin();
    write(1, "Your score is : ", 16);
    my_put_nbr(gam.score);
    write(1, "\n", 1);
    for (int a = 0; map[a] != NULL; a++)
        free(map[a]);
    free(map);
    if (gam.error == 84)
        return (84);
    return (0);
}
