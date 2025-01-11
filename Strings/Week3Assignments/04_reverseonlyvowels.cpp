#include<iostream>
#include<string>
using namespace std;
bool isVowel(char ch){
     ch = tolower(ch);
    return ch=='a' || ch=='e' || ch=='o' || ch=='i' || ch=='u';
}
    string reverseVowels(string s) {
        int low = 0;
        int high = s.size()-1;
        while(low<high){
            if(isVowel(s[low]) && isVowel(s[high])){
                swap(s[low],s[high]);
                low++;
                high--;
            }
            else if(!isVowel(s[low])){
                low++;
            }
            else{
                high--;
            }
        }
        return s;
    }
int main(){
    string s;
    getline(cin,s);
    string ans = reverseVowels(s);
    cout<<"After reversing the vowels string will be printed as : "<<ans<<endl;
    return 0;
}
//hello - holle
//leetcode - leotcede