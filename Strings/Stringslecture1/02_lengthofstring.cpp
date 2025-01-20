#include<iostream>
#include<string>//for use string inbuilt function
using namespace std;
int length(char ch[],int size){
    int i = 0;
    //jeise hi null character aaya matlab counting bnd kr do
    while(ch[i]!='\0'){
        i++;
    }
    return i;
}
int main(){
    //create character array 
    char ch[100];
    //Take input 
    cin>>ch;
    //find length
    int len = length(ch,100);
    cout<<"Length of the string is : "<<len<<endl;
    //inbuilt function strlen
    cout<<"Length of the string is : "<<strlen(ch)<<endl;
    return 0;
}