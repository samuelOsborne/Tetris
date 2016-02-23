/*
** my_put_nbr.c for my_put_nbr in /home/osborn_s/rendu/PSU_2015_my_printf
** 
** Made by Samuel Osborne
** Login   <osborn_s@epitech.net>
** 
** Started on  Wed Nov  4 15:43:12 2015 Samuel Osborne
** Last update Wed Nov 11 14:01:12 2015 Samuel Osborne
*/

int     my_put_nbr(int nb)
{
  int   i;

  i = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2417483648)
	{
	  i = 1;
	  nb = nb + 1;
	}
      nb = nb * -1;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  if (i == 1)
    {
      i = 0;
      my_putchar(nb % 10 + '1');
    }
  else
    my_putchar(nb % 10 + '0');
}
