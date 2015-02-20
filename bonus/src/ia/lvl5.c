/*
** lvl5.c<2> for chuck in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb  3 12:54:38 2015 anthony geiger
** Last update Tue Feb  3 13:05:31 2015 anthony geiger
*/

#include "allum.h"

void			chuck_noris(int *tab_all)
{
  int			i;
  int			nb;
  int			check;

  check = 0;
  i = 0;
  nb = 0;
  while (tab_all[i] != - 1)
    {
      check = check + tab_all[i];
      i++;
    }
  i = 0;
  while (tab_all[i] != -1)
    {
      if (tab_all[i] != 0)
	nb++;
      i++;
    }
  low_case_super(nb, i, tab_all, check);
}
