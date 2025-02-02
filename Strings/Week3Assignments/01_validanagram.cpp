#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
bool validanagram(string& s,string& t){
    //Method 1 - firstly sort then check it's size then compare all element
    // sort(s.begin(),s.end());
    // sort(t.begin(),t.end());
    // if((s.size() < t.size()) || (t.size()< s.size())) return false;
    // else{
    //     for(int i = 0; i < s.size();i++){
    //         if(s[i]!=t[i]){
    //             return false;
    //         }
    //     }
    // }
    // return true;

    //Method 2 = counting approach
    //IF WE NOT DO BY HASHMAP CREATE YOUR OWN MAP

    //Number of respective class in s string should be same to that of 't'
    // s => anagram             t => nagaram
    // freq table for s         freq table for t     
    // a => 3                   a = 3
    // g => 1                   g = 1
    // m => 1                   m = 1
    // n => 1                   n = 1
    // r => 1                   r = 1

    // freq table of (s) = freq of table of (t)
        // how to make freq table for strings??
        //ASCII => 256
    // unordered_map<int,int> hash;
    // int hash[256] = {0};
    // if(s.length() != t.length()) return false;
    // else{
    // for(int i = 0; i < s.length();i++){
    //     hash[s[i]]++;
    //     hash[t[i]]--;
    // }
    // //ab hmna jaise loop ko modify kiya hai upper ab hm niche s.length() kr skte hai kyuki ab to same hi hogi na length
    // for(int i = 0; i < 256;i++){//HO SKTA HAI KI S STRING MEIN SAB 0 HO LEKIN T MEIN NA HO ESLIYE HMM
    // //HMESHA 256 LIKHENGE YA ASA KUCH CONSTANT VALUE LIKHENGE TAAKI PURA ARRAY CHECK KARLE AADA CHUTA NA 
    //     if(hash[i]!= 0){//or esko hash i rkhenge hash[s[i]] ya hash[t[i]] nhi phir vo apna aap  apna pura array check kr lega
    //         return false;
    //     }
    // }
    // return true;
    // }


    unordered_map<int,int> hash;// map stl
    if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size();i++){
            hash[s[i]]++;
            hash[t[i]]--;
        }
        for(int i = 0; i < 256; i++){
            if(hash[i] != 0) return false;
        }
        return true;
}
int main(){
    string s;
    getline(cin,s);
    string t;
    getline(cin,t);
    bool ans = validanagram(s,t);
    if(ans){
        cout<<"Valid Anagram"<<endl;
    }
    else{
        cout<<"Invalid Anagram"<<endl;
    }
    return 0;
}
// anagram
// nagaram

// ab 
// acb

// abd
// abc