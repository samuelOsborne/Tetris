/*
** term_check.c for term_check in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Thu Mar 17 14:52:21 2016 Samuel
** Last update Sat Mar 19 14:16:04 2016 Lucas Villeneuve
*/

#include <term.h>
#include <stdlib.h>
#include "my.h"

void		check_term(char *term)
{
  int		ret;

  if (term == NULL)
    error_env();
  setupterm(term, 1, &ret);
  if (ret == 0)
    error_term(term);
}

void		check_env(char **ae, t_keybinds *keybinds)
{
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  k = 5;
  while (ae[i])
    {
      if (ae[i][0] == 'T')
        if (ae[i][1] == 'E')
          if (ae[i][2] == 'R')
            if (ae[i][3] == 'M')
              {
                if ((keybinds->term = malloc(sizeof(char)
					     * my_strlen(ae[i]))) == NULL)
                  return ;
                while (j != my_strlen(ae[i]))
		  keybinds->term[j++] = ae[i][k++];
              }
      i++;
    }
}
