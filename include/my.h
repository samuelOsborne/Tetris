/*
** my.h for my in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue Feb 23 10:31:40 2016 Samuel
** Last update Thu Feb 25 18:54:19 2016 Lucas Villeneuve
*/

#ifndef MY_H_
# define MY_H_

#ifndef _BSD_SOURCE
# define _BSD_SOURCE

typedef struct		s_tetris
{
  int			level;
  int			map_width;
  int			map_height;
}			t_tetris;

typedef struct		s_tetrimino
{
  char			*name;
  int			width;
  int			height;
  int			color;
}			t_tetrimino;

void	test_time(int);
int	my_printf(const char *format, ...);

#endif /* !BSD_SOURCE */
#endif /* !MY_H_ */
