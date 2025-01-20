#include<iostream>
using namespace std;
string adjacentduplicate(string& s){
    //ek string bna leta hu return krne ke liye
    string ans = "";
    //index start krta hu eska 0 se
    int index = 0;
    //mein tab hi insert kr paunga jb es character string ka right most character same nhi hoga
    //diff hoga tbhi push krunga
    //same hoga tb pop krenge
    //condition check krenge jab tak index string ki length se chota hai tab tak 
    while(index<s.length()){
        //agr same hua answer ka rightmost character and string ka character
        //then pop it
        if(s.length()>0 && ans[ans.length()-1]==s[index]){
            ans.pop_back();
        }
        else{
            //push 
            ans.push_back(s[index]);
        }
        index++;
    }
    return ans;
}
int main(){
    string s;
    getline(cin,s);
    string ans = adjacentduplicate(s);
    cout<<"After removing duplicate character at adjacent string form will like : "<<ans<<endl;
    return 0;
}
//azxxzy
//abbaca