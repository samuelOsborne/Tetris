/*
** print_the_keys2.c for print_the_keys2 in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Mar  7 11:24:07 2016 Samuel
** Last update Tue Mar  8 14:40:32 2016 Samuel
*/

#include "my.h"

void		check_and_print_keysl(t_keybinds *keybinds)
{
  if (keybinds->kl == 260)
    my_printf("Key Left : ^EOD\n");
  else if (keybinds->kl == 261)
    my_printf("Key Left : ^EOC\n");
  else if (keybinds->kl == 259)
    my_printf("Key Left : ^EOA\n");
  else if (keybinds->kl == 27)
    my_printf("Key Left : ^E\n");
  else if (keybinds->kl == 32)
    my_printf("Key Right : (space)\n");
  else
    my_printf("Key Left : %c\n", keybinds->kl);
}
