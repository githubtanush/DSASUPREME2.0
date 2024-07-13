#include<iostream>
#include<vector>
using namespace std;
void solve(string mapping[],string& output,int index,vector<string>& ans,string str){
    //base case
    // yeh vala case hmesha yaad rkhna
    if(index >= str.length()){
        //output string bn chuki hogi
        //store that string in ans array
        if(output.length()>0) ans.push_back(output);
        return ;
    }
    string temp = mapping[str[index]-'0'];
    for(auto ch:temp){
        output.push_back(ch);
        solve(mapping,output,index+1,ans,str);
        //backtracking
        output.pop_back();
    }
}
vector<string> lettercombination(string digits){
    string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string output = "";
    int index = 0;
    vector<string> ans;
    solve(mapping,output,index,ans,digits);
    return ans;
}
int main(){
    string digits;
    getline(cin,digits);
    vector<string> ans = lettercombination(digits);
    for(auto ch:ans){
        cout<<ch<<" ";
    }
    return 0;
}
// 23
// ad ae af bd be bf cd ce cf  