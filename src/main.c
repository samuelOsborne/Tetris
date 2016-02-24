/*
** main.c for main in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue Feb 23 10:27:54 2016 Samuel
** Last update Wed Feb 24 09:32:26 2016 Samuel
*/

#include "my.h"

void	init_screen()
{
  initscr();
  keypad(stdscr, TRUE);
  noecho();
  refresh();
  getch();
  endwin();
}

int	main()
{
  test_time(5); /*tu passes a test time le nmbr de mins */
  init_screen();
  return (0);
}
