#include  <string.h>
#include  <errno.h>
#include  <unistd.h>
#include  <stdlib.h>
#include  <stdio.h>
#include  <math.h>
#include  "208chevillettes.h"

void  printResult(t_result res[9], int deg_lib)
{
  int i = 0;
  while (i < deg_lib)
    {
      res[i].val_Tx *= 100;
      i++;
    }
    switch (deg_lib)
      {
        case 7:
          {
            cas1(res, deg_lib);
            break;
          }
        case 8:
          {
            cas2(res, deg_lib);
            break;
          }
        case 9:
          {
            cas3(res, deg_lib);
            break;
          }
      }
}

void  cas1(t_result res[9], int deg_lib)
{
   printf ("x\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|total\n",
      res[0].name, res[1].name, res[2].name, res[3].name, res[4].name,
      res[5].name, res[6].name);
    printf ("________________________________________________________________________\n");
    printf ("Ox\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%d\n",
      res[0].val_Ox, res[1].val_Ox, res[2].val_Ox, res[3].val_Ox,
      res[4].val_Ox, res[5].val_Ox, res[6].val_Ox, 100);
    printf ("Tx\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%d\n",
      res[0].val_Tx, res[1].val_Tx, res[2].val_Tx, res[3].val_Tx,
      res[4].val_Tx, res[5].val_Tx, res[6].val_Tx, 100);
}

void  cas2(t_result res[9], int deg_lib)
{
   printf ("x\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|total\n",
      res[0].name, res[1].name, res[2].name, res[3].name, res[4].name,
      res[5].name, res[6].name, res[7].name);
    printf ("____________________________________________________________________________________\n");
    printf ("Ox\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%d\n",
      res[0].val_Ox, res[1].val_Ox, res[2].val_Ox, res[3].val_Ox,
      res[4].val_Ox, res[5].val_Ox, res[6].val_Ox, res[7].val_Ox, 100);
    printf ("Tx\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%d\n",
      res[0].val_Tx, res[1].val_Tx, res[2].val_Tx, res[3].val_Tx,
      res[4].val_Tx, res[5].val_Tx, res[6].val_Tx, res[7].val_Tx, 100);
}

void  cas3(t_result res[9], int deg_lib)
{
  printf ("x\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|total\n",
      res[0].name, res[1].name, res[2].name, res[3].name, res[4].name,
      res[5].name, res[6].name, res[7].name, res[8].name);
    printf ("___________________________________________________________________________________________________\n");
    printf ("Ox\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%0.0f\t|%d\n",
      res[0].val_Ox, res[1].val_Ox, res[2].val_Ox, res[3].val_Ox,
      res[4].val_Ox, res[5].val_Ox, res[6].val_Ox, res[7].val_Ox,
      res[8].val_Ox, 100);
    printf ("Tx\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%0.1f\t|%d\n",
      res[0].val_Tx, res[1].val_Tx, res[2].val_Tx, res[3].val_Tx,
      res[4].val_Tx, res[5].val_Tx, res[6].val_Tx, res[7].val_Tx,
      res[8].val_Tx, 100);
}