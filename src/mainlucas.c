/*
** main.c for main in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue Feb 23 10:27:54 2016 Samuel
** Last update Wed Feb 24 13:32:41 2016 Lucas Villeneuve
*/

#include "my.h"
#include <ncurses.h>
#include <sys/ioctl.h>
#include <stdlib.h>

void			init_screen()
{
  SCREEN		*window;
  struct winsize	size;
  int			ch;
  int			i;

  window = newterm("xterm", stderr, stdin);
  set_term(window);
  clear();
  noecho();
  keypad(stdscr, TRUE);
  ioctl(0, TIOCGWINSZ, &size);
  check_winsz(&size);
  display_map();
  ch = 0;
  i = 2;
  while ((ch = getch) != 32)
    {
      usleep(500000);
      refresh();
      display_map();
      mvprintw(i++, 12, "*");
      if (i == 24)
	{
	  endwin();
	  exit(1);
	}
    }
  endwin();
}

int	main()
{
  /* test_time(5); /\*tu passes a test time le nmbr de mins *\/ */
  init_screen();
  return (0);
}
