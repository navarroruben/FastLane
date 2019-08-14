/*

Client program for FastLane project

File: tracker.cpp
Name: Ruben Navarro
Date: 10/24/2017
Version: 1.0

*/

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <vehicles.h>

// global constants
  const unsigned int 
  C1 = 6,    // short name
  C2 = 10,   // pass cap
  C3 = 10,   // load cap
  c4 = 2,
  c5 = 2,
  c6 = 2,  
  maxShiftSize = 100, 
  maxStringSize = 50;


int main()
{       
  CommercialVehicle* cv[maxShiftSize]; // pointer to CommercialVehicle class
  size_t shift = 0; // used to read shift
  char reg[maxStringSize]; // used to read registration
  char id[maxStringSize]; // used to read operator id
  char cdl[maxStringSize]; // used to read operator cdl 
  VehicleType vt; // variable to hold return of vehicle type function
  int shiftCount = 1; // used to keep track of shift loop for output
  
  std::cout << "\nFastLane Tracker started...\n" << std::endl; // display start message
  
  do 
  { 
    size_t regLength[maxStringSize];
    size_t idLength[maxStringSize];
    size_t cdlLength[maxStringSize];
    size_t carriageAmount = 0, // used to hold carriage amount
           busAmount = 0, // used to hold bus amount
           limoAmount = 0, // used to hold limo amount
           truckAmount = 0, // used to hold truck amount
           vanAmount = 0, // used to hold van amount
           tankerAmount = 0, // used to hold tanker amount
           flatbedAmount = 0, // used to hold flatbed 
           unknownAmount = 0, // used to hold unknown amount 
           badregsAmount = 0; // used to hold badregs amount
    float dimension = 0.00, // used to hold dimension  
          w = 0.00, // used to hold width 
          l = 0.00, // used to hold length
          h = 0.00, // used to hold height
          r = 0.00; // used to hold radius    
    unsigned int maxRegLength = 0,// variables to hold string lengths for formatting
                 maxIdLength = 0,
                 maxCdlLength = 0,
                 maxRegNum = 0,
                 maxIdNum = 0,
                 maxCdlNum = 0,
                 passengerTotal = 0, // used to hold passenger total
                 pc = 0; // used to read passenger capacity 



    std::cin >> shift; // read shift number from file

    if (shift == 0)
      break;

    for (size_t i = 0; i < shift; ++i)
    {
      std::cin >> reg; // read registration from file
      vt = CommercialVehicle::RegDecode(reg); // return vehicle type to vehicletype variable
           
      switch (vt) 
      {
        case 0:
          {
            badregsAmount += 1; 
            break;
          }
        case 1: 
          {
            unknownAmount += 1;
            std::cin >> id >> cdl; // reads operator ID and Operator CDL from file
            cv[i] = new CommercialVehicle(reg,id,cdl,0,0); // assigign Commerical Vehnicle object to array
            idLength[i] = strlen(id); // assign length of id to id array 
            cdlLength[i] = strlen(cdl);  // assign length of cdl to cdl array
            break; 
          }
        case 2:
          {
            carriageAmount += 1;
            std::cin >> id >> cdl >> pc; // as with previous case also reads passenger capacity
            cv[i] = new Carriage(reg,id,cdl,pc,0); // assign Carriage object to array
            passengerTotal += pc; // adds pc value to passenger total
            idLength[i] = strlen(id);
            cdlLength[i] = strlen(cdl);
            break;
          }
        case 3:
          {
            busAmount += 1;
            std::cin >> id >> cdl >> pc;
            cv[i] = new Bus(reg,id,cdl,pc,0); // assign Bus object to array            
            passengerTotal += pc;  
            idLength[i] = strlen(id);
            cdlLength[i] = strlen(cdl);
            break;
          }
        case 4:
          {
            limoAmount += 1;
            std::cin >> id >> cdl >> pc;
            cv[i] = new Limo(reg,id,cdl,pc,0); // assign Limo object to array 
            passengerTotal += pc;
            idLength[i] = strlen(id);
            cdlLength[i] = strlen(cdl);
            break;
          }
        case 5:
          {
            truckAmount += 1;
            std::cin >> id >> cdl; 
            cv[i] = new Truck(reg,id,cdl,0); // assign Truck object to array
            idLength[i] = strlen(id);
            cdlLength[i] = strlen(cdl);
            break; 
          }
        case 6:
          {
            vanAmount += 1;
            std::cin >> id >> cdl >> w >> l >> h; // as with previous case also reads width length and height  
            cv[i] = new Van(reg,id,cdl,w,l,h,0); // assign Van object to array
            dimension += cv[i]->LoadCapacity(); // calls and adds load capacity to dimension
            idLength[i] = strlen(id);
            cdlLength[i] = strlen(cdl);
            break;
          }
        case 7:
          {
            tankerAmount += 1;
            std::cin >> id >> cdl >> r >> l; // ass with previous case also reads radius and length to file 
            cv[i] = new Tanker(reg,id,cdl,r,l,0); // assign Tanker object to array
            dimension += cv[i]->LoadCapacity();  
            idLength[i] = strlen(id);
            cdlLength[i] = strlen(cdl);
            break; 
          }
        case 8:
          {
            flatbedAmount += 1;
            std::cin >> id >> cdl >> w >> l;
            cv[i] = new Flatbed(reg,id,cdl,w,l,0); // assign Flatbed object to array
            dimension += cv[i]->LoadCapacity();
            idLength[i] = strlen(id);
            cdlLength[i] = strlen(cdl);
            break;         
          }
      }
      regLength[i] = strlen(reg); // assign length of each shift to array
    } 

    maxRegLength = regLength [0];
    // for loop to check and assign max length of registration for formatting purposes
    for (size_t i = 0; i < shift; ++i)
    {
      if (regLength[i] > maxRegLength)
        maxRegLength = regLength[i];
    }
    if (maxRegLength < 12)
    {
      maxRegNum = 12;
    }
    else 
    {
      maxRegNum = maxRegLength;
    }
    // for loop to check and assign max length of operator id for formatting purposes
    for (size_t i = 0; i < shift; ++i)
    {
      if (idLength[i] > maxIdLength)
        maxIdLength = idLength[i];
    }
    if (maxIdLength < 12)
    {
      maxIdNum = 12;
    }
    else
    {
      maxIdNum = maxIdLength;
    }
    // for loop to check and assign max length of operator cdl for formatting purposes
    for (size_t i = 0; i < shift; ++i)
    {
    if (cdlLength[i] > maxCdlLength)
      maxCdlLength = cdlLength[i];
    }
    if (maxCdlLength < 12)
    {
      maxCdlNum = 12;
    }
    else
    {
      maxCdlNum = maxCdlLength;
    }
  
    // calculation for output format                                                                                                  
    unsigned int C4 = c4 + maxRegNum; // column for registration
    unsigned int C5 = c5 + maxIdNum; // column for operator id
    unsigned int C6 = c6 + maxCdlNum; // column for operator cdl
    
    // displays Shift n Summary
    std::cout << " Shift " << shiftCount << " Summary" << '\n'
              << " ===============" << '\n'
              << '\n'
              << "  Carriages:            " << carriageAmount << '\n'
              << "  Buses:                " << busAmount << '\n'
              << "  Limos:                " << limoAmount << '\n'
              << "  Trucks:               " << truckAmount << '\n'
              << "  Vans:                 " << vanAmount << '\n'
              << "  Tankers:              " << tankerAmount << '\n'
              << "  Flatbeds:             " << flatbedAmount << '\n'
              << "  Unknowns:             " << unknownAmount << '\n'
              << "  Badregs:              " << badregsAmount << '\n'
              << "  Total Passenger Cap:  " << passengerTotal << '\n'
              << "  Total Freight Cap:    " << std::fixed << std::setprecision(2) << dimension << std::endl;

    std::cout << '\n';

    // displays Shift n Log
    std::cout << " Shift " << shiftCount << " Log\n"
              << " ===============\n";
    std::cout << '\n'
              << std::setw(C1) << "Type"
              << std::setw(C2) << "Pass Cap"
              << std::setw(C3) << "Load Cap"
              << std::left << "  "
              << std::setw(C4) << "Registration"
              << std::setw(C5) << "Operator ID"
              << std::setw(C6) << "Operator CDL"
              << std::right
              << '\n';

    std::cout << std::setw(C1) << "----"
              << std::setw(C2) << "--------"
              << std::setw(C3) << "--------"
              << std::left << "  "
              << std::setw(C4) << "------------"
              << std::setw(C5) << "-----------"
              << std::setw(C6) << "------------"
              << std::right
              << '\n';
       
    // displays shift n log results 
    for (size_t i = 0; i < shift; ++i)
      {
        std::cout << std::setw(C1) << cv[i]->ShortName()
                  << std::setw(C2) << cv[i]->PassengerCapacity()
                  << std::setw(C3) << cv[i]->LoadCapacity()
                  << std::left << "  "
                  << std::setw(C4) << cv[i]->Registration()
                  << std::setw(C5) << cv[i]->Operator()
                  << std::setw(C6) << cv[i]->CDL()
                  << std::right 
                  << '\n';
        delete cv[i];     
 }  
    ++shiftCount; // shift counter for output purposes 
    std::cout << std::endl;
  } while (shift > 0);
 std::cout << "\n...Thank you for using FastLane Tracker.\n" << std::endl; 
 return 0;
} 
