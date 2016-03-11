/*
** menu.c for menu in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Feb 29 22:07:59 2016 Samuel
** Last update Fri Mar 11 09:34:14 2016 Samuel
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
  mvprintw(1, 5, "*** **** *** **** * ***");
  mvprintw(2, 5, " *  *     *  *  *   *");
  mvprintw(3, 5, " *  ****  *  **** * ***");
  mvprintw(4, 5, " *  *     *  * *  *   *");
  mvprintw(5, 5, " *  ****  *  *  * * ***");
  return (0);
}

void		print_next()
{
  int		y;

  y = 19;
  mvprintw(18, 23, "+--------+");
  mvprintw(24, 23, "+--------+");
  mvprintw(19, 24, "Next");
  while (y != 24)
    {
      mvprintw(y, 23, "|");
      mvprintw(y, 32, "|");
      y++;
    }
}

void		print_lines(t_keybinds *keybinds, t_tetris *tetris)
{
  char		*high_score;
  char		*scorec;
  char		*lines;
  char		*level;
  char		*timer;

  lines = "lines";
  level = "level";
  high_score = "High Score";
  scorec = "score";
  timer = "timer";
  mvprintw(7, 8, high_score);
  printw("         %d", tetris->high_score);
  mvprintw(8, 8, scorec);
  printw("              %d", tetris->score);
  mvprintw(10, 8, lines);
  printw("              %d", tetris->lines);
  mvprintw(11, 8, level);
  printw("              %d", keybinds->level);
  mvprintw(13, 8, timer);
}

void		menu(t_keybinds *keybinds, t_tetris *tetris)
{
  char		*top;
  char		*side;
  int		y;

  print_tetris();
  if (keybinds->next == 1)
    print_next();
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