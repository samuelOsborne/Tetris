/*
** my.h for my in /home/osborn_s/rendu/PSU_2015_my_printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Thu Nov 12 19:05:37 2015 Samuel Osborne
** Last update Mon Nov 16 22:15:51 2015 Samuel Osborne
*/

#include	<stdarg.h>

#ifndef		MY_H
# define	MY_H

int	pointer(va_list ap, char h);
void	my_putascii(char *str);
int	my_put_binaire(unsigned int number);
void	my_putchar(char a);
int	my_put_hexa(unsigned int number);
int	my_printf(const char *format, ...);
int	my_put_nbr(int nb);
int	my_put_octa(unsigned int number);
void	*my_put_pointer(long int number);
char	my_putstr(char *str);
int	my_put_unsignedint(unsigned int nb);
int	my_strlen(char *str);
void	my_putascii2(va_list list);
void	my_put_binaire2(va_list list);
void	my_putchar2(va_list list);
void	my_put_hexa2(va_list list);
void	my_put_hexabig2(va_list list);
void	my_put_nbr2(va_list list);
void	my_put_octa2(va_list list);
void	my_put_pointer2(va_list list);
void	my_putstr2(va_list list);
void	my_put_unsignedint2(va_list list);

#endif 
