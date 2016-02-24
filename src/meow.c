/*
** meow.c for meow in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Wed Feb 24 09:54:28 2016 Samuel
** Last update Wed Feb 24 13:37:26 2016 Samuel
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void		cat(char *filename)
{
  int		fd;
  int		reader;
  char		buffer[200];  /* change buffer to size of ints from file that lucas made */

  if ((fd = open(filename, O_RDONLY)) == -1)
    return;
  if ((reader = read(fd, buffer)))
    return (1);
}
