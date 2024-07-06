#include<iostream>
using namespace std;
// void createmapping(string& s){
//     char mapping[256] = {0};
//     char start = 'a';

//     for(int i = 0; i < s.size();i++){
//         if(mapping[s[i]]==0){
//         mapping[s[i]] = start;
//         start++;
//         }
//     }

//     for(int i = 0; i < s.size();i++){
//         s[i] = mapping[s[i]];
//     }
// }
// bool isisomorphic(string& s,string& t){
//     createmapping(s);
//     createmapping(t);
//     if(s.compare(t)==0){
//         return true;
//     }
//     return false;
// }
bool isisomorphic(string& s,string& t){
    int hash[256] = {0};//mapping each character of language s to language t
    bool istcharsmapped[256] = {0}; //stores if t[i] character is already marked or not 
    //Isomorphic string when exist when only s and t length are same
    for(int i= 0; i < s.size();i++){    
        //check krenge ki s[i] ke saara character match ho gay t se ya nhi or t ke bhi saara character map hokar true hogay ya nhi
        if(hash[s[i]]==0 && istcharsmapped[t[i]]==0){
            //essa hm s[i] ko t[i] se map krdenge or vo bhi uniquely
            hash[s[i]] = t[i];
            //t ke saara characters mark kr diye ki vo mark ho gay hai 
            istcharsmapped[t[i]] = true;
        }
    }
    for(int i = 0; i < s.size();i++){
        //jidhar bhi hashing mein dikkat aayi smj lo udhar hi mapping nhi hui to return false
        if(char(hash[s[i]])!= t[i]){
            return false;
        }
    }
    //yaah tak phunch gay matlab shi ja rah ho bete
    return true;
}
int main(){
    string s;
    getline(cin,s);
    string t;
    getline(cin,t);
    bool ans = isisomorphic(s,t);
    if(ans==1){
        cout<<"The strings are isomorphic strings"<<endl;
    }
    else{
        cout<<"The strings are not the isomorphic strings"<<endl;
    }
    return 0;
}
// egg 
// add