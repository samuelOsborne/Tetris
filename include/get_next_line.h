/*
** get_next_line.h for get_next_line in /media/villen_l/home/villen_l/rendu/CPE_2015_/CPE_2015_getnextline
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon Jan  4 11:04:10 2016 Lucas Villeneuve
** Last update Thu Mar  3 10:39:53 2016 Lucas Villeneuve
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (1)
# endif /* !READ_SIZE */

#include <stdlib.h>

void my_memset(char *str, int size);
char *my_realloc(char *str, size_t size);
char read_char(const int fd);
char *get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
