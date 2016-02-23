##
## Makefile for Makefile in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
## 
## Made by Samuel
## Login   <samuel@epitech.net>
## 
## Started on  Tue Feb 23 10:20:42 2016 Samuel
## Last update Tue Feb 23 10:39:26 2016 Samuel
##

NAME	=	tetris

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

LIB	=	-lmy -L./lib

CC	=	gcc

CFLAGS	=	-ansi -pedantic -W -Wall -Iinclude

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(LIB) $(OBJ)

all	:	$(NAME)

clean	:	
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
