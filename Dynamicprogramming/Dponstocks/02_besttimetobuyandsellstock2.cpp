#include<iostream>
using namespace std;
int maxprofitsolve(vector<int>& arr,int index,bool buy){
    if(index >= arr.size()) return 0;

    int profit = 0;
    if(buy){
        int includeprofit = -arr[index] + maxprofitsolve(arr,index+1,0);
        int skipprofit = 0 + maxprofitsolve(arr,index+1,1);
        profit = max(includeprofit,skipprofit);
    }
    else{
        int sellprofit = arr[index] + maxprofitsolve(arr,index+1,1);
        int skipprofit = 0 + maxprofitsolve(arr,index+1,0);
        profit = max(sellprofit , skipprofit);
    }
    return profit;
}
int maxprofit(vector<int>& arr){
    vector<vector<int> > dp;
    return maxprofitsolve(arr,0,1);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n ;i++) cin>>arr[i];
    cout<<maxprofit(arr);
    return 0;
}