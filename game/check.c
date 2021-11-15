/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include "tetris.h"
#include <time.h>

void check_a(char a, int b)
{
    for (int i = 0; COLOR[i] != -1; i++)
        if (a == i + 1 + '0' || b == i + 1) {
            init_pair(i + 1, COLOR[i], COLOR[i]);
            attron(COLOR_PAIR(i + 1));
        }
}

int check(char **map)
{
    int i = 0;
    int v = 0;
    static int end = 0;

    if (end == 0)
        end = my_strcol(map);
    for (i = 0; map[i] != NULL; i++)
        for (int o = 0; map[i][o] != '\0'; o++) {
            if (map[i][o] == '*' && i+1 == end)
                return (1);
            if (map[i][o] == '*' && map[i+1][o] != '.' && map[i+1][o] != '*')
                return (1);
            if (map[i][o] == '*')
                v++;
        }
    if (v == 0)
        return (1);
    return (0);
}

int check_op(char *str)
{
    int a = my_strlen(str);

    if (str[0] == 27 || str[0] == '^') {
        if (str[a-1] == 'C')
            return (KEY_RIGHT);
        if (str[a-1] == 'D')
            return (KEY_LEFT);
        if (str[a-1] == 'A')
            return (KEY_UP);
        if (str[a-1] == 'B')
            return (KEY_DOWN);
    }
    return (str[0]);
}

int check_time(int ch, options_t *option, game_t *gam)
{
    static int a = 0;
    int oui = 0;

    if (ch == check_op(option->keydrop))
        return (1);
    if (a == 0)
        a = time(NULL);
    oui = time(NULL);
    if (a < oui) {
        a = oui;
        gam->timer += 1;
        return (1);
    }
    return (0);
}

int check_ch(char **map, options_t *option, game_t *gam)
{
    int ch = 0;

    nodelay(stdscr, TRUE);
    ch = getch();
    if (ch == 0)
        return (0);
    if (ch == check_op(option->keyright))
        right_map(map);
    if (ch == check_op(option->keyleft))
        left_map(map);
    if (ch == check_op(option->keyturn))
        return (0);
    if (ch == check_op(option->keyquit))
        return (1);
    if (check_time(ch, option, gam) == 1)
        fall(map);
    return (0);
}
