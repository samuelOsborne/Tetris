/*
** check_and_ret.c for check_and_ret in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Sat Mar 19 18:17:07 2016 Samuel
** Last update Sat Mar 19 18:29:07 2016 Samuel
*/

#include "my.h"

int		check_and_ret(char *a)
{
  if (my_strcmp2(a, "--key-left=", 10) == 0)
    return (0);
  if (my_strcmp2(a, "--key-right=", 11) == 0)
    return (0);
  if (my_strcmp2(a, "--key-turn=", 10) == 0)
    return (0);
  if (my_strcmp2(a, "--key-drop=", 10) == 0)
    return (0);
  if (my_strcmp2(a, "--key-quit=", 10) == 0)
    return (0);
  if (my_strcmp2(a, "--key-pause=", 11) == 0)
    return (0);
  return (1);
}
