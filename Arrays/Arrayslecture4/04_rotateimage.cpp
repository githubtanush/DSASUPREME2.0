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
void rotateimage(vector<vector<int> >& arr){
    //mein agr transpose krdu then uske baad har ek ith row ko reverse krdu to vo image 
    //rotate ho jayegi
    //matlab yeh 2 step ka process hai 
    
    //Step 1 = meini transpose kr liya
    int n = arr.size();
    for(int i = 0; i < arr.size();i++){
        for(int j = i ; j < arr[i].size();j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    //Step 2 = meini transpose krne ke baad ab har ek line par jakar use reverse krna shuru kr diya
    // or har ek row ko reverse kr diya
    //reverse is a stl for vector we write (name.begin(),name.end())
    // for simple array reverse we use (name, name + n);
    for(int i = 0; i < arr.size();i++){
        reverse(arr[i].begin(),arr[i].end());
    }

}
void print(vector<vector<int> >& arr){
    for(int i = 0; i < arr.size();i++){
        for(int j = 0; j < arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int rows;
    cout<<"Enter how many rows do you want : ";
    cin>>rows;
    int cols;
    cout<<"Enter how many cols do you want : ";
    cin>>cols;
    vector<vector<int> > arr(rows,vector<int>(cols));
    input(arr);
    print(arr);
    rotateimage(arr);
    cout<<endl;
    print(arr);
    return 0;
}
// 3
// 3
// 1 2 3 
// 4 5 6
// 7 8 9