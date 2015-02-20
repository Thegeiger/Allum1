/*
** lvl3.c<2> for ia 3 in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb  3 12:51:23 2015 anthony geiger
** Last update Tue Feb  3 13:05:01 2015 anthony geiger
*/

#include "allum.h"

void			low_case_hard(int nb, int i, int *tab_all, int check)
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
      tab_all[i] = 0;
    }
  else if (nb == 1)
    {
      i = 0;
      while (tab_all[i] == 0)
	i++;
      if (tab_all[i] == 1)
	tab_all[i] = 0;
      else
	tab_all[i] = 1;
    }
  else
    check_imper(tab_all, check);
}

void			hard_ia(int *tab_all)
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
  low_case_hard(nb, i, tab_all, check);
}
