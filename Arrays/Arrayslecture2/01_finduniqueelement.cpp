// 01_finduniqueelement
#include<iostream>
#include<vector>
using namespace std;
//xor truth table
// 0 0 -> 0
// 1 1 -> 0
// 0 1 -> 1
// 1 0 -> 1
//means apna ek chiz notice ki ki agr 0 ko kisi ke sath bhi xor kre vhi number aa jayga
int getunique(vector<int>& arr){
    int ans = 0;
    for(int i = 0; i < arr.size();i++){
        ans = ans ^ arr[i];
    }
    return ans;
}
int main(){
    int n;
    cout<<"How many elements you want to insert in the array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin>>arr[i];
    cout<<"The unique element in the array is : "<<getunique(arr)<<endl;
    return 0;
}
// 5
// 1 1 2 3 3