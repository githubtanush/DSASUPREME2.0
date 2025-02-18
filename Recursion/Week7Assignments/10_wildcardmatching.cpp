#include<iostream>
using namespace std;
bool isMatchHelper(string& s,int si,string& p,int pi){
    // ? - matches any single character 
    // * - matches the sequence of characters
    // Rule - 1.) Out of all comparisons if any comparison return true than 
    // my answer will be true

    //base case
    if(si==s.size() &&  pi==p.size()) return true;
    if(si==s.size() && pi<p.size()) {
        while(pi < p.size()){
            if(p[pi]=='*') return false;
            pi++;
        }
        return true;
    }

    //single character matching vala case
    if(s[si]==p[pi] || '?'==p[pi]){
        return isMatchHelper(s,si+1,p,pi+1);
    }

    //ab multiple character match vala case mein aa jata hai 
    if(p[pi]=='*'){
        //exclude - treat '*' as empty or null
        bool caseA = isMatchHelper(s,si,p,pi+1);
        //include - treat '*' consume one character
        bool caseB = isMatchHelper(s,si+1,p,pi);
        
        return caseA || caseB;
    }
    //last tk aa gay matlab character match nhi hua 
    return false;
}
bool isMatch(string s,string p){
    //we can need two pointers for two strings
    int si = 0; //pointer index of s string
    int pi = 0; //pointer index of p string
    return isMatchHelper(s,si,p,pi);
}
int main(){
    string s;
    getline(cin,s);
    string p;
    getline(cin,p);
    bool ans = isMatch(s,p);
    if(ans){
        cout<<"String is Matched"<<endl;
    }
    else{
        cout<<"String is not matched"<<endl;
    }
    return 0;
}
//abcdefg
//ab*fg