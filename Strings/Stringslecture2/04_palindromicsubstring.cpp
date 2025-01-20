//palindromic substrings - i/p = "aba"
// a , aba , ab, ba , b, a

//Appraoch - brute force - find all substrings O(n2)
// and then at all check palindrome

//Acha solution = 
// palindrome = 2 pointer extreme left to extreme right

// for odd i j lga diya then outward direction mein jao 
// or substring find krte jao
// for even i j lga diya then outward direction mein jao 
// or substring find krte jao


#include<iostream>
using namespace std;
int expand(string s, int i,int j){
    int count = 0;
    while(i>=0 && j<s.length() && s[i] == s[j]){
        count++;
        i--;
        j++;
    }
    return count;
}
int countpalindromicsubstrings(string s){
    int totalcount = 0;
    for(int center = 0; center < s.length();center++){
        //odd
        int oddkaans = expand(s,center,center);
        //even
        int evenkaans = expand(s,center,center+1);
        totalcount  += oddkaans + evenkaans;
    }
    return totalcount;
}
int main(){
    string s = "aaa";
    int ans = countpalindromicsubstrings(s); 
    cout<<"Total substrings in this string is : "<<ans<<endl;
    return 0;
}
//abc
