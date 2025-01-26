#include<iostream>
using namespace std;
void findtarget(string s,int index,char target){
    //base case
    if(index >= s.size()) return ;

    //processing
    if(s[index] == target) cout<<index<<" ";

    //recursive relation
    findtarget(s,index+1,target);
}
int main(){
    string s;
    getline(cin,s);
    char target;
    cout<<"Enter the character you want to find in the string : ";
    cin>>target;
    findtarget(s,0,target);
    return 0;
}