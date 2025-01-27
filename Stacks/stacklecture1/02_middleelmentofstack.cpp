//Very important pattern 
//Most classical problems solve by this
#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int>& st,int& pos,int& ans){
    //Base case
    if(pos == 1){
        //jab position 1 aa jay to us element ko print kr lena
        ans = st.top();
        //or esko return krdo
        return ;
    }
    //1 case hm solve krenge
    //pos ko -- krte rho 
    pos--;
    //temp ke andar stack ka top rkhte jao 
    int temp = st.top();
    //usko save esliye kiya kyuki baad mein vo vaapis daalna ka kaam aayga
    st.pop();
    //recursion chlado
    solve(st,pos,ans);
    //stack ke andar temp ko push krte jao 
    st.push(temp);
}
int getmiddleelement(stack<int>& st){
    //size nikal lo stack ka
    int size = st.size();
    //jab stack ka empty ho jay to -1 return krdo
    if(st.empty()) return -1;
    else{
        //Stack is not empty
        int pos = 0;
        //even stack mein position nikalna ka liye
        if(size & 1) pos = size/2 + 1;
        //odd stack mein position nikalna ka liye
        else pos = size/2;
    //ans mein -1 ko store kr lo
    int ans = -1;
    //Recursion chla do 
    solve(st,pos,ans);
    //answer return krdo 
    return ans;
    }
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    int mid = getmiddleelement(st);
    cout<<"Middle Element is : "<<mid<<endl;
    return 0;
}