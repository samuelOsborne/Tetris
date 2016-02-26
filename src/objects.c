/*
** objects.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Thu Feb 25 21:15:34 2016 Lucas Villeneuve
** Last update Fri Feb 26 10:50:33 2016 Lucas Villeneuve
*/

#include <unistd.h>
#include <ncurses.h>
#include "my.h"

void	delete_letter(char **map, int i)
{
  int	j;

  j = 0;
  while (map[i][j] != 0)
    {
      if (map[i][j] == 'I')
	map[i][j] = ' ';
      j++;
    }
}

void	delete_line(char **map, t_tetris *tetris)
{
  int	i;
  int	j;
  int	count;

  i = 1;
  while (i < tetris->map_height)
    {
      count = 0;
      j = 1;
      while (map[i][j] == 'O')
	{
	  count++;
	  j++;
	}
      if (count == tetris->map_width)
	{
	  j = 1;
	  while (j <= tetris->map_width)
	    map[i][j++] = ' ';
	}
      i++;
    }
}

void	fall_letter(char **map, t_tetris *tetris)
{
  int	i;
  int	j;
  int	count;
  int	ch;

  i = 1;
  j = 6;
  count = 0;
  while (count < 30)
    {
      if (map[i + 1][j] == '-' || map[i + 1][j] == 'O')
      	{
      	  map[i][j] = 'O';
	  delete_letter(map, i - 1);
      	  i = 1;
	  count++;
      	}
      else
      	{
	  delete_letter(map, i - 1);
      	  map[i][j] = 'I';
      	  i++;
      	}
      delete_line(map, tetris);
      ch = getch();
      if (ch == 260 && j > 1 && map[i][j - 1] != 'O')
	j--;
      if (ch == 261 && j < tetris->map_width && map[i][j + 1] != '0')
	j++;
      refresh();
      display_map_tetris(map, tetris);
    }
}
