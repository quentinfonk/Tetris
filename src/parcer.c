/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** parcer.c
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tetris.h"

int my_isnum_tetri(char *av)
{
    int b = 0;

    if (av == NULL)
        return (84);
    if (av[0] == 0)
        return (84);
    for (; av[b] != '\0'; b++)
        if ((av[b] < '0' || av[b] > '9') && av[b] != ' ')
            return (84);
    return (0);
}

void fill_size(tetri_t *tetri, char *get)
{
    int a = 0;

    if (my_isnum_tetri(get) != 0) {
        tetri->error = 84;
        return;
    }
    tetri->width = getnbr(get, &a);
    tetri->height = getnbr(get, &a);
    tetri->color = getnbr(get, &a);
    if (tetri->color < 1 || tetri->color > 8)
        tetri->error = 84;
    if (tetri->width == 0 || tetri->height == 0 || tetri->color == 0) {
        tetri->error = 84;
        return;
    }
}

void fill_char_bis(tetri_t *tetri)
{
    int b = 0;

    for (int a = 0; a != tetri->height; a++) {
        for (b = my_strlen(tetri->tabb[a]) - 1; b != 0 && tetri->tabb[a][b]
            == ' '; b--);
        tetri->tabb[a][b + 1] = '\0';
    }
}

void fill_char(tetri_t *tetri, int fd)
{
    tetri->tabb = malloc(sizeof(char *) * (tetri->height + 1));
    if (tetri->tabb == NULL)
        tetri->error = 84;
    for (int a = 0; a != tetri->height; a++) {
        tetri->tabb[a] = get_next_line(fd);
        if (tetri->tabb[a] == NULL ||
            is_tabb_ok(tetri->tabb[a], tetri) == 84) {
            tetri->error = 84;
            return;
        }
    }
    fill_char_bis(tetri);
    tetri->tabb[tetri->height] = NULL;
    if (get_next_line(fd) != NULL)
        tetri->error = 84;
}

tetri_t tetri_parcer(char *filepath)
{
    tetri_t tetri;
    char *get = NULL;
    int fd = open(filepath, O_RDONLY);

    tetri.error = 0;
    if (fd == -1) {
        tetri.error = 84;
        return (tetri);
    }
    get = get_next_line(fd);
    if (get == NULL) {
        tetri.error = 84;
        return (tetri);
    }
    fill_size(&tetri, get);
    if (tetri.error != 84)
        fill_char(&tetri, fd);
    close(fd);
    return (tetri);
}
