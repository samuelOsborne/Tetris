/*
** fall_tetrimino.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Fri Mar  4 10:28:56 2016 Lucas Villeneuve
** Last update Sat Mar 19 14:26:46 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "my.h"
#include "get_next_line.h"

int	finish_fall(char **map, t_tetrimino *tetrimino,
		    t_tetris *tetris, int col)
{
  put_in_map(map, tetrimino, tetris->x, tetris->y);
  display_map_tetris(map, tetris);
  if (col == 2)
    return (2);
  else
    return (1);
}

int	fall_tetrimino2(char **map, t_tetrimino *tetrimino,
			t_keybinds *keybinds, t_tetris *tetris)
{
  int	col;

  if ((my_strcmp(keybinds->buffer, keybinds->kl) == 0)
      && collision(map, tetrimino, tetris->x - 1, tetris->y) == 0)
    tetris->x--;
  else if ((my_strcmp(keybinds->buffer, keybinds->kr) == 0)
	   && collision(map, tetrimino, tetris->x + 1, tetris->y) == 0)
    tetris->x++;
  else if (my_strcmp(keybinds->buffer, keybinds->kq) == 0)
    {
      endwin();
      exit(0);
    }
  else if (my_strcmp(keybinds->buffer, keybinds->kd) == 0)
    {
      while ((col = collision(map, tetrimino, tetris->x, tetris->y + 1)) == 0)
	tetris->y++;
      put_in_map(map, tetrimino, tetris->x, tetris->y);
      display_map_tetris(map, tetris);
      return (1);
    }
  pause_game(keybinds);
  return (0);
}

int	fall_tetrimino(char **map, t_tetris *t,
		       t_tetrimino *tetrimino, t_keybinds *keybinds)
{
  int	col;

  while (1)
    {
      menu(keybinds, t, tetrimino);
      if ((read(0, keybinds->buffer, 5) == -1))
	return (1);
      if ((col = collision(map, &tetrimino[t->tet], t->x, t->y + 1)) == 0)
	t->y++;
      else if (finish_fall(map, &tetrimino[t->tet], t, col) == 2)
	return (2);
      else
	return (1);
      fall_tetrimino2(map, &tetrimino[t->tet], keybinds, t);
      if (my_strcmp(keybinds->buffer, keybinds->kt) == 0
	  && collision(map, &tetrimino[t->tet], t->x, t->y) == 0)
	tetrimino[t->tet] = ini_rotate_tetrimino(tetrimino[t->tet],
						 map, t->x, t->y);
      my_memset(keybinds->buffer, 5);
      display_map_tetris(map, t);
      show_in_map(&tetrimino[t->tet], t->x, t->y);
      refresh();
      usleep(t->time_sleep);
    }
  return (0);
}
