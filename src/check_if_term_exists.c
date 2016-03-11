/*
** check_if_term_exists.c for check_if_term_exists in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Mar  7 21:15:00 2016 Samuel
** Last update Tue Mar  8 09:22:47 2016 Samuel
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <term.h>

char		*get_term(char **ae, char *term)
{
  int		i;
  int		j;
  int		k;

  k = 0;
  i = 0;
  while (ae[i])
    {
      if (ae[i][0] == 'T')
	if (ae[i][1] == 'E')
	  if (ae[i][2] == 'R')
	    if (ae[i][3] == 'M')
	    {
	      j = 5;
	      while (ae[i][j] != '\0')
		{
		  term[k] = ae[i][j];
		  j++;
		  k++;
		}
	    }
      i++;
    }
  return (term);
}

int		size_of_env(char **ae)
{
  int		i;
  int		j;

  i = 0;
  while (ae[i])
    {
      if (ae[i][0] == 'T')
	if (ae[i][1] == 'E')
	  if (ae[i][2] == 'R')
	    if (ae[i][3] == 'M')
	      j = my_strlen(ae[i]);
      i++;
    }
  return (j);
}

int		check_if_term_exists(char **ae)
{
  char		*term;
  int		size_env;
  int		ret;
  int		i;

  /* setenv("TERM", "LOL", 1); */
  size_env = size_of_env(ae);
  if ((term = malloc(sizeof(char) * size_env)) == NULL)
    return (1);
  term = get_term(ae, term);
  i = setupterm(term, 1, &ret);
  if (i == -1)
    {
      my_printf("Please use a valid terminal.\n");
      return (1);
    }
  return (0);
}
