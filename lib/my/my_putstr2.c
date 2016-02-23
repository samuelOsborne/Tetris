/*
** my_putstr2.c for my_putstr2 in /home/osborn_s/rendu/pointeur fonctions printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Thu Nov 12 23:27:55 2015 Samuel Osborne
** Last update Sat Nov 14 12:26:56 2015 Samuel Osborne
*/

#include <stdarg.h>
#include <stdlib.h>

int	my_putstr2(va_list list)
{
  char	*format;

  format = va_arg(list, char *);
  if (format == NULL)
    {
      my_putstr("(null)");
      return (1);
    }
  my_putstr(format);
}
