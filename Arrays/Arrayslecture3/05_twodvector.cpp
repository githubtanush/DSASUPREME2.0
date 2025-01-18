// 05_twodvector
#include<iostream>
#include<vector>
using namespace std;
void input(vector<vector<int> >& arr){
    for(int i = 0; i < arr.size();i++){
        for(int j = 0; j < arr[i].size();j++){
            cin>>arr[i][j];
        }
    }
}
void print(vector<vector<int> >& arr){
    for(int i = 0; i < arr.size();i++){
        for(int j = 0;j < arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int rows;
    cout<<"Enter the number of rows in the array : ";
    cin>>rows;
    int cols;
    cout<<"Enter the number of cols in the array : ";
    cin>>cols;
    // 2d vector vector name row size row items if initialize cols, likh do jo bi lena
    vector<vector<int> > arr(rows,vector<int>(cols));
    input(arr);
    print(arr);
    return 0;
}