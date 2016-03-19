/*
** write_to_keybind2.c for write_to_keybind2 in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Feb 29 17:51:01 2016 Samuel
** Last update Sat Mar 19 14:46:13 2016 Lucas Villeneuve
*/

#include "my.h"

void	put_pause(t_keybinds *keybinds, char *word)
{
  if (word[0] == '^' && word[1] == '[')
    {
      keybinds->kp[0] = 27;
      keybinds->kp[1] = word[2];
      keybinds->kp[2] = word[3];
    }
  else
    keybinds->kp = word;
}

void	put_next(t_keybinds *keybinds, char *word)
{
  char	*a;

  a = word;
  put_void(a);
  keybinds->next = 0;
}

char	*put_void(char *a)
{
  return (a);
}

void	put_level(t_keybinds *keybinds, char *word)
{
  keybinds->level = my_getnbr(word);
}

void	put_debug(t_keybinds *keybinds, char *word)
{
  char	*a;

  a = word;
  put_void(a);
  keybinds->debug = 1;
}
