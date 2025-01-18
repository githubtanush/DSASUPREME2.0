// 02_printpairs
#include<iostream>
#include<vector>
using namespace std;
void printpairs(vector<int>& arr){
    //row size = arr.size(); col size = arr[0].size or arr[i].size;
    //arr[0].size for fixed columns and arr[i] for different columns on each rows
    for(int i = 0; i < arr.size();i++){
        for(int j = i; j < arr.size();j++){
            //if j = 0 included from ith element
            //if j = 1 then not include ith element in pair
            // if j = 2 then not include ith and (i+1)th element in pair
            cout<<"("<<arr[i]<<","<<arr[j]<<")"<<" ";
        }
        cout<<endl; //next row starts on new line
    }
}
void printtriplets(vector<int>& arr){
    //row size = arr.size(); col size = arr[0].size or arr[i].size;
    //arr[0].size for fixed columns and arr[i] for different columns on each rows
    //change conditions in the for loop and explore different cases
    for(int i = 0; i < arr.size();i++){
        for(int j = i; j < arr.size();j++){
            for(int k = j + 1; k < arr.size();k++){
            //if j = 0 included from ith element
            //if j = 1 then not include ith element in pair
            // if j = 2 then not include ith and (i+1)th element in pair
            cout<<"("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<")"<<" ";
            }
        }
        cout<<endl; //next row starts on new line
    }
}
int main(){
    int n;
    cout<<"How many elements you want to insert in the array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin>>arr[i];
    printpairs(arr);
    printtriplets(arr);
    return 0;
}
// 5
// 1 2 3 4 5