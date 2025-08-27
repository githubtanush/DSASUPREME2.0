#include<iostream>
using namespace std;
int countsubsettab(vector<int>& arr,int target,int size){
    //Step 1 - intialize the vector array
    vector<vector<int> > dp(size+1,vector<int> (target+1,0));
    //Step 2 - initialize the rows and cols of first row and col
    for(int i = 0; i <= size; i++) dp[i][0] = 1;
    //Step 3 - applying for loops
    for(int i = 1; i <= size; i++){
        for(int j = 0;j <= target; j++){
            if(arr[i-1] <= j) dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            else dp[i][j] = dp[i-1][j];
        }
    }
    //Step 4 - return it
    return dp[size][target];
}
int countsubsetmem(vector<int>& arr,int target,int n,vector<vector<int> >& dp){
        if(n == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || arr[0] == target) return 1;
            return 0;
        }
        if(dp[n][target] != -1) return dp[n][target];
        
        if(arr[n] <= target) return dp[n][target] = 
                countsubsetmem(arr,target-arr[n],n-1,dp) + countsubsetmem(arr,target,n-1,dp);
        else return dp[n][target] = countsubsetmem(arr,target,n-1,dp);
    }

int countsubset(vector<int>& arr,int target,int n){
    //Step 2 - Initialize base case
    if(n == 0){
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || arr[0] == target) return 1;
        return 0;
    }

    //STep 1 - processing 
    if(arr[n] <= target)  return countsubset(arr,target-arr[n],n-1) + countsubset(arr,target,n-1);
    else return countsubset(arr,target,n-1);

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i < n; i++) cin>>arr[i];
    int target;
    cin>>target;
    // cout<<countsubsettab(arr,target,n)<<endl;
    cout<<countsubset(arr,target,n)<<endl;
    return 0;
}