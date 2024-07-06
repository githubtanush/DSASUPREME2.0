#include<iostream>
#include<string>
using namespace std;
//Palindrome check krna tumhe aata hai 
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
    for(int i = 0;i < s.size();i++){
        //ek or for loop chlaya jo agr ek se jada word hai toh string par iterate krwayga
        for(int j = i;j < s.size();j++){
            //yeh if condition se check krunga palindrome hai ya nhi 
            if(ispalindrome(s,i,j)){
                string t = s.substr(i,j-i+1);
                ans = t.size()>ans.size()?t:ans;
            }
        }
    }
    return ans;
}
int main(){
    string s;
    getline(cin,s);
    string ans = longestpalindrome(s);
    cout<<"Longest palindromic substring is : "<<ans<<endl;
    return 0;
}
//babad