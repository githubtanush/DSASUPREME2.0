#include<iostream>
using namespace std;
int maxScore(vector<int>& cardPoints, int k) {
    //Time complexity - O(2K)
    //Space complexity - O(1)
    //Sliding window approach 
        int lsum = 0, rsum = 0, maxsum = INT_MIN;
        for(int i = 0 ; i <= k - 1; i++) lsum += cardPoints[i];
        maxsum = lsum;
        int rindex = cardPoints.size()-1;
        for(int i = k-1; i >= 0; i--){
            lsum -= cardPoints[i];
            
            rsum += cardPoints[rindex--];
            
            maxsum = max(maxsum, lsum + rsum);
        }
        return maxsum;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n ;i++) cin>>nums[i];
    int k;
    cin>>k;
    cout<<maxScore(nums,k)<<endl;
return 0;
}