/*
** EPITECH PROJECT, 2020
** print
** File description:
** 2
*/

#include "tetris.h"

int check_node_x(node_t *node)
{
    int i = 0;
    int a = 0;

    while (node != NULL) {
        while (node != NULL && node->tetri.error == 84)
            node = node->next;
        if (node == NULL || node->tetri.tabb == NULL)
            return (a);
        for (; node->tetri.tabb[0][i] != '\0'; i++);
        if (i > a)
            a = i;
        node = node->next;
    }
    return (a);
}

int check_node_y(node_t *node)
{
    int i = 0;
    int a = 0;

    while (node != NULL) {
        while (node != NULL && node->tetri.error == 84)
            node = node->next;
        if (node == NULL || node->tetri.tabb == NULL)
            return (a);
        i = my_strcol(node->tetri.tabb);
        if (i > a)
            a = i;
        node = node->next;
    }
    return (a+1);
}

void pr_turn(options_t *option, int x, int y)
{
    char *str = "|";
    char *stack = "-";

    for (int i = y; i != 0; i--) {
        mvprintw(i+5, option->map_size.x+4, str);
        mvprintw(i+5, option->map_size.x+4+x+2, str);
    }
    for (int i = x+1; i != 0; i--) {
        mvprintw(5+1, option->map_size.x+4+i, stack);
        mvprintw(5+y, option->map_size.x+4+i, stack);
    }
    for (int i = 5; i != 0; i--) {
        mvprintw(0, option->map_size.x+1+i, stack);
        mvprintw(4, option->map_size.x+1+i, stack);
    }
    for (int i = 5; i != 0; i--) {
        mvprintw(i-1, option->map_size.x+1, str);
        mvprintw(i-1, option->map_size.x+4+3, str);
    }
}
