/*
   vtester.cpp

   Chris Lacher
   02/07/17

   Test harness for the vehicle object hierarchy

   VehicleType is an enumerated type with values:

     badSn, vehicle, carriage, bus, limo, truck, van, tanker, flatbed

   These classes are tested:

     Vehicle;
     Carriage;
     Bus;
     Limo;
     Truck;
     Van;
     Tanker;
     Flatbed;
     Box;
     Cylinder;
     Plane;
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

#include <vehicles.h>

//                      012345678901234567890123456789012345678901234567890123456789
char  snMessage  [53] = "*** OOPS - serial number not owned by vehicle object";
char  idMessage  [49] = "*** OOPS - id number not owned by vehicle object";
char  cdlMessage [50] = "*** OOPS - cdl number not owned by vehicle object";
// char  snOK        [6] = "sn_OK";
char  idOK        [6] = "id_OK";
char  cdlOK       [7] = "cdl_OK";
const size_t maxEntrySize = 1+strlen(snMessage);

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

  CommercialVehicle * Vptr;      // pointer to dynamically allocated CommercialVehicle object
  VehicleType v;                 // to hold type of vehicle
  char        sn [maxEntrySize]; // to hold user entry
  char        id [maxEntrySize]; // 
  char        cdl[maxEntrySize]; // 
  std::cout << std::fixed << std::showpoint << std:: setprecision(2); // set float output format
  do
  {
    strcpy (id,idOK);
    strcpy (cdl,cdlOK);
    Vptr = nullptr;
    std::cout << "\nEnter sn ('Q' to quit): ";
    (*isptr) >> std::setw(maxEntrySize) >> sn;
    if (BATCH) std::cout << sn << '\n';
    if (sn[0] == 'q' || sn[0] == 'Q') break;
    v = CommercialVehicle::RegDecode(sn);
    std::cout << '\n';
    switch (v)
    {
      case vehicle:
        Vptr = new CommercialVehicle(sn, id, cdl, 0, 1);
        break;
      case carriage:
        Vptr = new Carriage(sn, id, cdl, 0, 1);
        break;
      case bus:
        Vptr = new Bus(sn, id, cdl, 50, 1);
        break;
      case limo:
        Vptr = new Limo(sn, id, cdl, 8, 1);
        break;
      case truck:
        Vptr = new Truck(sn, id, cdl, 1);
        break;
      case van:
        Vptr = new Van(sn, id, cdl, 8, 10, 40, 1);
        break;
      case tanker:
        Vptr = new Tanker(sn, id, cdl, 3, 40, 1);
        break;
      case flatbed:
        Vptr = new Flatbed(sn, id, cdl, 8, 40, 1);
        break;
      case badReg:
        Vptr = new CommercialVehicle ("BadRegistrationNumber","!","!",0,1);
        break;
      default:  // should never get here
        std::cerr << "** ERROR: bad VehicleType passed to decision logic\n";
        break;
    } // end switch

    strcpy (sn, snMessage);
    strcpy (id, idMessage);
    strcpy (cdl, cdlMessage);
    std::cout << "Short Name:    " << Vptr -> ShortName() << '\n';
    std::cout << "Registration:  " << Vptr -> Registration() << '\n';
    std::cout << "Operator ID:   " << Vptr -> Operator() << '\n';
    std::cout << "Operator CDL:  " << Vptr -> CDL() << '\n';
    std::cout << "Passenger Cap: " << Vptr -> PassengerCapacity() << '\n';
    std::cout << "Load Capacity: " << Vptr -> LoadCapacity() << '\n';

    if (Vptr != nullptr) delete Vptr;
  } // end do
  while (sn[0] != '0');

  return 0;
} // end main
