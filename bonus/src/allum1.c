/*
** allum1.c for allum1 in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Mon Jan 26 10:20:45 2015 anthony geiger
** Last update Tue Feb  3 13:02:33 2015 anthony geiger
*/

#include <stdlib.h>
#include <sys/ioctl.h>
#include <ncurses/curses.h>
#include <termcap.h>
#include <term.h>
#include <termios.h>
#include <unistd.h>
#include "my.h"
#include "win.h"
#include "allum.h"

int	my_allum1(unsigned long buffer, int *tab_all, int size, int boole)
{
  static int		row;
  static int		select;
  t_place		s;

  tputs(tgetstr("cl", NULL), 1, my_putc);
  s.row = row;
  s.size = size;
  my_aff_allum(tab_all, size, row, 0);
  if (read(0, &buffer, 8) == - 1)
    return (-1);
  if (buffer == LEFT || buffer == DOWN || buffer == HIGHT || buffer == SPACE)
    row = my_ptr_tab(buffer, tab_all, &s, &select);
  else if (buffer == ESC)
    boole = 1;
  else if (buffer == ENTER)
    {
      if (select == 1)
	boole = 2;
      select = 0;
    }
  return (boole);
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

int			my_main_loop(int *tab_all, int size, int dif)
{
  int			ret;

  ret = 0;
  while (ret != 1)
    {
      if ((ret = my_allum1(0, tab_all, size, 0)) == - 1)
	return (2);
      if (check_lose(tab_all) == 1)
	return (3);
      if (ret == 2)
	if (bot_turn(tab_all, dif) == -1)
	  return (1);
      if (check_lose(tab_all) == 1)
	return (2);
    }
  return (0);
}
