#include<iostream>
using namespace std;
void subsequence(vector<int>& arr,int index,vector<int>& brr){
    if(index >= arr.size()){
        for(auto i : brr) cout<<i<<" ";
        cout<<endl;
        return ;
    }

    brr.push_back(arr[index]);
    subsequence(arr,index+1,brr);
    brr.pop_back();
    subsequence(arr,index+1,brr);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin>>arr[i];
    vector<int> brr;
    int index = 0;
    subsequence(arr,index,brr);
    for(auto i : brr) cout<<i<<endl;
    return 0;
}