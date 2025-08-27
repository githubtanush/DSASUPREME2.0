#include<iostream>
#include<vector>
using namespace std;
int unboundedknapsack(vector<int>& price,vector<int>& wt,int n,int target){
    //Step 1 - Initialize krte h vector ko 
    vector<vector<int> > dp(n+1,vector<int>(target+1,0));
    //Step 2 - ab ek or kaam krte h loop initialize krke solve krte h 
    for(int i = 1; i <= n ;i++){
        for(int j = 1; j <= n ;j++){
            if(wt[i-1] <= j) dp[i][j] = max(price[i-1] + dp[i][j-wt[i-1]],dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][target];
}
int main(){
    int n;
    cin>>n;
    vector<int> price(n);
    for(int i = 0; i < n ;i++) cin>>price[i];
    vector<int> wt(n);
    for(int i = 0; i < n ;i++) cin>>wt[i];
    int target;
    cin>>target;
    cout<<unboundedknapsack(price,wt,n,target)<<endl;

    return 0;
}