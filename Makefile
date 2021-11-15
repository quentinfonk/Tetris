##
## EPITECH PROJECT, 2020
## PSU_tetris_2019
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/get_next_line.c	\
		src/getnbr.c		\
		src/my_isnum.c		\
		src/parcer.c		\
		src/get_tetri.c		\
		src/node.c		\
		src/free_node.c		\
		src/my_strlen.c		\
		src/help.c		\
		src/tri_tetri.c		\
		src/manage_input.c	\
		src/options.c		\
		src/option2.c		\
		src/my_getnbr.c		\
		src/my_strdup.c		\
		src/option3.c		\
		src/my_put_nbr.c	\
		src/debug_mode.c	\
		game/game.c		\
		game/my_str_to_word_array.c	\
		game/int_str.c		\
		game/my_revstr.c	\
		game/my_strcpy.c	\
		game/moove.c		\
		game/print.c		\
		game/new_supp.c		\
		game/check.c		\
		game/option.c		\
		src/wait_key_pressed.c	\
		game/my_strcol.c	\
		src/is_tabb_ok.c	\
		src/are_param_valid.c	\
		game/check_star.c	\
		game/print2.c		\
		src/my_strcmp.c		\
		game/time.c		\

NAME	=	tetris

CPPFLAGS=	$(INCLUDE) $(NCURSE)

CFLAGS	=	-Wall -Wextra

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	-I./include

NCURSE	=	-lncurses

CC	?=	gcc

RM	?=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(INCLUDE) $(NCURSE) -o $(NAME)

debug:	CFLAGS += -g3
debug:	fclean $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re debug
