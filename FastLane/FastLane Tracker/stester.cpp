/*
   shapetester.cpp

   Chris Lacher
   02/07/17

   Test harness for the shape object hierarchy:
    0 - Shape
    1 - Box
    2 - Cylinder
    3 - Rectangle
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

#include <shapes.h>

int main(int argc, char* argv[])
{
  bool BATCH = 0;
  std::istream * isptr = &std::cin;
  std::ifstream ifs;
  if (argc > 1)
  {
    ifs.open(argv[1]);
    if (ifs.fail())
    {
      std::cout << " ** cannot open command file " << argv[1] << '\n';
      exit (EXIT_FAILURE);
    }
    isptr = &ifs;
    BATCH = 1;
  }

  Shape *   Sptr;   // pointer to dynamically allocated Shape object
  std::cout << std::fixed << std::showpoint << std:: setprecision(2); // set float output format
  float x(0.0),y(0.0),z(0.0);
  bool v;
  char sn;
  do
  {
    Sptr = nullptr;
    std::cout << "\nCodes: 0 = Shape, 1 = Box, 2 = Cylinder, 3 = Rectangle\n"
              << "Enter code followed by size arguments ('Q' to quit): ";
    (*isptr) >> sn;
    if (BATCH) std::cout << sn << '\n';
    switch (sn)
    {
      case '0': // Shape
        std::cout << " Enter X,Y,X,v: ";
        (*isptr) >> x >> y >> z >> v;
        if (BATCH)
          std::cout << ' ' << x 
                    << ' ' << y 
                    << ' ' << z 
                    << ' ' << (size_t)v 
                    << '\n';
        std::cout << '\n';
        Sptr = new Shape(x,y,z,v);
        break;
      case '1': // Box
        std::cout << " Enter L,W,H,v: ";
        (*isptr) >> x >> y >> z >> v;
        if (BATCH)
          std::cout << ' ' << x 
                    << ' ' << y 
                    << ' ' << z 
                    << ' ' << (size_t)v 
                    << '\n';
        std::cout << '\n';
        Sptr = new Box(x,y,z,v);
        break;
      case '2': // Cylinder
        std::cout << " Enter R,H,v: ";
        (*isptr) >> x >> z >> v;
        if (BATCH)
          std::cout << ' ' << x 
                    << ' ' << z
                    << ' ' << (size_t)v 
                    << '\n';
        std::cout << '\n';
        Sptr = new Cylinder(x,z,v);
        break;
      case '3': // Rectangle
        std::cout << " Enter L,W,v: ";
        (*isptr) >> x >> y >> v;
        if (BATCH)
          std::cout << ' ' << x 
                    << ' ' << y 
                    << ' ' << (size_t)v 
                    << '\n';
        std::cout << '\n';
        Sptr = new Rectangle(x,y,v);
        break;

      case 'q': case 'Q':
        sn = 'q';
        break;

      default:  // should never get here
        std::cerr << " ** ERROR: bad code passed to decision logic\n";
        break;
    } // end switch
    if (Sptr != nullptr)
    {
      std::cout << " Name: "   << Sptr -> Name() << '\n';
      std::cout << " Volume: " << Sptr -> Volume() << '\n';
      std::cout << " Area:   " << Sptr -> Area() << '\n';
      delete Sptr;
    }
    // do sn = isptr->get(); while (sn != '\n');
    x = y = z = 0.0;
  } // end do
  while (sn != 'q');

  return 0;
} // end main
