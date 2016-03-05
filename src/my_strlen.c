/*
** my_strlen.c for my_strlen in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Wed Mar  2 00:37:14 2016 Samuel
** Last update Wed Mar  2 00:38:21 2016 Samuel
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}
