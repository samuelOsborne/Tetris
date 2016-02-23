/*
** my_put_hexabig2.c for my_put_hexabig2 in /home/osborn_s/rendu/pointeur fonctions printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Fri Nov 13 11:13:40 2015 Samuel Osborne
** Last update Fri Nov 13 11:27:22 2015 Samuel Osborne
*/

#include <stdarg.h>

void	my_put_hexabig2(va_list list)
{
  unsigned int	number;

  number = (va_arg(list, unsigned int));
  my_put_hexabig(number);
}
