
#include	<SDL/SDL_gfxPrimitives.h>
#include	"qi.h"

void		draw_lgd_x(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_x)
{
  int		a, b, af;
  SDL_Rect	position;
  char	buff[4];

  memset(buff, '\0', 4);
  for ((af = 0, a = 50); a < WIN_WIDTH; (a += (50 * 5), af += 50))
    {
      position.x = a;
      for (b = pos_x - 6; b < pos_x; b++)
	{
	  position.y = b;
	  SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 0, 255, 255));
	  SDL_BlitSurface(rectangle, NULL, ecran, &position);
	}
      sprintf(buff, "%d", af);
      stringColor(ecran, a - 5, (WIN_HEIGHT - 45), buff, 0xffffffff);
      memset(buff, '\0', 4);
    }
  a -= (50 * 5);
  SDL_Flip(ecran);
}

void		draw_axe_x(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_x)
{
  int		a;
  SDL_Rect	position;

  for (a = 50; a < WIN_WIDTH; a++)
    {
      position.x = a;
      position.y = pos_x;
      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 0, 255, 255));
      SDL_BlitSurface(rectangle, NULL, ecran, &position);
    }
  SDL_Flip(ecran);
}

void		draw_lgd(SDL_Surface *ecran)
{
  char	buff[12];
  int	i;

  memset(buff, '\0', 12);
  sprintf(buff, "Prob");
  for (i = 0; i < 11; i++)
    {
      characterColor(ecran, 5 + (i * 10), 220/*(220 + (i * 20))*/, buff[i], 0xffffffff);
    }
  i += 4;
  stringColor(ecran, 4, (235), "(%)", 0xffffffff);
}

void		draw_lgd_y(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_y, int py)
{
  int		a, b, af;
  SDL_Rect	position;
  char		buff[4];

  memset(buff, '\0', 4);
  for ((af = 100, a = (50)); a < WIN_WIDTH; (a += (20 * 7), af -= 20))
    {
      position.y = a;
      for (b = pos_y ; b < pos_y + 6; b++)
	{
	  position.x = b;
	  SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 0, 255, 255));
	  SDL_BlitSurface(rectangle, NULL, ecran, &position);
	}
      sprintf(buff, "%d", af);
      stringColor(ecran, (py), a - 3, buff, 0xffffffff);
      memset(buff, '\0', 4);
    }
  SDL_Flip(ecran);
}
void		draw_axe_y(SDL_Surface *ecran, SDL_Surface *rectangle, int pos_y)
{
  int		a;
  SDL_Rect	position;

  for (a = 0; a < WIN_HEIGHT - 50; a++)
    {
      position.x = pos_y;
      position.y = a;
      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 0, 255, 255));
      SDL_BlitSurface(rectangle, NULL, ecran, &position);
    }
  SDL_Flip(ecran);
}
