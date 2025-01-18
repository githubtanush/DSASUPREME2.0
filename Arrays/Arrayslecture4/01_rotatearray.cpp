// 01_rotatearray
#include<iostream>
#include<vector>
using namespace std;
//Method 1 - modulus approach 
//Method 2 - temporary array
//Method 3 - reverse approach
void rotatearray(vector<int>& arr,int k){
    //jab bhi aise koi circular jeisa behaviour ho na 
    //ja counting aise chl rhi hai 0 1 2 0 1 2 then we 
    //try to use always modulus

    //Method 1 - modulus approach array 
//     int n = arr.size();// size nikala
//     vector<int> ans(n);//create kiya nya array 
//     for(int index = 0; index < n;index++){
//         int newindex = (index + k) % n; //nya index nikal liya
//         ans[newindex] = arr[index];
//     }
//     arr = ans;


    //Method 2 - reverse approach 
    //take k into the boundaries of size
     k = (k % arr.size());
    //reverse approach 
    //Step 1 - reverse the whole array
    reverse(arr.begin(),arr.end());
    //Step 2 - reverse the array till k
    reverse(arr.begin(),arr.begin()+k);
    //Step 3 - reverse the array from k to end
    reverse(arr.begin()+k,arr.end());
}
int main(){
    int n;
    cout<<"Enter number of elements you want to insert in the array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"How many rotations do you want in the array : ";
    cin>>k;
    rotatearray(arr,k);
    for(int i : arr) cout<<i<<" ";
    return 0;
}