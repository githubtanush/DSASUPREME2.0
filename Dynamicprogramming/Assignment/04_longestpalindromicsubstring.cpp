#include<iostream>
#include<string>
using namespace std;
//Longest palindromic substrings 
// => palindromic substrings
// => extract palindromic ones -> max length
// => max length substrings from all palindromic substrings

// Palindrome check krna tumhe aata hai 
//One approach with dynamic programming in which we solve this O(N^3) solution in O(N^2);
//palindrome => forward / backward same then it is called longest palindromic substring
// left to right right to left same hona chahiye
// One way with dynamic programming which u solve in dynamic programming 


//by the help of recursion we check i to j string is palindrome or not 
// if(true) then find length 
// if(maxlength < length) j - i + 1 current length;
// start = i ;
bool solve(string& s,int i,int j){
    int n = s.size();
    while(i>=j) {
        if(s[i] != s[j]) return false;
    }
    return true;
}   

string longestpalindrome(string& s){
    int n = s.size();
    for(int i = 0; i < n;i++){
        for(int j = i; j < n;j++){
            solve(s,i,j);
        }
    }
}
int main(){
    string s;
    getline(cin,s);
    string ans = longestpalindrome(s);
    cout<<"Longest palindromic substring is : "<<ans<<endl;
    return 0;
}
//babad