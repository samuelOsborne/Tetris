/*
** error.c for error in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Mar 14 20:28:37 2016 Samuel
** Last update Sat Mar 19 12:52:21 2016 Samuel
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	error(char *a, t_keybinds *keybinds)
{
  my_printf("%s is an invalid argument.\nHere is a helping hand :\n", a);
  print_help(keybinds->av);
  exit(0);
}

void	error_term(char *a)
{
  my_printf("%s is an invalid terminal, please have a valid terminal to play.\n", a);
  exit(0);
}

void	check_for_the_d(char **av, int pos, t_keybinds *keybinds)
{
  if ((my_strcmp(av[pos - 1], "-kl")) == 0 || (my_strcmp(av[pos - 1], "-kr")) == 0
      || (my_strcmp(av[pos - 1], "-kt")) == 0 || (my_strcmp(av[pos - 1], "-kd")) == 0 
      || (my_strcmp(av[pos - 1], "-kq")) == 0 || (my_strcmp(av[pos - 1], "-kp")) == 0)
    keybinds->debug = 0;
  else
    keybinds->debug = 1;
}

int	find_bind_with_k(t_keybinds *keybinds, char **av, int pos, int ac)
{
  char	b;
  char	*word;

  if (av[pos][1] == 'k' && ((pos + 1) < ac) && (av[pos][2] == 'l' 
	|| av[pos][2] == 'r' || av[pos][2] == 't' || av[pos][2] == 'd' 
						|| av[pos][2] == 'q' || av[pos][2] == 'p'))
    {
      word = av[pos + 1];
      b = av[pos][2];
      get_key_bind(b, keybinds, word);
      return (0);
    }
  if (av[pos][1] == 'w')
    keybinds->next = 0;
  else if (av[pos][1] == 'l' && ((pos + 1) < ac))
    keybinds->level = my_getnbr(av[pos + 1]);
  else if (av[pos][1] == 'd')
    check_for_the_d(av, pos, keybinds);
  else
    error(av[pos], keybinds);
  return (0);
}

char	*get_char(char *a)
{
  int	i;
  int	j;
  char	*ret;

  j = 0;
  i = 0;
  if ((ret = malloc(sizeof(char) * my_strlen(a))) == NULL)
    return (NULL);
  while (a[i] != '=' && a[i] != '\0')
    i++;
  i++;
  if (a[i] == '\0')
    exit(0);
  while (a[i] != '\0')
    {
      ret[j] = a[i];
      i++;
      j++;
    }
  ret[j] = '\0';
  return (ret);
}
