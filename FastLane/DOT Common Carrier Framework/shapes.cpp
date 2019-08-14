/*
Implementation code file for shape header file
 
File: shapes.cpp
Name: Ruben Navarro
Date: 10/21/2017
Version: 1.0

*/

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <shapes.h>

Shape::Shape (float x, float y,float z, bool v) : x_(x), y_(y), z_(z), verbose_(v)
{
  if (verbose_) std::cout << "Shape(" << x << ',' << y  << ',' << z << ',' << v << ")" << std::endl; // output when construction occurs
}

Shape::~Shape()
{
  if (verbose_) std::cout << "~Shape()" << std::endl; // output when deconstruction occurs 
}

const char* Shape::Name () const
{
  return "generic"; // returns "generic"
}

float Shape::Volume() const
{
  return 0.00; // return no value
}

float Shape::Area() const
{
  return 0.00; // return no value
}  

Box::Box (float l, float w, float h, bool v) : Shape(l, w, h, v)
{
  if (verbose_) std::cout << "Box(" << l << ',' <<  w << ',' << h << ',' << v << ")" <<  std::endl; // output when construction occurs
}

Box::~Box()
{
  if (verbose_) std::cout << "~Box()" << std::endl; // output when destruction occurs
}

const char* Box::Name () const
{
  return "box"; // return "box"
}

float Box::Volume () const
{
  return ((x_ * y_) * z_); // calculate volume of box and return result 
}

float Box::Area () const
{
  float areaHw = (2 * (z_ * y_)); // calculate height and width
  float areaHl = (2 * (z_ * x_)); // calculate height and length 
  float areaWl = (2 * (y_ * x_)); // calculate width and length

  return (areaHw + areaHl + areaWl); // adds all calculations from above and returns area
}

Cylinder::Cylinder (float r, float h, bool v) : Shape (r, 0, h, v)
{
  if (verbose_) std::cout << "Cylinder(" << r << ',' <<  h << ',' << v << ")" <<  std::endl; // output when construction occurs 
}

Cylinder::~Cylinder()
{
  if (verbose_) std::cout << "~Cylinder()" << std::endl; // output when deconstruction occurs 
}

const char* Cylinder::Name () const
{
  return "cylinder"; // returns "cylinder 
}

float Cylinder::Volume () const
{
  return (M_PI * (pow(x_, 2.0)) * z_); // calculates and returns results for volume of a cylinder 
}

float Cylinder::Area () const
{
  return ((2 * M_PI * x_ * z_) + (2 * M_PI * (pow(x_, 2.0)))); // calculates and returns area for a cylinder
}

Rectangle::Rectangle (float w, float l, bool v) : Shape (w, l, 0 , v)
{
  if (verbose_) std::cout << "Rectangle(" << w << ',' << l << ',' << v << ")" << std::endl; // output when construction occurs
}

Rectangle::~Rectangle()
{
  if (verbose_) std::cout << "~Rectangle()" << std::endl; // output when deconstruction occurs
}

const char* Rectangle::Name () const
{
  return "rectangle"; // returns rectanngle
}

float Rectangle::Area () const
{
  return (x_ * y_); // calculates and returns area for a rectangle 
}
