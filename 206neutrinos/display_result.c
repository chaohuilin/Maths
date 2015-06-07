/*
** display_result.c for 206neutrinos in /home/han_d/rendu/206neutrinos
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Wed May  6 17:01:42 2015 Daniel Han
** Last update Wed May  6 18:40:53 2015 Daniel Han
*/

#include <stdio.h>
#include <unistd.h>
#include "neutrinos.h"

void	display_result(t_neutrinos *n)
{
  printf("\tantal mãlinder : \t %.0f\n", n->popu);
  printf("\tstandardafvilgelse : \t %.2f\n", n->et);
  printf("\taritmetisk gennemsnit :  %.2f\n", n->moy_a);
  printf("\tkvadratisk gennemsnit :  %.2f\n", n->moy_q);
  printf("\tharmonisk gennemsnit : \t %.2f\n\n", n->moy_h);
}

void	display_goodbye()
{
  printf("goodbye\n");
}

void	display_prompt()
{
  write(1, "indtast din vaerdi : ", 21);
}
