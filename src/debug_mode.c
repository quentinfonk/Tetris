/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** debug_mode.c
*/

#include "tetris.h"

void key(char *key)
{
    for (int a = 0; key[a] != '\0'; a++) {
        if (key[a] == 27) {
            write(1, "^EO", 3);
            write(1, &key[my_strlen(key) - 1], 1);
            return;
        } else if (key[a] == ' ') {
            write(1, "(space)", 7);
            return;
        } else {
            write(1, key, my_strlen(key));
            return;
        }
    }
}

void print_keys(options_t *option)
{
    write(1, "Key Left :  ", 12);
    key(option->keyleft);
    write(1, "\n", 1);
    write(1, "Key Right :  ", 13);
    key(option->keyright);
    write(1, "\n", 1);
    write(1, "Key Turn :  ", 12);
    key(option->keyturn);
    write(1, "\n", 1);
    write(1, "Key Drop :  ", 12);
    key(option->keydrop);
    write(1, "\n", 1);
    write(1, "Key Quit :  ", 12);
    key(option->keyquit);
    write(1, "\n", 1);
    write(1, "Key Pause :  ", 13);
    key(option->keypause);
    write(1, "\n", 1);
}

void info_node(node_t *node)
{
    write(1, " :  Size ", 9);
    my_put_nbr(node->tetri.width);
    write(1, "*", 1);
    my_put_nbr(node->tetri.height);
    write(1, " :  Color ", 10);
    my_put_nbr(node->tetri.color);
    write(1, " :\n", 3);
    for (int a = 0; node->tetri.tabb[a] != NULL; a++) {
        write(1, node->tetri.tabb[a], my_strlen(node->tetri.tabb[a]));
        write(1, "\n", 1);
    }
}

void print_node(node_t *node)
{
    void *first = node;
    int a = 0;

    for (; node != NULL; a++)
        node = node->next;
    node = first;
    write(1, "Tetriminos :  ", 14);
    my_put_nbr(a);
    write(1, "\n", 1);
    while (node != NULL) {
        write(1, "Tetriminos :  Name ", 19);
        for (int a = 0; node->name[a] != '\0' && node->name[a] != '.'; a++)
            write(1, &node->name[a], 1);
        if (node->tetri.error != 84) {
            info_node(node);
        } else
            write(1, " :  Error\n", 10);
        node = node->next;
    }
    node = first;
}

void debug_mode(options_t *option, node_t *node)
{
    write(1, "*** DEBUG MODE ***\n", 19);
    print_keys(option);
    write(1, "Next :  ", 8);
    if (option->next == 1)
        write(1, "No\n", 3);
    else
        write(1, "Yes\n", 4);
    write(1, "Level :  ", 9);
    my_put_nbr(option->level);
    write(1, "\n", 1);
    write(1, "Size :  ", 8);
    my_put_nbr(option->map_size.x);
    write(1, "*", 1);
    my_put_nbr(option->map_size.y);
    write(1, "\n", 1);
    print_node(node);
    write(1, "Press any key to start Tetris\n", 30);
    wait_key_pressed();
}
