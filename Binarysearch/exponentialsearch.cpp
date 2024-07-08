//Exponential search//doubling search//galloping search//starzic search//unbounded search array 
#include<iostream>
#include<limits.h>
using namespace std;
int bs(int arr[],int s,int e,int x){
    while(s<=e){
        int mid = s + (e - s)/2;

        if(arr[mid]==x) return mid;
        else if(arr[mid]<x) s = mid + 1;
        else e = mid - 1;
    }
    return -1;
}
int exponentialsearch(int arr[],int size,int x){
    if(arr[0]==x) return 0;

    int i = 1;
    while(i < size && arr[i]<=x){
        i = i * 2;
    }

    return bs(arr,i/2,min(i,size-1),x);
}
int main(){
    int arr[] = {3,4,5,6,11,13,14,15,56,70};
    int size = sizeof(arr)/sizeof(int);
    int x = 13;
    int ans = exponentialsearch(arr,size,x);
    cout<<"Element is present at index : "<<ans<<endl;
    return 0;
}
//Time complexity  = O(2^n);