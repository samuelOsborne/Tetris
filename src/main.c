/*
** main.c for main in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue Feb 23 10:27:54 2016 Samuel
** Last update Wed Feb 24 14:04:09 2016 Lucas Villeneuve
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

void	print_help()
{
  my_putstr("Usage: ./tetris [options]\nOptions:\n");
  my_putstr("  --help\t\tDisplay this help\n");
  my_putstr("  -l --level={num}\tStart Tetris at level num\n");
  my_putstr("  -kl --key-left={K}\tMove tetrimino on LEFT with key K\n");
  my_putstr("  -kr --key-right={K}\tMove tetrimino on RIGHT with key K\n");
  my_putstr("  -kt --key-turn={K}\tTurn tetrimino with key K\n");
  my_putstr("  -kd --key-drop={K}\tSet default DROP on key K\n");
  my_putstr("  -kq --key-quit={K}\tQuit program when press key K\n");
  my_putstr("  -kp --key-pause={K}\tPause and restart game when press key K\n");
  my_putstr("  --map-size={row,col}\tSet game size at row, col\n");
  my_putstr("  -w --without-next\tHide next tetrimino\n");
  my_putstr("  -d --debug\t\tDebug mode\n");
}

int	main(int argc, char **argv)
{
  int	i;

  i = 1;
  /* test_time(5); /\*tu passes a test time le nmbr de mins *\/ */
  while (i < argc)
    {
      if (my_strcmp(argv[i], "--help") == 0)
	  print_help();
      i++;
    }
  /* init_screen(); */
  return (0);
}
