/*
** lvl4.c<2> for super in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb  3 12:53:36 2015 anthony geiger
** Last update Thu Feb 12 13:33:49 2015 anthony geiger
*/

#include "allum.h"

void			case_one_super(int *tab_all, int i)
{
  if (tab_all[i] == 1)
    tab_all[i] = 0;
  i = 0;
  while (tab_all[i] == 0)
    i++;
  if (tab_all[i] == 1)
    tab_all[i] = 0;
  else
    tab_all[i] = 1;
}

void			low_case_super(int nb, int i, int *tab_all, int check)
{
  if (nb == 2)
    {
      i = 0;
      while (tab_all[i] == 0)
	i++;
      if (tab_all[i] == 1)
	i++;
      while (tab_all[i] == 0)
	i++;
      if (tab_all[i] != 1)
	tab_all[i] = 2;
      else if (tab_all[i] == 2)
	tab_all[i] = 0;
      else
	tab_all[i] = 0;
    }
  else if (nb == 1)
    case_one_super(tab_all, i);
  else
    check_imper(tab_all, check);
}

void			super_ia(int *tab_all)
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
