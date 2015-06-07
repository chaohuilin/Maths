/*
** hotline.h for 203 in /home/nguye_1/rendu/203hotline
**
** Made by Alexandre NGUYEN
** Login   <nguye_1@epitech.net>
**
** Started on  Fri Mar 28 18:01:50 2014 Alexandre NGUYEN
** Last update Sun Mar 29 22:17:10 2015 LIN Chaohui
*/

#ifndef HOTLINE_H_
# define HOTLINE_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <ctime>

#include "graph/create_graph.h"
#include "hotline.h"
#include "graph/sdl.h"

#define	TIME (float)((((float)clock() - (float)begin_time) / (float)CLOCKS_PER_SEC)) * 1000

long double     fact(long double nb);
long double     combinaison(long double  k, long double n);
void		cas_one(char *arg1, char *arg2);
void		cas_two(char *arg);
int		hotline(int ac, char **av);
int		main(int ac, char **av);

#endif /* HOTLINE_H_ */
