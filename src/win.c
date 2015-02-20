/*
** termcap.c<2> for termcap in /home/geiger_a/rendu/allum1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb  3 12:38:30 2015 anthony geiger
** Last update Thu Feb 12 13:33:48 2015 anthony geiger
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

int	my_win(int win, int dif)
{
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
