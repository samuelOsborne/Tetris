/*
** my_strcpy.c for allum1 in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/CPE_2015_allum1
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed Feb 10 11:25:28 2016 Lucas Villeneuve
** Last update Thu Mar  3 14:09:51 2016 Lucas Villeneuve
*/

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}