#include<iostream>
#include<stack>
using namespace std;
void buildans(stack<string>& s,string& ans){
    //Base case - agr stack khali ho jaay to return krdo 
    if(s.empty()) return ;

    //stack ka top element access krte rho 
    string minpath = s.top();
    //or access krne ka baad pop bhi krte jao 
    s.pop();

    //Baaki recursion sambhal lega
    buildans(s,ans);

    //backtrack krte jao
    ans+=minpath;
}
string simplifypath(string path){
    stack<string> st;
    int i = 0;
    while(i < path.size()){
        int start = i;
        int end = i + 1;
        while(end < path.size() && path[end] != '/') end++;
        string minpath = path.substr(start,end-start);
        i = end;
        if(minpath == "/" || minpath=="/.") continue;
        if(minpath != "/..") st.push(minpath);
        else if(!st.empty()) st.pop();
    }
    string ans = st.empty() ? "/" : "";
    buildans(st,ans);
    return ans;
}
int main(){
    string path = "/home/user/Documents/../Pictures";
    string ans = simplifypath(path);
    cout<<ans<<endl;
    return 0;
}
// "/home/user/Pictures" answer