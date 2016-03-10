/*
** rotate_tetrimino.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon Mar  7 11:00:17 2016 Lucas Villeneuve
** Last update Tue Mar  8 14:04:09 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

void	rotate_tetrimino(t_tetrimino *tetrimino, t_tetrimino *new_tetrimino)
{
  int	i;
  int	j;
  int	tmp;

  j = 0;
  while (j < new_tetrimino->height)
    {
      i = 0;
      tmp = new_tetrimino->width - 1;
      while (i < new_tetrimino->width)
	{
	  new_tetrimino->piece[j][i] = tetrimino->piece[tmp][j];
	  i++;
	  tmp--;
	}
      new_tetrimino->piece[j][i] = 0;
      j++;
    }
}

t_tetrimino	ini_rotate_tetrimino(t_tetrimino tetrimino, char **map, int x, int y)
{
  t_tetrimino	new_tetrimino;
  int		i;

  new_tetrimino.width = tetrimino.height;
  new_tetrimino.height = tetrimino.width;
  new_tetrimino.color = tetrimino.color;
  if ((new_tetrimino.piece = malloc(new_tetrimino.height * sizeof(char *))) == NULL)
    return (tetrimino);
  i = 0;
  while (i < new_tetrimino.height)
    {
      if ((new_tetrimino.piece[i] = malloc(new_tetrimino.width + 1)) == NULL)
  	return (tetrimino);
      i++;
    }
  rotate_tetrimino(&tetrimino, &new_tetrimino);
  if (collision(map, &new_tetrimino, x, y) == 0)
    return (new_tetrimino);
  else
    return (tetrimino);
  return (tetrimino);
}
