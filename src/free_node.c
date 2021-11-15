/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** free_node.c
*/

#include "tetris.h"

void free_tetri(tetri_t tetri)
{
    for (int a = 0; tetri.tabb[a] != NULL; a++)
        free(tetri.tabb[a]);
    free(tetri.tabb);
}

void free_node(node_t *node)
{
    node_t *elem = node->next;

    while (node->next != NULL) {
        free(node->name);
        node->name = NULL;
        free(node);
        node = elem;
        elem = elem->next;
    }
}
