#include<iostream>
#include<vector> //for include vector
using namespace std;
void count01(vector<int>& arr){
    int n = arr.size();
    int zerocount = 0;
    int onecount = 0;
    for(int i = 0; i < n;i++){
        if(arr[i] == 0) zerocount++;
        else if(arr[i] == 1) onecount++;
    }
    cout<<"Zerocount for this array is : "<<zerocount<<endl;
    cout<<"Onecount for this array is : "<<onecount<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    count01(arr);
    return 0;
}
// 5
// 0 0 1 0 0