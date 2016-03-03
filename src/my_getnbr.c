/*
** my_getnbr.c for allum1 in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/CPE_2015_allum1
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed Feb 10 11:37:17 2016 Lucas Villeneuve
** Last update Fri Feb 12 14:40:41 2016 Lucas Villeneuve
*/

int	my_getnbr(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  if (!(str) || str[0] == 0)
    return (-1);
  while (str[i])
    {
      nb *= 10;
      nb += (str[i] - 48);
      i++;
      if ((str[i] < 48 || str[i] > 57) && str[i] != 0)
      	return (-1);
    }
  return (nb);
}
