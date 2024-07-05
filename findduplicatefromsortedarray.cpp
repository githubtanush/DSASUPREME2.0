#include<iostream>
#include<vector>
using namespace std;
int findduplicate(vector<int>& v){
    //Method 1  - sort and use the index wisely
    int n = v.size();
    // sort(v.begin(),v.end());
    // for(int i = 0; i < n-1;i++){
    //     if(v[i]==v[i+1]) return v[i];
    // }
    // return -1;

    //Method 2 - negative marking method in these we use the index very wisely
    // int ans = -1;
    // for(int i = 0; i < n;i++){
    //     int index = abs(v[i]);

    //     //Already visited ??
    //     if(v[index]<0) {
    //         ans = index;
    //         break;
    //     }

    //     //mark visited 
    // esma yaad rkhna ek baar nya index bnana ka baad usi ka use krna mein baar baar i likh rah hu yaah par
    //     v[index] *= -1;
    // }
    // return ans;


    //Method 3 - algo of while loop 
    // while(v[0] != v[v[0]]){
    //     swap(v[0],v[v[0]]);
    // }
    // return v[0];
}
int main(){
    vector<int> nums;
    int n;
    cin>>n;
    nums.resize(n);
    for(int i = 0; i < n;i++){
        cin>>nums[i];
    }
    int ans = findduplicate(nums);
   cout<<"The duplicate number in the array is : "<<ans<<endl;
    return 0;
}
// 5
// 1 3 4 2 2 

// 5
// 3 1 3 4 2