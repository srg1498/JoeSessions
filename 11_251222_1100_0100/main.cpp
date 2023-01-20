#include<iostream>
#include<vector>


// point 1
// class Counter{
//     private:
//     int count;
    
//     public:
//     Counter(){
//         count = 0;
//         std::cout<<"base default cons called\n";
//     }
    
//     Counter(int c){
//         count = c;
//         std::cout<<"base parametrized cons called\n";
//     }
    
//     Counter(const Counter &c){
//         std::cout<<"copy called\n";
//         count = c.count;
//     }

//     ~Counter(){
//         std::cout<<"base dest called\n";
//     }
    
//     int get_count() const{
//         return count;
//     }
    
//     Counter operator ++(){
//         return Counter(this->count++);
//     }
// };

// class Countdn : public Counter{
//     public:
//     Countdn(){
//         std::cout<<"derived default cons called\n";
//     }

//     ~Countdn(){
//         std::cout<<"derived dest called\n";
//     }
// };



// point 2
// class Counter{
//     protected:
//     int count;
    
//     public:
//     Counter():count(0){
//         std::cout<<"base default cons called\n";
//     }

//     Counter(int c):count(c){
//         std::cout<<"base parametrized cons called\n";
//     }
    
//     Counter(const Counter &c){
//         std::cout<<"copy called\n";
//         count = c.count;
//     }
    
//     int get_count() const{
//         return count;
//     }
    
//     Counter operator ++(){
//         return Counter(this->count++);
//     }
// };

// class Countdn : public Counter{
//     public:
//     Counter operator --(){
//         return Counter(this->count--);
//     }
// };




// point 4
// class Counter{
//     protected:
//     int count;
    
//     public:
//     Counter():count(0){
//         std::cout<<"base default cons called\n";
//     }
    
//     Counter(int c):count(c){
//         std::cout<<"base parametrized cons called\n";
//     }
    
//     Counter(const Counter &c){
//         std::cout<<"copy called\n";
//         count = c.count;
//     }
    
//     int get_count() const{
//         return count;
//     }
    
//     Counter operator ++(){
//         return Counter(this->count++);
//     }
// };

// class Countdn : public Counter{
//     public:
//     Countdn(){
//         std::cout<<"derived default cons called\n";
//     }
    
//     Countdn(int c) : Counter(c){
//         std::cout<<"derived parametrized cons called\n";
//     }

//     Counter operator --(){
//         return Counter(this->count--);
//     }
// };



// point 5
// class Person{
//     public:
//     Person(){
//         std::cout<<"base class default cons called\n";
//     }

//     void work(){
//         std::cout<<"Person work function called\n";
//     }
// };

// class Student : public Person{
//     public:
//     Student(){
//         std::cout<<"derived class default cons called\n";
//     }

//     void work(){
//         std::cout<<"student work function called\n";
//     }
// };


// class CustomStack{
//     protected:
//     int arr[5];
//     int idx;

//     public:
//     CustomStack(){
//         idx = -1;
//     }

//     void push(int x){
//         arr[++idx] = x;
//     }

//     void pop(){
//         idx--;
//     }

//     int top(){
//         return arr[idx];
//     }
// };


// class CustomStack2 : public CustomStack{
//     public:
//     void push(int x){
//         if(idx>=5){
//             std::cout<<"stack is full\n";
//             return;
//         }
//         CustomStack::push(x);
//     }

//     void pop(){
//         if(idx == -1){
//             std::cout<<"stack is empty\n";
//             return;
//         }
//         CustomStack::pop();
//     }

//     int top(){
//         if(idx == -1){
//             std::cout<<"stack is empty\n";
//             return;
//         }
//         return CustomStack::top();
//     }
// };




// point 6
class Shape{
    public:
    Shape(){
        std::cout<<"shape class cons called\n";
    }

    ~Shape(){
        std::cout<<"shape dest called\n";
    }

    void printShape(){
        std::cout<<"shape\n";
    }
};

class Quad{
    public:
    Quad(){
        std::cout<<"quad class cons called\n";
    }
    
    ~Quad(){
        std::cout<<"quad dest called\n";
    }

    void printQuad(){
        std::cout<<"quad\n";
    }
};

class Square : public Shape, public Quad{
    public:
    Square(){
        std::cout<<"square class cons called\n";
    }
    
    ~Square(){
        std::cout<<"square dest called\n";
    }

    void printSquare(){
        std::cout<<"square\n";
    }
};


int main(){
    // point 1
    //Countdn c1;
    //std::cout<<c1.get_count()<<"\n";
    //Counter c2 = ++c1;
    //std::cout<<c1.get_count()<<"\n";
    
    

    // point 2
    //Countdn c1;                                         // called cons, c1.count = 0
    //std::cout<<c1.get_count()<<"\n";                    // print c1 count, which is 0
    //Counter c2 = --c1;                                  // c2 count will be 0, c1 count will be decremented ans set to -1
    //std::cout<<"c1:"<<c1.get_count()<<"\n";             // print c1 count, which is -1
    //std::cout<<"c2:"<<c2.get_count()<<"\n";             // print c2 count, which is 0



    // point 3
    //int x=0, y=0, z=0;
    //std::cout<<"line1: "<<x<<" "<<y<<" "<<z<<"\n";     // 0 0 0                0 0 0 
    //y = x++;
    //std::cout<<"line2: "<<x<<" "<<y<<" "<<z<<"\n";     // 0 1 0                1 0 0
    //z = ++x;
    //std::cout<<"line3: "<<x<<" "<<y<<" "<<z<<"\n";     // 0 1 2                2 0 2



    // point 4
    //Countdn c1(5);
    //std::cout<<c1.get_count()<<"\n";


    

    // point 5
    //Person p1 = Person();
    //p1.work();
    //std::cout<<"\n\n\n";
    //Student s1;
    //s1.Person::work();



    // point 6
    Square* sq = new Square();
    Shape* sh = new Square();
    Quad* qu = new Square();
    
    Square sq1 = Square();
    Shape sh1 = Square();
    Quad qu1 = Square();  


    return 0;
}