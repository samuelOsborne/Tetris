/*
** my.h for my in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue Feb 23 10:31:40 2016 Samuel
** Last update Thu Mar 17 17:59:45 2016 Lucas Villeneuve
*/

#ifndef MY_H_
# define MY_H_

#ifndef _BSD_SOURCE
# define _BSD_SOURCE

#include <sys/ioctl.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>

typedef struct          s_keybinds
{
  char			*kl;
  char			*kr;
  char			*kt;
  char			*kd;
  char			*kq;
  char			*kp;
  char			buffer[5];
  int			next;
  int			level;
  int			size;
  int			row;
  int			col;
  int			debug;
}			t_keybinds;

typedef struct		s_tetris
{
  int			level;
  int			map_width;
  int			map_height;
  int			nb;
  int			high_score;
  int			score;
  int			lines;
  int			sleep;
  int			checker;
  int			x;
  int			y;
  int			next;
  int			tet;
}			t_tetris;

typedef struct		s_tetrimino
{
  char			*name;
  int			width;
  int			height;
  int			color;
  char			**piece;
}			t_tetrimino;

void    check_and_print_keysl(t_keybinds *keybinds);
void    check_and_print_keysr(t_keybinds *keybinds);
void    check_and_print_keyst(t_keybinds *keybinds);
void    check_and_print_keysd(t_keybinds *keybinds);
void    check_and_print_keysq(t_keybinds *keybinds);
void    check_and_print_keysp(t_keybinds *keybinds);
void    put_debug(t_keybinds *keybinds, char *word);
void    put_left(t_keybinds *keybinds, char *word);
void    put_right(t_keybinds *keybinds, char *word);
void    put_turn(t_keybinds *keybinds, char *word);
void    put_drop(t_keybinds *keybinds, char *word);
void    put_quit(t_keybinds *keybinds, char *word);
void    put_pause(t_keybinds *keybinds, char* word);
void    put_next(t_keybinds *keybinds, char *word);
void    put_level(t_keybinds *keybinds, char *word);
void	put_in_map(char **map, t_tetrimino *tetrimino, int x, int y);
void	show_in_map(t_tetrimino	*tetrimino, int x, int y);
void	test_time(int);
void	sort_tetrimino(t_tetrimino *tetrimino, int nb);
void	print_lines(t_keybinds *keybinds, t_tetris *tetris);
void	my_putstr(char *str);
void	fall_letter(char **map, t_tetris *tetris, t_keybinds *keybinds);
void	display_map_tetris(char **map, t_tetris *tetris);
void	init_keybinds(t_keybinds *keybinds);
void	init_keybinds2(t_keybinds *keybinds);
void	menu(t_keybinds *keybinds, t_tetris *tetris, t_tetrimino *tetrimino);
void	loop_game(char **map, t_tetris *tetris, t_tetrimino *tetrimino, t_keybinds *keybinds);
void	init_screen(t_tetris *tetris, char **map, t_tetrimino *tetrimino, t_keybinds *keybinds);
void	delete_line(char **map, t_tetris *tetris);
void	pause_game(t_keybinds *keybinds);
int	check_if_term_exists(char **ae);
int	compare_args_for_keybind(int ac, char **av, t_keybinds *keybinds);
int	map_size_detect(char *a, t_keybinds *keybinds);
int	get_key_bind(char a, t_keybinds *keybinds, char *word);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	usleep();
int	get_vars_tetrimino(t_tetrimino *tetrimino, int fd);
int	mode_non_canonique(int i);
int	my_strcmp(char *s1, char *s2);
int	check_winsz(struct winsize *size, t_tetris *tetris);
int	my_printf(const char *format, ...);
int	map_size_col(char *tmp, char *a, t_keybinds *keybinds, int pos);
int	collision(char **map, t_tetrimino *tetrimino, int x, int y);
int	fall_tetrimino(char **map, t_tetris *tetris, t_tetrimino *tetrimino, t_keybinds *keybinds);
char	*take_name(char *name, char *str);
char	*epurstr(char *str);
char    *my_strcpy(char *dest, char *src);
char	*my_strcat(char *dest, char *src);
char	**create_map(t_tetris *tetris);
char	*put_void(char *a);
char	return_char(char a);
t_tetrimino	*load_tetrimino(int nb, bool debug, t_tetris *tetris, int i);
t_tetrimino	*debug_mode(t_tetris *tetris, t_keybinds *keybinds);
t_tetrimino	*print_tetriminos(t_tetris *tetris, t_tetrimino *str);
t_tetrimino	ini_rotate_tetrimino(t_tetrimino tetrimino, char **map, int x, int y);
t_tetrimino	*ini_load(t_tetris *tetris);

#endif /* !BSD_SOURCE */
#endif /* !MY_H_ */
