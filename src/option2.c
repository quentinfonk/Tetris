/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** option2.c
*/

#include "tetris.h"

void change_key_pause(options_t *option, char *optarg, char *binar)
{
    (void) binar;
    if (my_strlen(optarg) == 0 || (my_strlen(optarg) > 1 &&
        optarg[0] != '^')) {
        write(2, "Error: invalid option\n", 22);
        exit(84);
    }
    option->keypause = my_strdup(optarg);
}

int check_size(char *optarg)
{
    int save = 0;

    for (int a = 0; optarg[a] != '\0'; a++) {
        if ((optarg[a] < '0' || optarg[a] > '9') && optarg[a] != ',')
            exit(84);
        if (optarg[a] == ',')
            save = a;
    }
    if (optarg[save + 1] > '9' || optarg[save + 1] < '1')
        exit(84);
    return (0);
}

void change_map_size(options_t *option, char *optarg, char *binar)
{
    (void) binar;
    int a = 0;

    if (my_strlen(optarg) < 3 || check_size(optarg) == 84) {
        write(2, "Error: invalid map size\n", 24);
        exit(84);
    }
    option->map_size.x = getnbr(optarg, &a);
    option->map_size.y = getnbr(optarg, &a);
}

void change_next(options_t *option, char *optarg, char *binar)
{
    (void) binar;
    (void) optarg;
    option->next = 1;
}

void change_debug(options_t *option, char *optarg, char *binar)
{
    (void) binar;
    (void) optarg;
    option->debug = 1;
}
