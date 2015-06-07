/*
** qi.h for 205QI in /home/han_d/rendu/205QI
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Mon Apr 13 15:31:59 2015 Daniel Han
** Last update Mon Apr 13 16:53:12 2015 Daniel Han
*/

#ifndef QI_H_
# define QI_H_


# define WIN_WIDTH	1200
# define WIN_HEIGHT	600

#include	<SDL/SDL.h>

void	draw_fleche_x(SDL_Surface *ecran, SDL_Surface *rectangle, int fle);
void	draw_fleche_y(SDL_Surface *ecran, SDL_Surface *rectangle, int fle);
void	draw_axe_x(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_x);
void	draw_axe_y(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_y);
void	draw_lgd_x(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_x);
void	draw_lgd_y(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_y, int py);
void	draw_lgd(SDL_Surface *ecran);

double	gauss(double ect, double u, double i);
void	draw_func_rep(SDL_Surface *ecran, SDL_Surface *rectangle, double ect, double u);

void*	xmalloc(size_t size);
void	Pause();
void	draw_legend(SDL_Surface *ecran);//, SDL_Surface *rectangle, int x, int y)

/*
** result.c
*/
void	courbe_repartition_qi(double, double);
void	pourcentage_inferieur_qi(double, double, double);
void	pourcentage_intervalle_qi(double, double, double, double);

#endif /* !QI_H_ */
