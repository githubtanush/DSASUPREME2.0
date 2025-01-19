// Insertion sort - in general increasing order
// example - take array - 5 | 4 | 3 | 2 | 1
// In insertion sort let us we ignore the 5 assume 5 is already sorted
// and starting sorting from 4


// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//Steps in insertion sort
// array -> 5 | 4 | 3 | 2 | 1
// Step 1 -> ignore 5 start from 4
//  5 | 4 | 3 | 2 | 1 
// 1.) 4 | 5 | 3 | 2 | 1
// 2.) 3 | 4 | 5 | 2 | 1
// 3.) 2 | 3 | 4 | 5 | 1
// 4.) 1 | 2 | 3 | 4 | 5

// i = 1 , key = v[i] => key = 4
// variable j = i - 1 while(j>=0 && v[j] > key) v[j+1] = v[j] j--;
// v[j+1] = key

// i = 2 , key = v[i]

// i = 0 kuch nhi krna 
// i = 1 to n - 1
// j = i - 1 to j >= 0


                    // N = 5
// Iterations           Comparisons         Generalize
// 1st Iteration        1                     1
// 2nd Iteration        2                     2
// 3rd Iteration        3                     3
// 4th Iteration        4                     n-1 comparison

// Sn = n ( n - 1 )/2 => O(n^2/2 - n/2) => O(n^2)
//Time complexity - O(N^2) and space complexity - O(1)
// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include<iostream>
#include<vector>
using namespace std;
void insertionsort(vector<int>& v){
    int n = v.size();
    // i = 0 , chodd deta hu 
    for(int i = 1; i < n;i++){
        int key = v[i];
        int j = i - 1;
        //Move elements of arr[0....i-1] that are greater than 
        //key to one position ahead of their current position
        while(j>=0 && v[j] > key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;//insertion 
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements we have : ";
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++) cin>>v[i];
    for(int i : v) cout<<i<<" ";
    insertionsort(v);
    cout<<endl;
    for(int i : v) cout<<i<<" ";
    return 0;
}