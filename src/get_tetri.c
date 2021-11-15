/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** get_tetri.c
*/

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "tetris.h"

char *re_mal(char *buffer, char *bis, int fr)
{
    int a = 0;
    char *str;

    if (bis == NULL)
        return buffer;
    if (buffer == NULL)
        return (NULL);
    for (; buffer[a] != '\0'; a++);
    for (int b = 0; bis[b] != '\0'; b++, a++);
    str = malloc(sizeof(char) * (a + 1));
    if (str == NULL)
        return (NULL);
    for (a = 0; buffer[a] != '\0'; a++)
        str[a] = buffer[a];
    for (int e = 0; bis[e] != '\0'; e++, a++)
        str[a] = bis[e];
    str[a] = '\0';
    if (fr == 1)
        free(buffer);
    return (str);
}

int my_cmp(char *av, char *str, int n)
{
    int b = 0;

    for (int a = n;av[a] != '\0' && str[b] != '\0'; a++, b++)
        if (str[b] != av[a])
            return (1);
    return (0);
}

int is_tetrimino(char *str)
{
    int a = 0;

    while (str[a] != '\0' && str[a] != '.')
        a++;
    if (str[a] == '\0')
        return (84);
    if (my_cmp(str, ".tetrimino", a) != 0)
        return (84);
    return (0);
}

struct dirent *read_dir(DIR *dir, char *path)
{
    struct dirent *rd_dir;

    if (dir == NULL) {
        perror(path);
        exit(84);
    }
    rd_dir = readdir(dir);
    if (rd_dir == NULL) {
        perror(path);
        exit(84);
    }
    return (rd_dir);
}

int get_tetri(node_t **node, char *path)
{
    DIR *dir = opendir(path);
    struct dirent *rd_dir = read_dir(dir, path);

    while (rd_dir != NULL) {
        if (rd_dir->d_name[0] != '.' && is_tetrimino(rd_dir->d_name) != 84) {
            add_node(node, re_mal(path, rd_dir->d_name, 0), rd_dir->d_name);
            rd_dir = readdir(dir);
        } else
            rd_dir = readdir(dir);
    }
    closedir(dir);
    tri_tetri(node);
    return (0);
}
