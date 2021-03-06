/*
** menu.c for menu in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Feb 29 22:07:59 2016 Samuel
** Last update Sat Mar 19 14:02:26 2016 Lucas Villeneuve
*/

#include <ncurses.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "my.h"

int		print_tetris()
{
  if (has_colors() == FALSE)
    return (1);
  start_color();
  mvprintw(1, 5, "***** **** ***** ***** ***** ****");
  mvprintw(2, 5, "  *   *      *   *   *   *   *");
  mvprintw(3, 5, "  *   ****   *   *****   *   ****");
  mvprintw(4, 5, "  *   *      *   *  *    *      *");
  mvprintw(5, 5, "  *   ****   *   *   * ***** ****");
  return (0);
}

void	show_next_in_map(t_tetrimino *tetrimino)
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
	      init_pair(10, tetrimino->color, 0);
	      attron(COLOR_PAIR(10));
	      mvprintw(i + 20, j + 24, "%c", tetrimino->piece[i][j]);
	      attroff(COLOR_PAIR(10));
	    }
	  j++;
	}
      i++;
    }
}

void		print_next(t_tetris *tetris, t_tetrimino *tetrimino)
{
  int		y;
  int		x;

  y = 19;
  mvprintw(18, 23, "+--------+");
  mvprintw(24, 23, "+--------+");
  mvprintw(19, 24, "Next");
  while (y != 24)
    {
      mvprintw(y, 23, "|");
      x = 24;
      if (y != 19)
	while (x != 31)
	  mvprintw(y, x++, " ");
      mvprintw(y, 32, "|");
      y++;
    }
  show_next_in_map(&tetrimino[tetris->next]);
}

void		print_lines(t_keybinds *keybinds, t_tetris *tetris)
{
  mvprintw(7, 8, "High Score");
  printw("         %d", tetris->high_score);
  mvprintw(8, 8, "Score");
  printw("              %d", tetris->score);
  mvprintw(10, 8, "Lines");
  printw("              %d", tetris->nb_lines);
  mvprintw(11, 8, "Level");
  printw("              %d", keybinds->level);
}

void		menu(t_keybinds *keybinds, t_tetris *tetris, t_tetrimino *tet)
{
  char		*top;
  char		*side;
  int		y;

  if (tetris->checker == 10)
    {
      keybinds->level++;
      tetris->time_sleep -= 100;
      tetris->checker = 0;
    }
  print_tetris();
  if (keybinds->next == 1)
    print_next(tetris, tet);
  y = 7;
  top = "+--------------------------+";
  side = "|";
  mvprintw(6, 5, top);
  mvprintw(17, 5, top);
  while (y != 17)
    {
      mvprintw(y, 5, side);
      mvprintw(y, 32, side);
      y++;
    }
  print_lines(keybinds, tetris);
}
