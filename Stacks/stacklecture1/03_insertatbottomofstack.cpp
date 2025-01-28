#include<iostream>
#include<stack>
using namespace std;
void insertatbottom(stack<int>& st,int& element){
//jab stack khali ho jaay tbhi element push krna hai 
if(st.empty()){
    //stack ka andar element push krna hai
    st.push(element);
    return ;
}
// 1 case mein solve krunga baaki recursion dekh lunga
int temp = st.top();
// phir mein pop kr dunga
st.pop();

//baakirecursion chacha dekh lenge
insertatbottom(st,element);
//backtracking kro ab 
//or backtracking krte time element vaapis se push krte jao
st.push(temp);
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    int element = 400;
    insertatbottom(st,element);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}