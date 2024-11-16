#include<iostream>
using namespace std;
class Stack{
    public:
        int* arr;
        int size;
        int top;
        
    Stack(int size){
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }
    void push(int element){
        if(top == size-1){
            cout<<"Stack Overflow"<<endl;
            return ;
        }
        else{
            top++;
            arr[top] = element;
        }
    }
    void pop(){
        if(top == -1){
            cout<<"Stack Underflow"<<endl;
            return ;
        }
        else{
            top--;
        }
    }
    int gettop(){
        if(top == -1){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        else return arr[top];
    }

    int getsize(){
        return top+1;
    }
    void print(){
        cout<<"Top Element : "<<gettop()<<endl;
        cout<<"Top : "<<top<<endl;
        for(int i = 0; i < getsize();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Stack st(8);
    st.push(10);
    st.push(38);
    st.push(93);
    st.print();
    return 0;
}