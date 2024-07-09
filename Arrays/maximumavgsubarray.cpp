#include<iostream>
#include<vector>
using namespace std;
double bruteforce(vector<int>& nums,int& k){
    int maxsum = INT_MIN;
    int n = nums.size();
    int i = 0;
    int j = k - 1;
    while(j < n){
        int sum = 0;
        for(int y = i; y <= j;y++){
            sum += nums[y];
        }
        maxsum = max(maxsum,sum);
        i++;
        j++;
    }
    double ans = (double) maxsum/k;
    return ans;
}
double slidingwindow(vector<int>& nums,int& k){
    int i = 0;
    int j = k - 1;
    int sum = 0;
    for(int y = i; y <= j;y++)
        sum += nums[y];
    int maxsum = sum;
        j++;
        while(j<nums.size()){
            sum = sum - nums[i++];
            sum = sum + nums[j++];
            maxsum = max(maxsum,sum);
        }
    double maxavg = maxsum /(double) k;
      return maxavg;
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
    double ans = bruteforce(nums,k);
    cout<<"Maximum avg subarray is : "<<ans<<endl;
    return 0;
}
// 6
// 1 12 -5 -6 50 3
// 4