/*
** getnb.c for getnb in /home/geiger_a/rendu/allum1/lib/my/src/str
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Mon Jan 26 10:42:33 2015 anthony geiger
** Last update Mon Jan 26 10:43:58 2015 anthony geiger
*/

#include "my.h"

int     my_getnb(char *str)
{
  int   i;
  int   nb;
  int   neg;

  nb = 0;
  i = 0;
  neg = 1;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
        nb = 10 * nb + str[i] - '0';
      if (str[i] == '-')
        neg *= - 1;
      ++i;
    }
  return (nb);
}
