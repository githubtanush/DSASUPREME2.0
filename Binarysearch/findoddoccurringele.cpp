#include<iostream>
#include<vector>
using namespace std;
int findoddocc(vector<int>& arr){
    int s = 0;
    int n = arr.size();
    int e = n - 1;
    while(s <= e){
        int mid = s + ( e - s )/2;
        if(s == e) return s;
        if(mid & 1){
            if(arr[mid-1]==arr[mid]) s = mid + 2;
            else e = mid - 1;
        }
        else{
            if(arr[mid]==arr[mid+1]) s = mid + 2;
            else e = mid;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    
    return 0;
}