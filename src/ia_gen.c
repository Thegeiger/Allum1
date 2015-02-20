/*
** ai_gen.c<2> for ai in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb  3 12:43:30 2015 anthony geiger
** Last update Thu Feb 12 13:33:49 2015 anthony geiger
*/

#include "my.h"
#include "allum.h"

void			check_imper(int *tab_all, int check)
{
  int			i;

  i = 0;
  if (check % 2 == 0)
    {
      while (tab_all[i] == 0)
	i++;
      if (tab_all[i] >= 1)
	tab_all[i]--;
    }
  else
    {
      while (tab_all[i] == 0)
	i++;
      if (tab_all[i] >= 2)
	tab_all[i] = tab_all[i] - 2;
      else
	tab_all[i] = tab_all[i] - 1;
    }
}

int			bot_turn(int *tab_all, int dif)
{
  static const t_boot	tab_ptr[] =
    {
      {1, &easy_ia},
      {2, &normal_ia},
      {3, &hard_ia},
      {4, &super_ia},
      {5, &chuck_noris}
    };
  int			i;

  i = 0;
  while (dif != tab_ptr[i].key)
    i++;
  tab_ptr[i].ptr_tab(tab_all);
  return (0);
}
