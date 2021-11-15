/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** main.c
*/

#include "tetris.h"

int my_strncmp(char *av, char *str, int n)
{
    int a = 0;

    for (; a != n && av[a] != '\0' && str[a] != '\0'; a++)
        if (str[a] != av[a])
            return (1);
    return (0);
}

void set_init(options_t *init)
{
    init->level = 1;
    init->keyleft = tigetstr("kcub1");
    if (init->keyleft == NULL)
        exit(84);
    init->keyright = tigetstr("kcuf1");
    init->keyturn = tigetstr("kcuu1");
    init->keydrop = tigetstr("kcud1");
    init->keyquit = my_strdup("q");
    init->keypause = my_strdup(" ");
    init->map_size.x = 20;
    init->map_size.y = 10;
    init->next = 0;
    init->debug = 0;
}

options_t *initialise_option(char **env)
{
    options_t *init;
    int a = 0;

    if (env == NULL) {
        write(2, "Error: no environnement\n", 24);
        exit(84);
    }
    for (; env[a] != NULL && my_strncmp(env[a], "TERM=", 4); a++);
    if (env[a] == NULL) {
        write(2, "Error: TERM not found in environnement\n", 39);
        exit(84);
    }
    if (setupterm(&env[a][5], 1, NULL) == -1)
        exit(84);
    init = malloc(sizeof(options_t) * 1);
    if (init == NULL)
        exit(84);
    set_init(init);
    return (init);
}

int are_tetris_valid(node_t *node)
{
    void *first = node;
    int valid_tetri = 0;

    if (node == NULL)
        return (84);
    while (node != NULL) {
        if (node->tetri.error != 84)
            valid_tetri = 1;
        node = node->next;
    }
    if (valid_tetri == 0)
        return (84);
    node = first;
    return (0);
}

int main(int ac, char **av, char **env)
{
    node_t *node = NULL;
    options_t *option = initialise_option(env);

    if (are_param_valid(av) == 84)
        return (84);
    get_tetri(&node, "tetriminos/");
    manage_input(ac, av, option);
    if (option->debug == 1)
        debug_mode(option, node);
    if (gamme(node, option) == 84) {
        free_node(node);
        free(option);
        return (84);
    }
    free_node(node);
    free(option);
    return (0);
}
