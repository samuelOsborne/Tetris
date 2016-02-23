/*
** my_putchar2.c for my_putchar2 in /home/osborn_s/rendu/pointeur fonctions printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Thu Nov 12 23:27:20 2015 Samuel Osborne
** Last update Fri Nov 13 15:16:46 2015 Samuel Osborne
*/

#include <stdarg.h>

void    my_putchar2(va_list list)
{
  char  b;

  b = (va_arg(list, int));
  my_putchar(b);
}
