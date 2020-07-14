/* @Author
Student Name: Baris Incesu
Student ID: 150170092
Date: 3.05.2020 */
#include <string>
#include <iostream>
#include "Person.h"
#include "Owner.h"
#include "Courier.h"
#pragma once

class Business
{
private:
    std::string bname; //A is business is represented with name and address.
    std::string adress;
    Owner *owner;
    int owner_number; //owner counter
    Courier *courier;
    int courier_number; //courier counter
public:
    Business(const std::string &name, const std::string &location,Owner * owner_arr,int a) // constructor for Business
    {
        bname = name;
        adress = location;
        owner = owner_arr; //owner_arr mounted to Business Obj.
        owner_number = a;   
        for (int i = 0; i < owner_number; i++)
        {
            (owner+i)->setOwnership(100/owner_number); // The amount of “ownership” should be adjusted during construction as well.

        }
        courier = NULL; //default business has no courier
        courier_number = 0;
    }
    void hire_courier(Courier &x) //This method accepts a Courier object as argument and inserts to courier array.
    {  //In this function applied maximum effort array-pointerartihmetic for memory leaks.
        if(courier == NULL) //first courier added.
        {
            Courier *a;
            a = new Courier[1];
            a[courier_number] = x;
            courier = a;
            courier_number++;
        }
        else if(courier != NULL) //If business has courier.
        {
            Courier *new_corr; 
            new_corr = new Courier[courier_number+1];
            for (int i = 0; i < courier_number; i++)
            { //copying courier -> nex_corr
                new_corr[i].setName(courier[i].getName());
                new_corr[i].setSurname(courier[i].getSurname());
                new_corr[i].setVehicle_type(courier[i].getVehicle_type());
            }
            new_corr[courier_number] = x; //adding last courier
            courier_number++; //courier redefiened. 
            courier = new_corr;
        }
    }
    void fire_courier(Courier &b) //fire_courier: This method accepts a Courier object, searches the courier and removes it from the list/array.
    {   //In this function applied maximum effort array-pointerartihmetic for memory leaks.
        if (b.getName() == "ERROR") //If the courier does not exist it should print an error message.
        {
            std::cout << "You tried delete the doesnt exist courier." << std::endl;
        }
        else
        {
            Courier *new_corr;
            new_corr = new Courier[courier_number];
            bool detected = false;
            for (int i = 0; i < courier_number; i++)
            {
                if (b == courier[i])
                {
                    detected = true;
                }
                else
                {
                    if(detected == false) //Copying courier->new_corr until delete courier[b]
                    { 
                        new_corr[i].setName(courier[i].getName());
                        new_corr[i].setSurname(courier[i].getSurname());
                        new_corr[i].setVehicle_type(courier[i].getVehicle_type()); 
                    }
                    else
                    {   //Copyin go on after delete courier[b]
                        new_corr[i-1].setName(courier[i].getName());
                        new_corr[i-1].setSurname(courier[i].getSurname());
                        new_corr[i-1].setVehicle_type(courier[i].getVehicle_type());
                    }
                }
            }
            courier = new_corr; //courier redefiened.
            courier_number--;
        }
    }
    void list_couriers() //This method prints all information (name, surname,vehicle_type) about all couriers to screen.
    { 
        for (int i = 0; i < courier_number; i++)
        {
            std::cout << courier[i].getName() << " " << courier[i].getSurname() << " " << courier[i].getVehicle_type() << std::endl;
        }

    }
    void list_owners() //This method prints all information (name, surname, ownership) about all owners to screen.
    {
        for (int i = 0; i < 2; i++)
        {
            std::cout << owner[i].getName() << " " << owner[i].getSurname() << " " << owner[i].getOwnership() << std::endl;
        }

    }
    int calculate_shipment_capacity() //This method should sum up total transportation capacity. 
    {
        int result = 0;
        for (int i = 0; i < courier_number; i++)
        {
        if(courier[i].getVehicle_type() == "car") { result = result +200; }
        else if(courier[i].getVehicle_type() == "motorcycle") { result = result +35; }
        else if(courier[i].getVehicle_type() == "bicycle") { result = result +10; }
        }
        return result;
   } 
    void operator()() //When () operator is invoked, it should print all information about the business (i.e., name, address, owners, couriers). You can use list_couriers and list_owners methods that you have implemented.
    {
        std::cout << bname << " " << adress << std::endl;
        this->list_owners();
        this->list_couriers();
    }
    Courier operator[](int x) //When [] operator is invoked, it should return courier with the given index. 
    {   
        if(x < courier_number && x >= 0)
        {
            Courier a = courier[x];
            return a;
        }
        else //If the index is invalid, it should print an error message.
        {
            std::cout << "Please enter vehicle type Car/Motorcycle/Bicycle." << std::endl;
            Courier Error;
            Error.setName("ERROR");
            Error.setSurname("ERROR");
            Error.setVehicle_type("ERROR");
            return Error;
        }
    }
    ~Business() { /*std::cout << "Business Deleted" << std::endl; */}
};