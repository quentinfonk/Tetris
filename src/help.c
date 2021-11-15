/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** help.c
*/

#include "tetris.h"

void help(options_t *option, char *optarg, char *binar)
{
    (void) option;
    (void) optarg;
    write(1, "Usage:  ", 8);
    write(1, binar, my_strlen(binar));
    write(1, " [option]\nOption:\n --help               ", 40);
    write(1, "Display this help\n -L --level={num}     Start Tetris at ", 56);
    write(1, "level num (def: 1)\n -l --key-left={K}    Move the ", 50);
    write(1, "tetrimino LEFT using the K key (def: left arrow)\n -r --", 55);
    write(1, "key-right   Move the tetrimino RIGHT using the K key (def:", 58);
    write(1, " right arrow)\n -t --key-turn={K}    TURN the tetrimino ", 55);
    write(1, "clockwise 90d using the K key (def: top arrow)\n -d --key", 56);
    write(1, "-drop={K}     DROP the tetrimino using the K key (def: ", 55);
    write(1, "down arrow)\n -q --key-quit={K}    QUIT the game using the", 57);
    write(1, " K key (def: 'q' key)\n -p --key-pause={K}   PAUSE/RESTART", 57);
    write(1, " the game using the K key (def: space bar)\n --map-size=", 55);
    write(1, "{row,col} Set the numbers of rows and columns of the map ", 57);
    write(1, "(def: 20,10)\n -w --without-next    Hide next tetrimino", 54);
    write(1, " (def: false)\n -D --debug           Debug mode (def: ", 53);
    write(1, "false)\n", 7);
    exit(0);
}
