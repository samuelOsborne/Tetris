/*
** epurstr.c for minishell1 in /media/villen_l/home/villen_l/rendu/PSU_2015_/PSU_2015_minishell1
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Thu Jan 21 10:08:48 2016 Lucas Villeneuve
** Last update Fri Mar 18 12:31:55 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include "my.h"

char	*loop_epurstr(char *str, char *tmp, int i, int j)
{
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	tmp[j++] = str[i++];
      else
	{
	  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	    i++;
	  if (str[i])
	    tmp[j++] = ' ';
	  else
	    {
	      tmp[j] = 0;
	      return (tmp);
	    }
	}
    }
  tmp[j] = 0;
  return (tmp);
}

char	*epurstr(char *str)
{
  char	*tmp;
  int	i;
  int	j;

  if ((tmp = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
    i++;
  tmp = loop_epurstr(str, tmp, i, j);
  free(str);
  return (tmp);
}

char	*epurend(char *str)
{
  int	len;

  len = my_strlen(str);
  while (len - 1 > 0 && str[len - 1] == ' ')
    {
      str[len - 1] = 0;
      len--;
    }
  return (str);
}
