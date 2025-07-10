#include<iostream>
#include<vector>
using namespace std;

int knapsackwithtabulation(int n,vector<int>& value,vector<int>& wt,int w){
    //Step 1 - Make one dp array and also do the initialization 
    vector<vector<int> > dp(n+1,vector<int>(w+1,0));
    
    //Step 2 - By using loops we find the maximum sum 
    for(int i = 1; i <= n ;i++){
        for(int j = 0; j <= w; j++){
            int pick = 0;
            if(wt[i-1] <= j) pick = value[i-1] + dp[i-1][j-wt[i-1]];
            int notpick = dp[i-1][j];
            dp[i][j] = max(pick,notpick);
        }
    }

    return dp[n][w];
}
int knapsackwithmem(int n,vector<int>& value,vector<int>& wt,int w,vector<vector<int> >& dp){
    //Base case
    if(n == 0 || w == 0) return 0;

    //Step 3 - if anywhere we find that dp[n][w] != -1 then return its value
    if(dp[n][w] != -1) return dp[n][w];

    //recursive code 
    //dekh sidi si baat hai 
    //agr to wt w[i] se km hai to include exclude krke jo maximum aayga vo rkhte hai 
    //Step 2 - store all the answers of recursive calls in dp array 
    int pick = 0;
    if(wt[n-1] <= w) 
        pick = value[n-1] + knapsackwithmem(n-1,value,wt,w - wt[n-1],dp);

    int notpick = knapsackwithmem(n-1,value,wt,w,dp);

    dp[n][w] = max(pick,notpick);
    return dp[n][w];

}
int knapsack(int n,vector<int>& value,vector<int>& wt,int w){
    //Base case
    if(n == 0 || w == 0) return 0;

    //recursive code 
    //dekh sidi si baat hai 
    //agr to wt w[i] se km hai to include exclude krke jo maximum aayga vo rkhte hai 
    int pick = 0;
    if(wt[n-1] <= w) pick = value[n-1] + knapsack(n-1,value,wt,w - wt[n-1]);

    int notpick = knapsack(n-1,value,wt,w);

    return max(pick,notpick);

}

int main(){
    int n;
    cin>>n;
    vector<int> value(n);
    for(int i = 0; i < n ;i++) cin>>value[i];
    vector<int> wt(n);
    for(int i = 0; i < n;i++) cin>>wt[i];
    int W;
    cin>>W;
    // cout<<knapsack(n,value,wt,W)<<endl;
    //For memoization step 1 - include vector of that type in which parameters changing
    // vector<vector<int> >dp(n+1,vector<int>(W+1,-1));
    // cout<<knapsackwithmem(n,value,wt,W,dp)<<endl;
    cout<<knapsackwithtabulation(n,value,wt,W)<<endl;
    return 0;
}