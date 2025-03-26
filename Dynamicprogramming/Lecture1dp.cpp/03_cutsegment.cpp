#include<iostream>
using namespace std;
int solveusingrec(int n,int x,int y,int z,vector<int>& dp){
    //your code here  
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;

    //Step 3 - if answer exists return the answer
    if(dp[n] != INT_MIN) return dp[n];

    int opt1 = solveusingrec(n-x,x,y,z,dp);
    int opt2 = solveusingrec(n-y,x,y,z,dp);
    int opt3 = solveusingrec(n-z,x,y,z,dp);

    int maxcut = 1 + max(opt1,max(opt2,opt3));

    //Step 2 - store answer in dp array
    dp[n] = (maxcut == INT_MIN)? INT_MIN: maxcut;

    return dp[n];
}
int maximizethecuts(int n,int x,int y,int z){
    //Step 1 - create dp array
    vector<int> dp(n+1,INT_MIN);
    int ans = solveusingrec(n,x,y,z,dp);
    return (ans<0) ? 0 : ans;
}
int main(){
    int n;
    cout<<"Enter the length of the segment : ";
    cin>>n;
    
    int x;
    cout<<"Enter the value of the cutter x : ";
    cin>>x;

    int y;
    cout<<"Enter the value of the cutter y : ";
    cin>>y;

    int z;
    cout<<"Enter the value of the cutter z : ";
    cin>>z;

    cout<<"The less to less number of cuts is possible in : "<<maximizethecuts(n,x,y,z)<<endl;
    return 0;
}
//only n is changing only 1 variable is changing so create 1d array
//because it is 1d dp