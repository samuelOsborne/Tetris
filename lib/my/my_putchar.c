/*
** my_putchar.c for my_putchar in /home/osborn_s/rendu/PSU_2015_my_printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Wed Nov  4 15:38:54 2015 Samuel Osborne
** Last update Fri Nov 13 10:58:47 2015 Samuel Osborne
*/

void	my_putchar(char a)
{
  write(1, &a, 1);
}
