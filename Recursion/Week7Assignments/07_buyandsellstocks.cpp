#include<iostream>
#include<vector>
using namespace std;
void maxprofitfinder(vector<int>& prices,int i,int& minprice,int& maxprofit){
    //base case
        if(i==prices.size()) return ;
    
    //solution for one case
    if(prices[i] < minprice) minprice = prices[i];

    int todaysprofit = prices[i] - minprice;
    if(todaysprofit > maxprofit ) maxprofit = todaysprofit;
    
    //Recursive equation
    maxprofitfinder(prices,i+1,minprice,maxprofit);
}
int maxprofit(vector<int>& prices){
    int minprice = INT_MAX;
    int maxprofit = INT_MIN;
    maxprofitfinder(prices,0,minprice,maxprofit);
    return maxprofit;
}
int main(){
    vector<int> prices;
    int n;
    cin>>n;
    prices.resize(n);
    for(int i = 0; i < n;i++){
        cin>>prices[i];
    }
    int ans = maxprofit(prices);
    cout<<"The maxprofit of stocks will be : "<<ans<<endl;
    return 0;
}

// 6    
// 7 1 5 3 6 4

// 5
// 7 6 4 3 1