/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** options.c
*/

#include "tetris.h"

void change_level(options_t *option, char *optarg, char *binar)
{
    (void) binar;
    if (optarg[0] == '\0' || my_isnum(optarg) == 84 || optarg[0] == '0') {
        write(2, "Error: invalid level selected\n", 30);
        exit(84);
    }
    option->level = my_getnbr(optarg);
}

void change_key_left(options_t *option, char *optarg, char *binar)
{
    (void) binar;
    if (my_strlen(optarg) == 0 || (my_strlen(optarg) > 1 &&
        optarg[0] != '^')) {
        write(2, "Error: invalid option\n", 22);
        exit(84);
    }
    option->keyleft = my_strdup(optarg);
}

void change_key_right(options_t *option, char *optarg, char *binar)
{
    (void) binar;
    if (my_strlen(optarg) == 0 || (my_strlen(optarg) > 1 &&
        optarg[0] != '^')) {
        write(2, "Error: invalid option\n", 22);
        exit(84);
    }
    option->keyright = my_strdup(optarg);
}

void change_key_drop(options_t *option, char *optarg, char *binar)
{
    (void) binar;
    if (my_strlen(optarg) == 0 || (my_strlen(optarg) > 1 &&
        optarg[0] != '^')) {
        write(2, "Error: invalid option\n", 22);
        exit(84);
    }
    option->keydrop = my_strdup(optarg);
}

void change_key_quit(options_t *option, char *optarg, char *binar)
{
    (void) binar;
    if (my_strlen(optarg) == 0 || (my_strlen(optarg) > 1 &&
        optarg[0] != '^')) {
        write(2, "Error: invalid option\n", 22);
        exit(84);
    }
    option->keyquit = my_strdup(optarg);
}
