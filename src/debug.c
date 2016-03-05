/*
** debug.c for tetri in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon Feb 29 16:12:27 2016 Lucas Villeneuve
** Last update Sat Mar  5 23:23:42 2016 Samuel
*/

#include <stdlib.h>
#include <dirent.h>
#include <ncurses.h>
#include "my.h"

void		print_the_keys(t_keybinds *keybinds)
{
  my_printf("Key Left : %d\n", keybinds->kl);
  my_printf("Key Right : %d\n", keybinds->kr);
  my_printf("Key Turn : %d\n", keybinds->kt);
  my_printf("Key Drop : %d\n", keybinds->kd);
  my_printf("Key Quit : %d\n", keybinds->kq);
  my_printf("Key Pause : %d\n", keybinds->kp);
  (keybinds->next == 0) ? my_printf("Next : No\n") : my_printf("Next : Yes\n");
  my_printf("Level : %d\n", keybinds->level);
  my_printf("Size : %d*%d\n", keybinds->col, keybinds->row);
}

void		debug_mode(t_keybinds *keybinds)
{
  DIR		*dir;
  struct dirent	*ent;
  int		i;

  i = 0;
  my_putstr("*** DEBUG MODE ***\n");
  print_the_keys(keybinds);
  if ((dir = opendir("tetrimino")) != NULL)
    {
      while ((ent = readdir(dir)) != NULL)
	if (ent->d_name[0] != '.')
	  i++;
      closedir(dir);
    }
  else
    my_putstr("Error\n");
  my_printf("Tetriminos : %d\n", i);
  load_tetrimino();
  my_putstr("Press a key to start Tetris\n");
  getchar();
}
