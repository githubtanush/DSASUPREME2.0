#include<iostream>
using namespace std;
string removeoccurrances(string& s,string& part){
    //hm find krenge string mein kaha located hai voh part then utni length tak ka part hm erase kr denge
    // while(s.find(part) != string::npos){
    //     //if inside loop it means that part exist in string
    //     s.erase(s.find(part),part.length());
    // }
    while(1){
        int found = s.find(part);
        if(found==string::npos) break;

        //remove krna hai 
        string lp = s.substr(0,found);
        string rp = s.substr(found+part.size(),s.size());
        
        //concatenate both pairs
        s = lp + rp;
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