/*

Vehicle Header file for DOT FastLane project
File: vehicles.h
Name: Ruben Navarrp
Date: 10/20/2017
Version: 1.2

*/

#ifndef _VEHICLES_H
#define _VEHICLES_H

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <shapes.h>

// enum for hold vehicle types
enum VehicleType { badReg = 0, vehicle = 1, carriage = 2, bus = 3, limo = 4, truck = 5, van = 6, tanker = 7, flatbed = 8 };

class CommercialVehicle
{
  public:
    const char* Registration       () const; // returns vehicle registration number
    const char* Operator           () const; // returns operator ID
    const char* CDL                () const; // returns operator CDL
    unsigned int PassengerCapacity () const; // returns passenger capacity
    virtual float LoadCapacity     () const; // virtual member function prototype to return volume or area of cargo space
    virtual  const char* ShortName () const; // virtual member function prototype to return "UNK"  
    static VehicleType RegDecode   (const char* sn); // returns vehicle type (enum type)

    CommercialVehicle              (); // default constructor
    // argument constructor
    CommercialVehicle      (const char* registration, const char* operatorID, const char* operatorCDL, unsigned short passengerCapacity, bool verbose = false);
    virtual ~CommercialVehicle     (); // virtual destructor 

  private:
    char* vehicleRegistration_;
    char* operatorID_;
    char* operatorCDL_;
    unsigned short passengerCapacity_;

    CommercialVehicle              (const CommercialVehicle& cv); // copy constructor
    CommercialVehicle& operator=   (const CommercialVehicle& cv); // assignment operator constructor

  protected: 
    bool verbose_;
};

class Carriage : public CommercialVehicle
{
  public:
    virtual const char* ShortName    () const; // virtual member function prototype to return "Carriage"

    Carriage                         (); // default constructor
    // argument constructor
    Carriage      (const char* registration, const char* operatorID, const char* operatorCDL, unsigned short passengerCapacity, bool verbose = false);
    virtual ~Carriage                (); // virtual  carriage destructor

  private: 
    Carriage                         (const Carriage& c); // copy constructor
    Carriage& operator=              (const Carriage& c); // assignment operator constructor
};

class Bus : public Carriage
{
  public:
    virtual const char* ShortName() const; // virtual member function prototype to return "Bus"

    Bus                              (); // default constructor
    // argument constructor
    Bus       (const char* registration, const char* operatorID, const char* operatorCDL, unsigned short passengerCapacity, bool verbose = false);
    virtual ~Bus                     (); // virtual bus deconstructor 
 
  private:
    Bus                              (const Bus& b); // copy constructor
    Bus& operator=                   (const Bus& b); // assignement operator constructor
};

class Limo : public Carriage
{
  public:
    virtual const char* ShortName    () const; // virtual member function prototype to return "LIM"
   
    Limo                             (); // default constructor
    // argument constructor
    Limo      (const char* registration, const char* operatorID, const char* operatorCDL, unsigned short passengerCapacity, bool verbose = false); 
    virtual ~Limo                    (); // virtual limo deconstructor 
  
  private:
    Limo                             (const Limo& l); // copy constructor
    Limo& operator=                  (const Limo& l); // assignment operator constructor
};

class Truck : public CommercialVehicle  
{
  public: 
    virtual const char* ShortName    () const; // virtual member function prototype to return "TRK"

    Truck                            (); // default constructor
    // argument constructor
    Truck                            (const char* registration, const char* operatorID, const char* operatorCDL, bool verbose = false);
    virtual ~Truck                   (); // virtual truck destructor
 
  private:
    Truck                            (const Truck& t); // copy constructor
    Truck& operator=                 (const Truck& t); // assigment operator 
};

class Van : public Truck, public Box
{
  public:
    virtual float LoadCapacity       () const; // virtual member function prototype to return volume of box 
    virtual const char* ShortName    () const; // virtual member function prototype to return "VAN"

    Van(); // default constructor
    // argument constructor
    Van(const char* registration, const char* operatorID, const char* operatorCDL, float width, float length, float height, bool verbose = false);
    virtual ~Van                    (); // virtual van destructor

  private: 
    Van                             (const Van& v); // copy constructor
    Van& operator=                  (const Van& v); // assignment operator constructor  
};

class Tanker : public Truck, public Cylinder 
{
  public:
    virtual float LoadCapacity      () const; // virtual member function to return volume of cylinder
    const char* ShortName           () const; // returns "TNK"

    Tanker                          (); // default constructor
    // argument constructor
    Tanker(const char* registration, const char* operatorID, const char* operatorCDL, float radius, float length, bool verbose = false);
    virtual ~Tanker                 (); // virtual destructor for tanker

  private:
    Tanker                          (const Tanker& t); // copy constructor
    Tanker& operator=               (const Tanker& t); // assignment operator constructor
};

class Flatbed : public Truck, public Rectangle
{
  public:
     virtual float LoadCapacity     () const; // virtual member function prototype to return area of rectangle
     virtual const char* ShortName  () const; // returns "FLT"

     Flatbed                        (); // default constructor
     // argument constructor
     Flatbed(const char* registration, const char* operatorID, const char* operatorCDL, float width, float length, bool verbose = false);
     virtual ~Flatbed               (); // virtual flatbed destructor

  private:
    Flatbed                         (const Flatbed& f); // copy constructor
    Flatbed& operator =             (const Flatbed& f);  // assignment operator constructor
}; 

#endif
