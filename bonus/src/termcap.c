/*
** termcap.c<2> for termcap in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb  3 12:38:30 2015 anthony geiger
** Last update Tue Feb  3 13:18:15 2015 anthony geiger
*/

#include <sys/ioctl.h>
#include <ncurses/curses.h>
#include <termcap.h>
#include <term.h>
#include <termios.h>
#include <unistd.h>
#include "my.h"
#include "win.h"
#include "allum.h"

int     my_actualisation(struct termios *term)
{
  if (tcsetattr(0, TCSANOW, term) == - 1)
    {
      my_putstr("Tcsetattr error.\n");
      return (- 1);
    }
  return (0);
}

int     my_putc(int c)
{
  int   ret;

  ret = write(1, &c, 1);
  return (ret);
}

int		my_start(struct termios *term, char **env)
{
  t_wind	win;

  (void)env;
  if (tgetent(NULL, "xterm") == - 1)
    {
      my_putstr("tgetent error\n");
      return (-1);
    }
  term->c_lflag &= ~ECHO;
  term->c_lflag &= ~ICANON;
  if (ioctl(0, TIOCGWINSZ, &win) == - 1)
    {
      my_putstr("ioctl error\n");
      return (-1);
    }
  tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putc);
  tputs(tgetstr("cl", NULL), 1, my_putc);
  tputs(tgetstr("vi", NULL), 1, my_putc);
  if (my_actualisation(term) == - 1)
    return (-1);
  return (0);
}

int	my_rest(struct termios *term, int win, int dif)
{
  term->c_lflag ^= ~ECHO;
  term->c_lflag ^= ~ICANON;
  if (my_actualisation(term) == - 1)
    return (-1);
  tputs(tgetstr("ve", NULL), 1, my_putc);
  tputs(tgetstr("cl", NULL), 1, my_putc);
  tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putc);
  if (win == 2)
    my_putstr("player win\n");
  if (win == 3)
    my_putstr("IA win\n");
  if (win == 3 && dif == 5)
    my_putstr("Chuck Noris win to EASY for him !\n");
  if (win == 2 && dif == 5)
    {
      my_putstr("If you take the last allum Chuck Noris win if ");
      my_putstr("you don't take the last allum you lose\n");
    }
  return (0);
}
