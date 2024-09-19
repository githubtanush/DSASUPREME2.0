#include<iostream>
using namespace std;
void reversestring(string s,int start,int end){
    //base case
    if(start>=end){
        cout<<s<<endl;
        return;
    }

    //processing
    swap(s[start],s[end]);

    //recursive relation
    reversestring(s,start+1,end-1);
}
int main(){
    string s = "Tanush Arora";
    cout<<"String given is this : "<<s<<endl;
    cout<<"Reversed string will look like this : ";
    reversestring(s,0,s.length()-1);
    return 0;
}