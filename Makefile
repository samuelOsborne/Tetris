##
## Makefile for Makefile in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
## 
## Made by Samuel
## Login   <samuel@epitech.net>
## 
## Started on  Tue Feb 23 10:20:42 2016 Samuel
## Last update Wed Feb 24 09:31:18 2016 Samuel
##

NAME	=	tetris

SRC	=	src/main.c 	\
		src/test_time.c	

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

LIB	=	-lmy -L./lib -lncurses

CC	=	gcc

CFLAGS	=	-Iinclude
CFLAGS	+=	-W -Wall -Wextra -ansi -pedantic

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

all	:	$(NAME)

clean	:	
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
