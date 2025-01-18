// twodarray
// 2-d array mein yeh kon sa dbba hai 1d mein yeh es formula se pta lgta hai
// column*i+j convert to double index to single index
#include<iostream>
#include<vector>
using namespace std;
void input(int arr[][4],int row,int col){
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            cout<<"Enter the input for row index : "<<i<<" column index : "<<j<<endl;
            cin>>arr[i][j];
        }
    }
}
// function ke andar bhi column ka size pass krna hi pdega 
//nhi kroga to error aayga kyuki conversion ke time columns 
//ki need hmesha pdti hai
void print(int arr[][4],int row,int col){
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void printcolwise(int arr[][4],int row,int col){
    for(int i = 0; i < col;i++){
        for(int j = 0; j < row;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}
//searching in twod array
bool search(int arr[][4],int row,int col,int target){
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            //target mil gya to return krdenge true
            if(arr[i][j] == target) return true;
        }
    }
    //mein yaah phuncha hu 
    //matlab saara k saara elements check ho chuka h
    //or target nhi mila hoga 
    //to mein return krdunga false;
    return false;
}
int main(){
    //2-d array creation 
    //when we declare array atleast we give number of columns size
    //for conversion number  c * i + j of columns ki need hoti hai 
    //that's why number of columns dena hi pdega


    // int crr[3][] = {
    //     {1,2,3,4},
    //     {5,6,7,8},
    //     {9,10,11,12}
    // };


    // int brr[][4] = {
    //     {1,2,3,4},
    //     {5,6,7,8},
    //     {9,10,11,12}
    // };
    int arr[3][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    int row = 3;
    int col = 4;
    print(arr,row,col);
    cout<<endl<<endl;
    printcolwise(arr,row,col);


    int brr[4][4];
    row = 4;
    col = 4;
    input(brr,row,col);
    cout<<endl;
    print(brr,row,col);
    int target = 15;
    if(search(brr,row,col,target)) cout<<"Bhaijaan target mil gya ooy..."<<endl;
    else cout<<"shit yrr target nhi milya yaar"<<endl;
    
    return 0;
}