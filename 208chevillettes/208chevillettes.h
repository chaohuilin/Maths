
#ifndef __208CHEVILLETTES_H_
# define __208CHEVILLETTES_H_

#define	EFF_MIN		10

typedef struct s_donnees
{
  int		lvl;
  double	nb[14];
} t_donnees;

extern t_donnees donnees[];

typedef struct s_variable
{
  double	o0[2];
  double	o1[2];
  double	o2[2];
  double	o3[2];
  double	o4[2];
  double	o5[2];
  double	o6[2];
  double	o7[2];
  double	o8[2];
  double	p;
}	t_variable;

typedef struct s_result
{
  char		*name;
  double	val_Ox;
  double	val_Tx;
} t_result;

//fonctions

void	loiBinomial(double tma, t_variable *var);
void  calcP(t_variable *var);
double  calcCarre(t_result res[9], double deg_lib);

//print result

void  printResult(t_result res[9], int deg_lib);
void  cas1(t_result res[9], int deg_lib);
void  cas2(t_result res[9], int deg_lib);
void  cas3(t_result res[9], int deg_lib);

//check values

int verifVal(t_variable *var, t_result res[9]);
int initVariable(t_variable *var, char *argv[]);

//check TabCase

void lessValues(t_variable *var, t_result res[9], int i,const char *s1, const char *s2);
int case1(t_variable *var, t_result res[9], int i);
int case2(t_variable *var, t_result res[9], int i);
int case3(t_variable *var, t_result res[9], int i);
int case4(t_variable *var, t_result res[9], int i);
int case5(t_variable *var, t_result res[9], int i);
int case6(t_variable *var, t_result res[9], int i);
int case7(t_variable *var, t_result res[9], int i);
int case8(t_variable *var, t_result res[9], int i);


#endif /* __208CHEVILLETTES_H_ */
