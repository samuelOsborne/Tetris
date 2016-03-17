/*
** map_size_detect.c for map_size_detect in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Thu Mar  3 16:53:02 2016 Samuel
** Last update Thu Mar 17 20:46:49 2016 Samuel
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
  tmp[j] = '\0';
  keybinds->row = my_getnbr(tmp);
  i++;
  map_size_col(tmp, a, keybinds, i);
  return (0);
}

void		return_char(char a, char *c, t_keybinds *keybinds)
{
  char		b;
  int		tok;

  tok = 0;
  if (a == 'w' && (my_strcmp(c, "--without-next") == 0))
    {
      b = 'w';
      tok = 1;
    }
  if (a == 'd' && (my_strcmp(c, "--debug") == 0))
    {
      b = 'D';
      tok = 1;
    }
  if (a == 'h' && (my_strcmp(c, "--help") == 0))
    {
      b = 'h';
      tok = 1;
    }
  if (tok == 1)
    get_key_bind(b, keybinds, "lol");
  else
    error(c, keybinds);
}
