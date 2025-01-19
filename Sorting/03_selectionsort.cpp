//Selection sort - what if , i select the minimum element and 
// put it at the right position
// in general sorting in ascending order


// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




// array -> 44 | 33 | 55 | 22 | 11
// Step 1 -> 44 | 33 | 55 | 22 | 11
// select the minimum element - 11 and place it at their right position
// 1.) 11 | 33 | 55 | 22 | 44
// 2.) 11 | 22 | 55 | 33 | 44 
// 3.) 11 | 22 | 33 | 55 | 44
// 4.) 11 | 22 | 33 | 44 | 55

// for ith iteration , pick smallest element from i to n - 1 index 
// and swap it with ith element

// i -> 0 to n - 1


                    // N = 5
// Iterations           Comparisons         Generalize
// 1st Iteration(i=0)       4                     n-1
// 2nd Iteration(i=1)       3                     n-2
// 3rd Iteration(i=2)       2                     n-3
// 4th Iteration(i=3)       1                     1 comparison

// outerloop -> n - 1 times;
// innerloop -> n - 1 times;
// Sn = n ( n - 1 )/2 => O(N^2)

//Time complexity - O(N^2) and space complexity - O(1)




// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


#include<iostream>
#include<vector>
using namespace std;
void selectionsort(vector<int>& v){
    int n = v.size();
    for(int i = 0; i < n - 1;i++){
        int minindex = i; //ith element hi smallest element hai
        for(int j = i + 1; j < n ;j++){
            if(v[j] < v[minindex]) minindex = j;
        }
        //swap ith and minindex elements;
        swap(v[i],v[minindex]);
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements we have : ";
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++) cin>>v[i];
    for(int i : v) cout<<i<<" ";
    selectionsort(v);
    cout<<endl;
    for(int i : v) cout<<i<<" ";
    return 0;
}
// 5
// 44 33 55 22 11