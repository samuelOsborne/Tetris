/*
** check_tetrimino.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed Feb 24 14:31:47 2016 Lucas Villeneuve
** Last update Fri Feb 26 10:30:34 2016 Samuel
*/

#include "my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


char	*take_name(char *name, char *str)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  while (name[i] && name[i] != '.')
    i++;
  /* if (name[i] == 0) */
  /*   return (NULL); */
  j = 0;
  while ((name[i] == str[j]) && str[j] != 0 && name[i] != 0)
    {
      i++;
      j++;
    }
  if (str[j] == 0)
    {
      if ((tmp = malloc(my_strlen(name))) == NULL)
	return (NULL);
      i = 0;
      while (name[i] && name[i] != '.')
	tmp[i] = name[i++];
      tmp[i] = 0;
      return (tmp);
    }
  return (NULL);
}

/* int	get_value() */
/* { */
  
/* } */

t_tetrimino	*check_tetrimino(char *file)
{
  int		fd;
  char		*tmp;
  t_tetrimino	tetrimino;

  tetrimino.name = take_name(file, ".tetrimino");
  if (tetrimino.name == NULL)
    {
      my_putstr("Error name\n");
      return (NULL);
    }
  if ((fd = open(file, O_RDONLY)) == -1)
    return (1);
  my_printf("Tetriminos : Name %s : ", tetrimino.name);
  free(tetrimino.name);
  /* if ((tmp = get_next_line(fd)) == NULL) */
  /*   { */
  /*     my_putstr("Error file\n"); */
  /*     return (NULL); */
  /*   } */
  /* get_value(tmp, &tetrimino); */
}
