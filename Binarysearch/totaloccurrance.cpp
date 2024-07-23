#include<iostream>
#include<vector>
using namespace std;
int findlowerbound(vector<int>& nums,int target){
    int s = 0;
    int e = nums.size()-1;
    int mid = s + (e - s)/2;
    int ans = -1;
    while(s <= e){
        if(nums[mid]==target){
            ans = mid;
            e = mid - 1;
        }
        else if(target < nums[mid]) e = mid - 1;
        else s = mid + 1; 
        mid = s + ( e - s )/2;
    }
    return ans;
}
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
int findtotaloccurrance(vector<int>& nums,int target){
    int lb = findlowerbound(nums,target);
    int rb = findupperbound(nums,target);
    return  rb - lb + 1;    
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
    int ans = findtotaloccurrance(nums,target);
    cout<<"Total occurrance of the element is : "<<ans<<endl;
    return 0;
}
// 8
// 1 2 3 3 3 3 3 9
// Enter the target : 3
// Total occurrance of the element is : 5