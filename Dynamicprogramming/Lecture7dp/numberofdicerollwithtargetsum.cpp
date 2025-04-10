#include<iostream>
#include<vector>
using namespace std;
//Pattern pkdo 
//es question mein explore no. of ways ki baat ho rhi hai or jab bhi number of ways ki baat ho matlab
//pattern kya hai explore all possible ways of the question to find the answer 
//to esme explore all possible ways vala pattern lgega

//include/exclude pattern  and all possible ways pattern difference ?
//This pattern is often used in backtracking or recursion problems where, at each step, you make a binary decision:
	// •	Include the current element.
	// •	Exclude the current element.
// This is a broader approach where you’re not limited to binary decisions. 
// Instead, you explore all valid choices at each step.
long long int MOD = 1000000007;
    int solveusingrec(int n,int k,int target){
        if(target == 0 && n == 0) return 1;

        if((target != 0 && n==0) || (target == 0 && n != 0)) return 0;
        
        int ans = 0;
        for(int i = 1; i <= k;i++) ans += solveusingrec(n-1,k,target-i);
        return ans;
    }
    int solveusingmem(int n,int k,int target,vector<vector<int> >& dp){
        if(target == 0 && n == 0) return 1;

        if((target != 0 && n==0) || (target == 0 && n != 0)) return 0;

        //Step 3 - check if answer is exist or not 
        if(dp[n][target] != -1) return dp[n][target];

        //Step 2 - store answer in dp array 
        int ans = 0;
        for(int i = 1; i <= k;i++){
            int recans = 0;
            if(target - i >= 0) recans = solveusingmem(n-1,k,target-i,dp) % MOD;
            ans = (ans % MOD + recans) % MOD;
        }
        dp[n][target] = ans;

        return dp[n][target];
    }
    int solveusingtabulation(int n,int k,int target){
        vector<vector<int> > dp(n+1,vector<int> (target+1,0));

        dp[n][target] = 1;

        for(int dice = n-1 ; dice >= 0; dice--){
            for(int sum = target; sum >= 0; sum--){
                int ans = 0;
                for(int face = 1; face <= k;face++){
                    int recans = 0;
                    if(sum + face <= target) recans = dp[dice+1][sum+face];
                    ans = (ans % MOD + recans % MOD) % MOD;
                }
                dp[dice][sum] = ans;
            }
        }
        return dp[0][0];
    }
    int solveusingSO(int n,int k,int target){
        // vector<vector<int> > dp(n+1,vector<int> (target+1,0));
        vector<int> curr(target+1,0);
        vector<int> next(target+1,0);

        next[target] = 1;
       

        for(int dice = n-1 ; dice >= 0; dice--){
            for(int sum = target; sum >= 0; sum--){
                int ans = 0;
                for(int face = 1; face <= k;face++){
                    int recans = 0;
                    if(sum + face <= target) recans = next[sum+face];
                    ans = (ans % MOD + recans % MOD) % MOD;
                }
                curr[sum] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int numRollsToTarget(int n, int k, int target) {
        //Step 1 - create the dp array 
        vector<vector<int> > dp(n+1,vector<int> (target+1,-1));
        // int ans = solveusingrec(n,k,target);
        // int ans = solveusingmem(n,k,target,dp);
        // int ans = solveusingtabulation(n,k,target);
        int ans = solveusingSO(n,k,target);
        return ans;
    }
int main(){
    int n;
    cout<<"Enter the number of the dice do you have : ";
    cin>>n;
    int k;
    cout<<"Enter the number of faces in the each die : ";
    cin>>k;
    int target;
    cout<<"Enter the target what you want to achieve : ";
    cin>>target;
    cout<<"Number of rolls to achieving the target is : "<<numRollsToTarget(n,k,target)<<endl;
    return 0;
}