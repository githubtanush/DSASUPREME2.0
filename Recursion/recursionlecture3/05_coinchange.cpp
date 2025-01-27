#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& coins,int amount){

//    base case
        if(amount==0){
            return 0;
        }
        //recursive relation
        int mini = INT_MAX;

        for(int i = 0 ; i < coins.size();i++){
            //find answer using ith coin
            int recursionkaans = 0;
            //call recursion only for valid amount i.e >=0  wala amounts
            if(amount-coins[i] >= 0){
                recursionkaans = solve(coins,amount-coins[i]);
                //recursion int max ke equal tab hota jab coin ki value amount se jada ho or answer negative mein jaana lg jaay
                //so avoid this condition because if reckaans is INT_MAX then it is overflow when we add 1 to INT_MAX
                if(recursionkaans != INT_MAX){
                    int ans = 1 + recursionkaans;
                    mini = min(mini,ans);
                }
            }
        }
        return mini;

}
int coinchange(vector<int>& coins,int amount){
    int ans = solve(coins,amount);
    if(ans==INT_MAX) return -1;
    else return ans;
}
int main(){
    vector<int> coins;
    int n;
    cin>>n;
    coins.resize(n);
    for(int i = 0; i < n;i++){
      cin>>coins[i];
    }
    int amount;
    cin>>amount;
    int ans = coinchange(coins,amount);
    cout<<ans<<endl;
    return 0;
}
//input-
//3 
//6 8 5
// 11
//output - 2

//input - 
// 1
// 2
// 3
//output  =  -1;