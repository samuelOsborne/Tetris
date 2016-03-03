/*
** main.c for main in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue Feb 23 10:27:54 2016 Samuel
** Last update Thu Mar  3 15:07:02 2016 Lucas Villeneuve
*/

#include <ncurses.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "my.h"

void			init_screen(t_tetris *tetris, char **map)
{
  SCREEN		*window;
  struct winsize	size;
 
  window = newterm("xterm", stderr, stdin);
  set_term(window);
  clear();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(false);
  cbreak();
  timeout(100);
  ioctl(0, TIOCGWINSZ, &size);
  check_winsz(&size);
  fall_letter(map, tetris);
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

int		main(int argc, char **argv)
{
  int		i;
  t_tetris	*tetris;
  char		**map;

  if ((tetris = malloc(sizeof(t_tetris))) == NULL)
    return (1);
  tetris->map_width = 10;
  tetris->map_height = 20;
  i = 1;
  while (i < argc)
    {
      if (my_strcmp(argv[i], "--help") == 0)
	  print_help();
      if (my_strcmp(argv[i], "--debug") == 0 || my_strcmp(argv[i], "-d") == 0)
	debug_mode(tetris);
      i++;
    }
  map = create_map(tetris);
  init_screen(tetris, map);
  return (0);
}
