#include<iostream>
using namespace std;
int length(char ch[],int size){
    int i = 0;
    //jeise hi null character aaya matlab counting bnd kr do
    while(ch[i]!='\0'){
        i++;
    }
    return i;
}
void reversestring(char ch[],int len){
    int i = 0;
    int j = len - 1;
    while(i <= j){
        swap(ch[i],ch[j]);
        i++;
        j--;
    }
}
int main(){
    //create character array 
    char ch[100];
    //Take input 
    cin.getline(ch,100);
    //find length
    int len = length(ch,100);
    cout<<"Length of the string is : "<<len<<endl;
    //inbuilt function strlen
    cout<<"Length of the string is : "<<strlen(ch)<<endl;

    cout<<"Before : "<<ch<<endl;
    reversestring(ch,len);
    cout<<"After : "<<ch<<endl;
    
    return 0;
}