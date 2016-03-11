/*
** objects.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Thu Feb 25 21:15:34 2016 Lucas Villeneuve
** Last update Fri Mar 11 11:53:36 2016 Samuel
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

int	mode_non_canonique(int i)
{
  static struct termios oldT;
  static struct termios newT;

  if (i == 0)
    {
      if (ioctl(0, TCGETS, &oldT) < 0)
        return (1);
      if (ioctl(0, TCGETS, &newT) < 0)
        return (1);
      newT.c_lflag &= ~ECHO;
      newT.c_lflag &= ~ICANON;
      newT.c_cc[VMIN] = 1;
      newT.c_cc[VTIME] = 0; /* ms */
      ioctl(0, TCSETS, &newT);
    }
  if (i == 1)
    ioctl(0, TCSETS, &oldT);
}

void	fall_letter(char **map, t_tetris *tetris, t_keybinds *keybinds)
{
  int	i;
  int	j;
  int	count;
  int	ch;

  i = 1;
  j = 6;
  count = 0;
  while (count < 50)
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
      menu(keybinds, score);
      /*ch = getch();*/
      if (ch == 260 && j > 1 && map[i][j - 1] != 'O')
	j--;
      if (ch == 261 && j < tetris->map_width && map[i][j + 1] != '0')
	j++;
      refresh();
      display_map_tetris(map, tetris);
    }
}
