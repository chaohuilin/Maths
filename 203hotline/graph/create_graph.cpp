//
// create_graph.cpp for create_graph in /home/lin_c/Downloads/203hotline/graph
// 
// Made by LIN Chaohui
// Login   <lin_c@epitech.net>
// 
// Started on  Sun Mar 29 21:55:17 2015 LIN Chaohui
// Last update Sun Mar 29 22:16:38 2015 LIN Chaohui
//

#include "create_graph.h"
#include "sdl.h"
#define FPS 60
#define LARGEUR_FENETRE 1800
#define HAUTEUR_FENETRE 900

double angleZ = 0;
double angleX = 0;
GLuint texture1;

Camera *camera;

void stop()
{
    delete camera;
    SDL_Quit();
}

int		graphic(char *arg)
{
  SDL_Event	event;
  const Uint32 time_per_frame = 1000/FPS;
  unsigned int width = LARGEUR_FENETRE;
  unsigned int height = HAUTEUR_FENETRE;

  Uint32 last_time,current_time,elapsed_time; //for time animation
  Uint32 start_time,stop_time; //for frame limit

  SDL_Init(SDL_INIT_VIDEO);
  atexit(stop);

  SDL_WM_SetCaption("203hotline", NULL);
  SDL_SetVideoMode(width, height, 32, SDL_OPENGL);

  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  gluPerspective(70,(double)width/height,0.001,1000);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  //  texture1 = loadTexture("lastru_g.jpg");

  camera = new Camera(Vector3D(50, -50, 50));

  last_time = SDL_GetTicks();
  for (;;)
    {
      start_time = SDL_GetTicks();
      while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                exit(0);
                break;
                case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    exit(0);
                    break;
                    default :
                    camera->OnKeyboard(event.key);
                }
                break;
                case SDL_KEYUP:
                camera->OnKeyboard(event.key);
                break;
                case SDL_MOUSEMOTION:
                camera->OnMouseMotion(event.motion);
                break;
                case SDL_MOUSEBUTTONUP:
                case SDL_MOUSEBUTTONDOWN:
                camera->OnMouseButton(event.button);
                break;
            }
        }

      current_time = SDL_GetTicks();
      elapsed_time = current_time - last_time;
      last_time = current_time;

      camera->animate(elapsed_time);

      Dessiner(arg);

      stop_time = SDL_GetTicks();
      if ((stop_time - last_time) < time_per_frame)
        {
            SDL_Delay(time_per_frame - (stop_time - last_time));
        }

    }

  return 0;
}

void		Dessiner(char *arg)
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glBindTexture(GL_TEXTURE_2D, texture1);

  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity( );

  camera->look();

  draw_bino(arg);
  draw_poisson(arg);

  int	j = -1;
  while (j++ < 15)
    cube(-2, 0, j * 4, 0.2, 3);

  int	i = 0;
  while (i++ < 50)
    cube(i * 3, 0, -4, 0.2, 3);

  glFlush();
  SDL_GL_SwapBuffers();
}


void		draw_bino(char *arg)
{
  double	res;
  double	p;
  long double	a = 0;
  long double	b = 3500;

  p = atof(arg) / (double)28800;
  while (a < 50)
    {
      res = combinaison(a, b) * pow(p, a) * pow((1 - p), (b - a));
      a += 1;
      cube(a * 3, 0, 0, res * 400, 0);
    }
}

void		draw_poisson(char *arg)
{
  double	res;
  double	p;
  int		a = 0;

  p = atof(arg) / (double)28800;
  p *= 3500;
  while (a < 50)
    {
      res = (exp(-p) *  pow(p, a)) / (fact(a));
      a += 1;
      cube(a * 3 + 1, 0, 0, res * 400, 1);
    }

}
