/*
** my_put_pointer.c for my_put_pointer in /home/osborn_s/rendu/PSU_2015_my_printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Tue Nov 10 21:14:07 2015 Samuel Osborne
** Last update Wed Nov 11 18:22:17 2015 Samuel Osborne
*/

#include <stdlib.h>
#include <stdarg.h>

void	*my_put_pointer(long int number)
{
  int   b;

  b = number;
  my_putstr("0x");
  my_put_hexa(b);
}
