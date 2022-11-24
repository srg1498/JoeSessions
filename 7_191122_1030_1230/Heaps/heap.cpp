#include<iostream>
#include<vector>

using namespace std;

class MinHeap{
    private:
             std::vector<int> elements;
             int n;

             void shiftUp(int idx){
                 while(idx/2 >= 1){
                     if(elements[idx/2] <= elements[idx])
                         break;
                     std::swap(elements[idx/2], elements[idx]);
                     idx = idx/2;        
                 }
             }

             void shiftDown(int idx){
                 while(2*idx <= n){
                    int minPos = idx;
                    if(elements[2*idx] < elements[idx])
                        minPos = 2*idx;
                    if((2*idx+1 <= n) && (elements[2*idx+1] < elements[minPos]))
                        minPos = 2*idx+1;
                    if(idx == minPos)
                        break;
                    std::swap(elements[idx], elements[minPos]);
                    idx = minPos;
                 }
             }

             void build(){
                for(int i=n/2;i>=1;i--){
                    shiftDown(i);
                }
             }

    public:
             MinHeap(){
                 elements.push_back(0);
                 n = 0;
             }

             MinHeap(std::vector<int> inputVector){
                 elements.push_back(0);
                 n = 0;
                 for(int i=0;i<inputVector.size();i++){
                    elements.push_back(inputVector[i]);
                    n += 1;
                 }
                 build();
             }

             void insertEle(int ele){
                 n += 1;
                 elements.push_back(ele);
                 shiftUp(n);
             }  

             void updateEle(int pos, int ele){
                if((pos > n) && (pos <= 0))
                    return;
                 elements[pos] = ele;
                 shiftDown(pos);
             } 

             void deleteEle(int pos){
                 if((pos > n) && (pos <= 0))
                    return;
                 std::swap(elements[pos], elements[n]);
                 n -= 1;
                 shiftDown(pos);
             }

             int minElement(){
                // can add check here
                return elements[1];
             }

             void printHeap(){
                for(int i=1;i<=n;i++)
                    std::cout<<elements[i]<<" ";
                std::cout<<"\n";
             }
};


int main(){

    //MinHeap mh = MinHeap();
    
    //mh.insertEle(25);
    //mh.insertEle(29);
    //mh.insertEle(10);
    //mh.insertEle(20);
    //mh.insertEle(30);
    //mh.insertEle(15);

    //mh.printHeap();
    //std::cout<<mh.minElement()<<"\n";

    //mh.updateEle(3, 26);
    //mh.printHeap();

    //mh.deleteEle(1);
    //mh.printHeap();
    //std::cout<<mh.minElement()<<"\n";

    std::vector<int> v = {23, 26, 10, 9, 17, 5, 29, 25, 31, 45, 18, 39, 34, 81, 99};

    MinHeap mh = MinHeap(v);
    mh.printHeap();
    std::cout<<mh.minElement()<<"\n";
    
    return 0;
}