/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** manage_input.c
*/

#include "tetris.h"

void (*fct[])(options_t *option, char *optarg, char *binar) = {help,
    change_level, change_key_left, change_key_right, change_key_turn,
    change_key_drop, change_key_quit, change_key_pause, change_map_size,
    change_next, change_debug};

void manage_input(int ac, char **av, options_t *option)
{
    char index = 0;
    int opt_rtrn = 0;
    const char *little_option = "L:l:r:t:d:q:p:wD";
    char *ref = "hLlrtdqpmwD";
    int i = 0;

    while (1) {
        index = getopt_long(ac, av, little_option, big_option, &opt_rtrn);
        if (index == -1)
            break;
        if (index == '?')
            exit(84);
        while (index != ref[i] && ref[i] != '\0')
            i++;
        if (ref[i] == '\0')
            return;
        fct[i](option, optarg, av[0]);
        i = 0;
    }
}
