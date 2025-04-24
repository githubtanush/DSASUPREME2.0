#include<iostream>
using namespace std;
int beautySum(string s) {
    // int beautysum = 0;
    // unordered_map<char,int>count;
    // for(int i = 0; i < s.size();i++){
    //     count.clear();
    //     for(int j = i ; j < s.size();j++){
    //         char& ch = s[j];
    //         count[ch]++;//freq update of char ch
            
    //         //To update mini and maxi again and again
    //         int mini = INT_MAX;
    //         int maxi = INT_MIN;

    //         //find most and least freq ch from the map
    //         for(auto each : count){
    //             maxi = max(maxi,each.second);
    //             mini = min(mini,each.second);
    //         }
    //     int beauty = maxi - mini;
    //     beautysum += beauty;
    //     }
    // }
    // return beautysum;


    //Another method
    int beautySum = 0;
    // unordered_map<char,int>mp;
    //find all substrings
    for(int i=0;i<s.size();i++){
        // mp.clear(); 
        int mp[256] = {0};
        for(int j=i; j<s.size();j++){
            // char ch = s[j];
            char &ch = s[j]; 
            mp[ch]++; //freq update of the char ch

            int mini = INT_MAX;
            int maxi = INT_MIN;
            //find most and least frequent ch from the map
            // for(auto each:mp){
            for(char ch = 'a' ; ch <= 'z' ;ch++){
                if(mp[ch] > 0){
                maxi=max(maxi,mp[ch]);
                mini=min(mini,mp[ch]);
                }
            }

            int beauty = maxi - mini;
            beautySum += beauty;
        }
    }
    return beautySum;
}
int main(){
    string s;
    cout<<"Enter the string s : ";
    cin>>s;
    cout<<"The beauty sum of the string is : "<<beautySum(s)<<endl;
    return 0;
}
//aabcb