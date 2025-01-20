#include<iostream>
using namespace std;
void replaceatwithspace(char ch[],int len){
    int index = 0;
    while(ch[index] != '\0'){
        char curr = ch[index];
        //agr mera curr at the rate hai then usko replace with space
        //insert with space
        if(curr == '@') ch[index] = ' ';
        index++; // index ko aaga bda do
    }
}
int main(){
    //creation
    char ch[100];

    //take input
    cin.getline(ch,100);

    //function to replace at the rate with space
    cout<<"Before : "<<ch<<endl;
    int len = strlen(ch);
    replaceatwithspace(ch,len);
    cout<<"After : "<<ch<<endl;

    return 0;
}
// My@name@is@Tanush@Arora