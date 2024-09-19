#include<iostream>
#include<vector>
using namespace std;
//base case
//one solution
//recursive call
void printsubarrayhelper(vector<int>& nums,int start,int end){
    //base case
    if(end == nums.size()) return ;

    //1 case solution
    for(int i = start;i<=end;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    //recursive call
    printsubarrayhelper(nums,start,end+1);
}
void printsubarray(vector<int>& nums){
    for(int start = 0; start<nums.size();start++){
        int end = start;
        printsubarrayhelper(nums,start,end);
    }
}
int main(){
    int size;
    cin>>size;
    vector<int> nums(size);
    for(int i = 0; i < size;i++){
       nums[i] = i+1;
    }
    printsubarray(nums);
    return 0;
}