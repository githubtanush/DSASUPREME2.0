#include<iostream>
#include<vector>
using namespace std;
int solveusingrec(vector<int>& nums,int curr,int prev){
    if(curr >= nums.size()) return 0;

    int include = 0;
    if(prev == -1 || nums[curr] > nums[prev])
        include = 1 + solveusingrec(nums,curr+1,curr);
    int exclude = 0 + solveusingrec(nums,curr+1,prev);
    int ans = max(include,exclude);
    return ans;
}
int solveusingmem(vector<int>& nums,int curr,int prev,vector<vector<int> >& dp){
    if(curr >= nums.size()) return 0;

    //Step 3 - check if already answer existing:- 
    //There is slight change of pattern add indexing shifting to them
    // because when we shift the index then -1 index reach at zero
    if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

    int include = 0;
    if(prev == -1 || nums[curr] > nums[prev])
        include = 1 + solveusingmem(nums,curr+1,curr,dp);
    int exclude = 0 + solveusingmem(nums,curr+1,prev,dp);
    dp[curr][prev+1] = max(include,exclude);
    return dp[curr][prev+1];
}
int solveusingtabulation(vector<int>& nums){
    int n = nums.size();
    //Step 1 - create the dp vector array 
    vector<vector<int> > dp(n+1,vector<int>(n+1,0));
    //Step 2 - Analyze the base case by applying for loop

    for(int curr = n - 1; curr >= 0; curr--){
        for(int prev = curr - 1; prev >= -1 ; prev--){
            int include = 0;
            if(prev == -1 || nums[curr] > nums[prev]) 
                    include = 1 + dp[curr + 1][curr + 1];//Indexing Shift
            int exclude = 0 + dp[curr + 1][prev + 1];
            dp[curr][prev+1] = max(include,exclude);
        }
    }
    return dp[0][0];
}

int solveusingSO(vector<int>& nums){
    int n = nums.size();
    //Step 1 - create two dp row vector array 
    vector<int> currrow(n+1,0);
    vector<int> nextrow(n+1,0);
    //Step 2 - Analyze the base case by applying for loop

    for(int curr = n - 1; curr >= 0; curr--){
        for(int prev = curr - 1; prev >= -1 ; prev--){
            int include = 0;
            if(prev == -1 || nums[curr] > nums[prev]) 
                    include = 1 + nextrow[curr + 1];
            int exclude = 0 + nextrow[prev + 1];
            currrow[prev+1] = max(include,exclude);
        }
        //Shifting 
        nextrow = currrow;
    }
    return nextrow[0];
}
int solveusingbs(vector<int>& nums){
    vector<int> ans;
    //initial state 
    ans.push_back(nums[0]);
    for(int i = 1; i < nums.size();i++){
        if(nums[i] > ans.back()) ans.push_back(nums[i]);
        else{
            //just bada number exist krta hai 
            int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
            //replace
            ans[index] = nums[i];
        }
    }
    return ans.size();
}
int lengthOfLIS(vector<int>& nums) {
    int curr = 0;
    int prev = -1;
    int n = nums.size();
    //Two parameters changing 
    //Step 1 - Create 2D Vector
    vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
    // int ans = solveusingrec(nums,curr,prev);
    // int ans = solveusingmem(nums,curr,prev,dp);
    // int ans = solveusingtabulation(nums);
    // int ans = solveusingSO(nums);
    int ans = solveusingbs(nums);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number of elements you want to insert in the array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin>>arr[i];
    cout<<"Longest Length of the increasing subsequence has : "<<lengthOfLIS(arr)<<endl;
    return 0;
}