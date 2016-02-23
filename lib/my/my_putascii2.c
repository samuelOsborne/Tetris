/*
** my_putascii2.c for my_putascii2 in /home/osborn_s/rendu/pointeur fonctions printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Fri Nov 13 11:06:31 2015 Samuel Osborne
** Last update Fri Nov 13 11:13:08 2015 Samuel Osborne
*/

#include <stdarg.h>

void	my_putascii2(va_list list)
{
  char	*str;
  
  str = (va_arg(list, char *));
  my_putascii(str);
}
