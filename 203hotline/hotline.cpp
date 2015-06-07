//
// hotline.cpp for hotline in /home/lin_c/Downloads/203hotline
// 
// Made by LIN Chaohui
// Login   <lin_c@epitech.net>
// 
// Started on  Sun Mar 29 21:47:24 2015 LIN Chaohui
// Last update Sun Mar 29 21:47:25 2015 LIN Chaohui
//

#include "hotline.h"

long double	fact(long double nb)
{
  long double	value = nb;
  long double	res = 1;
  long double	i;

  for(i = 1; i <= value; i++) {
    res *= i;
  }
  return (res);
}

long double	combinaison(long double k, long double n)
{
  long double	res = 1;
  long double	elem;

  if (k == 0)
    return (1);
  else if (k == 1)
    return (n);
  else
    {
      elem = 1;
      while (elem <= k)
	{
	  res *= n - (k - elem);
	  elem += 1;
	}
      res = res / fact(k);
      return res;
    }
}

void	cas_one(char *arg1, char *arg2)
{
  long double k = (long double)atoi(arg1);
  long double n = (long double)atoi(arg2);
  std::cout << std::setprecision(0) << std::fixed;
  std::cout << "Combinaison de " <<  arg1 << " parmis " << arg2 << " : " << combinaison(k, n) << std::endl;
}

void	cas_two(char *arg)
{
  double	p;
  double	res;
  long double	a = 0;
  long double	b = 3500;
  double	enc = 0;
  clock_t	begin_time = clock();

  std::cout << std::setprecision(2) << std::fixed;
  p = atof(arg) / (double)28800;
  while (a < 50)
    {
      res = combinaison(a, b) * pow(p, a) * pow((1 - p), (b - a));
      if (a > 25)
	enc += res;
      a += 1;
    }
  std::cout << "Loi binomiale:" << std::endl << "\t\tTemps de calcul: " << TIME << "ms " << std::endl << "\t\tProbabilité d'encombrement: " << enc * 100 << " % " << std::endl;

  begin_time = clock();
  a = 0;
  enc = 0;
  p *= 3500;
  while (a < 50)
    {
      res = (exp(-p) *  pow(p, a)) / (fact(a));
      if (a > 25)
	enc += res;
      a += 1;
    }
  std::cout << "Loi de Poisson:" << std::endl << "\t\tTemps de calcul: " << TIME << std::fixed << "ms " << std::endl << "\t\tProbabilité d'encombrement: " << enc * 100 << " % " << std::endl;
  graphic(arg);
}
