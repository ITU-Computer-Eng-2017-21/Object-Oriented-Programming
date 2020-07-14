/* @Author
Student Name: Baris Incesu
Student ID: 150170092
Date: 3.05.2020 */
#include <string>
#include <iostream>
#include "Person.h"
#pragma once

class Courier: public Person // You need to implement a Courier class as a subclass of Person class.
{
private:
    std::string vehicle_type; //10 kg for bicycle, 35 kg for motorcycle, and 200 kg for car
public:
    Courier(): Person(), vehicle_type("NULL") { } // default constructor for Courier
    Courier(const std::string &name, const std::string &surname, const std::string &vt)
        : Person(name, surname) //Parameterized Constructor
        {   //There can be 3 different types of vehicles which are: car, motorcycle, and bicycle. 
            if((vt == "car") || (vt == "motorcycle") || (vt == "bicycle")){vehicle_type = vt; }   
            else{std::cout << "Please enter vehicle type Car/Motorcycle/Bicycle." << std::endl;} //If any other type is given, an error message should be printed.
        } 
    std::string getVehicle_type() { return vehicle_type;} //getter
    void setVehicle_type(std::string a){ vehicle_type = a;} //setter
    bool operator==(Courier &x)  // fire_courier // should be overload == operator for Courier class which is required for the search part.
    {
        if ((getName() == x.getName()) && (getSurname() == x.getSurname()) && (getVehicle_type() == x.getVehicle_type()))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ~Courier() { /* std::cout << "Courier Deleted" << std::endl; */} // default destructor for Courier
};