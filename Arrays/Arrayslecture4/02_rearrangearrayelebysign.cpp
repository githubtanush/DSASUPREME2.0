// 02_rearrangearrayelebysign
#include<iostream>
#include<vector>
using namespace std;
//Method 1 - counting approach - make temporary array and solve
//Method 2 - play with indexes
vector<int> rearrange(vector<int>& arr){
    //Method 1 - count the negative elements put int the temporary array
    // vector<int> negative;
    // vector<int> positive;
    // for(int i= 0; i < arr.size();i++){
    //     if(arr[i] < 0) negative.push_back(arr[i]);
    //     else positive.push_back(arr[i]);
    // }
    // vector<int> ans;
    // int i = 0;
    // while(i < arr.size()/2){
    //     ans.push_back(positive[i]);
    //     ans.push_back(negative[i]);
    //     i++;
    // }
    // return ans;


    //Method 2 = play with indexes
    vector<int> ans(arr.size());
    int even = 0;
    int odd = 1;
    for(int i = 0; i < arr.size();i++){
        if(arr[i] < 0){
            ans[odd] = arr[i];
            odd += 2;
        }
        else{
            ans[even] = arr[i];
            even += 2;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter number of elements you want to take : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin>>arr[i];
    vector<int> ans = rearrange(arr);
    for(int i : ans) cout<<i<<" ";
    return 0;
}
// 6
// -3 -4 -5 6 2 1