/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++);
    return (a);
}
