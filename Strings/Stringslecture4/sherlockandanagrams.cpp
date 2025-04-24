#include<iostream>
#include<unordered_map>
using namespace std;
int sherlockAndAnagrams(string s) {
unordered_map<string, int>anagramaticSubstringCount;
    int anagramPairs = 0; //ans-> yahi find karna h
    // generate all substring
    for(int i=0; i<s.size(); i++) {
        for(int j=i; j<s.size(); j++) {
            string subString = s.substr(i, j-i+1);
            sort(subString.begin(), subString.end());
            anagramaticSubstringCount[subString]++;
            
        }   
    }
    
    // calculate pairs
    for(auto it: anagramaticSubstringCount) {
        int count = it.second;
        if(count > 1) {
            // find unique pairs
            anagramPairs += (count * (count-1))/2;
        }
    }
    
    return anagramPairs;
}
int main(){
    string s;
    cout<<"Enter the string s : ";
    cin>>s;
    cout<<"Total anagram pairs in these question is : "<<sherlockAndAnagrams(s)<<endl;
    return 0;
}
