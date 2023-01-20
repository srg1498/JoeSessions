#include<iostream>

class Base{
    public:
    int b;
    int c;
    //Base* this
    
    Base(){
        b = 5;
        c = 7;
        //this = address of object which has been created
    }

    void print(){
        std::cout<<"this: "<<this<<"\n";
        std::cout<<"Hello World\n";
    }

    void updateMembers(int b, int c){
        this->b = b;
        this->c = c;
    }
};



class BaseV{
    public:

    virtual void work(){
        std::cout<<"basev work\n";
    }

    virtual void print(){
        std::cout<<"print in basev\n";
    }

    virtual void hello() = 0;
};


class Derived1 : public BaseV{
    public:

    // void work(){
    //     std::cout<<"basev work\n";
    // }

    void work(){
        std::cout<<"derived1 work\n";
    }

    void print(){
        std::cout<<"print in derived1\n";
    }

    void hello(){
        std::cout<<"hello from derived1\n";
    }
};


class Derived2 : public BaseV{
    public:

    void work(){
        std::cout<<"derived2 work\n";
    }

    void print(){
        std::cout<<"print in derived2\n";
    }

    void hello(){
        std::cout<<"hello from derived2\n";
    }
};



int main(){
    
    // derived calling its own
    Derived1 d1;
    //d1.work();
    //d1.BaseV::work();


    // object slicing
    Derived1* d2 = new Derived1();
    //d2->work();
    delete d2;
    BaseV* d3 = new Derived1();
    //d3->work();
    delete d3;


    // virtual concept
    BaseV* d4 = new Derived1();
    BaseV* d5 = new Derived2();
    d4->work();
    d5->work();
    d4->print();
    d5->print();
    delete d4;
    delete d5;


    



    // basic intro on pointers
    int a = 5;
    //std::cout<<a<<"\n";                // normal variable 
    //std::cout<<&a<<"\n";               // giving the address

    int* p = new int(5);               // memory block created in heap whose address is stored in p
    //std::cout<<p<<"\n";                // storing the address of memory block created in heap
    //std::cout<<*p<<"\n";               // dereferencing the pointer variable

    delete p;                          // free the memory, its our responsibility to free the memory, its manual process




    // array handling using pointers
    int arr1[5];
    
    int b = 10;
    //std::cout<<b+6<<"\n";
    int* arr2 = new int[5];            // address of first block will be stored in arr2
    //std::cout<<arr2<<"\n";
    //std::cout<<arr2+1<<"\n";
    for(int i=0;i<5;i++){
        *(arr2+i) = i+1;
    }
    //std::cout<<*(arr2+3)<<"\n";
    
    delete[] arr2;

  
    

    // objects handling using pointers
    Base obj1;
    Base obj2 = Base();
    //std::cout<<sizeof(obj1)<<"\n";
    
    Base* obj3 = new Base();
    Base* obj4 = new Base[5];
    //std::cout<<obj4<<"\n";
    //std::cout<<obj4+1<<"\n";

    delete obj3;
    delete[] obj4;
    



    // arrow vs dot operator
    Base obj;
    //std::cout<<obj.b<<"\n";
    Base* obj5 = new Base();
    //std::cout<<obj5->b<<"\n";
    //std::cout<<(*obj5).b<<"\n";    
    delete obj5;
    

   
    
    // this pointer
    Base obj10;
    Base* ptr = &obj10;
    //std::cout<<"outside main: "<<ptr<<"\n";
    //obj10.print();

    Base obj20;
    Base* ptr2 = &obj20;
    //std::cout<<"outside main: "<<ptr2<<"\n";
    //obj20.print();
    //obj20.updateMembers(20, 30);
 
    return 0;
}