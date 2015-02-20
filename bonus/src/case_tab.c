/*
** case_tab.c<2> for case_tab in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb  3 12:57:24 2015 anthony geiger
** Last update Tue Feb  3 12:58:12 2015 anthony geiger
*/

#include "my.h"
#include "win.h"
#include "allum.h"

int	case_left(int *tab_all, int row, int size, int *select)
{
  (void)size;
  if (*select == 1)
    {
      if (tab_all[row] <= 0)
	return (row);
      else
	tab_all[row]--;
    }
  return (row);
}

int	case_down(int *tab_all, int row, int size, int *select)
{
  if (*select == 0)
    {
      if ((row) >= size - 1)
	{
	  row = 0;
	  while (tab_all[row] == 0)
	    row++;
	}
      else
	{
	  row = row + 1;
	  if (tab_all[row] == 0)
	    while (tab_all[row] == 0)
	      row++;
	}
    }
  return (row);
}

int	case_space(int *tab_all, int row, int size, int *select)
{
  (void)size;
  if (tab_all[row] <= 0)
    return (row);
  if (*select == 0)
    *select = 1;
  return (row);
}

int	case_hight(int *tab_all, int row, int size, int *select)
{
  int	i;

  i = 0;
  if (*select == 0)
    {
      while (tab_all[i] == 0)
	i++;
      if (row <= i)
	{
	  row = size - 1;
	  while (tab_all[row] == 0)
	    row--;
	}
      else
	{
	  row = row - 1;
	  while (tab_all[row] == 0)
	    row--;
	}
    }
  return (row);
}

int			my_ptr_tab(unsigned long buffer, int *tab_all,
				   t_place *s, int *select)
{
  static const t_key	tab_ptr[] =
    {
      {LEFT, &case_left},
      {DOWN, &case_down},
      {HIGHT, &case_hight},
      {SPACE, &case_space}
    };
  int			i;

  i = 0;
  while (buffer != tab_ptr[i].key)
    i++;
  if ((s->row = tab_ptr[i].ptr_tab(tab_all, s->row, s->size, select)) == -1)
    return (-1);
  return (s->row);
}
