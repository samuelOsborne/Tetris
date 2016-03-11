/*
** main.c for main in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue Feb 23 10:27:54 2016 Samuel
** Last update Fri Mar 11 09:27:42 2016 Samuel
*/

#include <ncurses.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "my.h"

int			get_input(t_keybinds *keybinds, int j)
{
  char			buffer[5];

  buffer[0] = '\0';
  buffer[1] = '\0';
  buffer[2] = '\0';
  buffer[3] = '\0';
  buffer[4] = '\0';
  buffer[5] = '\0';
  if ((read(0, buffer, 5)) == 0)
    return (1);
  if ((my_strcmp(buffer, keybinds->kl)) == 0 && j > 1)
    j--;
  else if ((my_strcmp(buffer, keybinds->kr)) == 0)
    j++;
  return (j);
}

void			init_screen(t_tetris *tetris, char **map, t_tetrimino *tetrimino, t_keybinds *keybinds)
{
  SCREEN		*window;
  struct winsize	size;
  /* t_highscore		score; */
 
  tetris->high_score = 0;
  tetris->score = 0;
  window = newterm("xterm", stderr, stdin);
  set_term(window);
  initscr();
  clear();
  noecho();
  start_color();
  nodelay(stdscr, true);
  keypad(stdscr, true);
  curs_set(false);
  ioctl(0, TIOCGWINSZ, &size);
  check_winsz(&size);
  loop_game(map, tetris, tetrimino, keybinds);
  endwin();
}

void	print_help(char *str)
{
  my_printf("Usage: %s [options]\nOptions:\n", str);
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
  t_tetrimino	*tetrimino;
  bool		debug;
  t_keybinds	keybinds;

  init_keybinds(&keybinds);
  if (argc != 1)
    compare_args_for_keybind(argc, argv, &keybinds);
  if ((tetris = malloc(sizeof(t_tetris))) == NULL)
    return (1);
  tetris->map_width = keybinds.col;
  tetris->map_height = keybinds.row;
  debug = false;
  i = 1;
  while (i < argc)
    {
      if (my_strcmp(argv[i], "--help") == 0)
	{
	  print_help(argv[0]);
	  return (1);
	}
      if (my_strcmp(argv[i], "--debug") == 0 || my_strcmp(argv[i], "-d") == 0)
	debug = true;
      i++;
    }
  if (debug == true)
    tetrimino = debug_mode(tetris, &keybinds);
  else
    tetrimino = ini_load(tetris);
  map = create_map(tetris);
  init_screen(tetris, map, tetrimino, &keybinds);
  return (0);
}
