##
## Makefile for Makefile in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
## 
## Made by Samuel
## Login   <samuel@epitech.net>
## 
## Started on  Tue Feb 23 10:20:42 2016 Samuel
## Last update Thu Mar 17 20:09:11 2016 Samuel
##

NAME	=	tetris

SRC	=	src/main.c 			\
		src/create_map.c		\
		src/check_winsz.c		\
		src/debug.c			\
		src/load_tetriminos.c		\
		src/load_tetriminos2.c		\
		src/fall_tetrimino.c		\
		src/fall_tetrimino2.c		\
		src/pause.c			\
		src/loop_game.c			\
		src/get_next_line.c		\
		src/epurstr.c			\
		src/my_getnbr.c			\
		src/my_strcpy.c			\
		src/my_strcmp.c			\
		src/my_strcat.c			\
		src/rotate_tetrimino.c		\
		src/init_keybinds.c		\
		src/compare_args_for_keybind.c	\
		src/print_the_keys.c		\
		src/print_the_keys2.c		\
		src/write_to_keybind.c		\
		src/write_to_keybind2.c		\
		src/write_to_keybind3.c	\
		src/map_size_detect.c		\
		src/menu.c			\
		src/error.c			\
		src/term_check.c		\
		src/reset.c			\

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

LDFLAGS	=	-lmy -L./lib -lncurses

CC	=	gcc

CFLAGS	=	-Iinclude

CFLAGS	+=	-W -Wall -Wextra -ansi

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)


clean:	
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all


.PHONY:		all clean fclean re
