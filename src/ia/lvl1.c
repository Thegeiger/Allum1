/*
** lvl1.c<2> for lvl 1 in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb  3 12:48:51 2015 anthony geiger
** Last update Thu Feb 12 13:33:50 2015 anthony geiger
*/

#include "allum.h"

void			easy_ia(int *tab_all)
{
  int			i;
  int			check;

  check = 0;
  i = 0;
  while (tab_all[i] != - 1)
    {
      check = check + tab_all[i];
      i++;
    }
  check_imper(tab_all, check);
}
