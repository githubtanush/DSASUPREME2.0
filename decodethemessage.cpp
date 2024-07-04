#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
// string decodethestring(string key,string message){
//     char mapping[256] = {0};
//     char start = 'a';

//     for(auto ch: key){
//         if(ch != ' ' && mapping[ch]==0){//IS CONDITION MEIN GLTI KR RAH HAI YAAD RKHNA MAPPING[CH]!= 0 NHI AAYGA CH != 0 AAYGA
//         mapping[ch] = start;
//         cout<<"mapping ch : "<<ch<<" and start : "<<mapping[ch]<<endl;
//         start++;
//         }
//     }

//     //ES STRING VICH ASSI ANSWER NU RETURN KR DAANGA
//     string ans;
//     for(auto ch: message){
//         if(ch==' '){
//             ans.push_back(' ');
//         }
//         else{
//             char decodedchar = mapping[ch];
//             cout<<"decoded char : "<<ch<<" for mapping character :  "<<mapping[ch]<< endl;
//             ans.push_back(decodedchar);
//         }
//     }
//     return ans;
// }
string decodethestring(string key,string message){
    unordered_map<char,char> hash;
    // char mapping[256] = {0};
    char start = 'a';

    for(auto ch: key){
        if(ch != ' ' && hash[ch]==0){//IS CONDITION MEIN GLTI KR RAH HAI YAAD RKHNA MAPPING[CH]!= 0 NHI AAYGA CH != 0 AAYGA
        //BY DEFAULT WHEN WE DOES NOT MAP HASH FUNCTION DEFAULTLY SET IT TO 0 VALUE BUT WHEN WE MAPPED HASH FUNCTION SET TO ONE 
        //THAT'S WHY IN IF CONDITIION THEY ARE MANAGE TO DO THIS    
        hash[ch] = start;
        cout<<"mapping ch : "<<ch<<" and start : "<<hash[ch]<<endl;
        start++;
        }
    }

    //ES STRING VICH ASSI ANSWER NU RETURN KR DAANGA
    string ans;
    for(auto ch: message){
        if(ch==' '){
            ans.push_back(' ');
        }
        else{
            char decodedchar = hash[ch];
            cout<<"decoded char : "<<ch<<" for mapping character :  "<<hash[ch]<< endl;
            ans.push_back(decodedchar);
        }
    }
    return ans;

}
int main(){
    string key;
    getline(cin,key);
    string message;
    getline(cin,message);
    string ans = decodethestring(key,message);
    cout<<ans<<endl;
    return  0;
}
// the quick brown fox jumps over the lazy dog
// vkbs bs t suepuv     