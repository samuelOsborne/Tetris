/*
** print_the_keys.c for print_the_keys in /media/samuel/Home/osborn_s/rendu/PSU_2015/PSU_2015_tetris
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Mon Mar  7 11:21:28 2016 Samuel
** Last update Mon Mar  7 20:01:07 2016 Samuel
*/

#include "my.h"

void		check_and_print_keysr(t_keybinds *keybinds)
{
  if (keybinds->kr == 260)
    my_printf("Key Right : ^EOD\n");
  else if (keybinds->kr == 261)
    my_printf("Key Right : ^EOC\n");
  else if (keybinds->kr == 259)
    my_printf("Key Right : ^EOA\n");
  else if (keybinds->kr == 27)
    my_printf("Key Right : ^E\n");
  else if (keybinds->kr == 32)
    my_printf("Key Right : (space)\n");
  else
    my_printf("Key Right : %c\n", keybinds->kr);
}

void		check_and_print_keyst(t_keybinds *keybinds)
{
  if (keybinds->kt == 260)
    my_printf("Key Turn : ^EOD\n");
  else if (keybinds->kt == 261)
    my_printf("Key Turn : ^EOC\n");
  else if (keybinds->kt == 259)
    my_printf("Key Turn : ^EOA\n");
  else if (keybinds->kt == 27)
    my_printf("Key Turn : ^E\n");
  else if (keybinds->kt == 32)
    my_printf("Key Right : (space)\n");
  else
    my_printf("Key Turn : %c\n", keybinds->kt);
}

void		check_and_print_keysd(t_keybinds *keybinds)
{
  if (keybinds->kd == 260)
    my_printf("Key Drop : ^EOD\n");
  else if (keybinds->kd == 261)
    my_printf("Key Drop : ^EOC\n");
  else if (keybinds->kd == 259)
    my_printf("Key Drop : ^EOA\n");
  else if (keybinds->kd == 27)
    my_printf("Key Drop : ^E\n");
  else if (keybinds->kd == 32)
    my_printf("Key Right : (space)\n");
  else
    my_printf("Key Drop : %c\n", keybinds->kd);
}

void		check_and_print_keysq(t_keybinds *keybinds)
{
  if (keybinds->kq == 260)
    my_printf("Key Quit : ^EOD\n");
  else if (keybinds->kq == 261)
    my_printf("Key Quit : ^EOC\n");
  else if (keybinds->kq == 259)
    my_printf("Key Quit : ^EOA\n");
  else if (keybinds->kq == 32)
    my_printf("Key Quit : (space)\n");
  else if (keybinds->kq == 27)
    my_printf("Key Quit : ^E\n");
  else
    my_printf("Key Quit : %c\n", keybinds->kq);
}
void		check_and_print_keysp(t_keybinds *keybinds)
{
  if (keybinds->kp == 260)
    my_printf("Key Pause : ^EOD\n");
  else if (keybinds->kp == 261)
    my_printf("Key Pause : ^EOC\n");
  else if (keybinds->kp == 259)
    my_printf("Key Pause : ^EOA\n");
  else if (keybinds->kp == 27)
    my_printf("Key Pause : ^E\n");
  else if (keybinds->kp == 32)
    my_printf("Key Right : (space)\n");
  else
    my_printf("Key Pause : %c\n", keybinds->kp);
}
