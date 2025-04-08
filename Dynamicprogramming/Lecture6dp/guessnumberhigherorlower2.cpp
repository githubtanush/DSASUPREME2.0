#include<iostream>
using namespace std;
int solveusingrec(int start,int end){
    //base case
    if(start >= end) return 0;// because ek hi number hai ya range se bahar hai to zero penalty

    int ans = INT_MAX;
    for(int i = start; i <= end;i++){
        ans = min(ans,i + max(solveusingrec(start,i-1),solveusingrec(i+1,end)));
    }
    return ans;
}
int solveusingmem(int start,int end,vector<vector<int> >& dp){
    //base case
    if(start >= end) return 0;

    //Step 3 - check dp exists or not
    if(dp[start][end] != -1) return dp[start][end];

    //Step 2 - store ans in dp array
    int ans = INT_MAX;
    for(int i = start; i <= end;i++){
        ans = min(ans,i + max(solveusingmem(start,i-1,dp),solveusingmem(i+1,end,dp)));
    }
    dp[start][end] = ans;
    return dp[start][end];
    
}
int solveusingtabulation(int n){
    //Step 1 - create the dp array 
    vector<vector<int> > dp(n+2,vector<int>(n+1,0));
    for(int start = n; start>=1; start--){
        for(int end = 1; end <= n;end++){
            if(start > end) continue; //invalid range
            int ans = INT_MAX;
            for(int i = start; i <= end;i++){
        ans = min(ans,i + max(dp[start][i-1],dp[i+1][end]));
    }
    dp[start][end] = ans;
        }
    }
    return dp[1][n];
}
    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        // int ans = solveusingrec(start,end);
        //Step 1 - create dp array 
        vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
        int ans = solveusingmem(start,end,dp);
        return ans;
    }
int main(){
    int n;
    cout<<"Choose one number for which we are able to trying predict : ";
    cin>>n;
    cout<<"Money amount minimum to minimum spend is : "<<getMoneyAmount(n)<<endl;
    return 0;
}