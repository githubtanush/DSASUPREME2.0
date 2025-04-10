#include<iostream>
#include<vector>
using namespace std;
bool solveusingrec(vector<int>& nums,int index,int sum,int target){
    if(index >= nums.size()) return 0;
    if(sum > target) return 0;
    if(sum == target) return true;

    //recursion
    bool include = solveusingrec(nums,index+1,sum+nums[index],target);
    bool exclude = solveusingrec(nums,index+1,sum,target);

    return include || exclude;
}
bool solveusingmem(vector<int>& nums,int index,int sum,int target,vector<vector<int> >& dp){
    if(index >= nums.size()) return 0;
    if(sum > target) return 0;
    if(sum == target) return true;

    //Step 3 - check answer exists or not 
    if(dp[index][sum] != -1) return dp[index][sum];

    //recursion 
    bool include = solveusingmem(nums,index+1,sum+nums[index],target,dp);
    bool exclude = solveusingmem(nums,index+1,sum,target,dp);

    return dp[index][sum] = (include || exclude);
}
bool solveusingtabulation(vector<int>& nums,int target){
    //Step 1 - create dp array 
    int n = nums.size();
    vector<vector<int> > dp(n+2,vector<int>(target+1,0));

    //Step 2 - Analyze the base case
    for(int row = 0; row <= nums.size();row++) dp[row][target] = 1;

    for(int i = n - 1 ; i >= 0; i--){
        for(int s = target ; s >= 0; s--){
            bool include = 0;
            if(s + nums[i] <= target) include = dp[i + 1][s+nums[i]];
            bool exclude = dp[i+1][s];

            dp[i][s] = (include || exclude);
        }
    }
    return dp[0][0];
}
bool solveusingtabulationSO(vector<int>& nums,int target){
    //Step 1 - create dp array 
    int n = nums.size();
   vector<int> curr(target+1,0);
   vector<int> next(target+1,0);

    //Step 2 - Analyze the base case
    curr[target] = 1;
    next[target] = 1;

    for(int i = n - 1 ; i >= 0; i--){
        for(int s = target ; s >= 0; s--){
            bool include = 0;
            if(s + nums[i] <= target) include = next[s+nums[i]];
            bool exclude = next[s];

            curr[s] = (include || exclude);
        }
        //Shifting
        next = curr;
    }
    return next[0];
}
bool canPartition(vector<int>& nums) {
    int index = 0;
    int totalsum = 0;
    for(int i = 0; i < nums.size();i++) totalsum += nums[i];

    //odd cannot be partioned
    if(totalsum & 1) return false;

    int target = totalsum/2;
    int currsum = 0;
    //Step 1 - to create dp array
    vector<vector<int> > dp(nums.size()+1,vector<int>(target+1,-1));
    // bool ans = solveusingrec(nums,index,currsum,target);
    // bool ans = solveusingmem(nums,index,currsum,target,dp);
    // bool ans = solveusingtabulation(nums,target);
    bool ans = solveusingtabulationSO(nums,target);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin>>arr[i];
    if(canPartition(arr)) cout<<"Array can be partitioned"<<endl;
    else cout<<"Array cannot be partioned"<<endl;
    return 0;
}