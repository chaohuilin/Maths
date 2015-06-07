/*
** vector3d.h for vector in /home/lin_c/Downloads/203hotline/graph
** 
** Made by LIN Chaohui
** Login   <lin_c@epitech.net>
** 
** Started on  Sun Mar 29 22:02:41 2015 LIN Chaohui
** Last update Sun Mar 29 22:02:45 2015 LIN Chaohui
*/

#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D
{
public:
    double X;
    double Y;
    double Z;

    Vector3D();
    Vector3D(double x,double y,double z);
    Vector3D(const Vector3D & v);
    Vector3D(const Vector3D & from,const Vector3D & to);

    Vector3D & operator= (const Vector3D & v);

    Vector3D & operator+= (const Vector3D & v);
    Vector3D operator+ (const Vector3D & v) const;

    Vector3D & operator-= (const Vector3D & v);
    Vector3D operator- (const Vector3D & v) const;

    Vector3D & operator*= (const double a);
    Vector3D operator* (const double a)const;
    friend Vector3D operator* (const double a,const Vector3D & v);

    Vector3D & operator/= (const double a);
    Vector3D operator/ (const double a)const;

    Vector3D crossProduct(const Vector3D & v)const;
    double length()const;
    Vector3D & normalize();
};

#endif //VECTOR3D_H
