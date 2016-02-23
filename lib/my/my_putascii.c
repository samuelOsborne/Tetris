/*
** my_putascii.c for my_putascii in /home/osborn_s/rendu/PSU_2015_my_printf/SRCS
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Tue Nov 10 21:59:21 2015 Samuel Osborne
** Last update Thu Nov 12 18:31:37 2015 Samuel Osborne
*/

#include <stdlib.h>
#include <stdarg.h>

void	my_putascii(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] == 127)
	{
	  my_putchar(92);
	  if (str[i] < 10)
	    my_putstr("00");
	  if (str[i] > 10 && str[i] < 20)
	  my_putchar('0');
	  my_put_octa(str[i]);
	}
      else
	my_putchar(str[i]);
      i++;
    }
}
