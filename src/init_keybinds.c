/*
** init_keyboards.c for init_keyboard in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Feb 29 19:18:33 2016 Samuel
** Last update Fri Mar 18 10:34:29 2016 Samuel
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"
#include <term.h>

void	init_keybinds3(t_keybinds *keybinds)
{
  char	*s;

  if ((keybinds->kd = malloc(sizeof(char) * 3)) == NULL)
    return ;
  s = tigetstr("kcud1");
  keybinds->kd[0] = s[0];
  keybinds->kd[1] = s[1];
  keybinds->kd[2] = s[2];
  keybinds->kd[3] = '\0';
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
  if ((keybinds->kl = malloc(sizeof(char) * 3)) == NULL)
    return ;
  s = tigetstr("kcub1");
  keybinds->kl[0] = s[0];
  keybinds->kl[1] = s[1];
  keybinds->kl[2] = s[2];
  keybinds->kl[3] = '\0';
  if ((keybinds->kr = malloc(sizeof(char) * 3)) == NULL)
    return ;
  s = tigetstr("kcuf1");
  keybinds->kr[0] = s[0];
  keybinds->kr[1] = s[1];
  keybinds->kr[2] = s[2];
  keybinds->kr[3] = '\0';
  if ((keybinds->kt = malloc(sizeof(char) * 3)) == NULL)
    return ;
  s = tigetstr("kcuu1");
  keybinds->kt[0] = s[0];
  keybinds->kt[1] = s[1];
  keybinds->kt[2] = s[2];
  keybinds->kt[3] = '\0';
  init_keybinds3(keybinds);
}
