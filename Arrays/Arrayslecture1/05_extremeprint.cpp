//extreme print in an array means first print left then right then again left then again right
#include<iostream>
#include<vector>
using namespace std;
void extremeprint(vector<int>& arr){
    //again we can use two pointer approach
    int left = 0;
    int right = arr.size()-1;
    while(left <= right){ //jab tak left right se km hai ya equal hai tb tk loop chlega
    //jab left or right equal hai tab do baar print na ho jay usko avoid krne ke liye 
    //yeh condition jroori hai ki ek hi baar print ho baki ko else mein daal denga
    if(left == right)cout<<arr[left]<<" ";
    else cout<<arr[left]<<" "<<arr[right]<<" ";
    left++;
    right--;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    for(int i : arr) cout<<i<<" ";
    cout<<endl;
    extremeprint(arr);
    return 0;
}
// 05_extremeprint
// 5
// 1 2 3 4 5