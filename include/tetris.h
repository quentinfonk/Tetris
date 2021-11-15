/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris.h
*/

#ifndef TETRIS_H
#define TETRIS_H

#define READ_SIZE (1)

//includes

#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <curses.h>
#include <term.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

//structures

typedef struct game_t
{
    int score;
    int next;
    int color;
    int error;
    int tetri_nb;
    int nb_line;
    int timer;
} game_t;

typedef struct tetri_t
{
    int error;
    int width;
    int height;
    int color;
    char **tabb;
} tetri_t;

typedef struct node_t
{
    tetri_t tetri;
    char *name;
    struct node_t *next;
} node_t;

static const struct option big_option[] =
{
    {"help", 0, 0, 'h'},
    {"level", 1, 0, 'L'},
    {"key-left", 1, 0, 'l'},
    {"key-right", 1, 0, 'r'},
    {"key-turn", 1, 0, 't'},
    {"key-drop", 1, 0, 'd'},
    {"key-quit", 1, 0, 'q'},
    {"key-pause", 1, 0, 'p'},
    {"map-size", 1, 0, 'm'},
    {"debug", 0, 0, 'w'},
    {NULL, 0, 0, 0},
};

typedef struct s_vector
{
    int x;
    int y;
} vector_t;

typedef struct s_options
{
    int level;
    char *keyleft;
    char *keyright;
    char *keyturn;
    char *keydrop;
    char *keyquit;
    char *keypause;
    vector_t map_size;
    int next;
    int debug;
} options_t;

static const int COLOR[] = {
    COLOR_RED, COLOR_WHITE, COLOR_BLUE, COLOR_YELLOW, COLOR_GREEN,
    COLOR_CYAN, -1
};

//proto

int get_tetri(node_t **node, char *path);
int getnbr(char *str, int *a);
int my_isnum(char *av);
char *get_next_line(int fd);
tetri_t tetri_parcer(char *filepath);
void add_node(node_t **node, char *path, char *name);
void free_node(node_t *node);
int my_strlen(char *str);
void help(options_t *option, char *optarg, char *binar);
void tri_tetri(node_t **node);
void print_nodes(node_t *node);
void manage_input(int ac, char **av, options_t *option);
void change_level(options_t *option, char *optarg, char *binar);
int my_getnbr(char const *str);
void change_key_left(options_t *option, char *optarg, char *binar);
void change_key_right(options_t *option, char *optarg, char *binar);
void change_key_turn(options_t *option, char *optarg, char *binar);
void change_key_drop(options_t *option, char *optarg, char *binar);
void change_key_quit(options_t *option, char *optarg, char *binar);
void change_key_pause(options_t *option, char *optarg, char *binar);
void change_map_size(options_t *option, char *optarg, char *binar);
void change_next(options_t *option, char *optarg, char *binar);
void change_debug(options_t *option, char *optarg, char *binar);
char *my_strdup(char *str);
int my_put_nbr(int nb);
void debug_mode(options_t *option, node_t *node);
char *re_mal(char *buffer, char *bis, int fr);
int gamme(node_t *node, options_t *option);
int check_ch(char **map, options_t *option, game_t *gam);
char **check_line(char **map, game_t *gam);
void pr_map(char **map, game_t *gam, node_t *node, options_t *option);
void next(game_t *gam, node_t *node, char *str, options_t *option);
int check(char **map);
void new(char **map, node_t *node, game_t *gam);
char **start_map(options_t *option);
char *my_revstr(char *str);
void check_a(char a, int b);
void pr_score(game_t *gam, options_t *option, node_t *node);
char *int_str(int a);
int my_strcol(char **str);
char **right_map(char **map);
char **left_map(char **map);
char **fall(char **map);
void check_star(char **map, int i, int o, game_t *gam);
void wait_key_pressed(void);
int is_tabb_ok(char *str, tetri_t *tetri);
int are_param_valid(char **av);
void check_star(char **map, int i, int o, game_t *gam);
int are_tetris_valid(node_t *node);
int check_node_x(node_t *node);
int check_node_y(node_t *node);
void pr_turn(options_t *option, int x, int y);
int my_strcmp(char *str, char *str_bis);
char *time_str(char *str, int timer);
void nb_lin(game_t *gam);

#endif
