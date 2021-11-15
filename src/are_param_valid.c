/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** are_param_valid.c
*/

#include "tetris.h"

int are_param_valid(char **av)
{
    int nb_arg = my_strcol(av);

    if (nb_arg == 1)
        return (0);
    if (av[1][0] != '-')
        return (84);
    for (int a = 1; av[a] != NULL; a++) {
        if (av[a][0] != '-' && av[a - 1][0] != '-')
            return (84);
        if (av[a][0] != '-' && (my_strcmp(av[a - 1], "-D") == 0 ||
            my_strcmp(av[a - 1], "--help") == 0 || my_strcmp(av[a - 1],
            "--debug") == 0))
            return (84);
    }
    return (0);
}
