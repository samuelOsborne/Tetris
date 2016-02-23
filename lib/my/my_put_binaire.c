/*
** my_put_binaire.c for my_put_binaire in /home/osborn_s/rendu/PSU_2015_my_printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Tue Nov 10 20:57:54 2015 Samuel Osborne
** Last update Sat Nov 14 15:09:40 2015 Samuel Osborne
*/

#include <stdlib.h>
#include <stdarg.h>

int     my_put_binaire(unsigned int number)
{
  int   *a;
  int   b;
  int   i;

  i = 0;
  b = number;
  a = malloc(150);
  if (a == NULL)
    return (1);
  while (b > 0)
    {
      a[i] = (b % 2);
      b = (b / 2);
      i++;
    }
  i = i - 1;
  while (i > -1)
    {
      my_put_nbr(a[i]);
      i--;
    }
  free(a);
}
