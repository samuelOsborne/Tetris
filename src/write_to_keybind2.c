/*
** write_to_keybind2.c for write_to_keybind2 in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Feb 29 17:51:01 2016 Samuel
** Last update Thu Mar  3 19:00:34 2016 Samuel
*/

#include "my.h"

void	put_pause(t_keybinds *keybinds, char word)
{
  keybinds->kp = word;
}

void	put_next(t_keybinds *keybinds, char word)
{
  char	a;

  a = word;
  put_void(a);
  keybinds->next = 0;
}

char	put_void (char a)
{
  return (a);
}

void	put_level(t_keybinds *keybinds, char word)
{
  keybinds->level = word;
}

void	put_debug(t_keybinds *keybinds, char word)
{
  char	a;

  a = word;
  put_void(a);
  keybinds->debug = 1;
}
