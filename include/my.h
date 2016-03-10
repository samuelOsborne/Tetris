/*
** my.h for my in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue Feb 23 10:31:40 2016 Samuel
** Last update Thu Mar 10 16:24:48 2016 Lucas Villeneuve
*/

#ifndef MY_H_
# define MY_H_

#ifndef _BSD_SOURCE
# define _BSD_SOURCE

#include <sys/ioctl.h>
#include <stdbool.h>

typedef struct		s_tetris
{
  int			level;
  int			map_width;
  int			map_height;
  int			nb;
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
void	my_putstr(char *str);
void	fall_letter(char **map, t_tetris *tetris);
void	display_map_tetris(char **map, t_tetris *tetris);
void	loop_game(char **map, t_tetris *tetris, t_tetrimino *tetrimino);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_strcmp(char *s1, char *s2);
int	check_winsz(struct winsize *size);
int	my_printf(const char *format, ...);
int	collision(char **map, t_tetrimino *tetrimino, int x, int y);
int	fall_tetrimino(char **map, t_tetris *tetris, t_tetrimino tetrimino);
char	*epurstr(char *str);
char    *my_strcpy(char *dest, char *src);
char	*my_strcat(char *dest, char *src);
char	**create_map(t_tetris *tetris);
t_tetrimino	*load_tetrimino(int nb, bool debug, t_tetris *tetris);
t_tetrimino	*debug_mode(t_tetris *tetris);
t_tetrimino	ini_rotate_tetrimino(t_tetrimino tetrimino, char **map, int x, int y);

#endif /* !BSD_SOURCE */
#endif /* !MY_H_ */
