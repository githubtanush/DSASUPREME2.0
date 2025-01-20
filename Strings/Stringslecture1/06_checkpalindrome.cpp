#include<iostream>
using namespace std;
bool checkpalindrome(char ch[],int n){
    int i = 0;
    int j = n - 1;
    while(i <= j){
        if(ch[i] != ch[j]) return false;
        i++;
        j--;
    }
    return true;
}
int main(){
    //create character array
    char ch[100];

    //take input
    cin.getline(ch,100);

    //check left and right side of array
    cout<<"Before : "<<ch<<endl;
    int len = strlen(ch);
    if(checkpalindrome(ch,len)) cout<<"Yes! it is a palindrome"<<endl;
    else cout<<"No! it is not a palindrome"<<endl;
    return 0;
}