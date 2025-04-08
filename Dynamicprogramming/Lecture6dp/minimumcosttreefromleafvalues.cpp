#include<iostream>
#include<vector>
#include<map>
using namespace std;
int solveusingrec(vector<int>& arr,map<pair<int,int>,int>& maxi,int s,int e){
    //base case
    if(s >= e) return 0;

    int ans = INT_MAX;
    for(int i = s; i < e ; i++){
        //i is used for partitioning
        ans = min(ans,(maxi[{s,i}] * maxi[{i+1,e}]) + solveusingrec(arr,maxi,s,i) + solveusingrec(arr,maxi,i+1,e) );
    }
    return ans;
}
 int solveusingmem(vector<int>& arr,map<pair<int,int>,int>& maxi,int s,int e,vector<vector<int> >& dp){
    //base case
    if(s >= e) return 0;

    //Step 3 - if answer exists
    if(dp[s][e] != -1) return dp[s][e];

    int ans = INT_MAX;
    for(int i = s; i < e ; i++){
        //i is used for partitioning
        ans = min(ans,(maxi[{s,i}] * maxi[{i+1,e}]) + solveusingmem(arr,maxi,s,i,dp) + solveusingmem(arr,maxi,i+1,e,dp) );
    }
    dp[s][e] = ans;
    return dp[s][e];
}
int solveusingtabulation(vector<int>& arr,map<pair<int,int>,int>& maxi){
    int n = arr.size();
    //Step 1 - make dp vector
    vector<vector<int> > dp(n+2,vector<int>(n+1,0));
    
    for(int s = n ; s >= 0; s--){
        for(int e = 0; e <= n-1; e++){
            if(s >= e) continue;

            int ans = INT_MAX;
            for(int i = s; i < e ;i++){
                //i is used here for partioning 
                ans = min(ans,(maxi[{s,i}] * maxi[{i+1,e}]) + dp[s][i] + dp[i+1][e]);
            }
            dp[s][e] = ans;
        }
    }
    return dp[0][n-1];

}
int mctFromLeafValues(vector<int>& arr) {
    map<pair<int,int>,int> maxi;
    for(int i = 0; i < arr.size();i++){
        maxi[{i,i}] = arr[i];
        for(int j = i + 1; j < arr.size();j++){
            maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);
        }
    }
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    //Step 1 - create dp array
    vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
    // int ans = solveusingrec(arr,maxi,s,e);
    // int ans = solveusingmem(arr,maxi,s,e,dp);
    int ans = solveusingtabulation(arr,maxi);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin>>arr[i];
    cout<<"Minimum cost tree from leaf values  : "<<mctFromLeafValues(arr)<<endl;
    return 0;
}