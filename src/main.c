/*
** main.c for main in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue Feb 23 10:27:54 2016 Samuel
** Last update Sat Mar  5 23:20:07 2016 Samuel
*/

#include <ncurses.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "my.h"

void			init_screen(t_tetris *tetris, char **map, t_keybinds *keybinds)
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
  menu(keybinds);
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
  t_tetris	tetris;
  t_keybinds	keybinds;
  char		**map;

  i = 1;
  init_keybinds(&keybinds);
  if (argc != 1)
    compare_args_for_keybind(argc, argv, &keybinds);
  while (i < argc)
    {
      if (my_strcmp(argv[i], "--help") == 0)
	  print_help();
      if (my_strcmp(argv[i], "--debug") == 0 || my_strcmp(argv[i], "-d") == 0)
	debug_mode(&keybinds);
      i++;
    }
  tetris.map_width = keybinds.col;
  tetris.map_height = keybinds.row;
  map = create_map(&tetris);
  init_screen(&tetris, map, &keybinds);
  return (0);
}
