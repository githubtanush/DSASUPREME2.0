// 04_shiftarrayele
#include<iostream>
#include<vector>
using namespace std;
void shiftarr(vector<int>& arr){
    //Step 1 = mein last value ko kisi temp mein store kr lunga
    int temp = arr[arr.size()-1];
    

    //Step 2 = mein har ek element ko ek ek krke right side shift kr dunga
    // int index = arr.size()-1;
    // for(int i = arr.size() - 2;i>=0;i--){
    //     arr[index--] = arr[i];
    // }
    //or we do like this
    for(int i = arr.size()-1 ; i>=1 ;i--){
        arr[i] = arr[i-1];
    }

    //Step 3 = mein temp ki value ko array ki 0th position mein daal dunga
    arr[0] = temp;
}
int main(){
    int n;
    cout<<"How many elements do you want to take in an array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin>>arr[i];
    shiftarr(arr);
    for(int i : arr) cout<<i<<" ";
    return 0;
}
// 10
// 1 2 3 4 5 6 7 8 9 10