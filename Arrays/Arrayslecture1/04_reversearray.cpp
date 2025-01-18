#include<iostream>
#include<vector>
using namespace std;
void reversearray(vector<int>& arr){
    // //we can use two pointer approach
    // int left = 0; 
    // int right = arr.size()-1;
    // while(left<=right){
    //     swap(arr[left],arr[right]);
    //     left++;
    //     right--;
    // }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n;i++) cin>>arr[i];
    for(int i : arr) cout<<i<<" ";
    reversearray(arr);
    cout<<endl;
    for(int i : arr)cout<<i<<" ";

    return 0;
}
// 5
// 1 2 3 4 5