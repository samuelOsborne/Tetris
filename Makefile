##
## Makefile for Makefile in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
## 
## Made by Samuel
## Login   <samuel@epitech.net>
## 
## Started on  Tue Feb 23 10:20:42 2016 Samuel
## Last update Tue Mar  8 15:18:11 2016 Lucas Villeneuve
##

NAME	=	tetris

SRC	=	src/main.c 		\
		src/create_map.c	\
		src/check_winsz.c	\
		src/test_time.c		\
		src/debug.c		\
		src/load_tetriminos.c	\
		src/fall_tetrimino.c	\
		src/loop_game.c		\
		src/get_next_line.c	\
		src/epurstr.c		\
		src/my_getnbr.c		\
		src/my_strcpy.c		\
		src/my_strcmp.c		\
		src/my_strcat.c		\
		src/rotate_tetrimino.c	\

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

LDFLAGS	=	-lmy -L./lib -lncurses

CC	=	gcc

CFLAGS	=	-Iinclude

CFLAGS	+=	-W -Wall -Wextra -ansi -pedantic

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)


clean:	
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all


.PHONY:		all clean fclean re
