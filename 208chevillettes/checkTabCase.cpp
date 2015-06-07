#include  <string.h>
#include  <errno.h>
#include  <unistd.h>
#include  <stdlib.h>
#include  <stdio.h>
#include  <math.h>
#include <iostream>
#include  "208chevillettes.h"

void lessValues(t_variable *var, t_result res[9], int i,const char *s1, const char *s2)
{
  if ((var->o0[0] + var->o1[0]) < EFF_MIN)
  {
    res[i].val_Ox = (var->o0[0] + var->o1[0] + var->o2[0]);
    res[i].val_Tx = (var->o0[1] + var->o1[1] + var->o2[1]);
    res[i].name = strdup(s1);
    var->o1[0] = -1;
    var->o2[0] = -1;
  }
  else
  {
    res[i].val_Ox = (var->o0[0] + var->o1[0]);
    res[i].val_Tx = (var->o0[1] + var->o1[1]);
    res[i].name = strdup(s2);
    var->o1[0] = -1;
  }
}

int case1(t_variable *var, t_result res[9], int i)
{
	if(var->o0[0] < EFF_MIN)
	{
      lessValues(var, res, i, "0-2", "0-1");
	  i++;
	}
  	else
  	{
      res[i].val_Ox = (var->o0[0]);
      res[i].val_Tx = (var->o0[1]);
      res[i].name = strdup("0");
      i++;
    }
    return (i);
}

int case2(t_variable *var, t_result res[9], int i)
{
	if(var->o1[0] != -1 && var->o1[0] < EFF_MIN)
	{
      lessValues(var, res, i, "1-3", "1-2");
	  i++;
	}
  	else if (var->o1[0] != -1)
    {
      res[i].val_Ox = (var->o1[0]);
      res[i].val_Tx = (var->o1[1]);
      res[i].name = strdup("1");
      i++;
    }
    return (i);
}

int case3(t_variable *var, t_result res[9], int i)
{
	if(var->o2[0] != -1 && var->o2[0] < EFF_MIN)
	{
      lessValues(var, res, i, "2-4", "2-3");
      i++;
	}
	else if (var->o2[0] != -1)
	{
	    res[i].val_Ox = (var->o2[0]);
	    res[i].val_Tx = (var->o2[1]);
	    res[i].name = strdup("2");
	    i++;
	}
	return (i);
}

int case4(t_variable *var, t_result res[9], int i)
{
	if(var->o3[0] != -1 && var->o3[0] < EFF_MIN)
    {
      lessValues(var, res, i, "3-5", "3-4");
      i++;
    }
  	else if (var->o3[0] != -1)
    {
      res[i].val_Ox = (var->o3[0]);
      res[i].val_Tx = (var->o3[1]);
      res[i].name = strdup("3");
      i++;
    }
    return (i);
}

int case5(t_variable *var, t_result res[9], int i)
{
	if(var->o4[0] != -1 && var->o4[0] < EFF_MIN)
	{
      lessValues(var, res, i, "4-6", "4-5");
	  i++;
	}
  	else if (var->o4[0] != -1)
    {
      res[i].val_Ox = (var->o4[0]);
      res[i].val_Tx = (var->o4[1]);
      res[i].name = strdup("4");
      i++;
    }
    return (i);
}

int case6(t_variable *var, t_result res[9], int i)
{
	if(var->o5[0] != -1 && var->o5[0] < EFF_MIN)
      lessValues(var, res, i, "5-7", "5-6");
  	else if (var->o5[0] != -1)
    {
      res[i].val_Ox = (var->o5[0]);
      res[i].val_Tx = (var->o5[1]);
      res[i].name = strdup("5");
      i++;
    }
    return (i);
}

int case7(t_variable *var, t_result res[9], int i)
{
	if(var->o6[0] != -1 && var->o6[0] < EFF_MIN)
	{
      lessValues(var, res, i, "6+", "6-7");
	  i++;
	}
  	else if (var->o6[0] != -1)
    {
      res[i].val_Ox = (var->o6[0]);
      res[i].val_Tx = (var->o6[1]);
      res[i].name = strdup("6");
      i++;
    }
    return (i);
}

int case8(t_variable *var, t_result res[9], int i)
{
	if(var->o7[0] != -1 && (var->o7[0] < EFF_MIN || var->o8[0] < EFF_MIN))
    {
      if ((var->o7[0] + var->o8[0]))
    	{
    	  res[i].val_Ox = (var->o7[0] + var->o8[0]);
    	  res[i].val_Tx = (var->o7[1] + var->o8[1]);
    	  res[i].name = strdup("7+");
    	  var->o8[0] = -1;
    	}
    	i++;
    }
  else if (var->o7[0] != -1)
    {
      res[i].val_Ox = (var->o7[0]);
      res[i].val_Tx = (var->o7[1]);
      res[i].name = strdup("7");
      i++;
      res[i].val_Ox = (var->o8[0]);
      res[i].val_Tx = (var->o8[1]);
      res[i].name = strdup("8");
      i++;
    }
    return (i);
}
