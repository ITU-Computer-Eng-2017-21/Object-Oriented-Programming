/* @Author
Student Name: Baris Incesu
Student ID: 150170092
Date: 3.05.2020 */
#include <string>
#include <iostream>
#include "Person.h"
#pragma once

class Owner: public Person // You need to implement an Owner class as a subclass of Person class.
{
private:
    int ownership; // The class should have an attribute named “ownership”, which represents the amount of ownership as percentage.

public:
    Owner(): Person() { } // default constructor for Owner
    Owner(const std::string &name, const std::string &surname)//Parameterized Constructor
        : Person( name, surname ) , ownership(0) { } 
    int getOwnership() {return ownership; } //getter - setter
    void setOwnership(int x){ ownership = x; }
    ~Owner() { /*std::cout << "Owner Deleted" << std::endl; */ } // default destructor for Owner
};