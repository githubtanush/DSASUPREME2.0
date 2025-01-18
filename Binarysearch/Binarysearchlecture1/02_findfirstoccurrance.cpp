#include<iostream>
#include<vector>
using namespace std;
// lowerbound or we can say that find the first occurrance of the number
int findlowerbound(vector<int>& nums,int target){
    // int s = 0;
    // int e = nums.size()-1;
    // int mid = s + (e - s)/2;
    // int ans = -1;
    // while(s <= e){
    //     if(nums[mid]==target){
    //         ans = mid;
    //         e = mid - 1;
    //     }
    //     else if(target < nums[mid]) e = mid - 1;
    //     else s = mid + 1; 
    //     mid = s + ( e - s )/2;
    // }
    // return ans;
    auto it = lower_bound(nums.begin(),nums.end(),target);
    return it-nums.begin();
}
int main(){
    vector<int> nums;
    int n;
    cin>>n;
    nums.resize(n);
    for(int i = 0; i < n;i++){
        cin>>nums[i];
    }
    int target;
    cout<<"Enter the target : ";
    cin>>target;
    int ans = findlowerbound(nums,target);
    cout<<"Targeted Element is found at index : "<<ans<<endl;
    return 0;
}
// 5
// 1 2 3 3 4
// 3
//2