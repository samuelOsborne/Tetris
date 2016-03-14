/*
** load_tetriminos.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Tue Mar  1 12:39:58 2016 Lucas Villeneuve
** Last update Mon Mar 14 14:09:01 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
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
      take_name(name, tmp);
      return (tmp);
    }
  return (NULL);
}

int	get_vars_tetrimino(t_tetrimino *tetrimino, int fd)
{
  char	*str;
  char	*tmp;
  int	i;
  int	j;
  int	k;

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
  i = 0;
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
	    return (0);
	  k++;
	  i = 0;
	}
      else
	tmp[i++] = str[j];
      j++;
    }
  return (0);
}

int	get_tetrimino(t_tetrimino *tetrimino, int fd, bool debug)
{
  char	*str;
  int	i;

  if ((tetrimino->piece = malloc(tetrimino->height * sizeof(char *) + 1)) == NULL)
    return (1);
  i = 0;
  while (i < tetrimino->height)
    {
      if ((tetrimino->piece[i] = malloc(tetrimino->width * sizeof(char) + 1)) == NULL)
	return (1);
      i++;
    }
  i = 0;
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

int	check_tetrimino(char *file, t_tetrimino *tetrimino, bool debug)
{
  int	fd;
  char	*tmp;

  if ((tetrimino->name = take_name(file, ".tetrimino")) == NULL)
    {
      my_putstr("Error name\n");
      return (1);
    }
  if ((tmp = malloc(my_strlen(file) + my_strlen("tetriminos/") + 1))
      == NULL)
    return (1);
  my_strcpy(tmp, "tetriminos/");
  file = my_strcat(tmp, file);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (1);
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
  close(fd);
  return (0);
}

t_tetrimino	*load_tetrimino(int nb, bool debug, t_tetris *tetris)
{
  struct dirent	*ent;
  DIR		*dir;
  t_tetrimino	*tetrimino;
  int		i;

  if ((tetrimino = malloc(sizeof(t_tetrimino) * nb)) == NULL)
    return (NULL);
  if ((dir = opendir("tetriminos")) != NULL)
    {
      i = 0;
      while ((ent = readdir(dir)) != NULL)
	if (ent->d_name[0] != '.')
	  if (check_tetrimino(ent->d_name, &tetrimino[i], debug) == 0)
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
