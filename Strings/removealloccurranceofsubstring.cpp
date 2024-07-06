#include<iostream>
using namespace std;
string removeoccurrances(string& s,string& part){
    //hm find krenge string mein kaha located hai voh part then utni length tak ka part hm erase kr denge
    while(s.find(part) != string::npos){
        //if inside loop it means that part exist in string
        s.erase(s.find(part),part.length());
    }
    return s;
}
int main(){
    string s;
    getline(cin,s);
    string part;
    getline(cin,part);
    string ans = removeoccurrances(s,part);
    cout<<"After removing the part string from s string it will return : "<<ans<<endl;
    return 0;
}
//str - abbcbaddcbabbbaac
//part - cba