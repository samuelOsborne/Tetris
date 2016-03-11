/*
** write_to_keybind.c for write_to_keybind in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Feb 29 17:49:25 2016 Samuel
** Last update Wed Mar  9 14:00:20 2016 Samuel
*/

#include "my.h"

void	put_left(t_keybinds *keybinds, char *word)
{
  if (word[0] == '^' && word[1] == '[')
    {
      keybinds->kl[0] = 27;
      keybinds->kl[1] = 'O';
      keybinds->kl[2] = word[3];
    }
  else 
    keybinds->kl = word;
}

void	put_right(t_keybinds *keybinds, char *word)
{
  if (word[0] == '^' &&word[1]== '[')
    {
      keybinds->kl[0] =27;
      keybinds->kl[1] = 'O';
      keybinds->kl[2] =word[3];
    }
  else
    keybinds->kr = word;
}

void	put_turn(t_keybinds *keybinds, char *word)
{
  if (word[0] == '^' &&word[1]== '[')
    {
      keybinds->kl[0] =27;
      keybinds->kl[1] = 'O';
      keybinds->kl[2] =word[3];
    }
  else
    keybinds->kt = word;
}

void	put_drop(t_keybinds *keybinds, char *word)
{
  if (word[0] == '^' &&word[1]== '[')
    {
      keybinds->kl[0] =27;
      keybinds->kl[1] = 'O';
      keybinds->kl[2] =word[3];
    }
  else
    keybinds->kd = word;
}

void	put_quit(t_keybinds *keybinds, char *word)
{
  if (word[0] == '^' &&word[1]== '[')
    {
      keybinds->kl[0] =27;
      keybinds->kl[1] = 'O';
      keybinds->kl[2] =word[3];
    }
  else
    keybinds->kq = word;
}
