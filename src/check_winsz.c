/*
** check_winsz.c for teris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed Feb 24 11:34:54 2016 Lucas Villeneuve
** Last update Fri Mar 11 16:04:27 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <sys/ioctl.h>
#include "my.h"

int	check_winsz(struct winsize *size, t_tetris *tetris)
{
  if (size->ws_row <= tetris->map_height)
    {
      printf("ROW %d %d", size->ws_row, size->ws_col);
      my_putstr("Error your terminal is not big enough to print the tetris\n");
      exit(1);
    }
  else if (size->ws_col <= 25 + tetris->map_width)
    {
      printf("COL %d %d", size->ws_row, size->ws_col);
      my_putstr("Error your terminal is not big enough to print the tetris\n");
      exit(1);
    }
  return (0);
} 
