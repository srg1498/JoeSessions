# 0 "employee.cpp"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "employee.cpp"
# 1 "employee.hpp" 1



class Employee{
    public:
    Employee(const char* name, int age);
    int getAge();

    private:
    const char* name;
    int age;
};
# 2 "employee.cpp" 2


Employee::Employee(const char* name, int age){
    name = name;
    age = age;
}

int Employee::getAge(){
    return age;
}
