/*
** move_block.c for move_block in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Wed Feb 24 18:50:44 2016 Samuel
** Last update Wed Feb 24 18:54:57 2016 Samuel
*/

#include "my.h"

void		move_block(int left, int right, int up)
{
  int		i;

  i = 30;
  while (i != 0)
    {
      mvprintw(i, 0, "|");
      i--;
    }
}
