/*
** menu.c for menu in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Feb 29 22:07:59 2016 Samuel
** Last update Sat Mar  5 23:04:42 2016 Samuel
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
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  mvprintw(1, 5, "*** **** *** **** * ***");
  mvprintw(2, 5, " *  *     *  *  *   *");
  mvprintw(3, 5, " *  ****  *  **   * ***");
  mvprintw(4, 5, " *  *     *  * *  *   *");
  mvprintw(5, 5, " *  ****  *  *  * * ***");
  attroff(COLOR_PAIR(1));
  return (0);
}

void		print_lines(t_keybinds *keybinds)
{
  char		*high_score;
  char		*scorec;
  char		*lines;
  char		*level;
  char		*timer;
  t_highscore	score;

  score.high_score = 0;
  score.score = 0;
  lines = "lines";
  level = "level";
  high_score = "High Score";
  scorec = "score";
  timer = "timer";
  mvprintw(10, 8, high_score);
  printw("         %d", score.high_score);
  mvprintw(11, 8, scorec);
  printw("              %d", score.score);
  mvprintw(14, 8, lines);
  mvprintw(15, 8, level);
  printw("              %d", keybinds->level);
  mvprintw(18, 8, timer);
}

void	menu(t_keybinds *keybinds)
{
  char	*top;
  char	*side;
  int	y;

  print_tetris();
  y = 10;
  top = "+--------------------------+";
  side = "|";
  mvprintw(9, 5, top);
  mvprintw(20, 5, top);
  while (y != 20)
    {
      mvprintw(y, 5, side);
      mvprintw(y, 32, side);
      y++;
    }
  print_lines(keybinds);
}
