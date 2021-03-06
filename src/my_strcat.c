/*
** my_strcat.c for my_strcat in /home/villen_l/rendu/Piscine_C_J07/ex_02
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Tue Oct  6 15:18:49 2015 Lucas Villeneuve
** Last update Thu Mar  3 14:34:50 2016 Lucas Villeneuve
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	len;

  i = 0;
  len = my_strlen(dest);
  while (src[i] != 0)
    {
      dest[len] = src[i];
      len = len + 1;
      i = i + 1;
    }
  dest[len] = '\0';
  return (dest);
}
