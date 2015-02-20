/*
** allum.h for allum in /home/geiger_a/rendu/allum1/include
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Jan 27 15:12:01 2015 anthony geiger
** Last update Tue Feb  3 13:02:32 2015 anthony geiger
*/

#ifndef ALLUM_H_
# define ALLUM_H_

# define HIGHT 4283163
# define DOWN 4348699
# define LEFT 4479771
# define RIGHT 4414235
# define ESC 27
# define ENTER 10
# define SPACE 32

# include <sys/ioctl.h>
# include <ncurses/curses.h>
# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>

typedef	struct		s_key
{
  unsigned long		key;
  int			(*ptr_tab)(int *tab_all, int row, int size, int *select);
}			t_key;

typedef	struct		s_boot
{
  int			key;
  void			(*ptr_tab)(int *tab_all);
}			t_boot;

typedef struct		s_place
{
  int			row;
  int			size;
}			t_place;

int			my_actualisation(struct termios *term);
int			my_putc(int c);
int			my_start(struct termios *term, char **env);
int			my_rest(struct termios *term, int win, int dif);
int			my_aff_allum(int *tab_all, int size, int row, int i);
int			case_left(int *tab_all, int row, int size, int *select);
int			case_down(int *tab_all, int row, int size, int *select);
int			case_space(int *tab_all, int row, int size, int *select);
int			case_hight(int *tab_all, int row, int size, int *select);
int			my_ptr_tab(unsigned long buffer, int *tab_all,
				   t_place *s, int *select);
int			my_allum1(unsigned long buffer, int *tab_all,
				  int size, int boole);
int			*my_put_allum(int size);
void			check_imper(int *tab_all, int check);
void			easy_ia(int *tab_all);
void			low_case(int nb, int i, int *tab_all, int check);
void			normal_ia(int *tab_all);
void			low_case_hard(int nb, int i, int *tab_all, int check);
void			hard_ia(int *tab_all);
void			case_one_super(int *tab_all, int i);
void			low_case_super(int nb, int i, int *tab_all, int check);
void			super_ia(int *tab_all);
void			chuck_noris(int *tab_all);
int			bot_turn(int *tab_all, int dif);
void			nothing();
int			check_lose(int *tab_all);
int			my_main_loop(int *tab_all, int size, int dif);
int			my_verif_size_dif(int size, int dif);

#endif /* !WIN_H_ */
