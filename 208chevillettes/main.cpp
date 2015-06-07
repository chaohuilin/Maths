#include	<string.h>
#include	<errno.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>
#include	"208chevillettes.h"

void	run(t_variable *_var)
{
  int		_end = 1;
  t_result	res[9];
  double	sommeCarre = 0; 
  double  max; 
  double  min;
  int		deg_lib = 0; 
  int i = 0;

  calcP(_var);
  loiBinomial(_var->p, _var);
  deg_lib = verifVal(_var, res);
  printResult(res, deg_lib);
  sommeCarre = calcCarre(res, deg_lib);
  printf ("\nloi choisie :\t\t\tB(100, %.4f)\n",_var->p);
  printf ("somme des carrés des écarts :\tX² = %.3f\n", sommeCarre);
  printf ("degrés de liberté :\t\tv = %d\n", (deg_lib - 2));
  while (i < 14 && _end != 0)
    {
      if (sommeCarre > donnees[deg_lib - 2].nb[i])
	       i++;
      else
	      {
      	  _end = 0;
      	  max = donnees[0].nb[i - 1];
      	  min = donnees[0].nb[i];
      	}
    }
  printf ("validité de l’ajustement :\t%.0f%% < P < %.0f%%\n", min, max);
}

int	main(int argc, char *argv[])
{
  t_variable	variable;

  if (argc != 10)
    {
      fprintf(stderr, "[Error] : No Enough Parameters\n");
      return (EXIT_FAILURE);
    }
  if (initVariable(&variable, argv) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  run(&variable);
  return EXIT_SUCCESS;
}
