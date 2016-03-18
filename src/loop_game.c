/*
** loop_game.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Sat Mar  5 15:00:46 2016 Lucas Villeneuve
** Last update Fri Mar 18 15:43:53 2016 Lucas Villeneuve
*/

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include "get_next_line.h"

void	end_game(t_keybinds *keybinds)
{
  mvprintw(15, 15, "GAME OVER");
  refresh();
  while (my_strcmp(keybinds->buffer, keybinds->kq) != 0)
    {
      my_memset(keybinds->buffer, 5);
      if ((read(0, keybinds->buffer, 5) == -1))
	return ;
      refresh();

    }
  endwin();
  exit(1);
}

void	loop_game(char **map, t_tetris *tetris, t_tetrimino *tetrimino, t_keybinds *keybinds)
{
  srand(time(NULL));
  tetris->next = rand() % tetris->nb;
  while (1)
    {
      tetris->tet = tetris->next;
      tetris->next = rand() % tetris->nb;
      tetris->y = 1;
      tetris->x = tetris->map_width / 2;
      if (fall_tetrimino(map, tetris, tetrimino, keybinds) == 2)
	{
	  end_game(keybinds);
	  return ;
	}
      delete_line(map, tetris);
      refresh();
    }
}
