/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** getnbr.c
*/

int getnbr(char *str, int *a)
{
    int nbr = 0;

    while (str[*a] > '9' || str[*a] < '0')
        (*a) += 1;
    while (str[*a] <= '9' && str[*a] >= '0') {
        nbr = nbr * 10 + (str[*a] - '0');
        (*a) += 1;
    }
    return (nbr);
}
