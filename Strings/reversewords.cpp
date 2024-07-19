#include<iostream>
using namespace std;
void helper(int i,string& ans,string s){
    while(s[i]!=' ' && i < s.length()){
        ans += s[i++];
    }
}
string reversewords(string s){
    int i = s.length()-1;
    while(s[i]==' ') i--;
    string ans = "";
    while(i>=0){
        if(s[i]==' ' && s[i+1]!= ' '){
            helper(i+1,ans,s);
            ans += ' ';
        }
        if(s[i] != ' ' && i==0){
            helper(i,ans,s);
        } 
        i--;
    }
    while(ans.back()==' ') ans.pop_back();
    return ans;
}
int main(){
    string s;
    getline(cin,s);
    string ans = reversewords(s);
    cout<<ans<<" ";
    return 0;
}
           
// The sky is blue
// blue is sky The 