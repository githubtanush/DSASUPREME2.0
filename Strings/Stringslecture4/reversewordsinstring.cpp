#include<iostream>
using namespace std;
string reverseWords(string s) {
    int n = s.size();
    string ans = "";
    reverse(s.begin(),s.end());
    for(int i = 0; i < s.size();i++){
     string word = "";
     while( i < n && s[i]!= ' ')
         word += s[i++];
     
     reverse(word.begin(),word.end());
     if(word.length() > 0) ans += " " + word;
    }
    return ans.substr(1);
 }
 int main(){
    string s;
    cout<<"Enter the string s which u want to reverse : ";
    getline(cin,s);
    cout<<"reverse words in string see like this : "<<reverseWords(s)<<endl;
    return 0;
 }