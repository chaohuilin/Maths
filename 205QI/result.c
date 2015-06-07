/*
** result.c for 205QI in /home/han_d/rendu/205QI
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Mon Apr 13 15:49:42 2015 Daniel Han
** Last update Mon Apr 13 17:20:38 2015 Daniel Han
*/

#include <stdio.h>
#include <math.h>
#include "qi.h"
#include  <SDL/SDL.h>
#include  <SDL/SDL_gfxPrimitives.h>
#include <unistd.h>

double		f(double moy, double et, double i)
{
  return ((1.f / (et * sqrt(2.f * M_PI))) *
	  exp(-1 * (pow((i - moy), 2.f)) / (2.f * pow(et, 2.f))));
}

void  draw_legend(SDL_Surface *ecran)
{
  rectangleColor(ecran, 100, 100, 280, 150, 0xffffffff);
  lineColor(ecran, 120, 126, 150, 126, 0x3a3affff);
  stringColor(ecran, 155, 123, "Repartition", 0xffffffff);
  stringColor(ecran, (WIN_WIDTH / 2), (WIN_HEIGHT - 30), "QI", 0xffffffff);
  SDL_Flip(ecran);
}

void  draw_func_rep(SDL_Surface *ecran, SDL_Surface *rectangle, double moy, double et)
{
  int   t, i = 0;
  double  t2;
  double  tmp;
  Sint16  vx[200];
  Sint16  vy[200];
  double  total = 0;

  for ((t = 0, t2 = 0); t2 < 200; (t2 += 0.01))
    {
      tmp = f(moy, et, (t2));
      if(i == 100)
      {
        t++;
        vx[t] = (int)(50 + t * 5);
        vy[t] = (WIN_HEIGHT - 50) - (total + tmp) * 5;
        i = 0;
      }
      total += tmp;
      if (i == 0)
        pixelColor(ecran, vx[t], vy[t], 0x3a3affff);
      if (t > 5)
        lineColor(ecran, vx[t - 1], vy[t - 1], vx[t], vy[t], 0x3a3affff);
      i++;
    }
  SDL_Flip(ecran);
}

void		courbe_repartition_qi(double moy, double et)
{
   SDL_Surface  *ecran = NULL, *rectangle = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
  ecran = SDL_SetVideoMode(WIN_WIDTH, WIN_HEIGHT, 32, SDL_HWSURFACE| SDL_DOUBLEBUF);
  if (ecran == NULL)
    {
      fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 1,2, 32, 0, 0, 0, 0);
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 12,2,45));
  draw_legend(ecran);
  draw_lgd(ecran);
  draw_axe_x(ecran, rectangle, WIN_HEIGHT - 50);
  draw_lgd_x(ecran, rectangle, WIN_HEIGHT - 50);
  draw_axe_y(ecran, rectangle, 50);
  draw_lgd_y(ecran, rectangle, 50, 25);
  draw_func_rep(ecran, rectangle, moy, et);
  sleep(10);
  //Pause();
  SDL_FreeSurface(rectangle);
  SDL_Quit();
}

void		pourcentage_inferieur_qi(double moy, double et, double qi)
{
  double	i;
  double	res;

  i = 0;
  res = 0;
  while (i < qi)
    {
      res += f(moy, et, i);
      i += 0.01;
    }
  printf("%.1f%% des personnes ont un QI inférieur à %d\n", res, (int)qi);
}

void		pourcentage_intervalle_qi(double moy, double et, double qi,
					  double qi2)
{
  double	i;
  double	res;

  i = qi;
  res = 0;
  while (i < qi2)
    {
      res += f(moy, et, i);
      i += 0.01;
    }
  printf("%.1f%% des personnes ont un QI compris entre %d et %d\n",
	 res, (int)qi, (int)qi2);
}
