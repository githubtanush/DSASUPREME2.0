#include<iostream>
#include<vector>
using namespace std;
int coinchange(vector<int>& coins,int amount){
    //base case 
    if(amount == 0) return 0;
    if(amount < 0) return INT_MAX;

    //processing
    int mini = INT_MAX;
    // int ans = INT_MAX;
    for(int i = 0; i < coins.size();i++){
        int coin = coins[i];
        //current coin ko sirf tbhi use krenge jab uski value <= amount hogi
        if(coin <= amount){
            int recans = coinchange(coins,amount - coin);
            if(recans != INT_MAX){
                int ans = 1 + recans;
                mini = min(mini,ans);
            }
        }
    }
    return mini;
}
int main(){
    int n;
    cout<<"Enter the number of coins that u have : "<<endl;
    cin>>n;
    vector<int> coins(n);
    for(int i = 0; i < n;i++) cin>>coins[i];
    int amount;
    cout<<"The targeted amount is : ";
    cin>>amount;
    coinchange(coins,amount);
    int ans = coinchange(coins,amount);
    if(ans == INT_MAX) return -1;
    else return ans;
    return 0;
}