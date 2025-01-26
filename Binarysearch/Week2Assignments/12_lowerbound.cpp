//upper bound - smallest number which is strictly greater to that number
//lowerbound - strictly greater than or equal to less than nmber
#include<iostream>
#include<vector>
using namespace std;
int findlowerbound(vector<int>& arr,int target){
    int s = 0;
    int e = arr.size()-1;
    while( s <= e){
        int mid = s + ( e - s )/2;
        if(arr[mid] > target) e = mid;
        else if(arr[mid] < target) s = mid + 1;
        else if(arr[mid] == target) e = mid;
    }
    if(arr[s] >= target) return s;
    else return e;
}
int findupperbound(vector<int>& arr,int target){
    int low = 0;
    int high = arr.size();
    while(high - low > 1){
        int mid = low + ( high - low )/2;
        if(arr[mid] > target) high = mid;
        else if(arr[mid] < target) low = mid + 1;
    }
    if(arr[low] > target) return low;
    else return high;
}
int main(){
    int n;
    cout<<"Enter the  value for n : ";
    cin>>n;
    
    vector<int> arr(n);
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the value for target : ";
    cin>>target
    findlowerbound(arr,target);
    return 0;
}

