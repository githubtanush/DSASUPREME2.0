// twodminmax
#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int minimum(int arr[][3],int row,int col){
    //same logic as array lecture 1 take one mini 
    //initialize it with int_max and doing
    int mini = INT_MAX;
    for(int i = 0; i < row;i++){
        for(int j = 0;j < col;j++){
            if(arr[i][j] < mini) mini = arr[i][j];
        }
    }
    return mini;
}
int maximum(int arr[][3],int row,int col){
    //same logic as array lecture 1 take one maxi 
    //initialize it with int_min and doing
    int maxi = INT_MIN;
    for(int i = 0; i < row;i++){
        for(int j = 0;j < col;j++){
            if(arr[i][j] > maxi) maxi = arr[i][j];
        }
    }
    return maxi;
}
int main(){
    int row = 3;
    int col = 3;
    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout<<"Minimum number in the array is : "<<minimum(arr,row,col)<<endl;
    cout<<"Maximum number in the array is : "<<maximum(arr,row,col)<<endl;
    return 0;
}