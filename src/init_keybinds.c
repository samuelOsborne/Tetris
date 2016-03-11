/*
** init_keyboards.c for init_keyboard in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Feb 29 19:18:33 2016 Samuel
** Last update Fri Mar 11 17:48:23 2016 Samuel
*/

#include "my.h"
#include <stdlib.h>

void	init_keybinds2(t_keybinds *keybinds)
{
  keybinds->kq[0] = 'q';
  if ((keybinds->kp = malloc(sizeof(char) * 3)) == NULL)
    return ;
  keybinds->kp[0] = 'p';
  keybinds->next = 1;
  keybinds->level = 1;
  keybinds->row = 20;
  keybinds->col = 10;
  keybinds->debug = 0;
}

void	init_keybinds(t_keybinds *keybinds)
{
  if ((keybinds->kl = malloc(sizeof(char) * 3)) == NULL)
    return ;
  keybinds->kl[0] = 27;
  keybinds->kl[1] = 'O';
  keybinds->kl[2] = 'D';
  if ((keybinds->kr = malloc(sizeof(char) * 3)) == NULL)
    return ;
  keybinds->kr[0] = 27;
  keybinds->kr[1] = 'O';
  keybinds->kr[2] = 'C';
  if ((keybinds->kt = malloc(sizeof(char) * 3)) == NULL)
    return ;
  keybinds->kt[0] = 27;
  keybinds->kt[1] = 'O';
  keybinds->kt[2] = 'A';
  if ((keybinds->kd = malloc(sizeof(char) * 3)) == NULL)
    return ;
  keybinds->kd[0] = 27;
  keybinds->kd[1] = 'O';
  keybinds->kd[2] = 'B';
  if ((keybinds->kq = malloc(sizeof(char) * 3)) == NULL)
    return ;
  init_keybinds2(keybinds);
}
