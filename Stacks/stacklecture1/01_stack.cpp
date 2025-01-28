//stack is a data structure which can store the elements in lifo order last in first out 
//which we insert last we firstly take this
//like example the order of plates in marriage(daashi)
//stack is a machine which always reverse the order of the array 


//stl c++  - creation stack<int> st - integer stack , stack<char> st - character stack
// stack<string> st - string stack , stack<node> - node stack;
// function is - st.top(), st.empty(), st.size(), st.pop(), st.push();
// u cannot acess the stack using indexing there is no indexing concept in stack
// the only way to access stack is by the top element
// u can access only 1 element one time in the stack 


// stack mein hm jeise bhi element daala agr pop out krenge 
// to reverse hi niklaga  
// to jaah bhi kayi aisa bola gya ho toh yaad rkhna stack se ho skta hai 
// kyuki stack ka matlab recursion or recursion ka matlab stack
// to jo bhi recursion se kr rah tha vo stack se kr skte hai
// or jo bhi stack se kr rah hai vo recursion se ho skta hai

#include<iostream>
using namespace std;
class Stack{
    public:
        int* arr;// stack array se hi bna hota bss dynamic array create krlo
        int size;// stack ka size kitna 
        int top;// stack ka top ka element kaha hai ya kon hai
        
    Stack(int size){
        arr = new int[size];//array ko bna diya or initialize kr diya size se
        this->size = size;// size ke andar uski value daal di
        this->top = -1;// top ka index shuru se start krdo
    }
    void push(int element){
        if(top == size-1){// agr top size -1 par aagya to matlab ki pura fill hogya array 
            cout<<"Stack Overflow"<<endl;
            return ;
        }
        else{// top ko aaga bda dunga pehle then uss top index par insert krwa dunga
            top++;// aaga bda diya
            arr[top] = element;// insert kr diya
        }
    }
    void pop(){
        if(top == -1){// agr top == -1 hai means ki voh underflow ho rah 
            cout<<"Stack Underflow"<<endl;
            return ;
        }
        else{
            top--;//simple top ko ghta do matlab ki pop ho gya
        }
    }
    int gettop(){
        if(top == -1){// agr top -1 hai to stack empty hai 
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        else return arr[top];//nhi to jo top par hai use return krdo
    }
    bool empty(){
        if(top == -1) return true;// agr top -1 hai to return true krdo ki empty hai array
        else return false;// or agr nhi hai to return false krdo ki array empty hai
    }
    int getsize(){
        return top+1;//size nikalna ka liye top+1 le lenge
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