#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
// void printarray(int arr[],int n,int index){
//     //base case 
//     if(index >= n){
//         return ;
//     }
//     //processing head to tail recursion
//     cout<<arr[index]<<" ";
//     //recursive relation
//     printarray(arr,n,index+1);
// }

// bool searcharray(int arr[],int n,int index,int target){
//     //base case 
//     if(index >= n)
//         return false;
//     //processing
//     if(arr[index]==target) return true;
//     //recursive relation
//     return searcharray(arr,n,index+1,target);
// }

// int findminimum(int arr[],int n,int index,int& mini){
//     //base case 
//     if(index >= n){
//         return -1;
//     }
//     //processing head to tail recursion
//     mini = min(mini,arr[index]);
//     //recursive relation
//     return findminimum(arr,n,index+1,mini);
// }

// void print(vector<int>& ans,int index){
//     //base case
//     if(index>=ans.size()) return ;
//     //processing
//     cout<<ans[index]<<" ";
//     //recursive relation 
//     print(ans,index+1);
// }
// bool checksorted(int arr[],int n,int index){
//     //base case
//     if(index>=n) return true;
//     //processing
//     if(arr[index]>arr[index-1]){
//        return checksorted(arr,n,index+1);
//     }
//     else{
//         //sort nhi hai 
//         return false;
//     }
// }

int binarysearch(int arr[],int s,int e,int target){
    //base case
    if(s>e) return -1;
    
    //processing
    int mid = s + ((e-s)>>1);
    if(arr[mid]==target) return mid;
    if(arr[mid] < target) return binarysearch(arr,mid+1,e,target);
    else return binarysearch(arr,s,mid-1,target);
}
int main(){
    int n;
    cin>>n;
    int arr[1000];
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    int s = 0;
    int e  = n - 1;
    // vector<int> ans(n);
    // for(int i = 0;i < n;i++){
    //     cin>>ans[i];
    // }
    // printarray(arr,n,index);
    //search in array 
    // int target ;
    // cin>>target;
    // bool ans = searcharray(arr,n,index,target);
    // if(ans){
    //     cout<<"Element is present in the array ";
    // }
    // else{
    //     cout<<"not present";
    // }
    // int mini = INT_MAX;
    // int ans = findminimum(arr,n,index,mini);
    // cout<<"The minimum value in answer is : "<<mini<<endl;

    // print(ans,index);
    // bool issorted = checksorted(arr,n,index);
    // if(issorted){
    //     cout<<"Array is sorted"<<endl;
    // }
    // else{
    //     cout<<"Array is not sorted"<<endl;
    // }
    int target;
    cin>>target;
    int ans = binarysearch(arr,s,e,target);
   cout<<"Index is found at target : "<<ans<<endl;
     
   return 0;
}