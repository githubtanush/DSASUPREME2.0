#include<iostream>
#include<vector>
using namespace std;
vector<double> getcollisiontimes(vector<vector<int> >& cars){
    
}
int main(){
    // we make one vector which 1st place is gives us the 
    // position of the car and 2nd place is gives us the 
    // speed of the car

    // and we check is there any car ahead of me with which 
    // I can  collide

    int rows;
    cout<<"Enter the number of rows : ";
    cin>>rows;

    int cols;
    cout<<"Enter the number of cols : ";
    cin>>cols;

    //make the 2d vector
    vector<vector<int> > v(rows,vector<int>(cols));

    //take the input in 2d vector
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols;j++){
            cin>>v[i][j];
        }
    }  



    return 0;
}