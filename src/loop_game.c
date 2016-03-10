/*
** loop_game.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Sat Mar  5 15:00:46 2016 Lucas Villeneuve
** Last update Thu Mar 10 10:37:48 2016 Lucas Villeneuve
*/

#include <ncurses.h>
#include "my.h"

void	end_game()
{
  mvprintw(15, 15, "GAME OVER");
  refresh();
  while (1);
}

void	loop_game(char **map, t_tetris *tetris, t_tetrimino *tetrimino)
{
  int	nb;

  while (1)
    {
      srand(time(NULL));
      nb = rand() % tetris->nb;
      if (fall_tetrimino(map, tetris, tetrimino[nb]) == 2)
	{
	  end_game();
	  return ;
	}
      delete_line(map, tetris);
      refresh();
    }
}