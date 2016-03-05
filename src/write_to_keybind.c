/*
** write_to_keybind.c for write_to_keybind in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Feb 29 17:49:25 2016 Samuel
** Last update Mon Feb 29 20:57:29 2016 Samuel
*/

#include "my.h"

void	put_left(t_keybinds *keybinds, char word)
{
  keybinds->kl = word;
}

void	put_right(t_keybinds *keybinds, char word)
{
  keybinds->kr = word;
}

void	put_turn(t_keybinds *keybinds, char word)
{
  keybinds->kt = word;
}

void	put_drop(t_keybinds *keybinds, char word)
{
  keybinds->kd = word;
}

void	put_quit(t_keybinds *keybinds, char word)
{
  keybinds->kq = word;
}
