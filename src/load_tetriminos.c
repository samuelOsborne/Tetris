/*
** load_tetriminos.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Tue Mar  1 12:39:58 2016 Lucas Villeneuve
** Last update Thu Mar  3 14:34:32 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"
#include "get_next_line.h"

char	*take_name(char *name, char *str)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  while (name[i] && name[i] != '.')
    i++;
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
	{
	  tmp[i] = name[i];
	  i++;
	}
      tmp[i] = 0;
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
	{
	  tmp[i] = str[j];
	  i++;
	}
      j++;
    }
  return (0);
}

int	get_tetrimino(t_tetrimino *tetrimino, int fd)
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
      my_strcpy(tetrimino->piece[i], str);
      my_printf("%s\n", tetrimino->piece[i]);
      i++;
    }
  return (0);
}

t_tetrimino	*check_tetrimino(char *file)
{
  int		fd;
  char		*tmp;
  t_tetrimino	*tetrimino;

  if ((tetrimino = malloc(sizeof(t_tetrimino))) == NULL)
    return (NULL);
  tetrimino->name = take_name(file, ".tetrimino");
  if (tetrimino->name == NULL)
    {
      my_putstr("Error name\n");
      return (NULL);
    }
  if ((tmp = malloc(my_strlen(file) + my_strlen("tetrimino/") + 1))
      == NULL)
    return (NULL);
  my_strcpy(tmp, "tetrimino/");
  file = my_strcat(tmp, file);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  get_vars_tetrimino(tetrimino, fd);
  my_printf("Tetriminos : Name %s : Size %d*%d : Color %d :\n", tetrimino->name,
	    tetrimino->width, tetrimino->height, tetrimino->color);
  get_tetrimino(tetrimino, fd);
  close(fd);
  return (tetrimino);
}

void		load_tetrimino()
{
  struct dirent	*ent;
  DIR		*dir;

  if ((dir = opendir("tetrimino")) != NULL)
    {
      while ((ent = readdir(dir)) != NULL)
	if (ent->d_name[0] != '.')
	  check_tetrimino(ent->d_name);
      closedir(dir);
    }
  else
    my_putstr("Error\n");
}
