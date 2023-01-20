#include<iostream>


class A{
    private:
        void privatePrint(){
            std::cout<<"private print\n";
        }

    protected:
        void protectedPrint(){
            std::cout<<"protected print\n";
        }

    public:
        A(){
            std::cout<<"Base class constructor\n";
        }
        ~A(){
            std::cout<<"Base class destructor\n";
        }


        void publicPrint(){
            std::cout<<"print this\n";
        }

        void publicAdd(){
            std::cout<<"add this\n";
        }

        void publicSub(){
            std::cout<<"sub this\n";
        }
};


class B : public A{
    public:
        B(){
            std::cout<<"Derived class constructor\n";
        }
        ~B(){
            std::cout<<"Derived class destructor\n";
        }

        void publicMul(){
            std::cout<<"mul this\n";
        }
};


int main(){
    std::cout<<"inheritance intro\n";
    A a = A();
    a.publicAdd();
    //a.protectedPrint(); - can not access protected members of a class outside
    //a.privatePrint(); - can not acess private members 

    //std::cout<<"\n\n\n";

    B b = B();
    b.publicMul();
    
    return 0;
}