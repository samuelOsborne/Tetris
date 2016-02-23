/*
** my_put_nbr2.c for my_put_nbr2 in /home/osborn_s/rendu/pointeur fonctions printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Thu Nov 12 23:29:13 2015 Samuel Osborne
** Last update Fri Nov 13 11:27:42 2015 Samuel Osborne
*/

#include <stdarg.h>

void	my_put_nbr2(va_list list)
{
  int	nb;

  nb = va_arg(list, int);
  my_put_nbr(nb);
}
