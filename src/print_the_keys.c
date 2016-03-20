/*
** print_the_keys.c for print_the_keys in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Mar  7 11:21:28 2016 Samuel
** Last update Sun Mar 20 16:39:40 2016 Samuel Osborne
*/

#include "my.h"

void		check_and_print_keysr(t_keybinds *keybinds)
{
  if (keybinds->kr[0] == 27)
    my_printf("Key Right : %s%c%c\n", "^E", keybinds->kr[1], keybinds->kr[2]);
  else if (my_strcmp(keybinds->kr, " ") == 0)
    my_printf("Key Right : (space)\n");
  else
    my_printf("Key Right : %s\n", keybinds->kr);
}

void		check_and_print_keyst(t_keybinds *keybinds)
{
  if (keybinds->kt[0] == 27)
    my_printf("Key Turn : %s%c%c\n", "^E", keybinds->kt[1], keybinds->kt[2]);
  else if (my_strcmp(keybinds->kt, " ") == 0)
    my_printf("Key Turn : (space)\n");
  else
    my_printf("Key Turn : %s\n", keybinds->kt);
}

void		check_and_print_keysd(t_keybinds *keybinds)
{
  if (keybinds->kd[0] == 27)
    my_printf("Key Drop : %s%c%c\n", "^E", keybinds->kd[1], keybinds->kd[2]);
  else if (my_strcmp(keybinds->kd, " ") == 0)
    my_printf("Key Drop : (space)\n");
  else
    my_printf("Key Drop : %s\n", keybinds->kd);
}

void		check_and_print_keysq(t_keybinds *keybinds)
{
  if (keybinds->kq[0] == 27)
    my_printf("Key Quit : %s%c%c\n", "^E", keybinds->kq[1], keybinds->kq[2]);
  else if (my_strcmp(keybinds->kq, " ") == 0)
    my_printf("Key Quit : (space)\n");
  else
    my_printf("Key Quit : %s\n", keybinds->kq);
}
void		check_and_print_keysp(t_keybinds *keybinds)
{
  if (keybinds->kp[0] == 27)
    my_printf("Key Pause : %s%c%c\n", "^E", keybinds->kq[1], keybinds->kp[2]);
  else if (my_strcmp(keybinds->kp, " ") == 0)
    my_printf("Key Pause : (space)\n");
  else
    my_printf("Key Pause : %s\n", keybinds->kp);
}
