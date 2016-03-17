/*
** write_to_keybind3.c for write_to_keybind3 in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Mar 14 10:53:32 2016 Samuel
** Last update Mon Mar 14 10:56:59 2016 Samuel
*/

#include "my.h"

void	put_help(t_keybinds *keybinds, char *word)
{
  keybinds->help = 1;
  put_void(word);
}
