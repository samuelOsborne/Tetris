/*
** debug.c for tetri in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon Feb 29 16:12:27 2016 Lucas Villeneuve
** Last update Sat Mar 19 14:19:02 2016 Lucas Villeneuve
*/

#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <dirent.h>
#include "my.h"

void		print_the_keys(t_keybinds *keybinds, t_tetris *tetris)
{
  my_putstr("*** DEBUG MODE ***\n");
  check_and_print_keysl(keybinds);
  check_and_print_keysr(keybinds);
  check_and_print_keyst(keybinds);
  check_and_print_keysd(keybinds);
  check_and_print_keysq(keybinds);
  check_and_print_keysp(keybinds);
  (keybinds->next == 0) ? my_printf("Next : No\n") : my_printf("Next : Yes\n");
  my_printf("Level : %d\n", keybinds->level);
  if (tetris->map_height < 10 || tetris->map_width < 10)
    {
      my_printf("Size : Error\n");
      exit(1);
    }
  my_printf("Size : %d*%d\n", tetris->map_height, tetris->map_width);
}

t_tetrimino	*ini_load(t_tetris *tetris)
{
  DIR		*dir;
  struct dirent	*ent;
  int		i;
  t_tetrimino	*tetrimino;

  if (tetris->map_height < 10 || tetris->map_width < 10)
    exit(1);
  i = 0;
  if ((dir = opendir("tetriminos")) != NULL)
    {
      while ((ent = readdir(dir)) != NULL)
	if (ent->d_name[0] != '.')
	  i++;
      closedir(dir);
    }
  else
    exit(1);
  if (i < 1)
    exit(1);
  tetrimino = load_tetrimino(i, false, tetris, 0);
  if ((tetrimino = print_tetriminos(tetris, tetrimino, false)) == NULL)
    return (NULL);
  return (tetrimino);
}

int		mode_non_canonique2(int i)
{
  static struct termios oldT;
  static struct termios newT;

  if (i == 0)
    {
      if (ioctl(0, TCGETS, &oldT) < 0)
        return (1);
      if (ioctl(0, TCGETS, &newT) < 0)
        return (1);
      newT.c_lflag &= ~ECHO;
      newT.c_lflag &= ~ICANON;
      newT.c_cc[VMIN] = 1;
      ioctl(0, TCSETS, &newT);
    }
  if (i == 1)
    if ((ioctl(0, TCSETS, &oldT)) < 0)
      return (1);
  return (0);
}

int		count_tetriminos()
{
  DIR		*dir;
  struct dirent	*ent;
  int		i;

  i = 0;
  if ((dir = opendir("tetriminos")) != NULL)
    {
      while ((ent = readdir(dir)) != NULL)
	if (ent->d_name[0] != '.'
	    && (take_name(ent->d_name, ".tetrimino") != NULL))
	  i++;
      closedir(dir);
    }
  else
    {
      my_putstr("Error load directory tetrimino\n");
      exit(1);
    }
  my_printf("Tetriminos : %d\n", i);
  if (i < 1)
    {
      my_putstr("Not enough tetriminos\n");
      exit(1);
    }
  return (i);
}

t_tetrimino	*debug_mode(t_tetris *tetris, t_keybinds *keybinds)
{
  int		i;
  char		buffer;
  t_tetrimino	*tetrimino;

  print_the_keys(keybinds, tetris);
  i = count_tetriminos();
  tetrimino = load_tetrimino(i, true, tetris, 0);
  sort_tetrimino(tetrimino, tetris->nb);
  if ((tetrimino = print_tetriminos(tetris, tetrimino, true)) == NULL)
    return (NULL);
  my_putstr("Press a key to start Tetris\n");
  mode_non_canonique2(0);
  if (read(0, &buffer, 1) == -1)
    return (NULL);
  mode_non_canonique2(1);
  return (tetrimino);
}
