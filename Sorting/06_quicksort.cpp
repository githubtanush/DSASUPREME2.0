//quick sort - given an unsorted array 
// 7 | 2 | 1 | 8 | 6 | 3 | 5 | 4
//simply we choose one pivot element such that the elements to the right
//of pivot > a[pivot]
// element left of pivot element < a[pivot]
// we make partition as such as posssible that in the left of pivot all element are 
// small and in the right of the pivot all the larger elements than pivot

// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// quick sort simple and good logic is take one pivot element and in the left of pivot 
// take all small elements and in the right of pivot take larger elements

// array -> 7 | 2 | 1 | 8 | 6 | 3 | 5 | 4

// pivot = end
// 1.) pivot = 7
// 2.) i = start - 1 , j = start;
// 3.) a[pivot] = 4; 


//logic - hr baar mein aarray ke last element ko hi pivot maanunga
//means simply we have logic that ki last element uthao or usko 
//pivot maan kar uska left or right arrange kr do

// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<iostream>
#include<vector>
using namespace std;
void quicksort(vector<int>& a,int s,int e){
    if(s >= e) return ;
    int pivot = e;
    int i = s - 1; 
    int j = s;
    // jab tak index pivot se km hai tab tak
    while(j < pivot){
        // jab tak jth index ka element ki value pivot index ke element 
        // se km hai to usko swap krdo or i ko aaga bda do
        if(a[j] < a[pivot]){
            i++;
            swap(a[i],a[j]);
        }
        //nhi to j ko aaga bdata jao
        j++;
    }
    //then last mein i jaha hai usko ek baar or aaga bda kr 
    //usko swap krdo pivot se baaki recursion bhaiya sambhal lenge
    i++;
    //i is the right position for the pivot element
    swap(a[i],a[pivot]);
    quicksort(a,s,i-1);
    quicksort(a,i+1,e);
}
int main(){
    int n;
    cout<<"Enter how many numbers you want to take : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin>>arr[i];
    int s = 0;
    int e = n-1;
    quicksort(arr,s,e);
    for(int i : arr) cout<<i<<" ";
    return 0;
}
//8
//7 2 1 8 6 3 5 4