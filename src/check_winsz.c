/*
** check_winsz.c for teris in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/PSU/PSU_2015_tetris
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed Feb 24 11:34:54 2016 Lucas Villeneuve
** Last update Fri Feb 26 10:47:01 2016 Samuel
*/

#include "my.h"
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>

int	check_winsz(struct winsize *size)
{
  if (size->ws_row <= 30)
    {
      my_putstr("Error your terminal is not big enough to print the tetris\n");
      exit(1);
    }
  else if (size->ws_col <= 20)
    {
      my_putstr("Error your terminal is not big enough to print the tetris\n");
      exit(1);
    }
  return (0);
} 
