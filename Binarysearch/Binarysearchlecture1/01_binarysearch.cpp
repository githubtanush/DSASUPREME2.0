// 01_binarysearch

//binary search - basically this algorithm find target in O(logN) time it divides the aray
//binary - means two means divide in two 
//search  - means searching
//we apply binary search on that array which follows this condition
// 1st.) Array is sorted it's not matter it is in increasing or decreasing
// 2nd.) apply on monotonic functions it is in ascending or descending order
#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int>& arr,int target){
    int s = 0;
    int e = arr.size()-1;
    int mid = s + ( e - s )/2; //To avoid overflow condition
    while(s <= e){
        if(arr[mid] == target) return mid;
        else if(target > arr[mid]) s = mid + 1;
        else e = mid - 1;
        mid = s+ ( e - s )/2;
    }
    //ab yaah tak phunch gay matlab target
    //nhi mila to hm return false krdenge
    return false;
}
int main(){
    int n;
    cout<<"Enter how many elements do you want to enter : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target : ";
    cin>>target;

    if(binarysearch(arr,target)) cout<<"bhaijaan mil gya ....."<<endl;
    else cout<<"Nhi milya";
    return 0;
}
//now count the time complexity
// 10,000 -> 10,000/2 -> 5,000/2 -> 2,500/2 -> 1,250/2 -> 625/2 -> 312/2 -> 156/2 -> 78/2 -> 39/2 -> 19/2 -> 9/2 -> 4/2 -> 2/2 -> 1
//means find in N/2^0 -> N/2^1 -> N/2^2 -> N/2^3 -> _________ -> N/2^k
// so N/2^K = 1
// so N = 2^K
// apply log
// logN = log2^K
// so it is k = logN