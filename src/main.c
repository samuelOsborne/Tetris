/*
** main.c for main in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue Feb 23 10:27:54 2016 Samuel
** Last update Sat Mar 19 15:10:43 2016 Samuel
*/

#include <ncurses.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <term.h>
#include "my.h"

void			init_screen(t_tetris *tetris, t_keybinds *keybinds)
{
  struct winsize	size;

  tetris->time_sleep = 125000 / keybinds->level;
  tetris->checker = 0;
  tetris->high_score = 0;
  tetris->score = 0;
  initscr();
  mode_non_canonique(0);
  clear();
  noecho();
  start_color();
  keypad(stdscr, true);
  curs_set(false);
  ioctl(0, TIOCGWINSZ, &size);
  check_winsz(&size, tetris);
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
  exit(1);
}

void		init_game(t_tetris *tetris, t_keybinds *keybinds)
{
  int		i;
  char		**map;
  t_tetrimino	*tetrimino;

  tetris->map_width = keybinds->col;
  tetris->map_height = keybinds->row;
  if (keybinds->debug == 1)
    tetrimino = debug_mode(tetris, keybinds);
  else
    tetrimino = ini_load(tetris);
  i = 0;
  while (i < tetris->nb)
    {
      if (tetrimino[i].width > tetris->map_width || tetrimino[i].height > tetris->map_height)
	{
	  my_printf("%s got value higher than the map\n", tetrimino[i].name);
	  exit(1);
	}
      i++;
    }
  map = create_map(tetris);
  init_screen(tetris, keybinds);
  loop_game(map, tetris, tetrimino, keybinds);
}

int		main(int argc, char **argv, char **ae)
{
  t_tetris	*tetris;
  t_keybinds	keybinds;

  keybinds.term = NULL;
  check_env(ae, &keybinds);
  if (keybinds.term == NULL)
    error_env();
  keybinds.av = argv[0];
  if ((tetris = malloc(sizeof(t_tetris))) == NULL)
    return (1);
  init_keybinds(&keybinds);
  if (argc != 1)
    compare_args_for_keybind(argc, argv, &keybinds);
  if (keybinds.help == 1)
    {
      print_help(argv[0]);
      endwin();
      exit(0);
    }  
  init_game(tetris, &keybinds);
  return (0);
}
