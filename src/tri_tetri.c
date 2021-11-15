/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tri_tetri.c
*/

#include "tetris.h"

int size_node(node_t **node)
{
    void *first = *node;
    int size = 0;

    while (*node != NULL) {
        (*node) = (*node)->next;
        size += 1;
    }
    (*node) = first;
    return (size);
}

void swap_tetri(node_t **node, node_t **first, node_t **aaa)
{
    node_t *save = NULL;

    if ((*node)->name[0] > (*node)->next->name[0]) {
        save = (*node)->next->next;
        (*node)->next->next = (*node);
        (*node) = (*node)->next;
        (*node)->next->next = save;
        if ((*aaa) != NULL)
            (*aaa)->next = (*node);
    }
    if ((*node)->next == (*first))
        (*first) = (*node);
    (*aaa) = (*node);
    (*node) = (*node)->next;
}

void tri_tetri(node_t **node)
{
    int size = size_node(node);
    node_t *first = (*node);
    node_t *aaa = NULL;

    for (int a = 0; a < size - 1; a++) {
        while ((*node)->next != NULL)
            swap_tetri(node, &first, &aaa);
        (*node) = first;
        aaa = NULL;
    }
}
