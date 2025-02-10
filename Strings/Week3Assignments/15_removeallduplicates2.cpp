#include<iostream>
#include<vector>
using namespace std;
//Method 1 - take extra array remove adjacent push / pop conditions
// bool arelastk_1charsame(string& ans,char& newch,int k){
//     int it = ans.size()-1;
//     for(int i = 0; i < k;i++){
//         if(newch != ans[it]) return false;
//         it--;
//     }
//     return true;
// }
// string removeduplicates(string s,int k ){
//      Time complexity - O(Nk) Space Complexity - O(1);
//     //Method 1 - new array creation and checking when push or pop
//     string ans = " ";
//     for(int i = 0; i < s.size();i++){
//         char& newch = s[i];
//         //This condition if vali yeh check krne ke liye liye answer ka size k-1 se km hai ya nhi
//         if(ans.size()<k-1){
//             ans.push_back(newch);
//         }
//         else{
//             if(arelastk_1charsame(ans,newch,k-1)){
//                 for(int j = 0; j < k-1;j++){
//                     ans.pop_back();
//                 }
//             }
//             else{
//                 ans.push_back(newch);
//             }
//         }
//     }
//     return ans;
// }//In this we again and again back to k elements which take more time


string removeduplicates(string& s,int k){//In this we loop iterate only 1 time so work is done in O(n) time complexity
    //Method2 - Use of two pointer approach very effectively
     //firstly we initialize two vectors
     //but in this we take the space of n size array so their time complexity is less but more space complexity
     int i  = 0, j =  0;
     vector<int> count(s.size());
     while(j<s.size()){
        s[i] = s[j];
        count[i] = 1;
        if(i>0 && s[i]==s[i-1])
            count[i] += count[i-1];
        if(count[i]==k)
            i -= k;
        i++,j++;
     }
     return s.substr(0,i);
}
//Timecomplexity - O(N) space complexity - O(N)
int main(){
    string s;
    getline(cin,s);
    int k ;
    cin>>k;
    string ans  = removeduplicates(s,k);
    cout<<"After removing k duplicates ans is formed like : "<<ans<<endl;
    return 0;
}
// deeedbbcccbdaa
// 3