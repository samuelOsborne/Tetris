/*
** my.h for my in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue Feb 23 10:31:40 2016 Samuel
** Last update Sat Mar  5 23:04:25 2016 Samuel
*/

#ifndef MY_H_
# define MY_H_

#ifndef _BSD_SOURCE
# define _BSD_SOURCE

#include <sys/ioctl.h>

typedef struct		s_keybinds
{
  int			kl;
  int			kr;
  int			kt;
  int			kd;
  int			kq;
  int			kp;
  int			next;
  int			level;
  int			size;
  int			row;
  int			col;
  int			debug;
}			t_keybinds;

typedef struct		s_highscore
{
  int			high_score;
  int			score;
}			t_highscore;

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

void    put_debug(t_keybinds *keybinds, char word);
void    put_left(t_keybinds *keybinds, char word);
void    put_right(t_keybinds *keybinds, char word);
void    put_turn(t_keybinds *keybinds, char word);
void    put_drop(t_keybinds *keybinds, char word);
void    put_quit(t_keybinds *keybinds, char word);
void    put_pause(t_keybinds *keybinds, char word);
void    put_next(t_keybinds *keybinds, char word);
void    put_level(t_keybinds *keybinds, char word);
void	debug_mode(t_keybinds *keybinds);
void	test_time(int);
void	load_tetrimino();
void	my_putstr(char *str);
void	fall_letter(char **map, t_tetris *tetris);
void	display_map_tetris(char **map, t_tetris *tetris);
void	init_keybinds(t_keybinds *keybinds);
void	menu(t_keybinds *keybinds);
int	compare_args_for_keybind(int ac, char **av, t_keybinds *keybinds);
int	map_size_detect(char *a, t_keybinds *keybinds);
int	get_key_bind(char a, t_keybinds *keybinds, char word);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_strcmp(char *s1, char *s2);
int	check_winsz(struct winsize *size);
int	my_printf(const char *format, ...);
int	map_size_col(char *tmp, char *a, t_keybinds *keybinds, int pos);
int	print_tetris();
char	*epurstr(char *str);
char    *my_strcpy(char *dest, char *src);
char	*my_strcat(char *dest, char *src);
char	**create_map(t_tetris *tetris);
char	return_char(char a);
char	put_void(char a);

#endif /* !BSD_SOURCE */
#endif /* !MY_H_ */
