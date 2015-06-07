/*
** canard.h for 204canards in /home/han_d/rendu/204canards
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Sun Apr 12 21:09:38 2015 Daniel Han
** Last update Sun Apr 12 21:14:26 2015 Daniel Han
*/

#ifndef  CANARD_H_
# define CANARD_H_

# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>

# define MAX 4096
# define WHITE 0xffffffff

typedef struct	s_canard
{
  SDL_Surface	*_screen;
  float		number;
  float		loop;
  float		res;
  float		result;
  float		x1[MAX];
  float		y1[MAX];
  float		x2[MAX];
  float		y2[MAX];
  int		color[1][3];
}		t_canard;

/*
** display_cas.c
*/
void		cas1(t_canard *);
void		cas2(t_canard *);
void		cas3(t_canard *);
void		cas4(t_canard *);

/*
** calc.c
*/
void		Display_graph(t_canard *, float *, float *);
void		myDisplay(t_canard *);
float		f(float, float);
void		display_res(t_canard *);
void		display_res2(t_canard *);


/*
** initSDL.c
*/
void		freeSDL(t_canard *);
void		drawArrow(t_canard *);
void		decorationWindow(t_canard *);
void		loopSDL(t_canard *);
int		initSDL(t_canard *);

/*
** main.c
*/
void		cleanStruct(t_canard *);
void		initColor(t_canard *);

#endif		/* !CANARD_H_ */
