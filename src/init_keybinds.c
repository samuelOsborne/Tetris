/*
** init_keyboards.c for init_keyboard in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Feb 29 19:18:33 2016 Samuel
** Last update Wed Mar  9 13:48:11 2016 Samuel
*/

#include "my.h"
#include <stdlib.h>

void	init_keybinds(t_keybinds *keybinds)
{
  if ((keybinds->kl = malloc(sizeof(char) * 3)) == NULL)
    return (1);
  keybinds->kl[0] = 27;
  keybinds->kl[1] = 'O';
  keybinds->kl[2] = 'D';
  if ((keybinds->kr = malloc(sizeof(char) * 3)) == NULL)
    return (1);
  keybinds->kr[0] = 27;
  keybinds->kr[1] = 'O';
  keybinds->kr[2] = 'C';
  /* keybinds->kr = "^[OC"; */
  keybinds->kt = " ";
  keybinds->kd = "x";
  keybinds->kq = "q";
  keybinds->kp = "p";
  keybinds->next = 1;
  keybinds->level = 1;
  keybinds->row = 20;
  keybinds->col = 10;
  keybinds->debug = 0;
}
