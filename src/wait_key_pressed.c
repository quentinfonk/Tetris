/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** wait_key_pressed.c
*/

#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

void wait_key_pressed(void)
{
    struct termios info_term;
    char *str = malloc(sizeof(char) * 1);

    if (str == NULL) {
        write(2, "Error malloc\n", 13);
        exit(84);
    }
    tcgetattr(0, &info_term);
    info_term.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &info_term);
    read(0, str, 1);
    free (str);
}
