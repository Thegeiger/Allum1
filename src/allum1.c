/*
** allum1.c for allum1 in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Mon Jan 26 10:20:45 2015 anthony geiger
** Last update Fri Feb 13 10:10:31 2015 anthony geiger
*/

#include <stdlib.h>
#include "my.h"
#include "win.h"
#include "allum.h"

int	my_allum1(int *tab_all, int size, int nb_line, int nb_row)
{

  tab_all[nb_line] = tab_all[nb_line] - nb_row;
  return (0);
}

int			*my_put_allum(int size)
{
  int			x;
  int			size_col;
  int			*tab_all;

  size_col = 1;
  x = 0;
  if ((tab_all = malloc(sizeof(int) * (size + 1))) == NULL)
    return (NULL);
  while (x != size)
    {
      tab_all[x] = size_col;
      size_col = size_col + 2;
      x++;
    }
  tab_all[x] = -1;
  return (tab_all);
}

int		nb_line_know(int *tab_all, int size)
{
  char			*s;
  int			nb_line;

  my_aff_allum(tab_all, size);
  my_putstr("enter your line\n");
  if ((s = get_next_line(0)) == NULL)
    exit (1);
  nb_line = my_getnb(s);
  return (nb_line -1);
}

int		nb_row_know()
{
  char			*s;
  int			nb_row;

  my_putstr("enter your nb of allum\n");
  if ((s = get_next_line(0)) == NULL)
    exit (1);
  nb_row = my_getnb(s);
  return (nb_row);
}

int			my_main_loop(int *tab_all, int size, int dif, int nb_row)
{
  int			nb_line;

  while (42)
    {
      if ((nb_line = nb_line_know(tab_all, size)) > size
	  || nb_line < 0 || tab_all[nb_line] == 0)
	{
	  my_putstr("bad line please retry\n");
	  continue;
	}
      if ((nb_row = nb_row_know()) == 0 || tab_all[nb_line] < nb_row)
	{
	  my_putstr("bad row please retry\n");
	  continue;
	}
      if ((my_allum1(tab_all, size, nb_line, nb_row)) == -1)
	return (2);
      if (check_lose(tab_all) == 1)
	return (3);
      if (bot_turn(tab_all, dif) == -1)
	return (1);
      if (check_lose(tab_all) == 1)
	return (2);
    }
  return (0);
}
