#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& nums,int s,int e){
    //base case
    if(s>e) return 0;

    //chori krlete hai 
    int option1 = nums[s] + solve(nums,s+2,e);

    //chori nhi krte hai exclude
    int option2 = 0 + solve(nums,s+1,e);

    //maximum ans lete hai 
    int finalans = max(option1,option2);
    return finalans;
}
int rob(vector<int>& nums){
    int n = nums.size();
    //single element - yaah par meini glti ki thi
    if(n==1) return nums[0];
    int option1 = solve(nums,0,n-2);
    int option2 = solve(nums,1,n-1);
    int ans = max(option1,option2);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n;i++){
        cin>>nums[i];
    }
    int ans = rob(nums);
    cout<<"At max you rob at : "<<ans<<" houses"<<endl;

    return 0;
}
//4
//1 2 3 1
