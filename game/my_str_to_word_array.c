/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_str_to_word_array.c
*/

#include "tetris.h"

int nbr_back_n(char *str)
{
    int b = 1;
    int a = 0;

    for (; str[a] == '\t' || str[a] == ' ' || str[a] == '\n'; a++);
    for (; str[a] != '\0'; a++) {
        if ((str[a] == ' ' || str[a] == '\t' || str[a] == '\n') &&
            (str[a + 1] != ' ' && str[a + 1] != '\n' && str[a + 1] != '\t' &&
            str[a + 1] != '\0'))
            b++;
    }
    return (b);
}

int size_col(char  *str, int nbr)
{
    int count = 0;
    int a = 0;

    while (nbr != 0) {
        for (; str[a] == ' ' || str[a] == '\n' || str[a] == '\t'; a++);
        while (str[a] != ' ' && str[a] != '\0' && str[a] != '\t' &&
            str[a] != '\n')
            a++;
        nbr--;
    }
    for (; str[a] == ' ' || str[a] == '\n' || str[a] == '\t'; a++);
    while (str[a] != ' ' && str[a] != '\0' && str[a] != '\t' &&
        str[a] != '\n') {
        a++;
        count++;
    }
    return (count);
}

char **mallo(char *str)
{
    int count = nbr_back_n(str);
    char **tabb = malloc(sizeof(char *) * (count + 1));

    if (tabb == NULL)
        return NULL;
    for (int a = 0; a != count; a++) {
        tabb[a] = malloc(sizeof(char) * (size_col(str, a) + 1));
        if (tabb[a] == NULL)
            return NULL;
    }
    return (tabb);
}

char **my_str_to_word_array(char *str)
{
    char **tabb = mallo(str);
    int a = 0, b = 0, c = 0;

    if (tabb == NULL)
        return NULL;
    for (; str[a] != '\0'; a++) {
        for (; str[a] == ' ' || str[a] == '\t' || str[a] == '\n'; a++);
        if (str[a] == '\0')
            break;
        for (; str[a] != ' ' && str[a] != '\0' && str[a] != '\t' &&
            str[a] != '\n'; c++, a++)
            tabb[b][c] = str[a];
        tabb[b][c] = '\0';
        b++;
        c = 0;
        if (str[a] == '\0')
            break;
    }
    tabb[b] = NULL;
    return (tabb);
}
