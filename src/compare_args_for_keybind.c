/*
** compare_args_for_keybind.c for compare_args_for_keybind in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Thu Mar 10 19:59:07 2016 Samuel
** Last update Thu Mar 17 20:08:58 2016 Samuel
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int		get_key_bind(char a, t_keybinds *keybinds, char *word)
{
  void		(*tab[10])(t_keybinds *keybinds, char *word);
  int		i;
  char		*str;

  str = "lrtdqpwLDh";
  i = 0;
  tab[0] = &put_left;
  tab[1] = &put_right;
  tab[2] = &put_turn;
  tab[3] = &put_drop;
  tab[4] = &put_quit;
  tab[5] = &put_pause;
  tab[6] = &put_next;
  tab[7] = &put_level;
  tab[8] = &put_debug;
  tab[9] = &put_help;
  while (str[i] != a)
    {
      if (i == 10)
        return (1);
      i++;
    }
  tab[i](keybinds, word);
  return (0);
}

int		map_size_col(char *tmp, char *a, t_keybinds *keybinds, int pos)
{
  int		j;

  j = 0;
  while (tmp[j] != '\0')
    {
      tmp[j] = 0;
      j++;
    }
  j = 0;
  pos--;
  while (a[pos] != '\0')
    {
      if (a[pos] >= 48 && a[pos] <= 57)
        {
          tmp[j] = a[pos];
          j++;
        }
      pos++;
    }
  keybinds->col = my_getnbr(tmp);
  return (0);
}

int		get_level(char *a, t_keybinds *keybinds)
{
  char		*tmp;
  int		i;
  int		j;

  j = 0;
  i = 0;
  if ((tmp = malloc(sizeof(char) * my_strlen(a))) == NULL)
    return (1);
  while (a[i] != '=' && a[i] != '\0')
    {
      tmp[i] = a[i];
      i++;
    }
  tmp[i] = '=';
  i++;
  check_if_correct(tmp, keybinds, i);
  my_reset(tmp);
  while (a[i] != '\0')
    {
      tmp[j] = a[i];
      i++;
      j++;
    }
  keybinds->level = my_getnbr(tmp);
  return (0);
}

int		parse_for_bind(char *a, t_keybinds *keybinds)
{
  char		*value;
  char		key;

  if (a[2] != 'k')
    {
      if (a[2] == 'm' && my_strcmp2(a, "--map-size=", 10) == 0)
	map_size_detect(a, keybinds);
      else if ((a[2] == 'w') || (a[2] == 'd') | (a[2] == 'h'))
	return_char(a[2], a, keybinds);
      else if (a[2] == 'l')
	get_level(a, keybinds);
      else
	error(a, keybinds);
      return (0);
    }
  else if (a[2] == 'k')
    {
      key = a[6];
      value = get_char(a);
      get_key_bind(key, keybinds, value);
    }
  else
    error(a, keybinds);
  return (0);
}

int		compare_args_for_keybind(int ac, char **av, t_keybinds *keybinds)
{
  int		i;

  i = 1;
  while (i != ac)
    {
      if (av[i][0] == '-' && av[i][1] == '-')
	parse_for_bind(av[i], keybinds);
      else if (av[i][0] == '-' && (av[i][1] == 'k' || av[i][1] == 'w' 
				   || av[i][1] == 'l' || av[i][1] == 'd'))
	find_bind_with_k(keybinds, av, i, ac);
      else if (av[i][0] == '-' && av[i][1] != 'k' && av[i][1] != 'w'
	       && av[i][1] != 'l' && av[i][1] != 'd')
	error(av[i], keybinds);
      i++;
    }
  return (0);
}
