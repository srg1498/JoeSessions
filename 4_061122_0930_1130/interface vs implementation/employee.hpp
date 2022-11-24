#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

class Employee{
    public:
    Employee(const char* name, int age);
    int getAge();

    private:
    const char* name;
    int age;
};

#endif