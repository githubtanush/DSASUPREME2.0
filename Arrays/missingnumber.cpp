#include<iostream>
#include<vector>
using namespace std;
// int missingnumber(vector<int>& nums){
//     //BRUTE FORCE  - 1.) SORT 
//     // 2.) CHECK THE INDEX WITH NUMS[INDEX]
//     //WHEN THERE IS NOT FOUND SAME MEANS THAT IS MISSING NUMBER
//     int n = nums.size();
//     sort(nums.begin(),nums.end());
//     for(int i = 0; i < n;i++){
//         if(i==nums[i]) continue;
//         else return i;
//     }
//     return n;
// }
// int summethod(vector<int>& nums){
//     int sum = 0;
//     int n = nums.size();
//     for(int i = 0; i < n;i++){
//         sum = sum + nums[i];
//     }
//     int totalsum = ((n) * (n+1))/2;
//     int ans = totalsum - sum ;
//     return ans;
// }

int xormethod(vector<int>& v){
    int n = v.size();
    int ans = 0;
    //XOR ALL V[I] VALUES
    for(int i = 0; i < n;i++){
        ans = ans ^ v[i];
    }
    //XOR ALL RANGE ITEMS
    for(int i = 0; i <= n;i++){
        ans = ans ^ i;
    }
    return ans;
}
int main(){
    vector<int> v;
    int n;
    cin>>n;
    v.resize(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    // int ans = missingnumber(v);
    // int ans = summethod(v);
    int ans = xormethod(v);
    cout<<"Missing number is : "<<ans<<endl;
    return 0;
}
// 3
// 3 0 1
// output - 2
// 9
// 9 6 4 2 3 5 7 0 1
//output - 8