#include<iostream>
using namespace std;
void printpermutation(string& str,int index){
    //Base case
    if(index >= str.size()){
        cout<<str<<" ";
        return ;
    }

    //recursively solution
    for(int j = index;j<str.length();j++){
        swap(str[index],str[j]);
        //recursively call
        printpermutation(str,index+1);
        //backtracking
        swap(str[index],str[j]);
    }
}
int  main(){
    string str;
    getline(cin,str);
    int index = 0;
    printpermutation(str,index);
    return 0; 
}