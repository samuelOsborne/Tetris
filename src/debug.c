/*
** debug.c for tetri in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon Feb 29 16:12:27 2016 Lucas Villeneuve
** Last update Thu Mar 10 19:58:21 2016 Samuel
*/

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
  my_printf("%s\n", keybinds->kl);
  my_printf("%s\n", keybinds->kr);
  my_printf("%s\n", keybinds->kt);
  my_printf("%s\n", keybinds->kd);
  my_printf("%s\n", keybinds->kq);
  my_printf("%s\n", keybinds->kp);
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

t_tetrimino	*debug_mode(t_tetris *tetris, t_keybinds *keybinds)
{
  DIR		*dir;
  struct dirent	*ent;
  int		i;
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
  getchar();
  return (tetrimino);
}
