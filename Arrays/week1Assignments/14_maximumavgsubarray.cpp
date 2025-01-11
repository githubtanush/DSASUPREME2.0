#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
double bruteforce(vector<int>& nums,int k){
    //we declare one maxsum variable initialize with int_min so that we can find the maximum sum
    int maxsum = INT_MIN;
    //then we declare i and j according to the length of the k 
    int i = 0 , j = k - 1;
    //if assume j is out of bound in maxsum then this is the condition of loop
    while(j < nums.size()){
        //then we declare one variable with sum in which we doing sum of k length of the array 
        int sum = 0;
        //then we initialize the for loop which is finding maxsum from i to j 
        for(int y = i ; y <= j ;y++)
            sum = sum + nums[y];
        //then we finding the maxsum from them 
        maxsum = max(maxsum,sum);
        // then after we finding maxsum we increment the i and j variable 
        i++,j++;
    }
    // finally which maxsum we have reached we use that 
    // for finding avg we divide maxsum with maximum length;
    double avg = maxsum /(double) k ;
    return avg;
}
double slidingwindow(vector<int>& nums,int k ){
    //then we declare i and j according to k
    int i = 0, j = k - 1;
    //initialize one variable to keep track of sum and initialize it with zero
    int sum = 0;
    for(int y = i ; y <= j ;y++)
        sum += nums[y];

    //if there is one window means that is 100 % confirm that maxsum is sum or
    //if there are more window than also fine because maxsum firstly store 1st window index
    int maxsum = sum;
    //then increment the j because nextly that can also check if it is out of bound or not
    j++;
    //then we apply out of bound conditions
    while(j < nums.size()){
        //declare sum variable and initialize it with 0 value
        //then we initialize but wait if there is only one condition then upper thing of for loop take care of this
        sum -= nums[i++];
        sum += nums[j++];
        maxsum = max(maxsum,sum);
    }
    double maxavg = maxsum / (double) k;
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
    double ans = slidingwindow(nums,k);
    cout<<"Maximum avg subarray is : "<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}
// 6
// 1 12 -5 -6 50 3
// 4