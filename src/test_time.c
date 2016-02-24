/*
** test_time.c for test_time in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue Feb 23 18:46:00 2016 Samuel
** Last update Wed Feb 24 11:40:57 2016 Lucas Villeneuve
*/

#include "my.h"
#include <unistd.h>

void		test_time(int mins)
{
  int		secs;

  secs = 60;
  while (mins != 0)
    {
      secs = 60;
      my_printf("%d : ", mins);
      while (secs != 0)
	{
	  my_printf("%d", secs);
	  my_printf("\b");
	  my_printf("\b");
	  if (secs != 1)
	    usleep(1000000);
	  secs--;
	}
      mins--;
    }
}
