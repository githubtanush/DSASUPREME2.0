//Exponential search//doubling search//galloping search//starzic search//unbounded search array 
//why this is exponential search - search means something search type 
//Linear search O(n) and binary search O(logn)
//what is exponential search - application - when u have an very large array with a very big size
//agr mein pura array mein binary search krne ki jagah ek part mein binary search lga du means agr mein ek part or subarray find krlu or boldu ki yhi eske bich mein hi mera answer exist krta hai
//to es lgana ki technique ko exponential binary search kehte hai
//use case  or application - when u have given with a sorted array  - 1.) search in infinite or unbounded arrays. 
// 2nd application .) - Better than binary search if x is in near beginning of the array.
#include<iostream>
#include<limits.h>
using namespace std;
int bs(int arr[],int s,int e,int x){
    //ab simple binary search lga diya us chota se subpart mein
    while(s<=e){
        int mid = s + (e - s)/2;

        if(arr[mid]==x) return mid;
        else if(arr[mid]<x) s = mid + 1;
        else e = mid - 1;
    }
    return -1;
}
int exponentialsearch(int arr[],int size,int x){
    //agr a[0] par hi x pada hai to 0 ko return krdenge or hmne yaah 0 vala return kyu kiya kyuki hm i 1 se initialize kr rah hai
    //or i 1 se initialize kyu kr rah hai kyuki agr 0 se initialize krenge to har jagah 0 0 0 0 hi reh jayga
    //That's why hm i ko 1 se initialize krenge
    if(arr[0]==x) return 0;

    int i = 1;
    while(i < size && arr[i]<=x){
        i = i * 2; //i*=2 or i = i << 1;
    }
    //ab hm return binary search kr denge
    return bs(arr,i/2,min(i,size-1),x);
}
int main(){
    int arr[] = {3,4,5,6,11,13,14,15,56,70};
    int size = sizeof(arr)/sizeof(int);
    int x = 13;
    // if we want to find 13 and array size is 10
    int ans = exponentialsearch(arr,size,x);
    cout<<"Element is present at index : "<<ans<<endl;
    return 0;
}
//Time complexity  = O(2^n);

//exponential search will help in unbounded array
//what is unbounded search  - means we find the element in the inifinite array - sorted
//i use exponential search in that case because when we don't know end but from the exponential search by i we found also end
