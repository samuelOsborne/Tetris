/*
** init_keyboards.c for init_keyboard in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Feb 29 19:18:33 2016 Samuel
** Last update Sat Mar  5 23:21:09 2016 Samuel
*/

#include "my.h"

void	init_keybinds(t_keybinds *keybinds)
{
  keybinds->kl = 260;
  keybinds->kr = 261;
  keybinds->kt = 259;
  keybinds->kd = 0;
  keybinds->kq = 27;
  keybinds->kp = 32;
  keybinds->next = 1;
  keybinds->level = 1;
  keybinds->row = 25;
  keybinds->col = 10;
  keybinds->debug = 0;
}
