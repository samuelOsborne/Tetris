/*
** debug.c for tetri in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon Feb 29 16:12:27 2016 Lucas Villeneuve
** Last update Fri Mar 11 14:00:25 2016 Samuel
*/

#include <termios.h>
#include <stdlib.h>
#include <dirent.h>
#include "my.h"

void		print_the_keys(t_keybinds *keybinds)
{
  /* check_and_print_keysl(keybinds); */
  /* check_and_print_keysr(keybinds); */
  /* check_and_print_keyst(keybinds); */
  /* check_and_print_keysd(keybinds); */
  /* check_and_print_keysq(keybinds); */
  /* check_and_print_keysp(keybinds); */
  my_printf("Key Left : %s\n", keybinds->kl);
  my_printf("Key Right : %s\n", keybinds->kr);
  my_printf("Key Turn : %s\n", keybinds->kt);
  my_printf("Key Drop : %s\n", keybinds->kd);
  my_printf("Key Quit : %s\n", keybinds->kq);
  my_printf("Key Pause :%s\n", keybinds->kp);
  (keybinds->next == 0) ? my_printf("Next : No\n") : my_printf("Next : Yes\n");
  my_printf("Level : %d\n", keybinds->level);
  my_printf("Size : %d*%d\n", keybinds->row, keybinds->col);
}

t_tetrimino	*ini_load(t_tetris *tetris)
{
  DIR		*dir;
  struct dirent	*ent;
  int		i;
  t_tetrimino	*tetrimino;

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
  tetrimino = load_tetrimino(i, false, tetris);
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

t_tetrimino	*debug_mode(t_tetris *tetris, t_keybinds *keybinds)
{
  DIR		*dir;
  struct dirent	*ent;
  int		i;
  char		buffer[1];
  t_tetrimino	*tetrimino;

  my_putstr("*** DEBUG MODE ***\n");
  print_the_keys(keybinds);
  my_printf("Size : %d*%d\n", tetris->map_height, tetris->map_width);
  i = 0;
  if ((dir = opendir("tetriminos")) != NULL)
    {
      while ((ent = readdir(dir)) != NULL)
	if (ent->d_name[0] != '.' && (take_name(ent->d_name, ".tetrimino") != NULL))
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
  tetrimino = load_tetrimino(i, true, tetris);
  my_putstr("Press a key to start Tetris\n");
  mode_non_canonique2(0);
  if (read(0, buffer, 1) == -1)
    return (1);
  mode_non_canonique2(1);
  return (tetrimino);
}
