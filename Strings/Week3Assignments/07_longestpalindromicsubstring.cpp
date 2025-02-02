#include<iostream>
#include<string>
using namespace std;
//Longest palindromic substrings 
// => palindromic substrings
// => extract palindromic ones -> max length
// => max length substrings from all palindromic substrings

// Palindrome check krna tumhe aata hai 

bool ispalindrome(string& s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
string longestpalindrome(string& s){
    //new string bna li answer name ki
    string ans = "";
    //ek for loop chlaya i variable se jis par hmm string par iterate krenge
    for(int i = 0;i < s.size();i++){ //=> O(N)
        //ek or for loop chlaya jo agr ek se jada word hai toh string par iterate krwayga
        for(int j = i;j < s.size();j++){ //=> O(N)                                                 ==> O(N^3)
            //yeh if condition se check krunga palindrome hai ya nhi 
            if(ispalindrome(s,i,j)){ //=> O(N)
                string t = s.substr(i,j-i+1);
                ans = t.size()>ans.size()?t:ans;
            }
        }
    }
    return ans;
}

//One approach with dynamic programming in which we solve this O(N^3) solution in O(N^2);
//palindrome => forward / backward same then it is called longest palindromic substring
// left to right right to left same hona chahiye
// One way with dynamic programming which u solve in dynamic programming 
int main(){
    string s;
    getline(cin,s);
    string ans = longestpalindrome(s);
    cout<<"Longest palindromic substring is : "<<ans<<endl;
    return 0;
}
//babad