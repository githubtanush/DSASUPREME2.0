#include<iostream>
#include<vector>
using namespace std;
int findupperbound(vector<int>& nums,int target){
    int s = 0;
    int e = nums.size()-1;
    int mid = s + (e - s)/2;
    int ans = -1;
    while(s <= e){
        if(nums[mid]==target){
            ans = mid;
            s = mid + 1;
        }
        else if(target < nums[mid]) e = mid - 1;
        else s = mid + 1; 
        mid = s + ( e - s )/2;
    }
    return ans;
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
    int ans = findupperbound(nums,target);
    cout<<"Targeted Element is found at index : "<<ans<<endl;
    return 0;
}
// 5
// 1 2 3 3 4
// 3
//3