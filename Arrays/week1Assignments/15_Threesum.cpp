#include<iostream>
#include<set>
#include<vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >ans;
        set<vector<int>> output;
        sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size();i++){
        int j = i+1;
        int k = nums.size()-1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum==0){
                output.insert({nums[i],nums[j],nums[k]});
                j++;
               k--;
            }
            else if(sum<0){
                j++;
            }
            else{
                k--;
            }
        }
    }
        for(auto triplets : output){
            ans.push_back(triplets);
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
    vector<vector<int> >ans = threeSum(nums);
    for(int i = 0; i < ans.size();i++){
        for(int j = 0; j < ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// -1 0 1 2 -1 -4