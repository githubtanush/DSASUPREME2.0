#include<iostream>
#include<vector>
using namespace std;
int pivotelement(vector<int>& arr){
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while(s <= e){
        int mid = s + ( e - s )/2;
        if(s==e) return s;
        if(mid-1>=0 && arr[mid-1] > arr[mid]) return mid-1;
        if(mid+1 < arr.size() && arr[mid] > arr[mid+1]) return mid;
        else if(arr[s] > arr[mid]) e = mid -1 ;
        else s = mid+1;
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
    int ans = pivotelement(arr);
    cout<<"The pivot index of the element are : "<<ans<<endl;
    return 0;
}
// 8
// 12 14 16 2 4 6 8 10