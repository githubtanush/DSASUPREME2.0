// vectors
//what is stl?
// stl is standard template library which provides 
// a collection of template class and functions that
//  offer common data structure and algorithms to make 
//programming more efficient and convenient;

//A vector in cpp is a dynamic array that grow or shrink in size, 
//making it a versatile and efficient data structure for storing and 
// manipulating sequences of elements

// #############################################################################################################################################################################################################################


// // features of vector
// 1.) contiguous memory 
// 2.) dynamic sizing
// 3.) automatic reallocation
// 4.) size and capacity
// 5.) array like access


// #############################################################################################################################################################################################################################
// int arr[5] - static array 
// dynamic array - 
// int n;
// cin>>n;
// int arr[n] //wrong bad practice
// //correct way for dynamic memory allocation
// int n;
// cin>>n;
// int *arr = new int[n]; //if we simply allocate but not take input 
// then it contain 0 or garbage value
//but due to this dynamic array we still restricted to the size of the array
// we not insert more than the size of the array

// #############################################################################################################################################################################################################################

// Vector now in vector we don't tell the size of the vector
// just keep inserting the elements, i will manage the reallocations
// na to user se puchna hai just keep inserting data
// is possible with the datatype vector
//vector is also an array but we don't tell the size of the vector
#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>& v){
    int size = v.size();
    //also we print with cout<<v.at(i)<<" ";
    for(int i = 0; i < size;i++) cout<<v[i]<<" ";
}
int main(){
    // in vector, we don't tell the size of the vector
    //just keep inserting , i will manage reallocations
    vector<int> v;//array hi hai vector of integer type
    // vector<char> b; // vector of character type

// #############################################################################################################################################################################################################################


    //for two d vectors
    // vector<vector<int> > arr(rows,vector<int>(cols,0));
    // array name(rows,vector array(columns, or initialization if any number))


// #############################################################################################################################################################################################################################


    //vector initialization
    // vector<int> arr; // default array with no data, 0 size
    // vector<int> arr2(5,-1); // we create array of size 5 and initialize with -1 data
    //but still we add elements because this is vector by v.push_back
    // vector<int> arr3 = {1,2,3,4,5};
    // vector<int> arr4{1,2,3,4,5};
    
// #############################################################################################################################################################################################################################


//how to copy vector
// vector<int> arr5 = {1,2,3,4,5};
// vector<int> arr6(arr5);


// #############################################################################################################################################################################################################################
    //inserting in vector
    // int n;
    // cin>>n;
    // for(int i = 0; i < n;i++){
    //     int d;
    //     cin>>d;
    //     v.push_back(d);
    // }
// #############################################################################################################################################################################################################################
    //insert in the array
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    print(v);
    //pop the array
    cout<<endl;
    v.pop_back();
    print(v);


// if i want to clear the vector then use - v.clear();
// for front element = v.front();
// for back element = v.back();


    return 0;
}

//how's this work 
//vector handle size automatically by doubling it
// v;                      cap         size
// v.push_back(1);         1           1
// v.push_back(2);         2           2
// v.push_back(3);         3           4
// v.push_back(4);         4           4
// v.push_back(5);         5           8