//
// objects.cpp for Init_block in /home/lin_c/Downloads/203hotline/graph
// 
// Made by LIN Chaohui
// Login   <lin_c@epitech.net>
// 
// Started on  Sun Mar 29 14:37:03 2015 LIN Chaohui
// Last update Sun Mar 29 21:59:12 2015 LIN Chaohui
//

#include "objects.h"

void		cube(double x, double y, double z, double size, int methode)
{
  glBegin(GL_POLYGON);
  glColor3f( 10.0, 10.0, 0.0);     glVertex3f(  0.5 + x, -0.5 + y, -0.5 + z); 
  glColor3f( 0.0, 10.0, 10.0);     glVertex3f(  0.5 + x,  0.5 + y, -0.5 + z );
  glColor3f( 20.0, 0.0, 5.0);     glVertex3f( -0.5 + x,  0.5 + y, -0.5 + z );  
  glColor3f( 25.0, 0.0, 1.0);     glVertex3f( -0.5 + x, -0.5 + y, -0.5 + z );  
  glEnd();

  // Gray side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   0.10,  0.20, 0.0);
  glVertex3f(  0.5 + x, -0.5 + y, 0.5 + z + size);
  glVertex3f(  0.5 + x,  0.5 + y, 0.5 + z + size);
  glVertex3f( -0.5 + x,  0.5 + y, 0.5 + z + size);
  glVertex3f( -0.5 + x, -0.5 + y, 0.5 + z + size);
  glEnd();

  // Blue side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.2,  0.0);
  glVertex3f( 0.5 + x, -0.5 + y, -0.5 + z);
  glVertex3f( 0.5 + x,  0.5 + y, -0.5 + z);
  glVertex3f( 0.5 + x,  0.5 + y,  0.5 + z + size);
  glVertex3f( 0.5 + x, -0.5 + y,  0.5 + z + size);
  glEnd();

  // Dark red side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.1,  0.20,  0.0);
  glVertex3f( -0.5 + x, -0.5 + y,  0.5 + z + size);
  glVertex3f( -0.5 + x,  0.5 + y,  0.5 + z + size);
  glVertex3f( -0.5 + x,  0.5 + y, -0.5 + z);
  glVertex3f( -0.5 + x, -0.5 + y, -0.5 + z);
  glEnd();

  // Green side - TOP
  glBegin(GL_POLYGON);
  if (methode == 0)
    glColor3f(   1.0,  0.0,  0.0);
  else if (methode == 1)
    glColor3f(   0.0,  1.0,  0.0);
  else
    glColor3f(   5.0,  5.0,  5.0);
  glVertex3f(  0.5 + x,  0.5 + y,  0.5 + z + size);
  glVertex3f(  0.5 + x,  0.5 + y, -0.5 + z);
  glVertex3f( -0.5 + x,  0.5 + y, -0.5 + z);
  glVertex3f( -0.5 + x,  0.5 + y,  0.5 + z + size);
  glEnd();

  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  if (methode == 0)
    glColor3f(1.0,  0.0,  0.0);
  else if (methode == 1)
    glColor3f(0.0,  1.0,  0.0);
  else
    glColor3f(5.0,  5.0,  5.0);
  glVertex3f(  0.5 + x, -0.5 + y, -0.5 + z);
  glVertex3f(  0.5 + x, -0.5 + y,  0.5 + z + size);
  glVertex3f( -0.5 + x, -0.5 + y,  0.5 + z + size);
  glVertex3f( -0.5 + x, -0.5 + y, -0.5 + z);
  glEnd();
}
