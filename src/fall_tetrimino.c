/*
** fall_tetrimino.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Fri Mar  4 10:28:56 2016 Lucas Villeneuve
** Last update Fri Mar 11 19:01:02 2016 Samuel
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>
#include <stdio.h>
#include "my.h"

void		put_in_map(char **map, t_tetrimino *tetrimino, int x, int y)
{
  int		i;
  int		j;

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
	      init_pair(1, tetrimino->color, NULL);
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

void	delete_line(char **map, t_tetris *tetris)
{
  int	i;
  int	j;
  int	count;
  int	tmp;

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
	{
	  tetris->lines = tetris->lines + 1;
	  tetris->checker = tetris->checker + 1;
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
      i++;
    }
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
}

int	fall_tetrimino(char **map, t_tetris *tetris, t_tetrimino tetrimino, t_keybinds *keybinds) /* maybe pass to display the size of the map from keybinds instead of char **map? */
{
  int	x;
  int	y;
  int	ch;
  int	col;
  char	buffer[5];

  y = 1;
  x = tetris->map_width / 2;
  while (1)
    {
      menu(keybinds, tetris);
      if ((read(0, buffer, 5) == -1))
	return (1);
      if ((col = collision(map, &tetrimino, x, y + 1)) == 0)
	y++;
      else
	{
      	  put_in_map(map, &tetrimino, x, y);
	  display_map_tetris(map, tetris);
	  if (col == 2)
	    return (2);
	  else
	    return (1);
	}
      if ((my_strcmp(buffer, keybinds->kl) == 0) && collision(map, &tetrimino, x - 1, y) == 0)
	x--;
      else if ((my_strcmp(buffer, keybinds->kr) == 0) && collision(map, &tetrimino, x + 1, y) == 0)
	x++;
      else if (my_strcmp(buffer, keybinds->kt) == 0 && collision(map, &tetrimino, x - 1, y) == 0)
	tetrimino = ini_rotate_tetrimino(tetrimino, map, x, y);
      else if (my_strcmp(buffer, keybinds->kq) == 0)
	exit(0);
      else if (my_strcmp(buffer, keybinds->kd) == 0)
	{
	  while ((col = collision(map, &tetrimino, x, y + 1)) == 0)
	    y++;
	  put_in_map(map, &tetrimino, x, y);
	  display_map_tetris(map, tetris);
	  if (col == 2)
	    return (2);
	  else
	    return (1);
	}
      buffer[0] = '\0';
      buffer[1] = '\0';
      buffer[2] = '\0';
      buffer[3] = '\0';
      buffer[4] = '\0';
      buffer[5] = '\0';
      display_map_tetris(map, tetris);
      show_in_map(&tetrimino, x, y);
      refresh();
      usleep(tetris->sleep);
    }
  mode_non_canonique(1);
  return (0);
}
