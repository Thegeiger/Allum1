/*
** aff.c<2> for aff in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb  3 12:42:31 2015 anthony geiger
** Last update Tue Feb  3 13:03:16 2015 anthony geiger
*/

#include "my.h"
#include "allum.h"

int			my_aff_allum(int *tab_all, int size, int row, int i)
{
  int			x;
  int			y;

  while (tab_all[i] != -1)
    {
      x = 0;
      y = 0;
      if (i == row)
	my_putstr("\033[31m");
      while (x != tab_all[i])
	{
	  while (y != ((size * 2 + 1) - tab_all[i]) / 2)
	    {
	      my_putchar(' ');
	      y++;
	    }
	  my_putchar('|');
	  x++;
	}
      if (i == row)
	my_putstr("\033[0m");
      my_putchar('\n');
      i++;
    }
  return (0);
}
