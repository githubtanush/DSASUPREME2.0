//Remove all adjacent duplicates in string 
// by stack we solve this problem
//like a valid parenthesis problem we try to pair this 
//check krunga top par element pda hai or agr pda hai remove kr dunga
#include<iostream>
using namespace std;
string removeduplicates(string s){
    // stack lunga character type ka 
    stack<char> st;
    //for each loop bgaunga elements par iterate krne ke liye
    for(auto ch : s){
        if(st.empty())st.push(ch); // agr stack empty hua toh stack ka andar character push krenge
        else if(!st.empty() && st.top() == ch) st.pop();// pair up 
        else st.push(ch);
    }
    string ans;
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string s;
    getline(cin,s);
    string str = removeduplicates(s);
    cout << "After Removing the adjacent duplicates : "<<str<<endl;
    return 0;
}
//azxxzy
