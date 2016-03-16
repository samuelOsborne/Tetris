/*
** pause.c for tetris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed Mar 16 11:12:58 2016 Lucas Villeneuve
** Last update Wed Mar 16 11:19:09 2016 Lucas Villeneuve
*/

#include "my.h"
#include "get_next_line.h"

void	pause_game(t_keybinds *keybinds)
{
  if (my_strcmp(keybinds->buffer, keybinds->kp) == 0)
    {
      while (1)
	{
	  my_memset(keybinds->buffer, 5);
	  if ((read(0, keybinds->buffer, 5) == -1))
	    return ;
	  if (my_strcmp(keybinds->buffer, keybinds->kp) == 0)
	    return ;
	}
    }
}
