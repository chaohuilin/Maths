#include  <string>
#include  <errno.h>
#include  <unistd.h>
#include  <stdlib.h>
#include  <stdio.h>
#include  <math.h>
#include <iostream>
#include  "208chevillettes.h"

int	verifNumber(char *str)
{
  int	i = 0;

  while (str[i] != '\0')
    {
      if (!(str[i] == ',' || str[i] == '.' || (str[i] >= '0' && str[i] <= '9')))
      	return (1);
      if (str[i] == ',')
	str[i] = '.';
      i++;
    }
  return (0);
}

int initVariable(t_variable *var, char *argv[])
{
  var->o0[0] = atof(argv[1]);
  var->o1[0] = atof(argv[2]);
  var->o2[0] = atof(argv[3]);
  var->o3[0] = atof(argv[4]);
  var->o4[0] = atof(argv[5]);
  var->o5[0] = atof(argv[6]);
  var->o6[0] = atof(argv[7]);
  var->o7[0] = atof(argv[8]);
  var->o8[0] = atof(argv[9]);
  if (var->o0[0] < 0 || var->o1[0] < 0 || var->o2[0] < 0 || var->o3[0] < 0 ||
      var->o4[0] < 0 || var->o5[0] < 0 || var->o6[0] < 0 || var->o7[0] < 0 ||
      var->o8[0] < 0)
    {
      fprintf(stderr, "[Error] : Use of négatif value\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int	verifVal(t_variable *var, t_result res[9])
{
  int	i = 0;

  i = case1(var, res, i);
  i = case2(var, res, i);
  i = case3(var, res, i);
  i = case4(var, res, i);
  i = case5(var, res, i);
  i = case6(var, res, i);
  i = case7(var, res, i);
  i = case8(var, res, i);
  return (i);
}