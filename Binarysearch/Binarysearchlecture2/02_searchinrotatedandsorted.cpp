#include<iostream>
#include<vector>
using namespace std;
// int pivotelement(vector<int>& arr){
//     int n = arr.size();
//     int s = 0;
//     int e = n - 1;
//     while(s <= e){
//         int mid = s + ( e - s )/2;
//         if(s==e) return s;
//         if(mid-1>=0 && arr[mid-1] > arr[mid]) return mid-1;
//         if(mid+1 < arr.size() && arr[mid] > arr[mid+1]) return mid;
//         else if(arr[s] > arr[mid]) e = mid -1 ;
//         else s = mid+1;
//     }
//     return -1;
// }
// int binarysearch(vector<int> arr,int s,int e,int target){
//     while(s<=e){
//         int mid = s + ( e -  s)/2;
//         if(arr[mid]==target) return mid;
//         else if(arr[mid]<target) s = mid + 1;
//         else e = mid - 1;
//     }
//     return -1;
// }
int searchinrotatedandsorted(vector<int>& arr,int target){
    // int pivotindex = pivotelement(arr);
    // int s = 0;
    // int e = arr.size() -  1;
    // int ans = -1;
    // if(target>=arr[0] && target <= arr[pivotindex]) ans = binarysearch(arr,0,pivotindex,target);
    // else ans = binarysearch(arr,pivotindex+1,e,target);
    // return ans;

    //Method 2 - Two pointer approach
    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;
    while(s<=e){
        int mid = s + ( e - s )/2;
        if(arr[mid]==target) return mid;
        else if(arr[s]<=arr[mid]){
            if(target>=arr[s] && target<=arr[mid]) e = mid - 1;
            else  s = mid + 1;
        }
        else{
            if(target>arr[mid] && target<=arr[e]) s = mid + 1;
            else e = mid - 1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int ans = searchinrotatedandsorted(arr,target);
    cout<<"The targeted element found at index : "<<ans<<endl;
    return 0;
}
// 8
// 12 14 16 2 4 6 8 10
// 14