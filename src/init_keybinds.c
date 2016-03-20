/*
** init_keyboards.c for init_keyboard in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Feb 29 19:18:33 2016 Samuel
** Last update Sun Mar 20 17:58:55 2016 Samuel
*/

#include <stdlib.h>
#include <ncurses.h>
#include <term.h>
#include "my.h"

void	init_keybinds3(t_keybinds *keybinds)
{
  char	*s;

  s = tigetstr("kcud1");
  keybinds->kd = s;
  if ((keybinds->kq = malloc(sizeof(char) * 3)) == NULL)
    return ;
  init_keybinds2(keybinds);
}

void	init_keybinds2(t_keybinds *keybinds)
{
  keybinds->kq[0] = 'q';
  keybinds->kq[1]= '\0';
  if ((keybinds->kp = malloc(sizeof(char) * 3)) == NULL)
    return ;
  keybinds->kp[0] = ' ';
  keybinds->kp[1] = '\0';
  keybinds->next = 1;
  keybinds->level = 1;
  keybinds->row = 20;
  keybinds->col = 10;
  keybinds->debug = 0;
  keybinds->help = 0;
}

void	init_keybinds(t_keybinds *keybinds)
{
  char	*s;

  check_term(keybinds->term);
  s = tigetstr("kcub1");
  keybinds->kl = s;
  s = tigetstr("kcuf1");
  keybinds->kr = s;
  s = tigetstr("kcuu1");
  keybinds->kt = s;
  init_keybinds3(keybinds);
}
