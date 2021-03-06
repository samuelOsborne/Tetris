/*
** my_put_hexa.c for my_put_hexa in /home/osborn_s/rendu/PSU_2015_my_printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Tue Nov 10 17:23:55 2015 Samuel Osborne
** Last update Sat Nov 14 15:07:55 2015 Samuel Osborne
*/

#include <stdlib.h>
#include <stdarg.h>

int     my_put_hexa(unsigned int number)
{
  char	*chars;
  int   b;
  int	temp;
  int	i;

  i = 0;
  b = number;
  chars = malloc(150);
  while (b > 0)
    {
      temp = (b % 16);
      if (temp < 10)
	chars[i] = temp + 48;
      else
	chars[i] = temp + 87;
      b = (b / 16);
      i++;
    }
  i = i - 1;
  while (i > -1)
    {
      my_putchar(chars[i]);
      i--;
    }
  free(chars);
}
