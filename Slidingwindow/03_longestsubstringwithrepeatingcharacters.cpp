#include<iostream>
#include<string>
using namespace std;
int lengthOfLongestSubstring(string s) {
        //Brute force - 
        //Time complexity - O(N^2)
        //Space complexity - O(256)
        // int maxlen = 0;
        // for(int left = 0; left < s.size(); left++){
        //     int hash[256] = {0};
        //     for(int right = left; right < s.size() ; right++){
        //         if(hash[s[right]] == 1) break;
        //         maxlen = max(maxlen, right - left + 1);
        //         hash[s[right]] = 1;
        //     }
        // }
        // return maxlen;


        //Optimal Approach 
        //if u are given anywhere substring maximum length of substring max sum 
        //Think once about Two pointers or Sliding window
        //Time complexity - O(N)
        //Space complexity - O(256)
        int maxlen = 0;
        int hash[256] = {-1};//number mapping with the index
        int n = s.size();
        int left = 0;
        int right = 0;
        while(right < n){
            if(hash[s[right]] != -1){
                if(hash[s[right]] >= left) left = hash[s[right]] + 1;
            }
            hash[s[right]] = right;
            maxlen = max(maxlen,right - left + 1);
            right++;
        }
        return maxlen;

    }
int main(){
    string s;
    getline(cin,s);
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}