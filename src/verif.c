/*
** verif.c<2> for verif in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb  3 12:40:32 2015 anthony geiger
** Last update Thu Feb 12 13:33:49 2015 anthony geiger
*/

#include "my.h"
#include "allum.h"

void			nothing()
{
  return ;
}

int			check_lose(int *tab_all)
{
  int			i;

  i = 0;
  while (tab_all[i] == 0)
    ++i;
  if (tab_all[i] == - 1)
    return (1);
  else
    return (0);
}

int	my_verif_size_dif(int size, int dif)
{
  if (size <= 1)
    {
      my_putstr("map to small");
      return (1);
    }
  if (dif != 1 && dif != 2 && dif != 3 && dif != 4 && dif != 5)
    {
      my_putstr("wrong difficulty easy = 1, normal = 2, hard = 3,");
      my_putstr("super = 4, Chuck Noris = 5\n");
      return (1);
    }
  return (0);
}
