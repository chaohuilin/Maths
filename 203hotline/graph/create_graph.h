/*
** create_graph.h for create_graph.h in /home/han_d/Dropbox/EPITECH PROJET/TEK2/lin_c/203hotline/graph
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Sun Mar 29 22:52:22 2015 Daniel Han
** Last update Sun Mar 29 22:52:27 2015 Daniel Han
*/

#ifndef CREATE_GRAPH_HPP_
# define CREATE_GRAPH_HPP_

#include "../hotline.h"
#include "camera.h"
#include "objects.h"

class TrackBallCamera
{
public:
  TrackBallCamera();

  virtual void OnMouseMotion(const SDL_MouseMotionEvent & event);
  virtual void OnMouseButton(const SDL_MouseButtonEvent & event);
  virtual void OnKeyboard(const SDL_KeyboardEvent & event);

  virtual void look();
  virtual void setMotionSensivity(double sensivity);
  virtual void setScrollSensivity(double sensivity);

  virtual ~TrackBallCamera();
protected:
  double _motionSensivity;
  double _scrollSensivity;
  bool _hold;
  double _distance;
  double _angleY;
  double _angleZ;
  SDL_Cursor * _hand1;
  SDL_Cursor * _hand2;
};

void            Dessiner(char *arg);
void		stop();
int             graphic(char *arg);
void            draw_bino(char *arg);
void            draw_poisson(char *arg);

#endif
