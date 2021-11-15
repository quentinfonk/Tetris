/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** print.c
*/

#include "tetris.h"

void norme(char c, game_t *gam)
{
    if (c == '*')
        check_a('a', gam->color);
    else if (c != '.')
        check_a(c, 0);
}

void next(game_t *gam, node_t *node, char *str, options_t *option)
{
    void *first = node;

    for (int a = 0;  a != gam->next; a++)
        node = node->next;
    while (node != NULL && node->tetri.error == 84)
        node = node->next;
    if (node == NULL)
        node = first;
    for (int i = 0; node->tetri.tabb[i] != NULL; i++) {
        for (int o = 0; node->tetri.tabb[i][o] != '\0'; o++) {
            str[0] = node->tetri.tabb[i][o];
            str[1] = '\0';
            if (str[0] == '*')
                check_a('a', node->tetri.color);
            mvprintw(i+7, option->map_size.x+5+o, str);
            attroff(COLOR_PAIR(1));
        }
    }
}

void print_map(char **map, game_t *gam)
{
    char str[2];

    for (int i = 0; map[i] != NULL; i++) {
        for (int o = 0; map[i][o]; o++) {
            str[0] = map[i][o];
            str[1] = '\0';
            norme(str[0], gam);
            printw(str);
            attroff(COLOR_PAIR(1));
        }
        printw("\n");
    }
}

void pr_map(char **map, game_t *gam, node_t *node, options_t *option)
{
    char str[2];

    start_color();
    clear();
    if (LINES < option->map_size.y || COLS < option->map_size.x) {
        printw("too small window ! make if bigger");
        return;
    }
    print_map(map, gam);
    pr_score(gam, option, node);
    if (option->next == 0)
        next(gam, node, str, option);
    refresh();
    usleep(50000);
}

void pr_score(game_t *gam, options_t *option, node_t *node)
{
    static int x = 0;
    static int y = 0;
    char *str = malloc(sizeof(char) * 6);
    char *stack = NULL;

    if (x == 0 && y == 0) {
        x = check_node_x(node);
        y = check_node_y(node)+1;
    }
    pr_turn(option, x, y);
    stack = int_str(gam->score);
    mvprintw(1, option->map_size.x + 6 - (my_strlen(stack)), stack);
    stack = int_str(gam->nb_line);
    mvprintw(2, option->map_size.x + 6 - (my_strlen(stack)),
    int_str(gam->nb_line));
    str = time_str(str, gam->timer);
    mvprintw(3, option->map_size.x+2, str);
}
