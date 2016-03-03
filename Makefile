##
## Makefile for Makefile in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
## 
## Made by Samuel
## Login   <samuel@epitech.net>
## 
## Started on  Tue Feb 23 10:20:42 2016 Samuel
## Last update Thu Mar  3 14:27:29 2016 Lucas Villeneuve
##

NAME	=	tetris

SRC	=	src/main.c 		\
		src/test_time.c		\
		src/check_winsz.c	\
		src/my_strcmp.c		\
		src/create_map.c	\
		src/objects.c		\
		src/debug.c		\
		src/load_tetriminos.c	\
		src/get_next_line.c	\
		src/epurstr.c		\
		src/my_getnbr.c		\
		src/my_strcpy.c		\
		src/my_strcat.c		\

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
