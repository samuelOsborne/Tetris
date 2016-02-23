/*
** my_strlen.c for my_strlen in /home/osborn_s/rendu/PSU_2015_my_printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Wed Nov  4 15:40:10 2015 Samuel Osborne
** Last update Wed Nov  4 15:40:44 2015 Samuel Osborne
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
