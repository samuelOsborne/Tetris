##
## Makefile for Makefile in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
## 
## Made by Samuel
## Login   <samuel@epitech.net>
## 
## Started on  Tue Feb 23 10:20:42 2016 Samuel
## Last update Wed Feb 24 14:02:19 2016 Lucas Villeneuve
##

NAME	=	tetris

SRC	=	src/main.c 		\
		src/test_time.c		\
		src/check_winsz.c	\
		src/map.c		\
		src/my_strcmp.c		\

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
