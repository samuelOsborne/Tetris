/*
** print_the_keys.c for print_the_keys in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Mar  7 11:21:28 2016 Samuel
** Last update Fri Mar 11 17:05:15 2016 Samuel
*/

#include "my.h"

void		check_and_print_keysr(t_keybinds *keybinds)
{
  if (keybinds->kr[0] == 27)
    my_printf("Key Right : %s%s\n", "^EO", keybinds->kr);
  else if (my_strcmp(keybinds->kr, " ") == 0)
    my_printf("Key Right : (space)\n");
  else
    my_printf("Key Right : %s\n", keybinds->kr);
}

void		check_and_print_keyst(t_keybinds *keybinds)
{
  if (keybinds->kt[0] == 27)
    my_printf("Key Turn : %s%s\n", "^EO", keybinds->kt);
  else if (my_strcmp(keybinds->kt, " ") == 0)
    my_printf("Key Turn : (space)\n");
  else
    my_printf("Key Turn : %s\n", keybinds->kt);
}

void		check_and_print_keysd(t_keybinds *keybinds)
{
  if (keybinds->kd[0] == 27)
    my_printf("Key Drop : %s%s\n", "^EO", keybinds->kd);
  else if (my_strcmp(keybinds->kd, " ") == 0)
    my_printf("Key Drop : (space)\n");
  else
    my_printf("Key Drop : %s\n", keybinds->kd);
}

void		check_and_print_keysq(t_keybinds *keybinds)
{
  if (keybinds->kq[0] == 27)
    my_printf("Key Quit : %s%s\n", "^EO", keybinds->kq);
  else if (my_strcmp(keybinds->kq, " ") == 0)
    my_printf("Key Quit : (space)\n");
  else
    my_printf("Key Quit : %s\n", keybinds->kq);
}
void		check_and_print_keysp(t_keybinds *keybinds)
{
  if (keybinds->kp[0] == 27)
    my_printf("Key Pause : %s%s\n", "^EO", keybinds->kp);
  else if (my_strcmp(keybinds->kp, " ") == 0)
    my_printf("Key Pause : (space)\n");
  else
    my_printf("Key Pause : %s\n", keybinds->kp);
}
