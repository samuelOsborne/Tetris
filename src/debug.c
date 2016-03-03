/*
** debug.c for tetri in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon Feb 29 16:12:27 2016 Lucas Villeneuve
** Last update Tue Mar  1 13:01:52 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <dirent.h>
#include "my.h"

void		debug_mode()
{
  DIR		*dir;
  struct dirent	*ent;
  int		i;
  t_tetris	tetris;

  my_putstr("*** DEBUG MODE ***\n");

  my_printf("Size : %d*%d\n", tetris.map_height, tetris.map_width);

  i = 0;
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
