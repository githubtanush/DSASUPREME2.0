#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& nums,int n,int index){
    //base case
    if(index>=n) return 0;

    //recursive relation
    //chori krlo - ith index par
    //agr chori krli included
    //then also we exclude i-1 and i+1 index
    int option1 = nums[index] + solve(nums,n,index+2);
    //agr chori hi nhi ki excluded
    int option2 = 0  + solve(nums,n,index+1);

    int finalAns = max(option1,option2);
    return finalAns;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n;i++){
        cin>>nums[i];
    }
    int index = 0;
    int ans = solve(nums,n,index);
    cout<<"At max you rob at : "<<ans<<" houses"<<endl;

    return 0;
}
//Input 
// 4
// 1 2 3 1

//output - 4