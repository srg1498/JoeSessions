#include<iostream>
#include "employee.hpp"

int main(){
    Employee e1 = Employee("sahil", 24);
    std::cout<<e1.getAge();
    return 0;
}