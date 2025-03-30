#include<iostream>
using namespace std;
int solveusingrec(int n,int k){
    if(n==1) return k;
    if(n==2) return k + k * ( k - 1 );

    int ans = (k-1) * ( solveusingrec(n-1,k) + solveusingrec(n-2,k) );
    return ans;
}
int solveusingmem(int n,int k,vector<int>& dp){
    if(n==1) return k;
    if(n==2) return k + k * ( k - 1 );

    //Step 3 - if result was found
    if(dp[n] != -1) return dp[n];

    //Step 2 - store result in dp vector
    dp[n] = (k-1) * ( solveusingmem(n-1,k,dp) + solveusingmem(n-2,k,dp) );
    return dp[n];
}
int solveusingtabulation(int n,int k){
    //Step 1 - create a 1d vector
    vector<int> dp(n+1,-1);
    //Step 2 - store intialization results
    dp[1] = k;
    dp[2] = k + k * (k - 1);

    for(int i = 3;i <= n;i++){
        dp[i] = (dp[i-1] + dp[i-2]) * (k-1);
    }
    return dp[n];
}
int spaceoptimization(int n,int k){
    int prev2 = k;
    int prev1 = k + k * (k - 1);

    int curr;
    if(n==1) return prev2;
    if(n==2) return prev1;
    for(int i = 3; i<=n;i++){
        curr = (prev1 + prev2) * (k-1);
        //Shift 
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
int paintingfence(int n,int k){
    // return solveusingrec(n,k);

    //only n is changing means 1d vector apply
    //Step 1 - create a dp array 
    // vector<int> dp(n+1,-1);
    // return solveusingmem(n,k,dp);

    return solveusingtabulation(n,k);
}
int main(){
    int n;
    cout<<"Enter how many post do you have : ";
    cin>>n;
    int k;
    cout<<"Enter the different types of colors do you have to color the post : ";
    cin>>k;
    cout<<"The total number of colors required for posting n color is : "<<paintingfence(n,k)<<endl;
    return 0;
}