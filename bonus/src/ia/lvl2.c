/*
** lvl2.c<2> for ia in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb  3 12:49:38 2015 anthony geiger
** Last update Tue Feb  3 13:04:52 2015 anthony geiger
*/

#include "allum.h"

void			low_case(int nb, int i, int *tab_all, int check)
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
  else
    check_imper(tab_all, check);
}

void			normal_ia(int *tab_all)
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
  low_case(nb, i, tab_all, check);
}
