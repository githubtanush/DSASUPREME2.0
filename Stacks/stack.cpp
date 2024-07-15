#include<iostream>
using namespace std;
class stack{
    public : 
            int *arr;
            int size;
            int top;
    stack(int size){
        arr = new int[size];
        this->size = size ;
        this->top = -1;
    }
    void push(int data){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
            return ;
        }
        else{
            top++;
            arr[top] = data;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return ;
        }
        else{
            top--;
        }
    }
    bool isempty(){
        if(top==-1){
            return true;
        }
        else return false;
    }
    int gettop(){
        if(top==-1){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }
    int getsize(){
        return top+1;
    }

    void print(){
        cout<<"Top Element : "<<gettop()<<endl;
        cout<<"Top : "<<top<<endl;
        cout<<"Stack : ";
        for(int i = 0; i < getsize();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    return 0;
}