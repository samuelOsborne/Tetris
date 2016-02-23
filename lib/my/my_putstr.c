/*
** my_putstr.c for my_putstr in /home/osborn_s/rendu/PSU_2015_my_printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Wed Nov  4 15:39:21 2015 Samuel Osborne
** Last update Sat Nov 14 12:25:17 2015 Samuel Osborne
*/

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
