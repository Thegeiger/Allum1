/*
** allum.h for allum in /home/geiger_a/rendu/allum1/include
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Jan 27 15:12:01 2015 anthony geiger
** Last update Fri Feb 13 10:08:44 2015 anthony geiger
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

int                     my_aff_allum(int *tab_all, int size);
int	my_allum1(int *tab_all, int size, int nb_line, int nb_row);
int			*my_put_allum(int size);
int		nb_line_know();
int		nb_row_know();
void			check_imper(int *tab_all, int check);
int			bot_turn(int *tab_all, int dif);
void			easy_ia(int *tab_all);
void			low_case(int nb, int i, int *tab_all, int check);
void			normal_ia(int *tab_all);
void			low_case_hard(int nb, int i, int *tab_all, int check);
void			hard_ia(int *tab_all);
void			case_one_super(int *tab_all, int i);
void			low_case_super(int nb, int i, int *tab_all, int check);
void			super_ia(int *tab_all);
void			chuck_noris(int *tab_all);
void			nothing();
int			check_lose(int *tab_all);
int	my_verif_size_dif(int size, int dif);
int	my_win(int win, int dif);
int	my_main_loop(int *tab_all, int size, int dif, int nb_row);

#endif /* !WIN_H_ */
