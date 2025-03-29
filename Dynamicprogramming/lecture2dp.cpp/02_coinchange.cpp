#include<iostream>
using namespace std;
int solveusingrec(vector<int>& coins,int amount){
    //base case
    if(amount == 0) return 0;

    //recursive relation
    int mini = INT_MAX; // mini update nhi hua koi answer nhi aaya to mini int max hojayga
    for(int i = 0; i < coins.size();i++){
        //find ans using ith coin 
        //call recursion only for valid amount i.e >= 0 wale amounts
        if(amount - coins[i] >= 0){
        int recursionkaans = solveusingrec(coins,amount-coins[i]);
        //if a valid answer 
        if(recursionkaans != INT_MAX){
            int ans = 1 + recursionkaans;
            mini = min(mini,ans);
        }
        }
    }
    return mini;  

}
int solveusingmem(vector<int>& coins,int amount,vector<int>& dp){
    //base case
    if(amount == 0) return 0;

    //already answer exist?
    if(dp[amount] != -1) return dp[amount];

    //recursive relation
    int mini = INT_MAX; // mini update nhi hua koi answer nhi aaya to mini int max hojayga
    for(int i = 0; i < coins.size();i++){
        //find ans using ith coin 
        //call recursion only for valid amount i.e >= 0 wale amounts
        if(amount - coins[i] >= 0){
        int recursionkaans = solveusingmem(coins,amount-coins[i],dp);
        //if a valid answer 
        if(recursionkaans != INT_MAX){
            int ans = 1 + recursionkaans;
            mini = min(mini,ans);
        }
        }
    }
    //Step 2 - store krna
    //Why we store the answer in dp array 
    //because if we need again this then we simply return it 
    //not calculate from basics 
    dp[amount] = mini;
    return dp[amount];  
}
//Bottom up approach
int solveusingtabulation(vector<int>& coins,int amount){
    //Step 1 - create a dp array 
    int n = amount;
    vector<int> dp(n+1,INT_MAX);
    //Step 2 - base case analyze
    dp[0] = 0;
    //for loop 
    for(int value = 1; value <= amount; value++){
        int mini = INT_MAX;
        for(int i = 0; i < coins.size();i++){
            //find ans using ith coin 
            //call recursion only for valid amount i.e >= 0 wale amounts
        if(value - coins[i] >= 0){
            int recursionkaans = dp[value-coins[i]]; 
            //if a valid answer 
            if(recursionkaans != INT_MAX){
                int ans = 1 + recursionkaans;
                mini = min(mini,ans);
            }
        }
        }
        dp[value] = mini;
    }
    return dp[amount];
}
int coinchange(vector<int>& coins,int amount){
    // int ans = solveusingrec(coins,amount);
    //Top - down appraoch (Recursion + Memoization)
    //1d dp because only amount value can changing
    //Step 1 - create a dp array 
    // int n = amount;
    // vector<int> dp(n+1,-1);
    // int ans = solveusingmem(coins,amount,dp); 

    //Bottom-Up approach (Tabulation Method)
    int ans = solveusingtabulation(coins,amount); 
    if(ans == INT_MAX) return -1; 
    return ans;
}
int main(){
    int n ;
    cout<<"Enter the size of the coins array : ";
    cin>>n;
    vector<int> coins(n);
    for(int i = 0; i < n;i++){
        cin>>coins[i];
    }
    int amount;
    cout<<"Enter the amount of the target you want to made : ";
    cin>>amount; 
    cout<<"The minimum number of coins required you to make a amount is : "<<coinchange(coins,amount);
    return 0;
}