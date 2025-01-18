// 03_sort01
//Approaches - 1.) counting approach
//2.) 2 pointer approach
//3.) sort function
#include<iostream>
#include<vector>
using namespace std;
void sort01(vector<int>& arr){
    //counting approach
//     int zerocount = 0;
//     int onecount = 0;
//     for(int i = 0; i < arr.size();i++){
//         if(arr[i] == 0) zerocount++;
//         if(arr[i] == 1) onecount++;
//     }
//     int index = 0;
//     while(zerocount--) arr[index++] = 0;
//     while(onecount--) arr[index++] = 1;


    // 2 pointer approach
    int left = 0;
    int right = arr.size()-1;
    while(left <= right){
        if(arr[left] == 0) left++;
        else if(arr[right] == 1) right--;
        else swap(arr[left],arr[right]);
    }
}
int main(){
    int n;
    cout<<"How many elements you want to insert in the array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin>>arr[i];
    for(int i : arr) cout<<i<<" ";
    sort01(arr);
    cout<<endl;
    for(int i : arr) cout<<i<<" ";
   return 0;
}
// 5
// 0 1 0 1 0