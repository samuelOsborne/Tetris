/*
** my.h for my in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue Feb 23 10:31:40 2016 Samuel
** Last update Thu Mar  3 15:08:03 2016 Lucas Villeneuve
*/

#ifndef MY_H_
# define MY_H_

#ifndef _BSD_SOURCE
# define _BSD_SOURCE

#include <sys/ioctl.h>

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
  char			**piece;
}			t_tetrimino;

void	test_time(int);
void	load_tetrimino();
void	my_putstr(char *str);
void	debug_mode(t_tetris *tetris);
void	fall_letter(char **map, t_tetris *tetris);
void	display_map_tetris(char **map, t_tetris *tetris);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_strcmp(char *s1, char *s2);
int	check_winsz(struct winsize *size);
int	my_printf(const char *format, ...);
char	*epurstr(char *str);
char    *my_strcpy(char *dest, char *src);
char	*my_strcat(char *dest, char *src);
char	**create_map(t_tetris *tetris);

#endif /* !BSD_SOURCE */
#endif /* !MY_H_ */
