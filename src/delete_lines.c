/*
** delete_lines.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Sat Mar 19 14:07:48 2016 Lucas Villeneuve
** Last update Sat Mar 19 14:08:25 2016 Lucas Villeneuve
*/

#include "my.h"

void	delete_line2(char **map, t_tetris *tetris, int i , int j)
{
  int	tmp;

  tetris->nb_lines++;
  tetris->checker++;
  tetris->score = tetris->score + 100;
  tmp = i;
  while (tmp > 1)
    {
      j = 1;
      while (j < tetris->map_width + 1)
	{
	  map[tmp][j] = map[tmp - 1][j];
	  j++;
	}
      tmp--;
    }
}

void	del_line_map(char **map, t_tetris *tetris)
{
  int	i;
  int	j;
  int	count;

  i = 1;
  while (i < tetris->map_height)
    {
      j = 1;
      count = 0;
      while (j < tetris->map_width + 1)
	{
	  if (map[i][j] != ' ')
	    count++;
	  j++;
	}
      if (count == tetris->map_width)
	delete_line2(map, tetris, i, j);
      i++;
    }
}
