/*
** my.h for my in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue Feb 23 10:31:40 2016 Samuel
** Last update Fri Feb 26 10:50:49 2016 Samuel
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

void	display_map_tetris(char **map, t_tetris *tetris);
void	test_time(int);
int	my_printf(const char *format, ...);
void	fall_letter(char **map, t_tetris *tetris);
void	my_putstr(char *str);
int	my_strcmp(char *s1, char *s2);
char	**create_map(t_tetris *tetris);


#endif /* !BSD_SOURCE */
#endif /* !MY_H_ */
