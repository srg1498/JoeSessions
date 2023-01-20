#include<iostream>

class Shape{
    public:
    virtual void sides() = 0;
    virtual void perimeter() = 0;
};

class Triangle : public Shape{
    public:
    void sides(){
        std::cout<<"it has 3 sides\n";
    }

    void perimeter(){
        std::cout<<"sum of 3 sides\n";
    }
};

class Quadrilateral : public Shape{
    public:
    void sides(){
        std::cout<<"it has 4 sides\n";
    }

    void perimeter(){
        std::cout<<"sum of 4 sides\n";
    }
};

class Pentagon : public Shape{
    public:
    void sides(){
        std::cout<<"it has 5 sides\n";
    }

    void perimeter(){
        std::cout<<"sum of 5 sides\n";
    }
};


class Hexagon : public Shape{
    public:
    void sides(){
        std::cout<<"it has 6 sides\n";
    }

    void perimeter(){
        std::cout<<"sum of 6 sides\n";
    }
};




// 1st way of implementing this

class OldPrinter{
    public:
    void print(string doc){
        std::cout<<"print this doc\n";
    }

    void scan(string doc){
        std::cout<<"scan this doc\n";
    }
};

class ModernPrinter{
    public:
    void print(string doc){
        std::cout<<"print this doc\n";
    }

    void scan(string doc){
        std::cout<<"scan this doc\n";
    }

    void 3dprint(string doc){
        std::cout<<"print this doc in 3d\n";
    }

    void deprint(string doc){
        std::cout<<"deprint this doc\n";
    }
};


// 2nd way

class IPrinter{
    public:
    virtual void print(string doc) = 0;
    virtual void scan(string doc) = 0;
    virtual void 3dprint(string doc) = 0;
    virtual void deprint(string doc) = 0;
};


class OldPrinter : public IPrinter{
    public:
    void print(string doc){
        std::cout<<"print this doc in \n";
    }

    void scan(string doc){
        std::cout<<"scan this doc\n";
    }

    void 3dprint(string doc){
        std::cout<<"not allowed\n";
    }

    void deprint(string doc){
        std::cout<<"not allowed\n";
    }
};


class ModernPrinter : public IPrinter{
    public:
    void print(string doc){
        std::cout<<"print this doc\n";
    }

    void scan(string doc){
        std::cout<<"scan this doc\n";
    }

    void 3dprint(string doc){
        std::cout<<"print this doc in 3d\n";
    }

    void deprint(string doc){
        std::cout<<"deprint this doc\n";
    }
};


// abstract or interface
class ISearch{
    public:
    virtual void searching(vector<int> arr, int num) = 0;
};

// concrete class - implementing the inetrface
class LinearSearch : public ISearch{
    public:
    void searching(vector<int> arr, int num){
        // implement linear search algo
    }
};

class BinarySearch : public ISearch{
    public:
    void searching(vector<int> arr, int num){
        // implement binary search algo
    }
};

class TernarySearch : public ISearch{
    public:
    void searching(vector<int> arr, int num){
        // implement ternary search algo
    }
};




int main(){
    // Triangle* tr = new Triangle();
    // tr->sides();
    // Quadrilateral* qd = new Quadrilateral();
    // qd->sides();
    // Pentagon* pg = new Pentagon();
    // pg->sides();

    Shape* sh = new Triangle();
    sh->sides();

    return 0;
}