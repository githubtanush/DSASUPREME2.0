#include<iostream>
#include<vector>
using namespace std;
vector<int> twosum(vector<int>& nums,int target){
    //brute force
    //hr ek pair nu check kar te jithe sum same aa gya return krdo
    vector<int> ans;
    int n = nums.size();
    // for(int i = 0; i < n;i++){
    //     for(int j = i + 1; j < n;j++){
    //         if(nums[i]+nums[j]==target){
    //             ans.push_back(i);
    //             ans.push_back(j);
    //         }
    //     }
    // }


    //2nd way = two pointer approach 
    //sort krne vala step baar baar bhul rah hu esko yaad rkhna
    sort(nums.begin(),nums.end());
    int i = 0;
    int j = n - 1;
    while(i < j){
        int sum = nums[i]+nums[j];
        if(sum==target){
            ans.push_back(i);
            ans.push_back(j);
            break;
        }
        else if(sum < target){
            i++;
        }
        else{
            //>target
            j--;
        }
    }
    return ans;


}
int main(){
    vector<int> nums;
    int n;
    cin>>n;
    nums.resize(n);
    for(int i = 0 ; i < n;i++){
            cin>>nums[i];
    }
    int target;
    cin>>target;
   vector<int> ans = twosum(nums,target);
   for(int i: ans){
    cout<<i<<" ";
   }
    return 0;
}
// 4  
// 2 7 11 15
// 9