/*
** reset.c for reset in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Thu Mar 17 20:07:55 2016 Samuel
** Last update Thu Mar 17 20:08:50 2016 Samuel
*/

#include "my.h"

void		my_reset(char *a)
{
  int		i;

  i = 0;
  while (a[i])
    {
      a[i] = 0;
      i++;
    }
}

void		check_if_correct(char *tmp, t_keybinds *keybinds, int i)
{
  tmp[i] = '\0';
  if (my_strcmp(tmp, "--level=") != 0)
    error(tmp, keybinds);
}
