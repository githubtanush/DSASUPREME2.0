#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int maxprofit(vector<int>& prices){
   //Brute solution 
        int maxpro = 0;
        for(int i = 0; i < prices.size();i++){
            for(int j = i+1; j < prices.size();j++){
                if(prices[j] > prices[i]){
                    maxpro = max(prices[j] - prices[i],maxpro);
                }
            }
        }
        return maxpro;



        //Optimal solution 
        // int minprice = INT_MAX;
        // int maxpro = INT_MIN;
        // for(int i = 0; i < prices.size();i++){
        //     minprice = min(minprice,prices[i]);
        //     maxpro = max(maxpro,prices[i]-minprice);
        // }
        // return maxpro;

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n ;i++) cin>>arr[i];
    cout<<maxprofit(arr);
    return 0;
}