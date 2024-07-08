#include<iostream>
#include<vector>
using namespace std;
// vector<int> twopointermethod(vector<int>& arr, int k, int x) {
//     int l = 0;
//     int h = arr.size()-1;
//     while(h-l >= k){
//         if(x-arr[l] > arr[h]-x) l++;
//         else h--;
//     }
//     // vector<int> ans;
//     // for(int i = l ; i <= h;i++){
//     //     ans.push_back(arr[i]);
//     // }
//     // return ans;
//     //T.C - O(n) S.C - O(n-k)
//     //one more way to write upper thing is 
//     return vector<int>(arr.begin()+l,arr.begin()+h+1);
// }
int lowerbound(vector<int>& arr, int x ){
    int s = 0;
    int e = arr.size()-1;
    int ans = e;
    while(s<=e){
        int mid = (s + e)/2;
        if(arr[mid]>=x){
            ans = mid ;
            e = mid - 1;
        }
        else if(x > arr[mid]) s = mid + 1;
        else e = mid - 1;
    }
    return ans;

}
vector<int> bsmethod(vector<int>& arr, int k, int x) {
    //findlowerbound first
    int h = lowerbound(arr,x);
    int l = h - 1;
    while(k--){
        if(l<0) h++;
        else if(h>=arr.size()) l--;
        else if(x-arr[l] > arr[h]-x) h++;
        else l--;
    }
    return vector<int>(arr.begin()+l+1,arr.begin()+h);

}
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    // return twopointermethod(arr,k,x);
    return bsmethod(arr,k,x);
}
int main(){
    vector<int> nums;
    int n;
    cin>>n;
    nums.resize(n);
    for(int i = 0; i < n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    int x;
    cin>>x;
    vector<int> ans = findClosestElements(nums,k,x);
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;
}
// 13
// 12 16 22 30 35 39 42 45 48 50 53 55 56
// 4
// 35