// sorting - means we make array to increasing order or decreasing order 
//generally sort means sort in increasing order
// -> algorithm depends on basic logic  
// swap the adjacents if needed till we get all the array sorted
//let's consider an array  - 5 | 4 | 3 | 2 | 1
//Step 1 -> 5 | 4 | 3 | 2 | 1
// 1.) 4 | 5 | 3 | 2 | 1
// 2.) 4 | 3 | 5 | 2 | 1
// 3.) 4 | 3 | 2 | 5 | 1
// 4.) 4 | 3 | 2 | 1 | 5 
// number of comparisons = 4
// now we see the last element is sorted this algorithm worked on this 
//logic that at 1st iteration largest element is at rightmost position

//Step 2 ->  4 | 3 | 2 | 1 | 5
// 1.) 3 | 4 | 2 | 1 | 5
// 2.) 3 | 2 | 4 | 1 | 5
// 3.) 3 | 2 | 1 | 4 | 5
//number of comparisons = 3
// now we see the last second element is sorted in this algorithm and make 
// at last second position 

//Step 3 -> 3 | 2 | 1 | 4 | 5
// 1.) 2 | 3 | 1 | 4 | 5
// 2.) 2 | 1 | 3 | 4 | 5
//number of comparisons = 2;
// now we see the last third element is sorted in this algorithm at last 
// third position

//Step 4 -> 2 | 1 | 3 | 4 | 5
// 1.) 1 | 2 | 3 | 4 | 5
// number of comparisons = 1
// now we see the last fourth element is sorted in this algorithm 
// and all the array is sorted


//means n - 1 iteration mein kaam ho gya

                    // N = 5
// Iterations           Comparisons         Generalize
// 1st Iteration        4                     n-1
// 2nd Iteration        3                     n-2
// 3rd Iteration        2                     n-3
// 4th Iteration        1                       1 comparison

// Sn = n ( n - 1 )/2;
// O(n) = O(n^2 /2 - n /2) => O(N^2) -> Time complexity
//Space complexity - O(1)

//Outerloop -> (n-1)
//Innerloop -> comparisons (n - i - 1)



#include<iostream>
#include<vector>
using namespace std;
void bubblesort(vector<int>& v){
    int n = v.size();
    for(int i = 0; i < n - 1;i++){
        for(int j = 0; j < n - i - 1; j++){
            if(v[j] > v[j+1]) swap(v[j],v[j+1]);
        }
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements we have : ";
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++) cin>>v[i];
    for(int i : v) cout<<i<<" ";
    bubblesort(v);
    cout<<endl;
    for(int i : v) cout<<i<<" ";
    return 0;
}