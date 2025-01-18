// 03_sumrowcoldiag
#include<iostream>
#include<vector>
using namespace std;
void rowwisesum(int arr[][4],int row,int col){
    for(int i = 0; i < row;i++){
        int sum = 0;
        for(int j = 0;j < col;j++){
            sum += arr[i][j];
        }
        cout<<"Sum for the row "<<(i+1)<<" is : "<<sum<<endl;
    }
}
void colwisesum(int arr[][4],int row,int col){
    for(int i = 0; i < col;i++){
        int sum = 0;
        for(int j = 0;j < row;j++){
            sum += arr[j][i];
        }
        cout<<"Sum for the col "<<(i+1)<<" is : "<<sum<<endl;
    }
}
void diagonalwisesum(int arr[][4],int row,int col){
    int sum = 0;
    for(int i = 0; i < row;i++){
        sum += arr[i][i];
    }
    cout<<"Sum for the diagonal elements is : "<<sum<<endl;
}
void ultadiagonalwisesum(int arr[][4],int row,int col){
    int sum = 0;
    for(int i = 0; i < row;i++){
        sum += arr[i][col-i-1];
    }
    cout<<"Sum for the ulta diagonal elements is : "<<sum<<endl;
}
int main(){
    int row = 4;
    int col = 4;
    int arr[4][4] = {
        {1,2,3,4},
        {4,5,6,7},
        {7,18,9,10},
        {1,2,3,4}
    };
    rowwisesum(arr,row,col);
    colwisesum(arr,row,col);
    diagonalwisesum(arr,row,col);
    ultadiagonalwisesum(arr,row,col);
    return 0;
}