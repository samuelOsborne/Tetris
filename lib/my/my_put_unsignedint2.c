/*
** my_put_unsignedint2.c for my_put_unsignedint2 in /home/osborn_s/rendu/pointeur fonctions printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Fri Nov 13 11:23:25 2015 Samuel Osborne
** Last update Fri Nov 13 11:28:51 2015 Samuel Osborne
*/

#include <stdarg.h>

void	my_put_unsignedint2(va_list list)
{
  unsigned int nb;

  nb = (va_arg(list, int));
  my_put_unsignedint(nb);
}
