//
// camera.cpp for camera in /home/lin_c/Downloads/203hotline/graph
// 
// Made by LIN Chaohui
// Login   <lin_c@epitech.net>
// 
// Started on  Sun Mar 29 21:49:05 2015 LIN Chaohui
// Last update Sun Mar 29 21:49:44 2015 LIN Chaohui
//

#include "camera.h"
#include <cmath>
#include <GL/glu.h>

Camera::Camera(const Vector3D & position)
{
    _position = position;
    _phi = 0;
    _theta = 0;
    VectorsFromAngles();

    _speed = 0.01;
    _sensivity = 0.2;
    _verticalMotionActive = false;
    _keyconf["forward"] = SDLK_z;
    _keyconf["backward"] = SDLK_s;
    _keyconf["strafe_left"] = SDLK_q;
    _keyconf["strafe_right"] = SDLK_d;
    _keyconf["boost"] = SDLK_LSHIFT;
    _keystates[_keyconf["forward"]] = false;
    _keystates[_keyconf["backward"]] = false;
    _keystates[_keyconf["strafe_left"]] = false;
    _keystates[_keyconf["strafe_right"]] = false;
    _keystates[_keyconf["boost"]] = false;
    SDL_WM_GrabInput(SDL_GRAB_ON);
    SDL_ShowCursor(SDL_DISABLE);
}

void Camera::OnMouseMotion(const SDL_MouseMotionEvent & event)
{
    _theta -= event.xrel*_sensivity;
    _phi -= event.yrel*_sensivity;
    VectorsFromAngles();
}

void Camera::OnMouseButton(const SDL_MouseButtonEvent & event)
{
    if ((event.button == SDL_BUTTON_WHEELUP)&&(event.type == SDL_MOUSEBUTTONDOWN))
    {
        _verticalMotionActive = true;
        _timeBeforeStoppingVerticalMotion = 250;
        _verticalMotionDirection = 1;

    }
    else if ((event.button == SDL_BUTTON_WHEELDOWN)&&(event.type == SDL_MOUSEBUTTONDOWN))
    {
        _verticalMotionActive = true;
        _timeBeforeStoppingVerticalMotion = 250;
        _verticalMotionDirection = -1;
    }
}

void Camera::OnKeyboard(const SDL_KeyboardEvent & event)
{
    for (KeyStates::iterator it = _keystates.begin();it != _keystates.end();
            it++)
    {
        if (event.keysym.sym == it->first)
        {
            it->second = (event.type == SDL_KEYDOWN);
            break;
        }
    }
}

void Camera::animate(Uint32 timestep)
{
    double realspeed = (_keystates[_keyconf["boost"]])?10*_speed:_speed;
    if (_keystates[_keyconf["forward"]])
        _position += _forward * (realspeed * timestep);
    if (_keystates[_keyconf["backward"]])
        _position -= _forward * (realspeed * timestep);
    if (_keystates[_keyconf["strafe_left"]])
        _position += _left * (realspeed * timestep);
    if (_keystates[_keyconf["strafe_right"]])
        _position -= _left * (realspeed * timestep);
    if (_verticalMotionActive)
    {
        if (timestep > _timeBeforeStoppingVerticalMotion)
            _verticalMotionActive = false;
        else
            _timeBeforeStoppingVerticalMotion -= timestep;
        _position += Vector3D(0,0,_verticalMotionDirection*realspeed*timestep);
    }
    _target = _position + _forward;

}

void Camera::setSpeed(double speed)
{
    _speed = speed;
}

void Camera::setSensivity(double sensivity)
{
    _sensivity = sensivity;
}

void Camera::setPosition(const Vector3D & position)
{
    _position = position;
    _target = _position + _forward;
}

void Camera::VectorsFromAngles()
{
    static const Vector3D up(0,0,1);
    if (_phi > 89)
        _phi = 89;
    else if (_phi < -89)
        _phi = -89;
    double r_temp = cos(_phi*M_PI/180);
    _forward.Z = sin(_phi*M_PI/180);
    _forward.X = r_temp*cos(_theta*M_PI/180);
    _forward.Y = r_temp*sin(_theta*M_PI/180);
    _left = up.crossProduct(_forward);
    _left.normalize();
    _target = _position + _forward;
}

void Camera::look()
{
    gluLookAt(_position.X,_position.Y,_position.Z,
              _target.X,_target.Y,_target.Z,
              0,0,1);
}

Camera::~Camera()
{
    SDL_WM_GrabInput(SDL_GRAB_OFF);
    SDL_ShowCursor(SDL_ENABLE);
}
