/*
** my_put_pointer2.c for my_put_pointer2 in /home/osborn_s/rendu/pointeur fonctions printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Fri Nov 13 11:19:24 2015 Samuel Osborne
** Last update Fri Nov 13 15:18:28 2015 Samuel Osborne
*/

#include <stdarg.h>

void	my_put_pointer2(va_list list)
{
  long int	number;

  number = (va_arg(list, int));
  my_put_pointer(number);
}
