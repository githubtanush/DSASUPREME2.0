#include<iostream>
#include<vector>
using namespace std;
// int bruteforce(vector<int>& nums){
//     int n = nums.size();
    
//     for(int i = 0; i < n;i++){
//          int lsum = 0;
//         int rsum = 0;
//         //AT I = 0 MY CURRENT INDEX IS STANDING

//         //COUNT LSUM BY EXCLUDING THE CURRENTINDEX
//         for(int j = 0; j < i;j++){
//             lsum += nums[j];
//         }

//         //COUNT RSUM BY EXCLUDING THE CURRENTINDEX
//         for(int j = i + 1; j < n;j++){
//             rsum += nums[j];
//         }
// cout<<"for index "<<i<<" leftsum : "<<lsum<<"rightsum : "<<rsum<<endl;
//         if(lsum==rsum) return i;
//     }
//     return -1;

// }

//GOOD METHOD
int bdiyaapproach(vector<int>& nums){
    int n = nums.size();

    //meini yaah glti ki naa enko size diya or na hi 0 se initialize kiya to koi garbage value aa gyi phir 
    vector<int> lsum(n,0);
    vector<int> rsum(n,0);

    for(int i = 1; i < n;i++){ // int i = 1 se start hoga nhi to index 0 par vo index -1 ki garbage value hi leta rhega
        lsum[i] = lsum[i-1] + nums[i-1]; 
    }

    for(int j = n-2; j >= 0;j--){//int i = n - 2 se start hoga nhi to n-1 par vo to index n ki garbage value hi leta rhega
        rsum[j] = rsum[j+1] + nums[j+1];
    }

    //now hm check krte hai enka answer kb same hua
    for(int i = 0; i < n;i++){
    if(lsum[i] == rsum[i]){
        cout<<"for index "<<i<<" leftsum : "<<lsum[i]<<"rightsum : "<<rsum[i]<<endl;
        return i;
    }
    }

    //PIVOT INDEX NOT FOUND
    return -1;

}
int main(){
    vector<int> nums;
    int n;
    cin>>n;
    nums.resize(n);
    for(int i = 0; i < n;i++){
        cin>>nums[i];
    }
    int ans = bdiyaapproach(nums);
    cout<<"Pivot index found at : "<<ans<<endl;

    return 0;
}
// 6 
// 1 7 3 6 5 6