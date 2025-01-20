#include<iostream>
using namespace std;
void uppercase(char ch[],int len){
    int index = 0;
    while(ch[index] != '\0'){
        char currcharacter = ch[index];
        //check if lowercase , then convert it into upper case 
        if(ch[index]>='a' && ch[index]<='z'){
            ch[index] = currcharacter - 'a' + 'A';
        }
        index++;
    }
}
void lowercase(char ch[],int len){
    int index = 0;
    while(ch[index] != '\0'){
        char currcharacter = ch[index];
        if(currcharacter>='A' && currcharacter <= 'Z')
            ch[index] = currcharacter - 'A' + 'a';
        index++;
    }
}
int main(){
    //create character array 
    char ch[100];
    //Take input 
    cin.getline(ch,100);
    //To convert it into uppercase
    cout<<"Before : "<<ch<<endl;
    int len = strlen(ch);
    uppercase(ch,len);
    cout<<"After : "<<ch<<endl;
    //convert it to lowercase
    lowercase(ch,len);
    cout<<"Double After : "<<ch<<endl;
    return 0;
}