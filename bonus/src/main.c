/*
** main.c for main in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb  3 12:26:16 2015 anthony geiger
** Last update Tue Feb  3 12:28:00 2015 anthony geiger
*/

#include <ncurses/curses.h>
#include <termcap.h>
#include <term.h>
#include <termios.h>
#include <signal.h>
#include "my.h"
#include "win.h"
#include "allum.h"

int			main(int argc, char **argv, char **env)
{
  int			size;
  struct termios	term;
  int			*tab_all;
  int			ret;
  int			dif;

  size = 0;
  if (argc != 3)
    return (0);
  signal(SIGINT, nothing);
  if (tcgetattr(0, &term) == - 1)
    return (1);
  size = my_getnb(argv[1]);
  dif = my_getnb(argv[2]);
  if (my_verif_size_dif(size, dif) == 1)
    return (1);
  if (my_start(&term, env) == -1)
    return (1);
  if ((tab_all = my_put_allum(size)) == NULL)
    return (1);
  if ((ret = my_main_loop(tab_all, size, dif)) == 1)
    return (1);
  if (my_rest(&term, ret, dif) == - 1)
    return (1);
  return (0);
}
