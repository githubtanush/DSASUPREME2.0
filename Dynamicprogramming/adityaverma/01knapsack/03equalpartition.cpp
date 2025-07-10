#include<iostream>
#include<vector>
using namespace std;
int subsetsum(vector<int>& arr,int n,int sum){
    //Step 1 - initialize the vector
    vector<vector<int> > dp(n+1,vector<int>(sum+1,0));
    //Step 2 - mein pehli row or column ke hisab se initialize krunga ab agr mujhe sum = 0 chahiye to always mere pass ek answers hai 
    for(int i = 0; i <= n ;i++) dp[i][0] = 1;
    //Step 3 - ab mere ko pura array ke hisab se set krna hai or subset find krna hai ..
    for(int i = 1; i <= n ;i++){
        for(int j = 1; j <= sum ;j++){
            if(arr[i-1] <= j ) dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int equalpartition(vector<int>& arr,int n,int target){
    if(target % 2 != 0) return false;
    return subsetsum(arr,n,target/2);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n ;i++) cin>>arr[i];
    int sum = 0;
    for(int i = 0; i < n ;i++) sum += arr[i];
    if(equalpartition(arr,n,sum)) cout<<"PARTITION HO SKDA YRR"<<endl;
    else cout<<"PARTITION NHI HO SKDA YRR"<<endl;
    return 0;
}