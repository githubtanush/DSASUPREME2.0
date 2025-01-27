#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int>& v,int s,int e,int target){
    //base case
    if(s > e){
        //element not found 
        return -1;
    }

    //processing --> 1 case khud solve kro
    int mid = s + ( e - s )/2;
    if(v[mid] == target) return mid;

    //baaki recursion sambhal lega
    if(v[mid] < target){
        //right mein jao
        return binarysearch(v,mid+1,e,target);

    }
    else{
        //left mein jao
        return binarysearch(v,s,mid-1,target);
    }

}
int main(){
    int n;
    cout<<"Enter the number of elements you want to take in the array : ";
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    int target;
    cout<<"Enter target : ";
    cin>>target;
    int index = binarysearch(v,0,n-1,target);
    if(index == -1) cout<<"Target Not Found"<<endl;
    else cout<<"Target is present at index : "<<index<<endl;
    return 0;
}