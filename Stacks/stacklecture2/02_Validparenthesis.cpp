#include<iostream>
#include<stack>
using namespace std;
// jab bhi mere ko thora sa bhi reversal vala case aaya balanced expression vla case aay to valid parenthesis 
// ko ek baar sochna hai thora dry run kroga to ho jayga
bool isvalid(string s){
    stack<char> st;
    for(int i = 0; i < s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch=='[' || ch=='{'){
            // for open bracket - just push
            st.push(ch);
        }
        else{
            if(!st.empty()){
                //closing bracket
                if(ch==')' && st.top()=='('){
                    st.pop();
                }
                else if(ch=='}' && st.top()=='{'){
                    st.pop();
                }
                else if(ch==']' && st.top()=='['){
                    st.pop();
                }
                else{
                    //no match
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(st.size()==0){
        return true;
    }
    else return false;
}
int main(){

}
