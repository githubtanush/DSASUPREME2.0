// custom sort sorting
#include<iostream>
using namespace std;
//custom comparator
static string str;
static bool compare(char char1,char char2){
    return (str.find(char1) < str.find(char2));
}
string customsortstring(string order, string s){
    str = order;
    sort(s.begin(),s.end(),compare);
    return s;
}
int main(){
    string order;
    cout<<"Take the order string : ";
    cin>>order;
    string s ;
    cout<<"Take the string s : ";
    cin>>s;
    string strs = customsortstring(order,s);
    cout<<"String by custom sorting contained this : "<<strs<<endl;
    return 0;
}
//order = cba
//s = cbad;

// order = cbafg
// s = abcd