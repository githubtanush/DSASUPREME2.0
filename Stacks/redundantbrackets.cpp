#include<iostream>
#include<stack>
using namespace std;
bool checkredundantbrackets(string& s){
    stack<char> st;
    for(int i = 0; i < s.length();i++){
        char ch = s[i];

        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else if(ch==')'){
            int operatorcount = 0;
            while(!st.empty() && st.top() != '('){
                char temp = st.top();
                if(temp=='+' || temp=='-' || temp=='*' || temp=='/'){
                    operatorcount++;
                }
                st.pop();
            }
            //yaah pr tb phunchoge jab
            //jab apke stack ke top pr ek opening bracket hoga
            st.pop();
            if(operatorcount == 0) return true;
        }
    }
    //agr mein yaah tak phuncha hu eska matlab ki har ek bracket ke pair ke bich mein ek operator pkka mila hoga
    //matlab return false;
    return false;
}
int main(){
    string str = "(((a+b)*(c+d)))";
    bool ans = checkredundantbrackets(str);

    if(ans){
        cout<<"Redundant bracket is present"<<endl;
    }
    else{
        cout<<"Redundant bracket is not present"<<endl;
    }
    return 0;
}