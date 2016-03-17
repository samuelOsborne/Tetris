/*
** fall_tetrimino2.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Tue Mar 15 14:11:58 2016 Lucas Villeneuve
** Last update Thu Mar 17 10:32:57 2016 Lucas Villeneuve
*/

#include <termios.h>
#include <ncurses.h>
#include "my.h"

void	put_in_map(char **map, t_tetrimino *tetrimino, int x, int y)
{
  int	i;
  int	j;

  i = 0;
  while (i < tetrimino->height)
    {
      j = 0;
      while (j < tetrimino->width)
	{
	  if (tetrimino->piece[i][j] != 0 && tetrimino->piece[i][j] != ' ')
	    map[y + i][x + j] = tetrimino->color + 48;
	  j++;
	}
      i++;
    }
}

void	show_in_map(t_tetrimino	*tetrimino, int x, int y)
{
  int		i;
  int		j;

  i = 0;
  while (i < tetrimino->height)
    {
      j = 0;
      while (j < tetrimino->width)
	{
	  if (tetrimino->piece[i][j] != 0)
	    {
	      init_pair(1, tetrimino->color, 0);
	      attron(COLOR_PAIR(1));
	      mvprintw(y + i + 2, x + j + 40, "%c", tetrimino->piece[i][j]);
	      attroff(COLOR_PAIR(1));
	    }
	  j++;
	}
      i++;
    }
}

int	collision(char **map, t_tetrimino *tetrimino, int x, int y)
{
  int	i;
  int	j;

  i = 0;
  while (i < tetrimino->height)
    {
      j = 0;
      while (j < tetrimino->width)
	{
	  if (tetrimino->piece[i][j] == '*' && map[y + i][x + j] != ' ')
	    {
	      if (y == 2)
		return (2);
	      else
		return (1);
	    }
	  j++;
	}
      i++;
    }
  return (0);
}

int		mode_non_canonique(int i)
{
  static struct termios oldT;
  static struct termios newT;

  if (i == 0)
    {
      if (ioctl(0, TCGETS, &oldT) < 0)
	return (1);
      if (ioctl(0, TCGETS, &newT) < 0)
        return (1);
      newT.c_lflag &= ~ECHO;
      newT.c_lflag &= ~ICANON;
      newT.c_cc[VMIN] = 0;
      newT.c_cc[VTIME] = 0.1;
      ioctl(0, TCSETS, &newT);
    }
  if (i == 1)
    if ((ioctl(0, TCSETS, &oldT)) < 0)
      return (1);
  return (0);
}
