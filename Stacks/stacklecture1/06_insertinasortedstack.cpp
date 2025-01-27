#include<iostream>
#include<stack>
using namespace std;
void insertsortedstack(stack<int>& st,int element){
    //jab bhi stack ka top access kr rah ho to dimag mein laal baati jlni chahiye ki 
    //check krlo stack empty hai ya nhiiiiii
    //base case - glti 
    // if(element > st.top) wrong condition

    if(st.empty() || element > st.top()){
        st.push(element);
        return ;
    }
    //1case solve kr do bhaiya taaki baaki recursion bhaiya ji dekh le
    int temp = st.top();
    st.pop();

    //recursion chacha sambhalna jara
    insertsortedstack(st,element);

    //backtrack krlo 
    st.push(temp);
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    int element = 5;
    insertsortedstack(st,element);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
