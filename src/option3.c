/*
** EPITECH PROJECT, 2020
** PSU_tetris.c
** File description:
** option3.c
*/

#include "tetris.h"

void change_key_turn(options_t *option, char *optarg, char *binar)
{
    (void) binar;
    if (my_strlen(optarg) == 0 || (my_strlen(optarg) > 1 &&
        optarg[0] != '^')) {
        write(2, "Error: invalid option\n", 22);
        exit(84);
    }
    option->keyturn = my_strdup(optarg);
}
