#include<iostream>
#include<vector>
using namespace std;
int subsetsum(vector<int>& arr,int n,int range){
    //Step 1 - Initializing the vector
    vector<vector<int> > dp(n+1,vector<int>(range+1,0));
    //Step 2 - Initialize the array 
   dp[0][0] = 1;
    //Step 3 - for loops lagao bhai..
    for(int i = 1; i <= n ;i++) {
        for(int j = 0;j <= range ;j++){
            if(arr[i-1] <= j) dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            else dp[i][j] = dp[i-1][j];
        }
    }
    int mindiff = INT_MAX;
    for(int i = 0; i < range/2;i++){
        if(dp[n][i]) mindiff = min(mindiff,abs(range - i) - i);
    }
    return mindiff;

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n ;i++) cin>>arr[i];
    int sum = 0;
    for(int i = 0; i < n ;i++) sum += arr[i];
    cout<<subsetsum(arr,n,sum)<<endl;
    return 0;
}