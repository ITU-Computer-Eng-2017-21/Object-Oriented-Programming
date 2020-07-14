/* @Author
Student Name: Baris Incesu
Student ID: 150170092
Date: 3.05.2020 */
#include <string>
#include <iostream>
#pragma once

class Person
{
protected:
    std::string m_name;
    std::string m_surname;
public:
    Person() : m_name("NULL"), m_surname("NULL") { } // default constructor for Person
    Person(const std::string &name, const std::string &surname)// member initilazer
        : m_name(name), m_surname(surname) { } 
    const std::string& getName() const { return m_name; } //Basic getter method!!
    const std::string& getSurname() const { return m_surname; } //Basic getter method!!
    void setName( std::string a) { m_name = a; } //setter methods..
    void setSurname( std::string a) { m_surname = a; }
    ~Person() { /*std::cout << "Person Deleted" << std::endl;*/ } // default destructor for Person
};