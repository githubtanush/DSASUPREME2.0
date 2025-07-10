#include<iostream>
#include<vector>
using namespace std;
bool targetsumtabulation(int n,vector<int>& arr,int target){
    //Step 1 - Initialize vector
    vector<vector<int> > dp(n+1,vector<int>(target+1,0));
    //Step 2 - Initialize the array 
    for(int i = 0; i <= n ;i++) dp[i][0] = 1;

    for(int i = 1; i <= n ;i++){
        for(int j = 1; j <= target ;j++){

            if(arr[i-1] <= j) dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][target];
}
bool targetsummem(int n,vector<int>& arr,int target,vector<vector<int> >& dp){
    if(target == 0) return 1;
    if(n == 0) return 0;

    //Step 3 - check dp array exists or not
    if(dp[n][target] != -1) return dp[n][target];


    //EXCLUDE KRENGE 
    if(arr[n-1] > target) return dp[n][target] = targetsummem(n-1,arr,target,dp);
    else
    return dp[n][target] =  targetsummem(n-1,arr,target,dp) || targetsummem(n-1,arr,target-arr[n-1],dp);
}
bool targetsum(int n,vector<int>& arr,int target){
    if(target == 0) return true;
    if(n == 0) return false;

    // If last element is greater than sum,
    // then ignore it
    if(arr[n-1] > target) return targetsum(n-1,arr,target);

    //Check if sum can be obtained by including 
  	// or excluding the last element
    return targetsum(n-1,arr,target) || targetsum(n-1,arr,target - arr[n-1]);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    int target;
    cin>>target;
    // if(targetsum(n,arr,target)) cout<<"MIL GYA AB TO PARTY HONI HI CHAHIYE"<<endl;
    // else cout<<"DFFA HOJA KRENGE YE LOG PARTY"<<endl;
    if(targetsumtabulation(n,arr,target)) cout<<"MIL GYA AB TO PARTY HONI HI CHAHIYE"<<endl;
    else cout<<"DFFA HOJA KRENGE YE LOG PARTY"<<endl;
    // vector<vector<int> > dp(n+1,vector<int>(target+1,-1));
    // if(targetsummem(n,arr,target,dp)) cout<<"MIL GYA AB TO PARTY HONI HI CHAHIYE"<<endl;
    // else cout<<"DFFA HOJA KRENGE YE LOG PARTY"<<endl;
    return 0;
}
// 6
// 3 34 4 12 5 2 
// 9