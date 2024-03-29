#pragma once
#include <iostream>
#include <string>

class Employee{
    public:
        int age;
        std::string name, position;
        Employee():Employee("", "", 0){};
        Employee(std::string empName, std::string empPosition, int empAge):
                age(empAge), name(empName), position(empPosition){};
        Employee(const Employee &parent){
            age = parent.age;
            name = parent.name;
            position = parent.position;
        }
        friend std::ostream& operator<<(std::ostream& stream, const Employee& dispEmployee){
            return stream << dispEmployee.name << ", " << dispEmployee.position << ". Age:" << dispEmployee.age;
        }
};