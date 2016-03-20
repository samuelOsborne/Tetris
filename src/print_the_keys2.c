/*
** print_the_keys2.c for print_the_keys2 in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Mar  7 11:24:07 2016 Samuel
** Last update Sun Mar 20 16:40:12 2016 Samuel Osborne
*/

#include "my.h"

void		check_and_print_keysl(t_keybinds *keybinds)
{
  if (keybinds->kl[0] == 27)
    my_printf("Key Left : %s%c%c\n", "^E", keybinds->kl[1], keybinds->kl[2]);
  else if (my_strcmp(keybinds->kl, " ") == 0)
    my_printf("Key Left : (space)\n");
  else
    my_printf("Key Left : %s\n", keybinds->kl);
}
