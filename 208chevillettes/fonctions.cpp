#include	<math.h>
#include	<gmpxx.h>
#include	"208chevillettes.h"

double		min(double a, double b)
{
  return ((a <= b) ? a : b);
}

mpz_class	 coeffBinomial(double n, double k)
{
  mpz_t b, tmp, tmp2, tmp3, i, k_, n_;
  double k2, i2 = 0;

  mpz_init_set_d(b, 1);
  mpz_init_set_d(i, 1);
  mpz_init_set_d(n_, n);
  mpz_init_set_d(tmp, 1);
  mpz_init_set_d(tmp2, 1);
  mpz_init_set_d(tmp3, 1);

  if ((k < 0) || (k > n))
    mpz_set_d(b, 0);
  else{
    k2 = min(k, (n - k));
    mpz_init_set_d(k_, k2);
    i2 = 1;
    while (i2 <= k2)
      {
	mpz_sub(tmp, n_, i);
	mpz_add_ui(tmp2, tmp, 1);
	mpz_mul(tmp3, b, tmp2);
	mpz_div(b, tmp3, i);
	mpz_add_ui(i, i, 1);
	i2++;
      }}
  mpz_class res(b);
  return (res);
}

void	loiBinomial(double p, t_variable *var)
{
  double	n = 100;
  int	k = 0;
  double	res = 0;
  double	tmp;

  while (k <= 50)
    {
      tmp = (coeffBinomial(n, k).get_d());
      tmp = (tmp * (pow(p, k)) * (pow((1 - p), (n - k))));
      switch (k)
      {
        case 0:
          var->o0[1] = tmp;
        case 1:
          var->o1[1] = tmp;
        case 2:
          var->o2[1] = tmp;
        case 3:
          var->o3[1] = tmp;
        case 4:
          var->o4[1] = tmp;
        case 5:
          var->o5[1] = tmp;
        case 6:
          var->o6[1] = tmp;
        case 7:
          var->o7[1] = tmp;
      }
      if (k > 7)
        var->o8[1] += tmp;
      res += tmp;
      k++;
    }
}

void  calcP(t_variable *var)
{
  var->p = (((0 * var->o0[0]) + (1 * var->o1[0]) + (2 * var->o2[0]) +
       (3 * var->o3[0]) + (4 * var->o4[0]) + (5 * var->o5[0]) +
       (6 * var->o6[0]) + (7 * var->o7[0]) +(8 * var->o8[0])) / 10000);
}

double  calcCarre(t_result res[9], double deg_lib)
{
  double  sommeCarre = 0;
  int   i = 0;

  while (i < deg_lib)
    {
      sommeCarre += (pow((res[i].val_Ox - res[i].val_Tx), 2) / res[i].val_Tx);
      i++;
    }
  return (sommeCarre);
}
