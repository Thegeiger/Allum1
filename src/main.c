/*
** main.c for main in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb  3 12:26:16 2015 anthony geiger
** Last update Fri Feb 13 10:07:47 2015 anthony geiger
*/

#include <ncurses/curses.h>
#include <termcap.h>
#include <term.h>
#include <termios.h>
#include <signal.h>
#include "my.h"
#include "win.h"
#include "allum.h"

int			main(int argc, char **argv)
{
  int			size;
  int			*tab_all;
  int			ret;
  int			dif;

  size = 0;
  if (argc != 3)
    return (0);
  size = my_getnb(argv[1]);
  dif = my_getnb(argv[2]);
  if (my_verif_size_dif(size, dif) == 1)
    return (1);
  if ((tab_all = my_put_allum(size)) == NULL)
    return (1);
  if ((ret = my_main_loop(tab_all, size, dif, 0)) == 1)
    return (1);
  if (my_win(ret, dif) == - 1)
    return (1);
  return (0);
}
