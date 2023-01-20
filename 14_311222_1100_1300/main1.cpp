#include<iostream>
#include<string>

void print(int a, std::string b){
    std::cout<<a<<" "<<b<<"\n";
}

void print(int a, int b){
    std::cout<<a<<" "<<b<<"\n";
}

int main(){
    print(2, "joe");
    return 0;
}