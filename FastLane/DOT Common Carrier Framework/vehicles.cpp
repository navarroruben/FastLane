/* 
Vehicle Implementation file for DOT FastLane project
File: vehicles.cpp
Name: Ruben Navarro
Date: 10/20/201
Version:1.0                                                                                                                                                    
*/

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <vehicles.h>
#include <shapes.h>
#include <cstring>
#include <shapes.cpp>

CommercialVehicle::CommercialVehicle (const char* r, const char* oID, const char* oCDL, unsigned short pc, bool v) : passengerCapacity_(pc), verbose_(v)
{
  if (verbose_) std::cout << "CommercialVehicle(" << r << ',' << oID << ',' << oCDL << ',' << pc << ',' << v << ")" << std::endl; // output when construction occurs

  size_t size = strlen(r); // get size of r string
  vehicleRegistration_ = new char [size]; // allocate size to vehicleRegistration_ array
  std::strcpy(vehicleRegistration_, r); // copy r to vehicleRegistration_ array 
   
  size_t size1 = strlen(oID); // get size of oID string 
  operatorID_ = new char [size1]; // allocate size to operatorID_
  std::strcpy(operatorID_, oID); // copy oID to operatorID_
  
  size_t size2 = strlen(oCDL); // get size of oCDL string 
  operatorCDL_ = new char [size2]; // allocate size to operatorCDL_
  std::strcpy(operatorCDL_, oCDL); // copy oCDL to operatorCDL_ 
}  

CommercialVehicle::~CommercialVehicle()
{
  if (verbose_) std::cout << "~CommercialVehicle()" << std::endl; //output when deconstruction occurs
}

const char* CommercialVehicle::Registration() const
{
  return vehicleRegistration_; // returns vehicleRegistration_
}
  
const char* CommercialVehicle::Operator () const
{
  return operatorID_; // returns operatorID_
}

const char* CommercialVehicle::CDL () const
{
  return operatorCDL_; //returns operatorCDL_
}

unsigned int CommercialVehicle::PassengerCapacity () const
{
  return passengerCapacity_; // returns passengerCapacity_
}

float CommercialVehicle::LoadCapacity () const
{
  return 0.00; // returns no value for load capacity if not replaced with virtual function   
}                                                                                                                                                                                                                            
const char* CommercialVehicle::ShortName () const
{
  return "UNK"; // returns "UNK" 
}
VehicleType CommercialVehicle::RegDecode (const char* sn)
{ 
  // check is first char in sn equals the vehicle type     
  if (sn[0] == '1')
    return vehicle;
  else if (sn[0] == '2')
    return carriage;
  else if (sn[0] == '3')
    return bus;
  else if (sn[0] == '4')
    return limo;
  else if (sn[0] == '5')
    return truck;
  else if (sn[0] == '6')
    return van;
  else if (sn[0] == '7')
   return tanker;
  else if (sn[0] == '8')
    return flatbed;
  
  return badReg;     
}

Carriage::Carriage (const char* r, const char* oID, const char* oCDL, unsigned short pc, bool v) : CommercialVehicle(r,oID,oCDL,pc,v) 
{
  if(v) std::cout << "Carriage(" << r << ',' << oID << ',' << oCDL << ',' << pc << ',' << v << ")" << std::endl; // outputs when construction occurs 
}

Carriage::~Carriage()
{
  if (verbose_) std::cout << "~Carriage()" << std::endl; // outputs when deconstruction occurs
}

const char* Carriage::ShortName() const
{
  return "CAR"; // returns "CAR"
}

Bus::Bus (const char* r, const char* oID, const char* oCDL, unsigned short pc, bool v) : Carriage(r,oID,oCDL,pc,v)
{
  if (v) std::cout << "Bus(" << r << ',' << oID << ',' << oCDL << ',' << pc << ',' << v << ")" << std::endl; //outputs when construction occurs 
}

Bus::~Bus()
{
  if (verbose_) std::cout << "~Bus()" << std::endl; // outputs when deconstructor occurs
}

const char* Bus::ShortName () const
{
  return "BUS"; // returns "BUS"
}
 
Limo::Limo (const char* r, const char* oID, const char* oCDL, unsigned short pc, bool v) : Carriage(r,oID,oCDL,pc,v)
{
  if (v) std::cout << "Limo(" << r << ',' << oID << ',' << oCDL << ',' << pc << ',' << v << ")" << std::endl; // outputs when constructoin occurs 
}

Limo::~Limo()
{
  if (verbose_) std::cout << "~Limo()" << std::endl; // outputs when deconstruction occurs
}

const char* Limo::ShortName () const
{
  return "LIM"; // returns "LIM"
}

Truck::Truck (const char* r, const char* oID, const char* oCDL, bool v) : CommercialVehicle(r,oID,oCDL,0,v)
{
  if (v) std::cout << "Truck(" << r << ',' << oID << ',' << oCDL << ',' << v << ")" << std::endl; // outputs when construction occurs
}

Truck::~Truck()
{
  if (verbose_) std::cout << "~Truck()" << std::endl; // outputs when deconstruction occurs
} 

const char* Truck::ShortName() const
{
  return "TRK"; // returns "TRK"
}

Van::Van (const char* r, const char* oID, const char* oCDL, float w, float l, float h, bool v) : Truck(r,oID,oCDL,v), Box(w,l,h,v)
{
  if (v) std::cout << "Van(" << r << ',' << oID << ',' << oCDL << ',' << w << ',' << l << ',' << h << ',' << v << ")" << std::endl; // outputs when construction occurs
}

Van::~Van()
{
  if (CommercialVehicle::verbose_) std::cout << "~Van()" << std::endl; // outputs when deconstruction occurs 
}

float Van::LoadCapacity () const
{
 
 return Volume(); // calls volume calculation from box  
}
const char* Van::ShortName () const
{
  return "VAN"; // returns box
}

Tanker::Tanker (const char* r, const char* oID, const char* oCDL, float w, float l, bool v) : Truck(r,oID,oCDL,v), Cylinder(w, l, v)
{
  if(v) std::cout << "Tanker(" << r << ',' << oID << ',' << oCDL << ',' << w << ',' << l <<',' << v << ")" << std::endl; // outputs when construction occurs
}

Tanker::~Tanker ()
{
  if (CommercialVehicle::verbose_) std::cout << "~Tanker()" << std::endl; // outputs when deconstruction occurs
}

float Tanker::LoadCapacity () const
{
  return Volume(); // returns volume of cylinder
}

const char* Tanker::ShortName () const
{
  return "TNK"; //returns "TNK"
}   

Flatbed::Flatbed (const char* r, const char* oID, const char* oCDL, float w, float l, bool v) : Truck(r,oID,oCDL,v), Rectangle(w,l,v)
{
  if(v) std::cout << "Flatbed(" << r << ',' << oID << ',' << oCDL << ',' << w << ',' << l << ',' << v << ")" << std::endl; // outputs when contruction occurs
}
Flatbed::~Flatbed()
{
  if (CommercialVehicle::verbose_) std::cout << "~Flatbed()" << std::endl; // outputs when deconstruction occurs 
}
float Flatbed::LoadCapacity() const
{
  return Area(); // returns area of rectangle
}
const char* Flatbed::ShortName () const
{
  return "FLT"; // returns "FLT"
}
