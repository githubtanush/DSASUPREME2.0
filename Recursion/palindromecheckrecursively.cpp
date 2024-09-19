#include<iostream>
using namespace std;
 //base case
 //one case solution
 //baaki recursion sambhallega
 bool ispalindrome(string& s,int start, int end){
    //base case
    if(start > end) return true;

    //One case solution
    if(s[start] != s[end]) return false;

    return ispalindrome(s,start+1,end-1);
 }
 int main(){
    string s;
    cin>>s;
    cout<<ispalindrome(s,0,s.size()-1)<<endl;
    return 0;
 }