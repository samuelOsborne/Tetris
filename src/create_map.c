/*
** moving_object.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Thu Feb 25 18:10:30 2016 Lucas Villeneuve
** Last update Sat Mar  5 23:26:34 2016 Samuel
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

void	make_tb(char **map, t_tetris *tetris, int j)
{
  int	i;

  i = 0;
  while (i < tetris->map_width + 2)
    {
      map[j][i] = '-';
      i++;
    }
  map[j][i] = 0;
}

void	make_borders(char **map, t_tetris *tetris)
{
  int	i;
  int	j;

  j = 1;
  while (j < tetris->map_height)
    {
      i = 0;
      map[j][i++] = '|';
      while (i <= tetris->map_width)
	map[j][i++] = ' ';
      map[j][i++] = '|';
      map[j][i] = 0;
      j++;
    }
}

void	display_map_tetris(char **map, t_tetris *tetris)
{
  int	i;

  i = 0;
  while (i < tetris->map_height + 2)
    {
      mvprintw(i + 2, 35, map[i]);
      i++;
    }
}

char	**create_map(t_tetris *tetris)
{
  char	**map;
  int	i;

  map = malloc(sizeof(char *) * tetris->map_height + 3);
  if (map == NULL)
    return (NULL);
  i = 0;
  while (i < tetris->map_height + 3)
    {
      map[i] = malloc(tetris->map_width + 3);
      if (map[i] == NULL)
	return (NULL);
      i++;
    }
  make_tb(map, tetris, 0);
  make_tb(map, tetris, tetris->map_height);
  make_borders(map, tetris);
  return (map);
}
