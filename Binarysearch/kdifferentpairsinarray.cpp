#include<iostream>
#include<set>
#include<vector>
using namespace std;
//brute force (naive solution) - when we iterate from each and every pair of element
//mst approach - 2 pointer approach
//different pairs chahiye to use set for take distinct pairs

int bs(vector<int>& nums,int s,int x){
    int e = nums.size()-1;
    while(s<=e){
        int mid = s + ( e - s)/2;
        if(nums[mid] == x )return mid;
        else if(nums[mid] < x) s = mid + 1;
        else e = mid - 1;
    }
    return -1;
}
int findpairs(vector<int>& nums,int k ){
    //method 1 - brute force(naive force)
    // set<pair<int,int> > ans;
    //     int n = nums.size();
    //     for(int i = 0; i < n;i++){
    //         for(int j = i + 1; j < n;j++){
    //             int diff = abs(nums[i]-nums[j]);
    //             if(diff == k){
    //                 ans.insert({nums[i],nums[j]});
    //             }
    //         }
    //     }
    //     return ans.size();

    // //method 2 - two pointer approach
    // //firstly sort the arrays
    // int n = nums.size();
    // sort(nums.begin(),nums.end());
    // set<pair<int,int> >ans;
    // int i = 0;
    // int j = 1;
    // while(j < n){
    //     int diff = nums[j]-nums[i];
    //     if(diff == k){
    //         ans.insert({nums[i],nums[j]});
    //         i++;
    //         j++;
    //     }
    //     else if(diff>k){
    //         i++;
    //     }
    //     else{
    //         j++;
    //     }
    //     if(i==j) j++;
    // }
    // return ans.size();

    //Method 3 - Binary search
    //can we apply binary search on this question
    //pehle sort krdenge kyuki binary search to sorted array mein hi applicable hai 
    sort(nums.begin(),nums.end());
    //set lunga taaki different pairs ko store krwa sku
    set<pair<int,int> >ans;
    for(int i = 0; i < nums.size();i++){
        // a[i]
        // search->a[i] + k [right subarray];
        if(bs(nums,i+1,nums[i]+k) != -1){
            ans.insert({nums[i],nums[i]+k});
        }   
    }
    return ans.size();
}
//T.C - O(Nlogn);
int main(){
    vector<int> nums;
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<"Give the input to the array : ";
    for(int i = 0;i < n;i++){
        int data;
        cin>>data;
        nums.push_back(data);
    }
    int k;
    cout<<"Enter how many unique pairs of what difference do you want : ";
    cin>>k;
    int ans = findpairs(nums,k);
    cout<<"The number of unique pairs are : "<<ans<<endl;
    return 0;
}

// 5 
// 1 1 3 4 5 