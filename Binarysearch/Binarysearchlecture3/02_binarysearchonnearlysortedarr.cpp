#include<iostream>
#include<vector>
using namespace std;
//binary search on nearly sorted array means answer is on mid-1/mid or mid+1
int binarysearchonnearlysortedarray(vector<int>& arr,int target){
    int s = 0;
    int e = arr.size() - 1;
    while( s <= e){
        int mid = s + ( e - s )/2;
        if(arr[mid] == target) return mid;
        if(arr[mid - 1 ]==target) return mid-1;
        if(arr[mid + 1 ]==target) return  mid+1;
        if(target > arr[mid]) s = mid + 1;
        else e = mid - 1;
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
    int ans = binarysearchonnearlysortedarray(arr,target);
    cout<<"Targeted element is found at index : "<<ans<<endl;
    return 0;
}
// 7
// 20 10 30 50 40 70 60