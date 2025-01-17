#include<iostream>
#include<string>
#include<cstring>
using namespace std;
// void lastoccltr(string& s,char x,int i,int& ans){
//     //base case
//     if(i>=s.size()) return ;

//     //ek case solve krte hai 
//      left to right mein mere ko ek solution mil rah tha to bhi mein aaga ja rah tha last occurrance dhundh rah tha
//     if(s[i]==x) ans = i;

//     //recursive reln
//     lastoccltr(s,x,i+1,ans);
// }

void lastoccrtl(string& s,char x,int i,int& ans){
    //base case
    if(i<0) return ;

    //right to left mein jab ek baar mil gya tbhi return krdenge kyuki vohi last occurrance hogi sidhi si baat
    if(s[i]==x){
        ans = i;
        return ;
    }

    //recursive relation
    lastoccrtl(s,x,i-1,ans);

}
int main(){
    string s;
    cout<<"Enter string : ";
    getline(cin,s);
    char ch;
    cout<<"Enter character : ";
    cin>>ch;
    //stl to find last occurance of the character in string
    // const char* c = strrchr(s.c_str(),ch);
    // if(c!=NULL){
    //     cout<<c<<endl;
    // }
    int ans = -1;
    // int i = 0;
    // lastoccltr(s,ch,i,ans);
    lastoccrtl(s,ch,s.size()-1,ans);
    cout<<ans<<endl;

    return 0;
}

// abcddedg
// d
// char* output = std::strrchr(input, '/');