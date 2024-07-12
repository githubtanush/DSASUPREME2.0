#include<iostream>
#include<vector>
using namespace std;
int helper(vector<int>& days,vector<int>& costs,int i){
    //base case
    if(i>=days.size()) return 0;

    //solution for a case 1 day pass taken
    int cost1 = costs[0] + helper(days,costs,i+1);

    //solution for a case 7 day pass taken
    int passendday = days[i] + 7 - 1;
    int j = i;
    while(j<days.size() && days[j] <= passendday){
        j++;
    }
    int cost7 = costs[1] + helper(days,costs,j);

    //solution for a case 30 day pass taken
    passendday = days[i] + 30 - 1;
    j = i;
    while(j<days.size() && days[j] <= passendday){
        j++;
    }
    int cost30 = costs[2] + helper(days,costs,j);

    return min(cost1,min(cost7,cost30));
}
int mincost(vector<int>& days,vector<int>& costs){
    return helper(days,costs,0);
}
int main(){
    int n;
    cin>>n;
    vector<int> days(n);
    for(int i = 0; i < n;i++){
        cin>>days[i];
    }
    vector<int> costs;
    costs.push_back(2);
    costs.push_back(7);
    costs.push_back(15);
    int ans  = mincost(days,costs);
    cout<<"The mincost for travelling is : "<<ans<<endl;
    return 0;
}
//input - 
// 6
// 1 4 6 7 8 20
//output - 11

//input - 
// 12
// 1 2 3 4 5 6 7 8 9 10 30 31
//output - 17