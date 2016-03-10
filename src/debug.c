/*
** debug.c for tetri in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon Feb 29 16:12:27 2016 Lucas Villeneuve
** Last update Thu Mar 10 16:46:08 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <dirent.h>
#include "my.h"

t_tetrimino	*ini_load(t_tetris *tetris)
{
  DIR		*dir;
  struct dirent	*ent;
  int		i;
  t_tetrimino	*tetrimino;

  i = 0;
  if ((dir = opendir("tetriminos")) != NULL)
    {
      while ((ent = readdir(dir)) != NULL)
	if (ent->d_name[0] != '.')
	  i++;
      closedir(dir);
    }
  else
    exit(1);
  if (i < 1)
    exit(1);
  tetrimino = load_tetrimino(i, false, tetris);
  return (tetrimino);
}

t_tetrimino	*debug_mode(t_tetris *tetris)
{
  DIR		*dir;
  struct dirent	*ent;
  int		i;
  t_tetrimino	*tetrimino;

  my_putstr("*** DEBUG MODE ***\n");
  my_printf("Size : %d*%d\n", tetris->map_height, tetris->map_width);
  i = 0;
  if ((dir = opendir("tetriminos")) != NULL)
    {
      while ((ent = readdir(dir)) != NULL)
	if (ent->d_name[0] != '.' && (take_name(ent->d_name, ".tetrimino") != NULL))
	  i++;
      closedir(dir);
    }
  else
    {
      my_putstr("Error load directory tetrimino\n");
      exit(1);
    }
  my_printf("Tetriminos : %d\n", i);
  if (i < 1)
    {
      my_putstr("Not enough tetriminos\n");
      exit(1);
    }
  tetrimino = load_tetrimino(i, true, tetris);
  my_putstr("Press a key to start Tetris\n");
  getchar();
  return (tetrimino);
}
