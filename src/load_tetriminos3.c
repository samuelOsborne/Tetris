/*
** load_tetriminos3.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Sat Mar 19 14:27:38 2016 Lucas Villeneuve
** Last update Sat Mar 19 14:38:37 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"

void		sort_tetrimino(t_tetrimino *tetrimino, int nb)
{
  bool		done;
  int		i;
  t_tetrimino	tmp;

  done = false;
  while (done == false)
    {
      done = true;
      i = 0;
      while (i < nb - 1)
        {
  	  if (my_strcmp(tetrimino[i].name, tetrimino[i + 1].name) > 0)
  	    {
  	      tmp = tetrimino[i];
  	      tetrimino[i] = tetrimino[i + 1];
  	      tetrimino[i + 1] = tmp;
  	      done = false;
  	    }
  	  i++;
        }
    }
}

int	print_tetriminos2(t_tetrimino *str, int i)
{
  char	*file;
  char	*tmp;
  int	fd;

  if ((file = malloc(my_strlen(str[i].name) + 1)) == NULL)
    return (1);
  if ((tmp = malloc(my_strlen(str[i].name) + my_strlen("tetriminos/")
		    + my_strlen(".tetrimino") + 1)) == NULL)
    return (1);
  my_strcpy(file, str[i].name);
  my_strcpy(tmp, "tetriminos/");
  file = my_strcat(tmp, file);
  file = my_strcat(file, ".tetrimino");
  if ((fd = open(file, O_RDONLY)) == -1)
    return (1);
  return (fd);
}

t_tetrimino	*print_tetriminos(t_tetris *tetris,
				  t_tetrimino *str, bool debug)
{
  int	i;
  int	j;
  int	nb;
  int	fd;
  t_tetrimino *tetrimino;

  i = 0;
  j = 0;
  if ((tetrimino = malloc(sizeof(t_tetrimino) * tetris->nb)) == NULL)
    return (NULL);
  nb = tetris->nb;
  while (i < nb)
    {
      if ((fd = print_tetriminos2(str, i)) == 1)
	return (NULL);
      if (check_value_tetrimino(&str[i], debug, fd) == 1)
	tetris->nb--;
      else
	tetrimino[j++] = str[i];
      close(fd);
      i++;
    }
  return (tetrimino);
}
