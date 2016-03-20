/*
** load_tetriminos2.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon Mar 14 14:44:35 2016 Lucas Villeneuve
** Last update Sun Mar 20 15:36:50 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

char	*fill_tmp(char *name, char *tmp, int j)
{
  int	i;

  i = 0;
  while (i < j)
    {
      tmp[i] = name[i];
      i++;
    }
  tmp[i] = 0;
  return (tmp);
}

char	*take_name(char *name, char *str)
{
  int	i;
  char	*tmp;

  i = 0;
  while (name[i])
    {
      while (name[i] != '.')
	{
	  i++;
	  if (name[i] == 0)
	    return (NULL);
	}
      if (my_strcmpn(name, str, i) == 0)
	{
	  if ((tmp = malloc(my_strlen(name))) == NULL)
	    return (NULL);
	  fill_tmp(name, tmp, i);
	  return (tmp);
	}
      if (name[i + 1] == 0 || name[i + 1] == '.')
	return (NULL);
      i++;
    }
  return (NULL);
}

void	fill_vars_tetrimino(t_tetrimino *tetrimino,
			    char *str, char *tmp, int i)
{
  int	j;
  int	k;

  j = 0;
  k = 0;
  while (1)
    {
      if (str[j] == ' ' || str[j] == 0)
	{
	  tmp[i] = 0;
	  if (k == 0)
	    tetrimino->width = my_getnbr(tmp);
	  else if (k == 1)
	    tetrimino->height = my_getnbr(tmp);
	  else if (k == 2)
	    tetrimino->color = my_getnbr(tmp);
	  if (str[j] == 0)
	    return ;
	  k++;
	  i = 0;
	}
      else
	tmp[i++] = str[j];
      j++;
    }
}

int	get_vars_tetrimino(t_tetrimino *tetrimino, int fd)
{
  char	*str;
  char	*tmp;

  str = get_next_line(fd);
  if (str == NULL)
    return (1);
  str = epurstr(str);
  if ((tmp = malloc(my_strlen(str))) == NULL)
    exit(1);
  fill_vars_tetrimino(tetrimino, str, tmp, 0);
  return (0);
}
