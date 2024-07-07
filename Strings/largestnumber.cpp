#include<iostream>
#include<vector>
#include<string>
using namespace std;
static bool mycomp(string a,string b){
    string t1 = a + b;
    string t2 = b + a;
    return t1>t2;
}
string largestnumber(vector<int> nums){
    //ek string vector bna liya strings ko store krna ke liye
    vector<string> snums;
    //saara integers ko string mein convert kr liya
    for(auto s:nums){
        snums.push_back(to_string(s));
    }
    //sort kr diya or sort krte time agr 0 sbse pehle aa jay to ek 0 return krdo kyuki 0 se chota or kya hi hoga
    sort(snums.begin(),snums.end(),mycomp);
    if(snums[0]=="0") return "0";
    // answer string bna lo return krna ke liya answer ko 
    string ans = "";
    for(auto str:snums){
        ans += str;
    }
    return ans;
}
int main(){
vector<int> nums;
int n;
cin>>n;
nums.resize(n);
for(int i = 0; i < n;i++){
    cin>>nums[i];
}
string ans = largestnumber(nums);
cout<<"Therefore the largest number build by this vector array is : "<<ans<<endl;
    return 0;
}
// 3 30 34 5 9