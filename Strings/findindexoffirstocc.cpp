#include<iostream>
using namespace std;
int str(string haystack,string needle){
    int n = haystack.length();
    int m = needle.length();
    // koi fayda hai nhi last 3rd element se aaga check krne ka
    for(int i = 0; i <= n-m;i++){
        for(int j = 0; j < m ;j++){
            //agr needle or haystack equal nhi to kro break j vala loop ko 
            if(needle[j] != haystack[i+j]){
                break;
            }
            //agr loop exit hona ka time tak same aagya to return krdo i ko kyuki vhi i to hai first occurance
            if(j==m-1) return i;
        }
    }
    return -1;
}
int main(){
    string haystack;
    getline(cin,haystack);
    string needle;
    getline(cin,needle);
    int ans = str(haystack,needle);
    cout<<"First occurance of substring needle in the haystack is : "<<ans<<endl;
    return 0;
}
// sadbutsad
// sad