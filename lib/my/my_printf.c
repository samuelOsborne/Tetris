/*
** my_printf.c for my_printf in /home/osborn_s/rendu/PSU_2015_my_printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Wed Nov  4 15:25:52 2015 Samuel Osborne
** Last update Sat Nov 14 12:24:03 2015 Samuel Osborne
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int	pointer(va_list ap, char h)
{
  void (*tab[11])(va_list);
  int	i;
  char *str;

  str = "SbcxXdiopsu";
  i = 0;
  tab[0] = &my_putascii2;
  tab[1] = &my_put_binaire2;
  tab[2] = &my_putchar2;
  tab[3] = &my_put_hexa2;
  tab[4] = &my_put_hexabig2;
  tab[5] = &my_put_nbr2;
  tab[6] = &my_put_nbr2;
  tab[7] = &my_put_octa2;
  tab[8] = &my_put_pointer2;
  tab[9] = &my_putstr2;
  tab[10] = &my_put_unsignedint2;
  while (str[i] != h)
    {
      i++;
      if (i == 11)
	return (1);
    }
  tab[i](ap);
}

int	my_printf(const char *format, ...)
{
  va_list	ap;
  int	i;
  char h;

  i = 0;
  va_start(ap, format);
  while (format[i]  != '\0')
  {
    if (format[i] == '%')
      {
	i++;
	if (format[i] == ' ')
	  while (format[i] == ' ')
	    i++;
	if (format[i] == '%')
	  my_putchar('%');
	else
	  h = format[i];
	pointer(ap, h);
      }
    else
      my_putchar(format[i]);
    i++;
  }
  va_end(ap);
}
