/*
** aff.c<2> for aff in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb  3 12:42:31 2015 anthony geiger
** Last update Thu Feb 12 13:47:44 2015 anthony geiger
*/

#include "my.h"
#include "allum.h"

int			my_aff_allum(int *tab_all, int size)
{
  int			x;
  int			y;
  int			i;

  i = 0;
  while (tab_all[i] != -1)
    {
      x = 0;
      y = 0;
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
      my_putchar('\n');
      i++;
    }
  return (0);
}
