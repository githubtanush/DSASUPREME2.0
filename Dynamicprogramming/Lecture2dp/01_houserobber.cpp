#include<iostream>
using namespace std;
//Adjacent house mein chori nhi krni kyuki phir police ki call 
//chli jaygi or bula lenge
int solveusingrec(vector<int>& nums,int index){
    if(index >= nums.size()) return 0;

    // if i do robbery in ith house then we can't do robbery in 
    // i+1 and i-1

    //sirf index ki value change ho rhi hai matlab 1 parameter change ho rah 
    //matlab 1d dp hai 
    //1st case - include 
    int include = nums[index] + solveusingrec(nums,index+2);
    //2nd case - exclude
    int exclude = 0 + solveusingrec(nums,index+1);

    //max of include/exclude
    int ans = max(include,exclude);

    //return krdo answer nu 
    return ans;
}
//jab recursion ka code copy paste kroga to function ka name change pehle hi krlo 
//baad mein dikkat ho jaati hai 
int solveusingmemoization(vector<int>& nums,int index,vector<int>& dp){
    if(index >= nums.size()) return 0;


    //from base case to processing check in between 
    //if answer exist in between then return 
    if(dp[index] != -1) return dp[index];
     
    // if i do robbery in ith house then we can't do robbery in 
    // i+1 and i-1

    //sirf index ki value change ho rhi hai matlab 1 parameter change ho rah 
    //matlab 1d dp hai 
    //1st case - include 
    int include = nums[index] + solveusingmemoization(nums,index+2,dp);
    //2nd case - exclude
    int exclude = 0 + solveusingmemoization(nums,index+1,dp);

    //max of include/exclude
    // Step 2 - replace ans with dp array 
    dp[index] = max(include,exclude);

    //return krdo answer nu 
    return dp[index];
}

//solve by tabulation
//bottom up or tabulation mein yeh baat yaad rkhna 
//ki hme kuch set of answers diye hua hme just unko analyze krke
// new answers drive krne hai 
int solveusingtabulation(vector<int>& nums){
//Memoization vala code ke andar loop code 0 se n tk gya tha 
//to bottom up approach mein n se 0 ki taraf aayga
    int n = nums.size();
    //Step 1 - create the array
    vector<int> dp(n,-1);

    //dp[index] -> ? left to right full array ka answer kya hoga
    //dp[index] left to right calculate all the value till the last of the array 

    //Step 2 - exact opposite of top down 
    dp[n-1] = nums[n-1];

    for(int index = n-2; index >= 0; index--){
        int tempans = 0;
        if(index + 2 < n){
            tempans = dp[index+2];
        }
        int include = nums[index] + tempans;
        int exclude = 0 + dp[index+1];
        dp[index] = max(include,exclude);
    }
    return dp[0];//99% cases ke andar dp[initial state] return krna hota
    // or initial state index = 0 hi thi
}
//space optimization possible ? 
int solveusingspaceoptimization(vector<int>& nums){
    int n = nums.size();
    int prev = nums[n-1];
    int next = 0;
    int curr ;

    for(int index = n - 2; index >= 0; index--){
        int tempans = 0;
        if(index+2 < n){
            tempans = next;
        }
        int include = nums[index] + tempans;
        int exclude = 0 + prev;
        curr = max(include,exclude);

        //bhul jata hu 
        next = prev;
        prev = curr;

    }
    return prev;
}

int rob(vector<int>& nums){
    int index = 0;
    int n = nums.size();
    // int ans = solveusingrec(nums,index);
    // return ans;

    //Step 1 - find what type of dp is that and this is 1d dp
    // so create vector array 
    // vector<int> dp(n,-1);
    // int ans = solveusingmemoization(nums,index,dp);
    // return ans;

    int ans = solveusingspaceoptimization(nums);
    return ans;
}


int main(){
    int n;
    cout<<"Enter the size of the vector array : ";
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n;i++){
        cin>>nums[i];
    }
    cout<<"Total robbery done by robber is : "<<rob(nums)<<endl;
    return 0;
}