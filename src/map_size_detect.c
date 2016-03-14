/*
** map_size_detect.c for map_size_detect in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Thu Mar  3 16:53:02 2016 Samuel
** Last update Mon Mar 14 08:43:01 2016 Samuel
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int		map_size_detect(char *a, t_keybinds *keybinds)
{
  int		i;
  int		j;
  char		*tmp;

  j = 0;
  i = 0;
  if ((tmp = malloc(sizeof(char) * my_strlen(a))) == NULL)
    return (1);
  while (a[i] != '=' && a[i] != '\0')
    i++;
  i++;
  while (a[i] != ',' && a[i] != '\0')
    {
      if (a[i] >= 48 && a[i] <= 57)
        {
          tmp[j] = a[i];
          j++;
        }
      i++;
    }
  keybinds->row = my_getnbr(tmp);
  i++;
  map_size_col(tmp, a, keybinds, i);
  return (0);
}

char		return_char(char a)
{
  char		b;

  if (a == 'w')
    b = 'w';
  if (a == 'd')
    b = 'D';
  return (b);
}
