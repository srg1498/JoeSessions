#include<iostream>

using namespace std;

class custom_vec{
    private:
    int *arr;
    int siz, cap;

    public:
    
    custom_vec():siz(0), cap(0){
        arr = NULL;
    }
    
    custom_vec(int n):siz(n), cap(n){
        arr = new int[n];
    }
	
	custom_vec(int n, int val):siz(n), cap(n){
        arr = new int[n];
		for(int i=0;i<n;i++){
			arr[i] = val;
		}
    }
    
    void push_back(int ele){
        if(siz+1 <= cap){
            arr[siz++] = ele;
        }else{
            int *b;
            if(cap){
                b = new int[cap*2];
                cap *= 2;
            }else{
                b = new int[1];
                cap = 1;
            }
            for(int i=0;i<siz;i++){
                b[i] = arr[i];
            }
            delete [] arr;
            arr = b;
            arr[siz++] = ele;
        }
    }

    int pop_back(){
        if(siz){
            return arr[siz--];
        }
    }

    int size(){
        return siz;
    }

    int capacity(){
        return cap;
    }

    int at(int i){
		if(i>=siz){
			throw "out of range";
		}
        return arr[i];
    }

    int operator [](int i){
        return arr[i];
    }
};

int main(){
    
    custom_vec v1;
    custom_vec v2(5);
    cout<<v1.size()<<" "<<v1.capacity()<<"\n";
    cout<<v2.size()<<" "<<v2.capacity()<<"\n";
    v1.push_back(2);
    v2.push_back(3);
    cout<<v1.size()<<" "<<v1.capacity()<<"\n";
    cout<<v2.size()<<" "<<v2.capacity()<<"\n";
    cout<<v2[5];

    return 0;
}