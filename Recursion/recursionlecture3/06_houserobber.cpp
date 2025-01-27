#include<iostream>
#include<vector>
using namespace std;
int rob(vector<int>& nums,int index){
    int size = nums.size();

    //base case
    if(index >= size) return 0;

    //chori krlo - ith index par
    int option1 = nums[index] + rob(nums,index+2);
    //chori mat kro - ith index par
    int option2 = 0 + rob(nums,index+1);

    int finalans = max(option1,option2);
    return finalans;
}
int main(){
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++) cin>>v[i];
    rob(v,0);
    return 0;
}