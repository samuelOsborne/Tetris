/*
** fall_tetrimino.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Fri Mar  4 10:28:56 2016 Lucas Villeneuve
** Last update Fri Mar 11 10:12:07 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
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

int	fall_tetrimino(char **map, t_tetris *tetris, t_tetrimino tetrimino, t_keybinds *keybinds) /* maybe pass to display the size of the map from keybinds instead of char **map? */
{
  int	x;
  int	y;
  int	ch;
  int	col;

  y = 1;
  x = 5;
  while (1)
    {
      menu(keybinds, tetris);
      ch = getch();
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
      if (ch == 260 && collision(map, &tetrimino, x - 1, y) == 0)
	x--;
      else if (ch == 261 && collision(map, &tetrimino, x + 1, y) == 0)
	x++;
      else if (ch == 259)
	tetrimino = ini_rotate_tetrimino(tetrimino, map, x, y);
      else if (ch == 100)
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
      display_map_tetris(map, tetris);
      show_in_map(&tetrimino, x, y);
      refresh();
      usleep(75000);
    }
  return (0);
}
