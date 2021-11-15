/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** node.c
*/

#include "tetris.h"

void fill_name(node_t **element, char *name)
{
    int size = my_strlen(name);
    int a = 0;

    (*element)->name = malloc(sizeof(char) * (size + 1));
    if ((*element)->name == NULL)
        exit(84);
    for (; name[a] != '\0'; a++)
        (*element)->name[a] = name[a];
    (*element)->name[a] = '\0';
}

void add_node(node_t **node, char *path, char *name)
{
    node_t *element = malloc(sizeof(node_t));

    if (element == NULL)
        exit(84);
    fill_name(&element, name);
    element->tetri = tetri_parcer(path);
    element->next = *node;
    (*node) = element;
}
