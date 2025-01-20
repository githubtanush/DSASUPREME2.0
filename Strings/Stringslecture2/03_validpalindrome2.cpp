//valid palindrome 2
//atmost 1 removal se agr palindrome bne to bna do
//atmost 1 removal means you cannot remove or you remove by one
//atmost 1 simply means 0 or 1 removal to make valid palindrome

#include<iostream>
using namespace std;
bool checkpalindrome(string s, int i,int j){
    while(i<=j){
        if(s[i] != s[j]) return false;
        else{
            i++;
            j--;
        }
    }
    //agr yaah tak phunche matlab check ho gya mtlb 
    //return true krdo
    return true;
}
bool validpalindrome(string s){
    int left = 0;
    int right = s.length()-1;
    while(left < right){
        if(s[left] == s[right]){
            left++;
            right--;
        }
        else{
            //s[i]!=s[j];
            //1 removal allowed
            // check palindrome for remaining string after removal

            //ith character -> remove
            bool ans1 = checkpalindrome(s,left+1,right);
            //jth character -> remove
            bool ans2 = checkpalindrome(s,left,right-1);

            return ans1 || ans2;
        }
    }
    //agr yaah tak phunche ho matlab valid palindrome hai matlab 0 removal 
    //matlab valid palindrome 
    return true;
}
int main(){
    //create the string
    string s;
    //take input in the s
    cin>>s;
    //check that it is palindrome
    bool ans = validpalindrome(s);
    if(ans) cout<<"It is valid palindrome"<<endl;
    else cout<<"It is not a valid palindrome"<<endl;
    return 0;
}