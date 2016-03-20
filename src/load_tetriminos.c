/*
** load_tetriminos.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Tue Mar  1 12:39:58 2016 Lucas Villeneuve
** Last update Sun Mar 20 15:09:36 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"
#include "get_next_line.h"

int	fill_tab_tetrimino(t_tetrimino *tetrimino, int fd, int i)
{
  char	*str;
  int	store;

  store = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      if (my_strlen(str) > tetrimino->width && str[my_strlen(str) - 1] != ' ')
	return (1);
      if (i >= tetrimino->height)
	return (1);
      if (my_strlen(str) > store)
	store = my_strlen(str);
      if (my_strcpy_tetrimino(tetrimino->piece[i], str) == NULL)
	return (1);
      i++;
    }
  if (store < tetrimino->width)
    return (1);
  return (0);
}

int	get_tetrimino(t_tetrimino *tetrimino, int fd)
{
  int	i;

  if ((tetrimino->piece = malloc(tetrimino->height * sizeof(char *) + 1))
      == NULL)
    return (1);
  i = 0;
  while (i < tetrimino->height)
    {
      if ((tetrimino->piece[i] = malloc(tetrimino->width * sizeof(char) + 2))
	  == NULL)
	return (1);
      i++;
    }
  if (fill_tab_tetrimino(tetrimino, fd, 0) == 1)
    return (1);
  return (0);
}

int	check_value_tetrimino(t_tetrimino *tetrimino, bool debug, int fd)
{
  int	i;

  get_vars_tetrimino(tetrimino, fd);
  if ((tetrimino->color > 7 || tetrimino->color < 0) || tetrimino->height < 1
      || tetrimino->width < 1)
    {
      if (debug == true)
	my_printf("Tetriminos : Name %s : Error\n", tetrimino->name);
      return (1);
    }
  if (get_tetrimino(tetrimino, fd) == 1)
    {
      if (debug == true)
      	my_printf("Tetriminos : Name %s : Error\n", tetrimino->name);
      return (1);
    }
  if (debug == true)
    my_printf("Tetriminos : Name %s : Size %d*%d : Color %d :\n",
	      tetrimino->name, tetrimino->width, tetrimino->height,
	      tetrimino->color);
  i = 0;
  if (debug == true)
    while (i < tetrimino->height)
      my_printf("%s\n", epurend(tetrimino->piece[i++]));
  return (0);
}

int	check_tetrimino(char *file, t_tetrimino *tetrimino)
{
  if ((tetrimino->name = take_name(file, ".tetrimino")) == NULL)
    return (1);
  return (0);
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
