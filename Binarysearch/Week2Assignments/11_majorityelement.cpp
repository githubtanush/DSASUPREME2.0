#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int>& nums){
    // sort(nums.begin(),nums.end());
    // return nums[(0 + nums.size()-1)/2];

//     auto it1 = lower_bound(nums.begin(),nums.end(),3);
//     cout<<*it1<<endl;
//     cout<<"Index : "<<it1 -  nums.begin()<<endl;

//     auto it2 = upper_bound(nums.begin(),nums.end(),3);
//     cout<<*it2<<endl;
//     cout<<"Index : "<<it2 - nums.begin()<<endl;

//    return (it2 - nums.begin()) -  (it1 - nums.begin()) + 1;

}
int main(){
    vector<int> nums;
    int n;
    cin>>n;
    nums.resize(n);
    for(int i = 0; i < n;i++){
        cin>>nums[i];
    }
    int ans = binarysearch(nums);
    cout<<"Majority Element is : "<<ans<<endl;
    return 0;
}