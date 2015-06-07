/*
** neutrinos.h for 206neutrinos in /home/han_d/rendu/206neutrinos
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Mon May  4 03:50:53 2015 Daniel Han
** Last update Wed May  6 19:07:39 2015 Daniel Han
*/

#ifndef NEUTRINOS_H_
# define NEUTRINOS_H_

# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define BLACK	"\033[0;m"

typedef struct	s_neutrinos
{
  double	popu;
  double	et;
  double	moy_a;
  double	moy_q;
  double	moy_h;
  double	tmp;
}		t_neutrinos;

typedef struct			s_save
{
  unsigned long long int	cste;
  unsigned long long int	save_a;
  double			save_h;
}				t_save;

/*
** calculate.c
*/
void	calculate(t_neutrinos *, t_save *, double);
int	init(t_neutrinos *, t_save *, char **);

/*
** check.c (( return on success ? 0 : -1 ))
*/
int	is_integer(char *);

/*
** display_error.c
*/
void	display_parser_error();
void	display_av_error(int, char *);
void	display_usage_error(char *);

/*
** display_result.c
*/
void	display_result(t_neutrinos *);
void	display_goodbye();
void	display_prompt();

/*
** parser.c
*/
void	parser(t_neutrinos *, t_save *);

#endif /* !NEUTRINOS_H_ */
