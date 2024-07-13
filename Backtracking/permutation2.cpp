#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void permuteunique(vector<int>& nums,vector<vector<int> >& ans,int start){
    // base case
    if(start == nums.size()) {
        ans.push_back(nums);
        return ;
    }
    unordered_map<int,bool> visited;
    for(int i = start; i < nums.size();i++){
        if(visited.find(nums[i])!= visited.end()) continue;
        visited[nums[i]] = true;
        swap(nums[i],nums[start]);
        permuteunique(nums,ans,start+1);
        swap(nums[i],nums[start]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int> > ans;
        permuteunique(nums,ans,0);
        //print answer into set
        // set<vector<int> >st;
        // for(auto e:ans)
        //     st.insert(e);
        // ans.clear();
        // for(auto e:st)
        //     ans.push_back(e);
        return ans;
    }
int  main(){
   vector<int> nums;
   int n;
   cin>>n;
   nums.resize(n);
   for(int i = 0; i < n;i++){
    cin>>nums[i];
   }
   vector<vector<int> > ans = permuteUnique(nums);
   for(auto  i : ans){
    for(auto j : i){
        cout<<j<<" ";
    }
    cout<<endl;
   }
    return 0; 
}
//Input - 
// 3
// 1 1 2
//output - 
// 1 1 2 
// 1 2 1 
// 2 1 1 

//Input - 
// 3
// 1 2 3

//output - 
// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 2 1 
// 3 1 2 