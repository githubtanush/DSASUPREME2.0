#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
    string s;
    cout<<"Enter string : ";
    getline(cin,s);
    char ch;
    cout<<"Enter character : ";
    cin>>ch;
    char str1 = s.c_str();
    char c = strchr(str1,ch);
    if(c!=NULL){
        cout<<c<<endl;
    }


    return 0;
}