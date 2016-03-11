/*
** compare_args_for_keybind.c for compare_args_for_keybind in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Thu Mar 10 19:59:07 2016 Samuel
** Last update Fri Mar 11 21:08:30 2016 Samuel
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int		get_key_bind(char a, t_keybinds *keybinds, char *word)
{
  void		(*tab[9])(t_keybinds *keybinds, char *word);
  int		i;
  char		*str;

  str = "lrtdqpwLD";
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
  while (str[i] != a)
    {
      if (i == 9)
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
  while (a[pos] != '\0')
    {
      if (a[pos] >= 48 && a[pos] <= 56)
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
      tmp[i] = 0;
      i++;
    }
  i++;
  while (a[i] != '\0')
    {
      tmp[j] = a[i];
      i++;
      j++;
    }
  keybinds->level = my_getnbr(tmp);
  return (0);
}

char		*get_char(char *a)
{
  int		i;
  int		j;
  char		*ret;

  j = 0;
  i = 10;
  if ((ret = malloc(sizeof(char) * my_strlen(a))) == NULL)
    return (NULL);
  while (a[i] != '\0')
    {
      ret[j] = a[i];
      i++;
      j++;
    }
  return (ret);
}

int		parse_for_bind(char *a, t_keybinds *keybinds)
{
  char		*value;
  char		key;

  if (a[2] != 'k')
    {
      if (a[2] == 'm')
        {
          map_size_detect(a, keybinds);
          return (0);
        }
      else if (a[2] == 'w' || a[2] == 'd')
        key = return_char(a[1]);
      else
        {
          get_level(a, keybinds);
          return (0);
        }
      get_key_bind(key, keybinds, "lo");
    }
  else if (my_strlen(a) == 6)
    key = a[6]; /* charnge here to collect the char * */
  value = get_char(a);
  get_key_bind(key, keybinds, value);
  return (0);
}

int		compare_args_for_keybind(int ac, char **av, t_keybinds *keybinds)
{
  int		i;
  char		a;
  char		*word;

  i = 1;
  while (i != ac)
    {
      if (av[i][0] == '-' && av[i][1] == '-')
        parse_for_bind(av[i], keybinds);
      else if (av[i][1] == 'k' || av[i][1] == 'w')
        {
          a = av[i][1];
          if (av[i][1] == 'k' && ((i + 1) < ac))
            {
              word = av[i + 1];
              a = av[i][2];
            }
          get_key_bind(a, keybinds, word);
        }
      else if (av[i][1] == 'l' && ((i + 1) < ac))
        keybinds->level = my_getnbr(av[i + 1]);
      i++;
    }
  return (0);
}
