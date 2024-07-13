#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void solve(string& s,unordered_set<string>&ans,int invalidopen,int invalidclose,int balance,int index,string& output){
    //base case
    if(index >= s.length()){
        //valid answer 
        if(invalidopen==0 && invalidclose==0 && balance==0) ans.insert(output);
        return ;
    }
    //INCLUDE/EXCLUDE PATTERN
    if(s[index] != '(' && s[index]!= ')'){
        output.push_back(s[index]);
        solve(s,ans,invalidopen,invalidclose,balance,index+1,output);
        output.pop_back();
    }
    else{
        //brackets
        //2nd case -> ( and )
        //open bracket
        if(s[index]=='('){
            //inc/exc
            //remove kru
            if(invalidopen>0) solve(s,ans,invalidopen-1,invalidclose,balance,index+1,output);
            //remove na kru 
            output.push_back('(');
            solve(s,ans,invalidopen,invalidclose,balance+1,index+1,output);
            output.pop_back();
        }
        else if(s[index]==')'){
            //remove kru 
            if(invalidclose > 0){
                solve(s,ans,invalidopen,invalidclose-1,balance,index+1,output);
            }
            //remove na kru 
            //jaha aap glti krte ho
            //ap ek closed bracket par khda ho 
            //and previously koi bhi open bracket nhi hai
            //toh kya mein remove na kru ?
            if(balance>0){
                 output.push_back(')');
                 solve(s,ans,invalidopen,invalidclose,balance-1,index+1,output);
                 output.pop_back(); 
            }
        }
    }

}
vector<string> removeinvalidparenthesis(string s){
    unordered_set<string> ans;
    int invalidopen = 0;
    int invalidclosed = 0;
    int balance = 0;
    int index = 0;
    string output = "";
    
    for(auto ch:s){
        if(ch== '('){
            invalidopen++;
        }
        else if(ch==')'){
            if(invalidopen>0){
                invalidopen--;
            }
            else{
                invalidclosed++;
            }
        }
    }
    solve(s,ans,invalidopen,invalidclosed,balance,index,output);
    return vector<string>(ans.begin(),ans.end());

}
int main(){
    string s;
    getline(cin,s);
    vector<string> ans = removeinvalidparenthesis(s);
    for(auto ch: ans){
        cout<<ch<<",";
    }
    cout<<endl;
    return 0;

}
// ()())()
//output - 
// ()()(),(())()


// (a)())()
// (a)()(),(a())()