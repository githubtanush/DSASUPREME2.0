//ek single array ka use krke two stack ki kahani ko implement krna hai 
// find that approach where u don't have a memory waste 

//Method 1 - mein ek single array ko 2 parts mein divide kr leta hu 
// or ek part mein stack 1 implement kr dunga
// or dusra part mein stack 2 implement kr dunga
// but esma ek ghata agr mein yeh array ko 2 parts mein divide krdu or stack 1
// ka n/2 size pura occupied ho gya to jo aaga space bchi hai vo vo occupy nhi 
// krega to esko kehta hai memory wastage 
//There is very memory wastage 


// so we find a approach where we don't show a memory wastage

//so another method 2 - 
// we know that we access the array only by the top pointer
//so we intialize the top1 and top2 two pointers for stack
// stack 1 left se right ki taraf or stack 2 right se left ki taraf 
//element insert kr rah hoga

//when top1 == -1 means stack1 is empty - underflow condition
//when top2 == -1 means stack2 is empty - underflow condition

// and when top2 - top1 == 1 aa jaay matlab saari ki saari memory 
//fill ho chuki hai
// overflow ho jayga ab to or insert nhi krna

 
#include<iostream>
using namespace std;
class Stack{
    public:
        int *arr;
        int size;
        int top1;
        int top2;
        
    Stack(int size){
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data){
        if(top2-top1 == 1) cout<<"Overflow"<<endl;
        else{
        top1++;
        arr[top1] = data;
        }
    }
    void push2(int data){
    if(top2-top1 == 1) cout<<"Overflow"<<endl;
    else{
        top2--;
        arr[top2] = data;
        }
    }
    void pop1(){
        if(top1 == -1) cout<<"Underflow"<<endl;
        else{
            arr[top1] = 0;
            top1 = -1;
        }
    }
    void pop2(){
        if(top2 == size) cout<<"Underflow"<<endl;
        else{
            arr[top2] = 0;
            top2++;
        }
    }
    void print(){
        cout<<endl;
        cout<<"Top 1 : "<<top1<<endl;
        cout<<"Top 2 : "<<top2<<endl;
        for(int i = 0; i < size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Stack st(6);
    st.push1(10);
    st.push1(20);
    st.push1(30);
    st.push2(40);
    st.push2(50);
    st.push2(60);
    st.push2(500);
    st.print();
    return 0;
}