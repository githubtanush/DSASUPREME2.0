#include<iostream>
using namespace std;
class heap{
    public:
        int* arr;
        int capacity;
        int size;
    
    heap(int capacity){
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
    }

    void insert(int val){
        if(size == capacity){
            cout<<"Heap Overflow"<<endl;
            return ;
        }

        size++;
        
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parentindex = index/2;
            if(arr[index] > arr[parentindex]){
                swap(arr[index],arr[parentindex]);
                index = parentindex;
            }
            else break;
        }
    }
    
    void printheap(){
        for(int i = 0; i <= size;i++) cout<<arr[i]<<" ";
    }

};
int main(){
    return 0;

}