/*
** load_tetriminos2.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon Mar 14 14:44:35 2016 Lucas Villeneuve
** Last update Mon Mar 14 14:45:14 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

char	*fill_tmp(char *name, char *tmp)
{
  int	i;

  i = 0;
  while (name[i] && name[i] != '.')
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
  int	j;
  char	*tmp;

  i = 0;
  j = 0;
  while (name[i] && name[i] != '.')
    i++;
  while ((name[i] == str[j]) && str[j] && name[i])
    {
      i++;
      j++;
    }
  if (str[j] == 0)
    {
      if ((tmp = malloc(my_strlen(name))) == NULL)
	return (NULL);
      fill_tmp(name, tmp);
      return (tmp);
    }
  return (NULL);
}

void	fill_vars_tetrimino(t_tetrimino *tetrimino, char *str, char *tmp, int i)
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
    {
      my_putstr("gnl failed\n");
      return (1);
    }
  str = epurstr(str);
  if ((tmp = malloc(my_strlen(str))) == NULL)
    {
      my_putstr("Malloc failed\n");
      return (1);
    }
  fill_vars_tetrimino(tetrimino, str, tmp, 0);
  return (0);
}
