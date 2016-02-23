/*
** my_put_unsignedint.c for my_put_unisignedint in /home/osborn_s/rendu/PSU_2015_my_printf/SRCS
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Wed Nov 11 15:40:26 2015 Samuel Osborne
** Last update Fri Nov 13 11:45:03 2015 Samuel Osborne
*/

int     my_put_unsignedint(unsigned int nb)
{
  if (nb >= 10)
    my_put_unsignedint(nb / 10);
    my_putchar(nb % 10 + '0');
}
