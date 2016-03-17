/*
** load_tetriminos.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Tue Mar  1 12:39:58 2016 Lucas Villeneuve
** Last update Thu Mar 17 18:00:16 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"
#include "get_next_line.h"

int	fill_tab_tetrimino(t_tetrimino *tetrimino, int fd, bool debug, int i)
{
  char	*str;

  while ((str = get_next_line(fd)) != NULL)
    {
      if (my_strlen(str) > tetrimino->width)
	{
	  if (debug == true)
	    my_putstr("Error: Width of the piece is wrong\n");
	  return (1);
	}
      if (i >= tetrimino->height)
	{
	  if (debug == true)
	    my_putstr("Error: Height of the piece is wrong\n");
	  return (1);
	}
      my_strcpy(tetrimino->piece[i], str);
      i++;
    }
  i = 0;
  if (debug == true)
    while (i < tetrimino->height)
      my_printf("%s\n", tetrimino->piece[i++]);
  return (0);
}

int	get_tetrimino(t_tetrimino *tetrimino, int fd, bool debug)
{
  int	i;

  if ((tetrimino->piece = malloc(tetrimino->height * sizeof(char *) + 1))
      == NULL)
    return (1);
  i = 0;
  while (i < tetrimino->height)
    {
      if ((tetrimino->piece[i] = malloc(tetrimino->width * sizeof(char) + 1))
	  == NULL)
	return (1);
      i++;
    }
  if (fill_tab_tetrimino(tetrimino, fd, debug, 0) == 1)
    return (1);
  return (0);
}

int	check_value_tetrimino(t_tetrimino *tetrimino, bool debug, int fd)
{
  get_vars_tetrimino(tetrimino, fd);
  if ((tetrimino->color > 7 || tetrimino->color < 0) || tetrimino->height < 1
      || tetrimino->width < 1)
    {
      if (debug == true)
	my_printf("Tetriminos : Name %s : Error\n", tetrimino->name);
      return (1);
    }
  if (debug == true)
    my_printf("Tetriminos : Name %s : Size %d*%d : Color %d :\n",
	      tetrimino->name, tetrimino->width, tetrimino->height,
	      tetrimino->color);
  if (get_tetrimino(tetrimino, fd, debug) == 1)
    return (1);
  return (0);
}

int	check_tetrimino(char *file, t_tetrimino *tetrimino)
{
  if ((tetrimino->name = take_name(file, ".tetrimino")) == NULL)
    return (1);
  return (0);
}

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

t_tetrimino	*print_tetriminos(t_tetris *tetris, t_tetrimino *str)
{
  int	i;
  int	j;
  int	nb;
  int	fd;
  char	*file;
  char	*tmp;
  t_tetrimino *tetrimino;

  i = 0;
  j = 0;
  if ((tetrimino = malloc(sizeof(t_tetrimino) * tetris->nb)) == NULL)
    return (NULL);
  nb = tetris->nb;
  while (i < nb)
    {
      if ((file = malloc(my_strlen(str[i].name) + 1)) == NULL)
	return (NULL);
      if ((tmp = malloc(my_strlen(str[i].name) + my_strlen("tetriminos/")
			+ my_strlen(".tetrimino") + 1)) == NULL)
	return (NULL);
      my_strcpy(file, str[i].name);
      my_strcpy(tmp, "tetriminos/");
      file = my_strcat(tmp, file);
      file = my_strcat(file, ".tetrimino");
      if ((fd = open(file, O_RDONLY)) == -1)
      	return (NULL);
      if (check_value_tetrimino(&str[i], true, fd) == 1)
	tetris->nb--;
      else
	{
	  tetrimino[j] = str[i];
	  j++;
	}
      close(fd);
      free(file);
      i++;
    }
  return (tetrimino);
}

t_tetrimino	*load_tetrimino(int nb, bool debug, t_tetris *tetris, int i)
{
  struct dirent	*ent;
  DIR		*dir;
  t_tetrimino	*tetrimino;

  if ((tetrimino = malloc(sizeof(t_tetrimino) * nb)) == NULL)
    return (NULL);
  if ((dir = opendir("tetriminos")) != NULL)
    {
      i = 0;
      while ((ent = readdir(dir)) != NULL)
	if (ent->d_name[0] != '.')
	  if (check_tetrimino(ent->d_name, &tetrimino[i]) == 0)
	    i++;
      tetris->nb = i;
      if (i < 1)
	{
	  if (debug == true)
	    my_putstr("Not enough tetriminos\n");
	  exit(1);
	}
      closedir(dir);
    }
  else if (debug == true)
    my_putstr("Error\n");
  return (tetrimino);
}
