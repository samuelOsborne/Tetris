/*
** strcmp.c for strcmp in /media/villen_l/home/villen_l/rendu/PSU_2015_/PSU_2015_minishell1
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Tue Jan 19 15:09:18 2016 Lucas Villeneuve
** Last update Sat Mar 19 15:47:10 2016 Samuel
*/

int	my_strcmp2(char *s1, char *s2, int stop)
{
  int	i;
  int	sum;

  i = 0;
  while ((s1[i] != 0 && s2[i] != 0) && (s1[i] == s2[i] && i < stop))
    i++;
  sum = s1[i] - s2[i];
  return (sum);
}

int	my_strcmp(char *s1, char *s2)
{
  int   i;
  int   sum;

  i = 0;
  while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
    i++;
  sum = s1[i] - s2[i];
  return (sum);
}
