/*
Header file for  framework supporting DOT FastLane project
File: shapes.h 
Name: Ruben Navarro
Date: 10/20/17
Version: 1.0                                                                                                          
*/

#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>
#include <cstdlib>
#include <cstdint>


class Shape
{
  public:
    virtual const char* Name () const; // virtual member function prototype to return "generic" 
    virtual float Volume     () const; // virtual member function prototype to return volume of object
    virtual float Area       () const; // virtual member function prototype to return area of object

    Shape                    (); // default constructor
    Shape                    (float x, float y, float z, bool verbose = false); //argument consturctor 
    virtual ~Shape           (); // virtual shape destructor

  protected:
    float x_, y_, z_; // dimensions of shape
    bool verbose_ = false; 

  private:
    Shape                    (const Shape& s); // copy constructor
    Shape& operator=         (const Shape& s); // assignment operator constructor
}; // end of shape class

class Box : public Shape
{
  public:
    virtual const char* Name   () const; // virtual member function prototype to return "box"
    virtual float Volume       () const; // virtual member function prototype to return volume of box object 
    virtual float Area         () const; // virtual member function prototype to return surface area of box object

    Box                        (); // default constructor
    Box                        (float width, float length,float height, bool verbose = false); // argument constructor
    virtual ~Box               (); // virtual box destructor

  private:
  Box                        (const Box& b); // copy constructor
  Box& operator=             (const Box& b); // assignment operator constructor
};

class Cylinder : public Shape
{
  public:
    virtual const char* Name   () const; // virtual member function prototype to return "cylinder"
    virtual float Volume       () const; // virtual member function prototype to return volume of cylinder object
    virtual float Area         () const; // virtual member function prototype to return surface area of cylinder object

    Cylinder                   (); // default constructor
    Cylinder                   (float radius, float height, bool verbose = false); //argument constructor 
    virtual ~Cylinder          (); // virtual cylinder destructor

  private:
    Cylinder                   (const Cylinder& c); // copy constructor
    Cylinder& operator=        (const Cylinder& c); // assigment operator constructor
};

class Rectangle : public Shape
{
  public:
    virtual const char* Name   () const; // virtual member function prototype returns "rectangle"
    virtual float Area         () const; // returns area of rectangle object

    Rectangle                  (); // default constructor
    Rectangle                  (float width, float length, bool verbose = false); // argument constructor
    virtual ~Rectangle         (); // virtual rectangle destructor

  private:
    Rectangle                  (const Rectangle& r); // copy constructor
    Rectangle& operator=       (const Rectangle& r); // assignment operator constructor
};

#endif
